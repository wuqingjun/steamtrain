#include "color.h"
#include "cube.h"
#include "pile.h"
#include "tube.h"
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
void tube(double l, double w,  double h, int degree, Color color)
{
    glPushMatrix();
    double d = 1.0;
    glScaled(l, w, h); 
    glColor3f(color.r, color.g, color.b);
    glEnd();
    glPopMatrix();
}
