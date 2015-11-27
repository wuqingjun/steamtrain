#include "color.h"
#include "pie.h"
#include "cylinder.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


extern float rep;
extern float shinyvec[1];
extern unsigned int texture[20];
extern float white[4];
extern float black[4];

//
// draw the cylinder. for example the stick holding the bubble.
//
void cylinder(double r, double h, Color color)
{
    glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,white);
    double d = 1.0;
    glScaled(r, h, r); 
    pie(1, color);
	glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUAD_STRIP);
    for(int i = 0;i <= 360; i += d)
    {
		glNormal3f(Cos(i), 0, Sin(i));
        glVertex3f(Cos(i), 0, Sin(i));
		glNormal3f(Cos(i), 0, Sin(i));
        glVertex3f(Cos(i), 1, Sin(i));
    }
    glEnd();
    glTranslated(0, 1, 0);
    pie(1, color);
    glPopMatrix();
}
