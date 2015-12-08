#include <cmath>
#include <vector>
#include "color.h"
#include "smoke.h"
#include "particle.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void initsmokeparticles(int minx, int maxx, int miny, int maxy, int minz, int maxz, 
	int yspeedmin, int yspeedmax, int otherspeedmin, int otherspeedmax, 
	int scaleMin, int scaleMax, Color color, Particle *particles, int amount)
{
	for(int i = 0; i < amount; ++i)
	{
		Particle &p = particles[i];
		p.x = (maxx != 0 ? rand() % maxx : 0) + minx;			
		p.y = (maxy != 0 ? rand() % maxy : 0) + miny;			
		p.z = (maxz != 0 ? rand() % maxz : 0) + minz;			
		
		p.scale = rand() % scaleMax + scaleMin;

		p.xspeed = ((otherspeedmax != 0 ? rand() % otherspeedmax : 0) + otherspeedmin) * (rand() % 2 ? 1: -1);
		p.yspeed = (yspeedmax != 0 ? rand() % yspeedmax : 0) + yspeedmin; 
		p.zspeed =( (otherspeedmax != 0 ? rand() % otherspeedmax : 0) + otherspeedmin) * (rand() % 2 ? 1 : -1);
		p.color = color;
	}	
}

void drawsmoke(Particle * particles, int amount, double timespan)
{
	glPushMatrix();
	
	for(int i = 0; i < amount; ++i)
	{
		Particle &p = particles[i];
		drawparticle(&p);

		p.x += p.xspeed * timespan;
		p.y += p.yspeed * timespan;
		p.z += p.zspeed * timespan;

		p.xspeed += (p.xacc + rand() % 3 * (rand() % 2 == 1 ? 1 : -1)) * timespan;
		p.yspeed += p.yacc * timespan;
		p.zspeed += (p.zacc + rand() % 3 * (rand() % 2 == 1 ? 1 : -1)) * timespan;
	}
	glPopMatrix();
}
