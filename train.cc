#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "cylinder.h"
#include "color.h"
#include "train.h"
#include "cube.h"
#include "pie.h"
#include "cover.h"
#include "wheel.h"
#include "pile.h"

double angle = 0;

//
// draw the cylinder. 
//
void train(double x, double y, double z, double scaleX, double scaleY, double scaleZ)
{
    int iTimeElapsed = glutGet(GLUT_ELAPSED_TIME);
    float fRevolveScale2 = 0.1f;
    angle = iTimeElapsed * fRevolveScale2;

    Color black(0, 0, 0, 1);
    glPushMatrix();
    glTranslated(x, y, z);
	glScaled(scaleX, scaleY, scaleZ);

	glTranslated(-0.2 * angle / 360, 0, 0);	

	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	cylinder(0.3333, 1.2, black);

	glTranslated(0, -0.1, 0);		
	pie(0.3333 - 0.1 * Tan(60), Color(1,1,1,1));
	glRotated(180, 0, 0, 1);
	cover(0.3333 - 0.1 * Tan(60), 60, 0.1, black);
	glRotated(180, 0, 0, 1);
	glTranslated(0, 0.1, 0);
	glRotated(180, 0, 0, 1);
	glTranslated(0, -1.2, 0);
	cover(0.3333, 60, 0.1, black);
	glTranslated(0, -0.4, 0);
	cylinder(0.3333 + Tan(60) * 0.1, 0.3, black);
	glTranslated(0.1, -0.3, 0);
	cube(0.3333 + Tan(60) * 0.2, 0.6, 0.3333 + Tan(60) * 0.1, black);
	glTranslated(0.37, -0.6, 0);
	glRotated(60, 0,1, 0);
	pile(0.6, 1.2, 120, Color(1,0,0,1));

	glPopMatrix();	

	glPushMatrix();
	glTranslated(0.2333, 0.3, 0);	
	cylinder(0.1333, 0.2, black);	
	glTranslated(0, 0.15, 0);	
	glRotated(180, 0, 0, 1);
	cover(0.1333, 30, 0.44, black);
	glRotated(180, 0, 0, 1);
	glTranslated(0, 0.44, 0);
	cylinder(0.1333 + 0.44 * Tan(30), 0.1, black);
	glTranslated(0, 0.15, 0);
	cover(0.1333 + 0.44 * Tan(30) - 0.05 * Tan(60), 60, 0.05, black);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4, -0.3, 0);
	cube(0.4, 0.1, 0.2, black);
	glPopMatrix();
	
	glPushMatrix();
	glRotated(-90, 0, 0, 1);
	glTranslated(0, 0, 0);
	pie(0.3333, black);
	glTranslated(0, 0.6667, 0);
	pie(0.3333, Color(0, 0, 0, 1));
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.6, -0.4, 0);
	cube(0.65, 0.1, 0.6, black);
	glRotated(90, 1, 0, 0);

	glTranslated(-0.2, -0.6, 0.1); 
	threewheels(0.20, 0.25, 0.35, 0.1, 0.05, 0.8, black, 1); 		
	glRotated(180, 1, 0, 0);
	glTranslated(0, -1.2, 0); 
	threewheels(0.20, 0.25, 0.35, 0.1, 0.05, 0.8, black, -1); 		

    glPopMatrix();
    glPopMatrix();
}
