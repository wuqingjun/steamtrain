#include "color.h"
#include "diamondsquare.h"
#include "tunnel.h" 
#include "smoothheightmap.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


extern float rep;
extern float shinyvec[1];
extern unsigned int texture[20];
extern vector<vector<float> > heightmap;

const double PI = 3.1415926;

//
// 
//

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

const float tunnelHeight = 0.28;

void tunnel(double x, double y, double z, double ml, double mw, double mh, double tl, double th)
{
	int M = heightmap.size();
	int H = pow(2, 6);
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(ml, mw, mh);

	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if( i >= M / 4 && i <= M / 2 && heightmap[i][j] / H < tunnelHeight)
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
				if(i < M/ 4 || i > M / 2 || (points[0][1] >= tunnelHeight  && points[1][1] >= tunnelHeight  && points[2][1] >= tunnelHeight))
				{
				glBegin(GL_TRIANGLES);
				for(int p = 0;idx > 1 && p < 3; ++p)
				{
					glNormal3f(norm[0], norm[1], norm[2]);
					glVertex3f(points[p][0], points[p][1], points[p][2]); 
				}
				glEnd();
				}
			}
		}
	}
	glPopMatrix();
}
