// diamondsquare.cpp : diamond square algorithm 
//
#include "diamondsquare.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


void diamondsquare(vector<vector<float> > &res, float rate, int M, int a, int b, int c, int d)
{
	if (a + 1 < c)
	{
		int m = (a + c) / 2, n = (b + d) / 2;
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		res[m][n] = (res[a][b] + res[a][d] + res[c][b] + res[c][d]) / 4 + r * M * rate;

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		res[a][n] = (res[a][b] + res[m][n] + res[a][d] + (3 * a >= 2 * c ? res[3 * a / 2 - c / 2][n] : 0)) / 4 + r * M * rate;

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		res[m][b] = (res[a][b] + res[m][n] + res[c][b] + (3 * b >= 2 * d ? res[m][3 * b / 2 - d / 2] : 0)) / 4 + r * M * rate;

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		res[c][n] = (res[c][b] + res[m][n] + res[c][d] + (a + 2 * res.size() > 3 * c ? res[3 * c / 2 - a / 2][n] : 0)) / 4 + r * M * rate;

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		res[m][d] = (res[c][b] + res[m][n] + res[c][d] + (b + 2 * res.size() > 3 * d ? res[3 * d / 2 - b / 2][n] : 0)) / 4 + r * M * rate;

		diamondsquare(res, rate * rate, M, a, b, m, n);
		diamondsquare(res, rate * rate, M, m, b, c, n);
		diamondsquare(res, rate * rate, M, a, n, m, d);
		diamondsquare(res, rate * rate, M, m, n, c, d);
	}
}
