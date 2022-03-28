import numpy as np
import scipy.spatial

import transforms as ts

class Edge(object):
    '''
    Base edge class.
    Some methods are abstract and should be redefined.
    Provides numerical Jacobian computations.
    '''

    def __init__(self, vertices):
        self.vertices = vertices
        self._J = None
        self.inf = None
    
    def linearize(self):
        DELTA = 1E-9
        self._J = []
        for vertex in self.vertices:
            J = None
            start_params = vertex.params
            for dim in range(vertex.dim):
                vertex.params = start_params
                delta_params = np.zeros(vertex.dim)
                delta_params[dim] = DELTA
                vertex.update(delta_params)
                self.compute_error()
                error_diff = self.error
                vertex.params = start_params
                delta_params[dim] = -DELTA
                vertex.update(delta_params)
                self.compute_error()
                error_diff -= self.error
                if J is None:
                    J = np.zeros((len(error_diff), vertex.dim))
                J[:, dim] = error_diff / 2.0 / DELTA
            self._J.append(J)

        
    def J(self, vertex_index):
        assert self._J is not None and vertex_index < len(self._J)
        return self._J[vertex_index]
    
    @property
    def inf(self):
        raise Exception('Not implemented')
    
    @property
    def error(self):
        raise Exception('Not implemented')
    
    def compute_error(self):
        raise Exception('Not implemented')
    
    def chi2(self):
        return np.dot(np.dot(self.error, self.inf), self.error)


class Vertex(object):
    '''
    Basic vertex class.
    Update method is abstract and should be reimplemented
    '''

    def __init__(self, params):
        self.params = params
    
    def update(self, delta):
        raise Exception('Not implemented')
    
    @property
    def dim(self):
        return len(self.params)


class SE2Vertex(Vertex):
    '''Vertex class that represents SE(2) class of transformations'''

    def __init__(self, params):
        assert len(params) == 3
        super(SE2Vertex, self).__init__(params)
        
    def update(self, delta):
        transform = np.array([np.cos(self.params[2]), -np.sin(self.params[2]), 0.0,
                              np.sin(self.params[2]), np.cos(self.params[2]), 0.0,
                              0.0, 0.0, 1.0]).reshape((3, 3))
        self.params += np.dot(transform, delta)


class Feature(object):
    '''Represents feature and associated data: feature vertex, related edges and type'''
    
    UNDEFINED = 0
    POINT = 1
    LINE = 2
    
    def __init__(self, vertex, edges, ftype):
        self.vertex = vertex
        self.edges = edges
        self.ftype = ftype

    @property
    def visualization_data(self):
        if self.ftype == Feature.POINT:
            return self.vertex.params
        return None


class PriorEdge(Edge):
    inf = None
    error = None

    def __init__(self, vertex, event, cov_diag):
        super(PriorEdge, self).__init__([vertex])
        self.inf = np.linalg.inv(np.diag(cov_diag))
        self._pose = np.array(event['pose'])

    def compute_error(self):
        self.error = np.array(self._pose) - np.array(self.vertices[0].params)

class OdometryEdge(Edge):
    inf = None
    error = None

    def __init__(self, from_vertex, to_vertex, event):
        super(OdometryEdge, self).__init__([from_vertex, to_vertex])
        alpha = np.array(event['alpha']).reshape((3, 2))
        self.inf = np.diag(1.0 / np.dot(alpha, np.square(np.array(event['command']))))
        self._v, self._w = event['command']
    
    @property
    def from_vertex(self):
        return self.vertices[0]
    
    @property
    def to_vertex(self):
        return self.vertices[1]


    def compute_error(self):
        '''
        #########################################
        TO_IMPLEMENT Seminar.Task#3
        '''
        x_t = self.vertices[1].params[0]
        y_t = self.vertices[1].params[1]
        theta = self.vertices[1].params[2]

        x_t_prev = self.vertices[0].params[0]
        y_t_prev = self.vertices[0].params[1]
        theta_prev = self.vertices[0].params[2]


        mu = 0.5 * ((x_t_prev - x_t) * np.cos(theta_prev) + (y_t_prev - y_t) * np.sin(theta_prev))/ \
                    ((y_t_prev - y_t) * np.cos(theta_prev) - (x_t_prev - x_t) * np.sin(theta_prev))

        x_c = (x_t_prev + x_t)/2 + mu*(y_t_prev-y_t)
        y_c = (y_t_prev + y_t)/2 + mu*(x_t-x_t_prev)

        sign = np.sign(y_c - y_t_prev)

        center_in_prev = np.array([x_c, y_c]) - self.from_vertex.params[:-1]
        r = np.linalg.norm(center_in_prev)
        delta_theta = np.arctan2(y_t - y_c, x_t - x_c) - np.arctan2(y_t_prev - y_c, x_t_prev - x_c)


        v_est = r*delta_theta*sign
        omega_est = delta_theta

        theta_est = theta_prev + omega_est
        cos_dist = scipy.spatial.distance.cosine(np.array([x_t - x_t_prev, y_t - y_t_prev]),
                                          np.array([np.cos(theta_prev), np.sin(theta_prev)]))
        # That means car was going linear

        if (cos_dist < 1e-3 or  np.fabs(cos_dist - 2.) < 1e-3):
            est_ = np.array([np.dot(np.array([x_t - x_t_prev, y_t - y_t_prev]),
                                    np.array([np.cos(theta_prev), np.sin(theta_prev)])), 0.])
            v_est = est_[0]
            omega_est = est_[1]

        self.error = np.array(
            [
                self._v - v_est,
                self._w - omega_est,
                theta - theta_est
            ]
        )

class Landmark(Vertex):
    '''
    Represents positon of feature in the map
    '''
    
    def __init__(self, params):
        assert len(params) == 2
        super(Landmark, self).__init__(params)
    
    def update(self, delta):
        self.params += delta


class LandmarkObservationEdge(Edge):
    inf = None
    error = None

    '''
    #########################################
    TO_IMPLEMENT Homework.Task#1
    '''
    def __init__(self, pose_vertex, feature_vertex, event):
        super(LandmarkObservationEdge, self).__init__([pose_vertex, feature_vertex])
        self._z = np.array(event['measurement'])
        self._inf = np.array(event['Q'])

    def compute_error(self):
        car_pose = self.vertices[0].params
        feature_pose = self.vertices[1].params
        diff_x = (car_pose[0] - self._z[0])
        diff_y = (car_pose[1] - self._z[1])

        landmark_pos_local_frame = np.array(
            [
                car_pose[0] * np.cos(car_pose[2]) + car_pose[1] * np.sin(car_pose[2]) + self._z[0],
                car_pose[0] * np.sin(car_pose[2]) - car_pose[1] * np.cos(car_pose[2]) + self._z[1]
             ]
        )

        print(landmark_pos_local_frame)
        self.error = landmark_pos_local_frame - feature_pose
        print(self.error)