#include "color.h"
#include "CSCIx229.h"
#include "cover.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void cover(double r, double angle, double h, Color color)
{
    glPushMatrix();
    double d = 1.0;
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLE_STRIP);
    double R = r + h * Tan(angle);
    for(int i = 0; i <=360; i += d)
    {
		glVertex3f(R * Cos(i), -h, R * Sin(i));
		glVertex3f(r * Cos(i), 0, r * Sin(i));
    }
    glEnd();
    glPopMatrix();
}
