#ifndef	__SMOKE_H__ 
#define	__SMOKE_H__

#include "CSCIx229.h"
#include "particle.h"
#include "color.h"

#ifdef __cplusplus
extern "C" {
#endif

void initsmokeparticles(int minx, int maxx, int miny, int maxy, int minz, int maxz, 
	int yspeedmin, int yspeedmax, int otherspeedmin, int otherspeedmax, 
	int scaleMin, int scaleMax, Color color, Particle *particles, int amount);

void drawsmoke(Particle * particles, int amount, double timespan);
//
// draw the cylinder. for example the stick holding the bubble.
//
#ifdef __cplusplus
}   
#endif  

#endif //__CYLINDER_H__
