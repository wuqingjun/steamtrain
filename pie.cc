#include "color.h"
#include "CSCIx229.h"
#include "pie.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//
// draw circular surface.
//
void pie(double r, Color color)
{
    double d = 1.0;
    glPushMatrix();

    glScaled(r, 1, r);
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);

   for(int i = 0;i <= 360; i += d)
   {
		glVertex3f(Cos(i), 0, Sin(i));
   }

    glEnd();
    glPopMatrix();
}

