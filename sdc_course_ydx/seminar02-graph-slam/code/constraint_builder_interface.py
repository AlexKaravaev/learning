import numpy as np
import graph_elements as ge
import transforms as ts

class Constraint(object):
    '''
    Stores constraint information: pose edges and features.
    The content strongly depends on producer.
    '''

    def __init__(self, pose_edges=[], features=[]):
        self.pose_edges = list(pose_edges)
        self.features = list(features)


class IConstraintBuilder(object):
    '''
    Abstract class for constraint builder.
    
    add_event() is populated with sequential events.
    When the class is ready to return new constraint it should return 'True' from ready() method.
    When ready attribute is set build method is invoked to obtain created constraint.
    '''
    
    def add_event(self, event):  
        raise Exception('Not implemented')
    
    def ready(self):
        raise Exception('Not implemented')
    
    def build(self):
        raise Exception('Not implemented')


class PriorEdgeConstraintBuilder(IConstraintBuilder):
    '''
    Builds initialization constraint based on init event
    '''

    def __init__(self, pose_vertices):
        self._pose_vertices = pose_vertices
        self._ready = False
        self._edge = None
    
    def add_event(self, event):
        if event['type'] != 'init':
            self._ready = False
            return
        self._ready = True
        '''
        #########################################
        TO_IMPLEMENT Seminar.Task#2
        '''
        self._edge = ge.PriorEdge(self._pose_vertices[0], event, [0.1, 0.1, 0.1])
    
    def ready(self):
        return self._ready
    
    def build(self):
        if not self.ready():
            return None
        constraint = Constraint(pose_edges=[self._edge])
        self._edge = None
        self._ready = False
        return constraint


class OdometryConstraintBuilder(IConstraintBuilder):
    '''
    Builds odometric constraints based on control measurements
    '''

    def __init__(self, pose_vertices):
        self._pose_vertices = pose_vertices
        self._ready = False
        self._edge = None
    
    def add_event(self, event):
        if event['type'] != 'control':
            self._ready = False
            return
        self._ready = True
        '''
        #########################################
        TO_IMPLEMENT Seminar.Task#4
        '''
        self._edge = ge.OdometryEdge(self._pose_vertices[event['time']], self._pose_vertices[event['time'] + 1], event)


    def ready(self):
        return self._ready
    
    def build(self):
        if not self.ready():
            return None
        constraint = Constraint(pose_edges=[self._edge])
        self._edge = None
        self._ready = False
        return constraint


class LandmarkConstraintBuilder(IConstraintBuilder):
    def __init__(self, pose_vertices):
        self._ready = False
        self._feature = None
        self._pose_vertices = pose_vertices
        self._observed_features = {}
        '''
        #########################################
        TO_IMPLEMENT Homework.Task#2
        '''

    def add_event(self, event):
        '''
        #########################################
        TO_IMPLEMENT Homework.Task#2
        '''
        if event['type'] != 'point':
            self._ready = False
            return

        timestamp = event['time']
        landmark_pos_local_frame = np.array(event['measurement'])
        landmark_id = event['index']


        if landmark_id not in self._observed_features:
            # Transform landmark to global frame
            self._ready = True
            T = ts.Transform2D.from_pose(self._pose_vertices[timestamp].params)
            landmark_pos_global_frame = T.transform(landmark_pos_local_frame)
            self._feature = ge.Feature(ge.Landmark(landmark_pos_global_frame), edges=[], ftype=1)
            self._observed_features[landmark_id] = self._feature
        else:
            self._ready = False

        self._observed_features[landmark_id].edges.append(
            ge.LandmarkObservationEdge(self._pose_vertices[timestamp], self._observed_features[landmark_id].vertex, event))
    
    def ready(self):
        return self._ready
    
    def build(self):
        if not self.ready():
            return None
        constraint = Constraint(features=[self._feature])
        self._feature = None
        self._ready = False
        return constraint
