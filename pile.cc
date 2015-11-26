#include "color.h"
#include "pile.h"
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
void pile(double r, double h, int degree, Color color)
{
    glPushMatrix();
    double d = 1.0;
    glScaled(r, h, r); 
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUAD_STRIP);
    for(int i = 0;i <= degree; i += d)
    {
        glVertex3f(Cos(i), 0, Sin(i));
        glVertex3f(Cos(i), 1, Sin(i));
    }
    glEnd();
    glPopMatrix();
}
