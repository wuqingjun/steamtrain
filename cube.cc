#include "color.h"
#include "cube.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//
// draw a square
// 

extern float shinyvec[1];
extern float white[4];
extern float black[4];

void cube(double l, double w, double h, Color color)
{
   //  Save transformation
   glPushMatrix();
   glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS, shinyvec);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, black);

   //  Offset
   glScaled(l,w,h);
   //  Cube
   glBegin(GL_QUADS);
   //  Front
   glColor3f(color.r,color.g,color.b);
   glNormal3f(0, 0, 1); 
   glVertex3f(-1,-1, 1);
   glNormal3f(0, 0, 1); 
   glVertex3f(+1,-1, 1);
   glNormal3f(0, 0, 1); 
   glVertex3f(+1,+1, 1);
   glNormal3f(0, 0, 1); 
   glVertex3f(-1,+1, 1);
   //  Back
   glColor3f(color.r,color.g,color.b);
   glNormal3f(0, 0, -1); 
   glVertex3f(+1,-1,-1);
   glNormal3f(0, 0, -1); 
   glVertex3f(-1,-1,-1);
   glNormal3f(0, 0, -1); 
   glVertex3f(-1,+1,-1);
   glNormal3f(0, 0, -1); 
   glVertex3f(+1,+1,-1);
   //  Right
   glColor3f(color.r,color.g,color.b);
   glNormal3f(1, 0, 0); 
   glVertex3f(+1,-1,+1);
   glNormal3f(1, 0, 0); 
   glVertex3f(+1,-1,-1);
   glNormal3f(1, 0, 0); 
   glVertex3f(+1,+1,-1);
   glNormal3f(1, 0, 0); 
   glVertex3f(+1,+1,+1);
   //  Left
   glColor3f(color.r,color.g,color.b);
   glNormal3f(-1, 0, 0); 
   glVertex3f(-1,-1,-1);
   glNormal3f(-1, 0, 0); 
   glVertex3f(-1,-1,+1);
   glNormal3f(-1, 0, 0); 
   glVertex3f(-1,+1,+1);
   glNormal3f(-1, 0, 0); 
   glVertex3f(-1,+1,-1);
   //  Top
   glColor3f(color.r,color.g,color.b);
   glNormal3f(0, 1, 0); 
   glVertex3f(-1,+1,+1);
   glNormal3f(0, 1, 0); 
   glVertex3f(+1,+1,+1);
   glNormal3f(0, 1, 0); 
   glVertex3f(+1,+1,-1);
   glNormal3f(0, 1, 0); 
   glVertex3f(-1,+1,-1);
   //  Bottom
   glColor3f(color.r,color.g,color.b);
   glNormal3f(0, -1, 0); 
   glVertex3f(-1,-1,-1);
   glNormal3f(0, -1, 0); 
   glVertex3f(+1,-1,-1);
   glNormal3f(0, -1, 0); 
   glVertex3f(+1,-1,+1);
   glNormal3f(0, -1, 0); 
   glVertex3f(-1,-1,+1);
   //  End
   glEnd();
   //  Undo transofrmations
   glPopMatrix();
}
