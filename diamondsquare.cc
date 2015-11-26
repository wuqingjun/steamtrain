// diamondsquare.cpp : diamond square algorithm 
//
#include "diamondsquare.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const int INC = 5;

int random(int a, int b)
{
	return rand() % b + a;	
}

int max(int a, int b, int c, int d)
{
	return max(max(max(a, b), c), d);
}


int min(int a, int b, int c, int d)
{
	return min(min(min(a, b), c), d);
}

void diamondsquare(vector<vector<float> > &res, float rate, int M, int H, int a, int b, int c, int d)
{
	if (a + 1 < c)
	{
		int m = (a + c) / 2, n = (b + d) / 2;
		int maxN = max(res[a][b], res[a][d], res[c][b], res[c][d]); 
		int	minN = min(res[a][b], res[a][d], res[c][b], res[c][d]);  
		res[m][n] = (minN == maxN ?  random(minN, minN + INC) : random(minN, maxN));

		if(a == 0 || a == M - 1)
		{
			res[a][n] = 0;
		}
		else
		{
			maxN = max(res[a][b], res[m][n], res[a][d], (3 * a >= 2 * c ? res[3 * a / 2 - c / 2][n] : 0));
			minN = min(res[a][b], res[m][n], res[a][d], (3 * a >= 2 * c ? res[3 * a / 2 - c / 2][n] : 0));
			res[a][n] = (minN == maxN ?  random(minN, minN + INC) : random(minN, maxN));
		}

		if(b == 0 || b == M - 1)
		{
			res[m][b] = 0;
		}
		else
		{
			maxN = max(res[a][b], res[m][n], res[c][b], (3 * b >= 2 * d ? res[m][3 * b / 2 - d / 2] : 0));
			minN = min(res[a][b], res[m][n], res[c][b], (3 * b >= 2 * d ? res[m][3 * b / 2 - d / 2] : 0));
			res[m][b] = (minN == maxN ?  random(minN, minN + INC) : random(minN, maxN));
		}

		if(c == 0 || c == M - 1)
		{
			res[c][n] = 0;
		}
		else
		{
			maxN = max(res[c][b], res[m][n], res[c][d], (a + 2 * res.size() > 3 * c ? res[3 * c / 2 - a / 2][n] : 0));
			minN = min(res[c][b], res[m][n], res[c][d], (a + 2 * res.size() > 3 * c ? res[3 * c / 2 - a / 2][n] : 0));
			res[c][n] = (minN == maxN ?  random(minN, minN + INC) : random(minN, maxN));
		}

		if(d == 0 || d == M - 1)
		{
			res[m][d] = 0;
		}	
		else
		{
			maxN = max(res[c][b], res[m][n], res[c][d], (b + 2 * res.size() > 3 * d ? res[3 * d / 2 - b / 2][n] : 0));
			minN = min(res[c][b], res[m][n], res[c][d], (b + 2 * res.size() > 3 * d ? res[3 * d / 2 - b / 2][n] : 0));
			res[m][d] = (minN == maxN ?  random(1, minN + 2) : random(minN, maxN));
		}

		diamondsquare(res, rate, M, H * rate, a, b, m, n);
		diamondsquare(res, rate, M, H * rate, m, b, c, n);
		diamondsquare(res, rate, M, H * rate, a, n, m, d);
		diamondsquare(res, rate, M, H * rate, m, n, c, d);
	}
}
