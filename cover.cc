#include "color.h"
#include "CSCIx229.h"
#include "cover.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

extern float shinyvec[1];
extern float white[4];
extern float black[4];

void cover(double r, double angle, double h, Color color)
{
    glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,white);

    double d = 1.0;
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLE_STRIP);
    double R = r + h * Tan(angle);
    for(int i = 0; i <=360; i += d)
    {
		glNormal3f(Cos(angle) * Cos(i), Sin(angle), Cos(angle) * Sin(i));
		glVertex3f(R * Cos(i), -h, R * Sin(i));
		glNormal3f(Cos(angle) * Cos(i), Sin(angle), Cos(angle) * Sin(i));
		glVertex3f(r * Cos(i), 0, r * Sin(i));
    }
    glEnd();
    glPopMatrix();
}
