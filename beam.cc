#include "color.h"
#include "CSCIx229.h"
#include "beam.h"
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
void beam(float x, float y, float z, float angle, float dirx, float diry, float dirz, int lightnum)
{
	glEnable(GL_LIGHTING);
	glEnable(lightnum);
	float Ambient[]   = {1.0, 1.0, 0.2, 1.0};
    float Diffuse[]   = {0.8, 0.8, 0.8, 1.0}; 
    float Specular[]  = {0.4, 0.8, 0.8, 1.0}; 
    glLightfv(lightnum, GL_AMBIENT,  Ambient);
    glLightfv(lightnum, GL_DIFFUSE,  Diffuse);
    glLightfv(lightnum, GL_SPECULAR, Specular);
    glLightf(lightnum, GL_SPOT_EXPONENT, 20);
    glLightf(lightnum, GL_SPOT_CUTOFF, 60);
    glLightf(lightnum, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(lightnum, GL_LINEAR_ATTENUATION, 0);
    glLightf(lightnum, GL_QUADRATIC_ATTENUATION, 0);
	float pos[4] = {x, y, z, 1};
    glLightfv(lightnum, GL_POSITION, pos);
	glPushMatrix();
	glTranslated(x, y, z);
	float spotDir[4] = {dirx, diry, dirz, 1};
    glLightfv(lightnum, GL_SPOT_DIRECTION, spotDir);
	glPopMatrix();
}
