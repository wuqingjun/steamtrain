#include "color.h"
#include "square.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//
// draw a square
// 

void square(double x, double y, double z, double l, double w, Color color)
{
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(l, 1, w);
    	glColor3f(1.0,1.0, 1.0);
	glBegin(GL_QUADS);		
	glVertex3f(1.0, 0, 1.0);
	glVertex3f(1.0, 0, -1.0);	
	glVertex3f(-1.0, 0, -1.0);	
	glVertex3f(-1.0, 0, 1.0);	
	glEnd();
	glPopMatrix();
}
