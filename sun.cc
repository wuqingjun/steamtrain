#include "color.h"
#include "CSCIx229.h"
#include "sphere.h"
#include "sun.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

extern int ambient;
extern int diffuse;
extern int specular;
extern int angel;
extern float white[4];
extern int expo;
extern int cons;
extern int linear;
extern int quad;

//
// draw circular surface.
//
void sun(double x, double y, double z, double r, Color color, int lightnum)
{
	glEnable(GL_LIGHTING);
	float Ambient[]   = {0.2, 0.2, 0.2, 1.0};
    float Diffuse[]   = {0.2, 0.2, 0.2, 1.0}; 
    float Specular[]  = {0.4, 0.4, 0.4, 1.0}; 
    glLightfv(lightnum, GL_AMBIENT,  Ambient);
    glLightfv(lightnum, GL_DIFFUSE,  Diffuse);
    glLightfv(lightnum, GL_SPECULAR, Specular);
	float bubbleposition[4] = {float(x), float(y), float(z), 1};
    glLightfv(lightnum, GL_POSITION, bubbleposition);
	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, white);
	glEnable(lightnum);

	glPushMatrix();
	sphere(x, y, z, r, 0, 180, color, true, lightnum, -1);
	glPopMatrix();
}
