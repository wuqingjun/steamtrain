#include "color.h"
#include "CSCIx229.h"
#include "pie.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

extern float shinyvec[1];
extern float white[4];
extern float black[4];

//
// draw circular surface.
//
void pie(double r, Color color)
{
    double d = 1.0;
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,white);

    glScaled(r, 1, r);
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);

   for(int i = 0;i <= 360; i += d)
   {
		glNormal3f(0, -1, 0);
		glVertex3f(Cos(i), 0, Sin(i));
   }

    glEnd();
    glPopMatrix();
}

