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
extern float white[4];

//
// draw circular surface.
//
void sun(double x, double y, double z, double r, Color color, int lightnum)
{
	glPushMatrix();
	sphere(x, y, z, r, 0, 180, color, true, lightnum, -1);
	float Ambient[]   = {float(0.01) * ambient , float(0.01) * ambient , float(0.01) *ambient ,1.0};
    float Diffuse[]   = {float(0.01) * diffuse , float(0.01) * diffuse , float(0.01) *diffuse ,1.0};
    float Specular[]  = {float(0.01) * specular, float(0.01) * specular, float(0.01) *specular,1.0};
    glLightfv(lightnum, GL_AMBIENT,  Ambient);
    glLightfv(lightnum, GL_DIFFUSE,  Diffuse);
    glLightfv(lightnum, GL_SPECULAR, Specular);
    glEnable(lightnum);
	glPopMatrix();
}
