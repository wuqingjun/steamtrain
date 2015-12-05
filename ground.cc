#include "color.h"
#include "ground.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


extern float rep;
extern float shinyvec[1];
extern int ntexGrass;
extern int ntexMountain;
extern int ntexRock;
extern int ntexDesert;
extern float white[4];
extern float black[4];

//
// draw the cylinder. for example the stick holding the bubble.
//
void ground(double x, double y, double z, double l, double w, Color color)
{
    glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS, shinyvec);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, white);
	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, black);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ntexDesert);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTranslated(x, y, z);
	glScaled(l, 1, w);
	glTranslated(-0.5, 0, -0.5);
	glNormal3f(0, 1, 0);

	int numIter = 50;
	double step = 1.0 / numIter;
	
	for(int j = 0; j < numIter; ++j)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for(int i = 0; i < numIter; ++i)
		{
			glColor3f(color.r, color.g, color.b);	
			glVertex3f(i * step, 0, (j + 1) * step);
			glColor3f(color.r, color.g, color.b);	
			glVertex3f(i * step, 0, (j) * step);
		}
		glEnd();
	}  
    glPopMatrix();
	
/*
//	glTexCoord2f(0 * repl, 0 * repl);
	glVertex3f(-1, 0, 1);	
	glNormal3f(0, 1, 0);
//	glTexCoord2f(0 * repl, 1 * repl);
	glVertex3f(1, 0, 1);	
	glNormal3f(0, 1, 0);
//	glTexCoord2f(1 * repl, 1 * repl);
	glVertex3f(1, 0, -1);	
	glNormal3f(0, 1, 0);
//	glTexCoord2f(1 * repl, 0 * repl);
	glVertex3f(-1, 0, -1);	
    glEnd();
//	glDisable(GL_TEXTURE_2D);
*/
}
