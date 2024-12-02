/*
 * kalman.hpp
 * 
 * 28-11-2024 by madpl
 */
#pragma once


const double Q = 0.01;	// process noise
const double R = 0.1;	// measurement noise

double kalmanFilter(double measurement, double& estimate, double& P); 
