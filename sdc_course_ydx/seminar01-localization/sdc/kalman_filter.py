# -*- coding: utf-8 -*-
import numpy as np


def kalman_transit_covariance(S, A, R):
    """
    :param S: Current covariance matrix
    :param A: Either transition matrix or jacobian matrix
    :param R: Current noise covariance matrix
    """
    new_s = np.dot(np.dot(S, A), S.T) + R
    return new_s


def kalman_process_observation(mu, S, observation, C, Q):
    """
    Performs processing of an observation coming from the model: z = C * x + noise
    :param mu: Current mean
    :param S: Current covariance matrix
    :param observation: Vector z
    :param C: Observation matrix
    :param Q: Noise covariance matrix (with zero mean)
    """
    new_k = np.dot(np.dot(S,C.T),np.linalg.inv(np.dot(np.dot(C,S), C.T) + Q))
    new_mu = mu + np.dot(new_k, (observation-np.dot(C, mu)))
    new_s = np.dot((np.eye(mu.shape[0]) - np.dot(new_k, C)),S)

    return new_mu, new_s
