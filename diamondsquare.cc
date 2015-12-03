// diamondsquare.cpp : diamond square algorithm 
//
#include "diamondsquare.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int random(int a, int b)
{
	return rand() % b + a;	
}


float avg(float a, float b, float c, float d)
{
	return (a + b + c + d) / 4;
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
	int INC = H;
	if (a + 1 < c)
	{
		int m = (a + c) / 2, n = (b + d) / 2;
		float maxN = max(res[a][b], res[a][d], res[c][b], res[c][d]); 
		float minN = min(res[a][b], res[a][d], res[c][b], res[c][d]);  
		float av = avg(res[a][b], res[a][d], res[c][b], res[c][d]);
		res[m][n] = av + (random(minN, maxN + INC) - minN) * rate;
		if(a != 0 && a != M - 1)
		{
			maxN = max(res[a][b], res[m][n], res[a][d], (3 * a >= 2 * c ? res[3 * a / 2 - c / 2][n] : 0));
			minN = min(res[a][b], res[m][n], res[a][d], (3 * a >= 2 * c ? res[3 * a / 2 - c / 2][n] : 0));
			av = avg(res[a][b], res[m][n], res[a][d], (3 * a >= 2 * c ? res[3 * a / 2 - c / 2][n] : 0));
			int temp = 0;
			if(a < 4 || a > M - 5)
			{
				temp = random(0, max(H / 4, 1)) * rate * rate;
			}
			else
			{
				temp = (random(minN, maxN + INC) - minN) * rate;
			}
			res[a][n] =  av + temp;
		}

		if(b != 0 && b != M - 1)
		{
			maxN = max(res[a][b], res[m][n], res[c][b], (3 * b >= 2 * d ? res[m][3 * b / 2 - d / 2] : 0));
			minN = min(res[a][b], res[m][n], res[c][b], (3 * b >= 2 * d ? res[m][3 * b / 2 - d / 2] : 0));
			av = avg(res[a][b], res[m][n], res[c][b], (3 * b >= 2 * d ? res[m][3 * b / 2 - d / 2] : 0));
			int temp = 0;
			if(b < 4 || b > M - 5)
			{
				temp = random(0, max(H / 4, 1)) * rate * rate;
			}
			else
			{
				temp = (random(minN, maxN + INC) - minN) * rate;
			}
			res[m][b] =  av + temp;
		}

		if(c != 0 && c != M - 1)
		{
			maxN = max(res[c][b], res[m][n], res[c][d], (a + 2 * (int)res.size() > 3 * c ? res[3 * c / 2 - a / 2][n] : 0));
			minN = min(res[c][b], res[m][n], res[c][d], (a + 2 * (int)res.size() > 3 * c ? res[3 * c / 2 - a / 2][n] : 0));
			av = avg(res[c][b], res[m][n], res[c][d], (a + 2 * (int)res.size() > 3 * c ? res[3 * c / 2 - a / 2][n] : 0));
			int temp = 0;
			if(c < 4 || c > M - 5)
			{
				temp = random(0, max(H / 4, 1)) * rate * rate;
			}
			else
			{
				temp = (random(minN, maxN + INC) - minN) * rate;
			}
			res[c][n] =  av + temp;
		}

		if(d != 0 && d != M - 1)
		{
			maxN = max(res[c][b], res[m][n], res[c][d], (b + 2 * (int)res.size() > 3 * d ? res[3 * d / 2 - b / 2][n] : 0));
			minN = min(res[c][b], res[m][n], res[c][d], (b + 2 * (int)res.size() > 3 * d ? res[3 * d / 2 - b / 2][n] : 0));
			av = avg(res[c][b], res[m][n], res[c][d], (b + 2 * (int)res.size() > 3 * d ? res[3 * d / 2 - b / 2][n] : 0));
			int temp = 0;
			if(d < 4 || d > M - 5)
			{
				temp = random(0, max(H / 4, 1)) * rate * rate;
			}
			else
			{
				temp = (random(minN, maxN + INC) - minN) * rate;
			}
			res[m][d] =  av + temp;
		}
		diamondsquare(res, rate * rate, M, H, a, b, m, n);
		diamondsquare(res, rate * rate, M, H, m, b, c, n);
		diamondsquare(res, rate * rate, M, H, a, n, m, d);
		diamondsquare(res, rate * rate, M, H, m, n, c, d);
	}
}
