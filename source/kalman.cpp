/*
 * kalman.cpp
 * 
 * 28-11-2024 by madpl
 */
#include "kalman.hpp"


double kalmanFilter(double measurement, double& est, double& P)
{
	// prognosis
	P += Q;

	// calculate Kalman coeficient
	double K = P / (P + R);

	// update estimate: est
	est = est + K * (measurement - est);

	// update error
	P = (1 - K) * P;

	return est;
}
