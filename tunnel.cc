#include <algorithm>
#include "color.h"
#include "diamondsquare.h"
#include "tunnel.h" 
#include "smoothheightmap.h"
#include "cube.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

extern float rep;
extern float shinyvec[1];
extern unsigned int texture[20];
extern vector<vector<float> > heightmap;
extern float shinyvec[1];
extern float white[4];
extern float black[4];

const double PI = 3.1415926;

//
// 
//

float maxof3(float a, float b, float c)
{
	return max(max(a, b), c);
}

float minof3(float a, float b, float c)
{
	return min(min(a, b), c);
}

float dist(float a, float b, float c)
{
	return maxof3(a, b, c) - minof3(a, b, c);
}

vector<float> normal3points(vector<vector<float> > &originPoints, int idx)
{
	vector<vector<float> > points;
	for(int i = 0; i < 3; ++i)
	{
		points.push_back(originPoints[(idx + i) % 3]);	
	}	
	
	vector<float> res(3, 0);
	float x = (points[1][1] - points[0][1]) * (points[2][2] - points[0][2]) - (points[2][1] - points[0][1]) * (points[1][2] - points[0][2]);  
	float y = (points[1][2] - points[0][2]) * (points[2][0] - points[0][0]) - (points[2][2] - points[0][2]) * (points[1][0] - points[0][0]);  
	float z = (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) - (points[2][0] - points[0][0]) * (points[1][1] - points[0][1]);  
	if(y < 0)
	{
		x = -x, y = -y; z = -z;
	}
	res[0] = x / sqrt(x * x + y * y + z * z);	
	res[1] = y / sqrt(x * x + y * y + z * z);	
	res[2] = z / sqrt(x * x + y * y + z * z);	
	return res;
}

const float tunnelHeight = 0.24;

void tunnel(double x, double y, double z, double ml, double mw, double mh, double tl, double th)
{
	int M = heightmap.size();
	int H = pow(2, 6);
	glPushMatrix();
	glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS, shinyvec);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, white);
	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, black);
	glTranslated(x, y, z);
	glScaled(ml, mw, mh);

	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if( i >= 0.4 * M && i <= 0.6 * M && heightmap[i][j] / H < tunnelHeight)
			{
				heightmap[i][j] = tunnelHeight * H;
			}	
		}
	}

	glColor3f(0, 0.8, 0);
	for(int i = 0; i < M - 1; ++i)
	{
		vector<vector<float> > points(3, vector<float>(3, 0));
		int idx = 0;
		for(int j = 0; j < M ; ++j)
		{
			for(int n = 0; n < 2; ++n)
			{
				points[idx % 3][0] = 1.0 * (i + n) / H;
				points[idx % 3][1] = heightmap[(i +n)][j] / H;
				points[idx % 3][2] = 1.0 * j / H;	
				++idx;
				vector<float> norm = normal3points(points, idx % 3);
				if(i >= 0.4 * M && i <= 0.6 * M)  
				{
					points[0][1] = max(points[0][1], tunnelHeight);	
					points[1][1] = max(points[1][1], tunnelHeight);	
					points[2][1] = max(points[2][1], tunnelHeight);	
				}
				
				glBegin(GL_TRIANGLES);
				for(int p = 0;idx > 1 && p < 3 && dist(points[0][0], points[1][0], points[2][0]) * H < 0.25 * M; ++p)
				{
					glNormal3f(norm[0], norm[1], norm[2]);
					glVertex3f(points[p][0], points[p][1], points[p][2]); 
				}
				glEnd();
			}
		}
	}

	glPushMatrix();
	glTranslated(0.5 * M / H, tunnelHeight / 2,  0.5 * M / H); 
	cube(0.099 * M / H, 0.5 * tunnelHeight, 0.5 * M / H, Color(0, 0.8,0, 1), 0X3C, 1); 
	cube(0.097 * M / H, 0.498 * tunnelHeight, 0.498 * M / H, Color(1, 0,0, 1), 0X3C, -1); 
	glPopMatrix();

	glPopMatrix();
}
