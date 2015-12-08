#ifndef __PARTICLE_H__ 
#define	__PARTICLE_H__ 

#include "CSCIx229.h"
#include "color.h"

struct XYZ
{
	double x;
	double y;
	double z;
};

struct FACET3
{
	XYZ p1;
	XYZ p2;
	XYZ p3;
};

struct Particle
{
	double x;
	double y;
	double z;
	double scale;
	double xspeed;
	double xacc;
	double yspeed;
	double yacc;
	double zspeed;
	double zacc;
	double rotatex;
	double rotatez;
	Color color;
};


#ifdef __cplusplus
extern "C" {
#endif

void drawparticle(Particle *p);
//
// draw the cylinder. for example the stick holding the bubble.
//
#ifdef __cplusplus
}   
#endif  

#endif //__CYLINDER_H__
