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

void cube(double l, double w, double h, Color color, int faces = 0X3F, int normalDirection = 1)
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
   glColor3f(color.r,color.g,color.b);
   
   //  Front
	if(faces & 0X01)
	{
		glNormal3f(0, 0, normalDirection); 
		glVertex3f(-1,-1, 1);
		glNormal3f(0, 0, normalDirection); 
		glVertex3f(+1,-1, 1);
		glNormal3f(0, 0, normalDirection); 
		glVertex3f(+1,+1, 1);
		glNormal3f(0, 0, normalDirection); 
		glVertex3f(-1,+1, 1);
	}
   //  Back
	if(faces & 0X02)
	{
		glNormal3f(0, 0, -normalDirection); 
		glVertex3f(+1,-1,-1);
		glNormal3f(0, 0, -normalDirection); 
		glVertex3f(-1,-1,-1);
		glNormal3f(0, 0, -normalDirection); 
		glVertex3f(-1,+1,-1);
		glNormal3f(0, 0, -normalDirection); 
		glVertex3f(+1,+1,-1);
	}
   //  Left
	if(faces & 0X04)
	{
		glNormal3f(-normalDirection, 0, 0); 
		glVertex3f(-1,-1,-1);
		glNormal3f(-normalDirection, 0, 0); 
		glVertex3f(-1,-1,+1);
		glNormal3f(-normalDirection, 0, 0); 
		glVertex3f(-1,+1,+1);
		glNormal3f(-normalDirection, 0, 0); 
		glVertex3f(-1,+1,-1);
	}
   //  Top
	if(faces & 0X08)
	{
		glNormal3f(0, normalDirection, 0); 
		glVertex3f(-1,+1,+1);
		glNormal3f(0, normalDirection, 0); 
		glVertex3f(+1,+1,+1);
		glNormal3f(0, normalDirection, 0); 
		glVertex3f(+1,+1,-1);
		glNormal3f(0, normalDirection, 0); 
		glVertex3f(-1,+1,-1);
	}
   //  Right
	if(faces & 0X10)
	{
		glNormal3f(normalDirection, 0, 0); 
		glVertex3f(+1,-1,+1);
		glNormal3f(normalDirection, 0, 0); 
		glVertex3f(+1,-1,-1);
		glNormal3f(normalDirection, 0, 0); 
		glVertex3f(+1,+1,-1);
		glNormal3f(normalDirection, 0, 0); 
		glVertex3f(+1,+1,+1);
	}
   //  Bottom
	if(faces & 0X20)
	{
		glNormal3f(0, -normalDirection, 0); 
		glVertex3f(-1,-1,-1);
		glNormal3f(0, -normalDirection, 0); 
		glVertex3f(+1,-1,-1);
		glNormal3f(0, -normalDirection, 0); 
		glVertex3f(+1,-1,+1);
		glNormal3f(0, -normalDirection, 0); 
		glVertex3f(-1,-1,+1);
	}
   //  End
   glEnd();
   //  Undo transofrmations
   glPopMatrix();
}
