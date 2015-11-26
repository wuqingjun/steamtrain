#include "color.h"
#include "diamondsquare.h"
#include "terrain.h" 
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

void terrain(double l, double w, double h)
{
	int M = heightmap.size();
	glPushMatrix();
	glScaled(l, w, h);
	glColor3f(0.3, 0.4, 0.5);
	for(int i = 0; i < M - 1; ++i)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for(int j = 0; j < M ; ++j)
		{
			glVertex3f(1.0 * i / M, heightmap[i][j] / M, 1.0 * j / M); 		
			glVertex3f(1.0 * (i + 1) / M, heightmap[i + 1][j] / M, 1.0 * j / M); 		
		}
		glEnd();
	}
	glPopMatrix();
}
