#include "color.h"
#include "CSCIx229.h"
#include "cube.h"
#include "cylinder.h"
#include "wheel.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


extern double angle;
extern int ntexWood;
extern int ntexMetal;

void ring(double r, double m, double h1, Color color)
{
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	double d = 1.0;
	glBegin(GL_TRIANGLE_STRIP);
	for(int i = 0; i <=360; i += d)
	{
		glVertex3f(r * Cos(i), 0, r * Sin(i)); 
		glVertex3f(m * Cos(i), 0, m * Sin(i)); 
	}
	glEnd();	
	glBegin(GL_TRIANGLE_STRIP);
	for(int i = 0; i <=360; i += d)
	{
		glVertex3f(r * Cos(i), h1, r * Sin(i)); 
		glVertex3f(m * Cos(i), h1, m * Sin(i)); 
	}
	glEnd();	
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <=360; i += d)
	{
		glVertex3f(r * Cos(i), 0, r * Sin(i)); 
		glVertex3f(r * Cos(i), h1, r * Sin(i)); 
	}
	glEnd();	
	glBegin(GL_QUAD_STRIP);
	for(int i = 0; i <=360; i += d)
	{
		glVertex3f(m * Cos(i), 0, m * Sin(i)); 
		glVertex3f(m * Cos(i), h1, m * Sin(i)); 
	}
	glEnd();	
	glPopMatrix();	
}


void wheel(double r, double m, double R, double h1, double h2,  Color color, int rotateDirection)
{
	glPushMatrix();
	glRotatef(angle * rotateDirection, 0.0, 1.0, 0.0);
	ring(r, m, h1, color);
	ring(m, R, h2, color);
	glPushMatrix();
	glTranslated(0, (h1 + h2) / 2, 0);
	cylinder(0.03, 1.18, color);
	for(int i = 0; i <= 360; i += 30)
	{
		cube(m, .01, .01, color, 0X3F, 1, ntexMetal);
		glRotated(30, 0, 1, 0);
	}	
	glPopMatrix();
	
	glTranslated(0, 0, 0.03);	
	Color c(1, 0,0, 1);
	cube(0.05, 0.03, 0.12, c, 0X3F, 1, ntexMetal);				
	glTranslated(0, -0.10, 0.085);
	cylinder(0.03, 0.02, color);
	
	glPopMatrix();
}

void twowheels(double r, double m, double R, double h1, double h2, double distance, Color color, int rotateDirection)
{
	glPushMatrix();
	wheel(r, m, R, h1, h2, color, rotateDirection);	
	glTranslated(distance, 0, 0);
	wheel(r, m, R, h1, h2, color, rotateDirection);	
	glTranslated(-distance, 0, 0);
	glTranslated(0.1 * Sin(angle) + distance / 2, -0.015,  0.1 * Cos(angle));
	cube(distance / 2 * 1.15, 0.03, 0.03, Color(1, 1, 1,1), 0X3F, 1, ntexMetal);
	glPopMatrix();
}

void threewheels(double r, double m, double R, double h1, double h2, double distance, Color color, int rotateDirection)
{
	glPushMatrix();
	wheel(r, m, R, h1, h2, color, rotateDirection);	
	glTranslated(distance, 0, 0);
	wheel(r, m, R, h1, h2, color, rotateDirection);	
	glTranslated(distance, 0, 0);
	wheel(r, m, R, h1, h2, color, rotateDirection);	
	glTranslated(-distance, 0, 0);
	glTranslated( 0.1 * Sin(rotateDirection * angle), -0.015,  0.1 * Cos(rotateDirection * angle));
	cube(distance * 1.15, 0.03, 0.03, Color(1, 1, 1,1), 0X3F, 1, ntexMetal);
	glPopMatrix();
}
