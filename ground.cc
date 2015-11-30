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
extern unsigned int texture[20];

//
// draw the cylinder. for example the stick holding the bubble.
//
void ground(double x, double y, double z, double l, double w, Color color)
{
    glPushMatrix();
	glTranslated(x, y, z);
	glScaled(l, 1, w);
	glColor3f(color.r, color.g, color.b);	
    glBegin(GL_POLYGON);
	glVertex3f(-1, 0, 1);	
	glVertex3f(1, 0, 1);	
	glVertex3f(1, 0, -1);	
	glVertex3f(-1, 0, -1);	
    glEnd();
    glPopMatrix();
}
