#include "color.h"
#include "diamondsquare.h"
#include "mountain.h" 
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

extern float repl;
extern float shinyvec[1];
extern float shinyvec[1];
extern float white[4];
extern float black[4];
extern int ntexGrass;
extern int ntexRock;
extern int ntexMountain;
extern int ntexDesert;
const double PI = 3.1415926;

//
// 
//

vector<float> normal(vector<vector<float> > &originPoints, int idx)
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

void mountain(vector<vector<float> > &heightmap, double x, double y, double z, double l, double w, double h)
{
	float repl = 1.2;
	int M = heightmap.size();
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, black);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ntexDesert);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTranslated(x, y, z);
	glScaled(l, h, w);
	glColor3f(0.9, 0.3, 0.3);
	for(int i = 0; i < M - 1; ++i)
	{
		vector<vector<float> > points(3, vector<float>(3, 0));
		int idx = 0;
		for(int j = 0; j < M ; ++j)
		{
			for(int n = 0; n < 2; ++n)
			{
				points[idx % 3][0] = 1.0 * (i + n) / M;
				points[idx % 3][1] = heightmap[(i +n)][j] / M;
				points[idx % 3][2] = 1.0 * j / M;	
				vector<float> norm = normal(points, idx % 3);
				++idx;
				glBegin(GL_TRIANGLES);
				for(int p = 0;idx > 1 && p < 3; ++p)
				{
					glNormal3f(norm[0], norm[1], norm[2]);
					glTexCoord2f( repl * points[p][0],  repl * points[p][2] );
					glVertex3f(points[p][0], points[p][1], points[p][2]); 
				}
				glEnd();
			}
		}
	}
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
