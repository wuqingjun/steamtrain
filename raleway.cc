#include "color.h"
#include "cube.h"
#include "raleway.h"
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
void raleway(double l, double w, double h, double space,  Color color)
{
	glPushMatrix();
	glScaled(1, w, h);	
	cube(l, 0.15, 0.1, color, 0X3F, 1);
	glTranslated(0, 0, 1.4);
	cube(l, 0.15, 0.1, color, 0X3F, 1);
	glTranslated(-l/2, -0.2, -0.7);
	for(double bl = 0.0; bl <= l; bl += 0.4)
	{
		cube(0.4, 0.2, 1.2, Color(1, 0, 0, 1), 0X3F, 1);		
		glTranslated(1, 0, 0);
	}	
	glPopMatrix();	
}
