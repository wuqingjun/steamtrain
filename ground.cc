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
extern float rep;

//
// draw the cylinder. for example the stick holding the bubble.
//
void ground(double x, double y, double z, double l, double w, Color color)
{
    glPushMatrix();
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ntexGrass);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTranslated(x, y, z);
	glScaled(l, 1, w);
	glColor3f(color.r, color.g, color.b);	
    glBegin(GL_QUADS);
	glTexCoord2f(0 * rep, 0 * rep);
	glVertex3f(-1, 0, 1);	
	glTexCoord2f(0 * rep, 1 * rep);
	glVertex3f(1, 0, 1);	
	glTexCoord2f(1 * rep, 1 * rep);
	glVertex3f(1, 0, -1);	
	glTexCoord2f(1 * rep, 0 * rep);
	glVertex3f(-1, 0, -1);	
    glEnd();
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
