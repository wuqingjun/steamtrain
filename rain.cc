#include <cmath>
#include "color.h"
#include "rain.h"
#include "cover.h"
#include "sphere.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



extern float rep;
extern float shinyvec[1];
extern unsigned int texture[20];
extern float rainspeed;

//
// 
//
void rainDrop(RainDropDesc &drop)
{
	glPushMatrix();
	glTranslated(drop.newx, drop.newy, drop.newz);
	glRotatef(drop.rotatex, 1, 0, 0);
	glRotatef(drop.rotatez, 0, 0, 1);
	glScaled(drop.scale, drop.scale, drop.scale);
	cover(0, 30, 0.3, Color(0.8, 0.9, 0.95, 1));
	sphere(0, -0.3, 0, 0.173, 90, 180, Color(0.8, 0.9, 0.95, 1), false, -1, -1, 1); 
	glPopMatrix();
}

void initrain(int maxx, int maxy, int maxz, int scaleMin, int scaleMax, int rotatex, int rotatez, RainDropDesc *drops, int amount)
{
	for(int i = 0; i < amount; ++i)
	{
		int x = rand() % maxx * (rand() % 2 ? -1 : 1);
		int y = (rand() % maxy + 800) * (rand() % 2 ? -1 : 1);
		int z = rand() % maxz * (rand() % 2 ? -1 : 1);
		int scale = rand() % scaleMax + scaleMin;
		drops[i].newx = drops[i].x = x;
		drops[i].newy = drops[i].y = y;
		drops[i].newz = drops[i].z = z;
		drops[i].scale = scale;
		drops[i].rotatex = rotatex;
		drops[i].rotatez = rotatez;
	}	
}

void drawrain(RainDropDesc * drops, int amount, float speed)
{
	double dist = speed * 60;	
	for(int i = 0; i < amount; ++i)
	{
		drops[i].newx += dist * Sin(15) * Cos(15); 
		drops[i].newy += -dist * Cos(15); 
		drops[i].newz += -dist * Sin(15) * Sin(15); 
		if(drops[i].newy < 0)
		{
			drops[i].newx = drops[i].x;	
			drops[i].newy = drops[i].y;	
			drops[i].newz = drops[i].z;	
		}
		if(drops[i].newy < 800)
		{
			rainDrop(drops[i]);
		}
	}
}
