#ifndef __RAIN_H__	
#define	__RAIN_H__ 

#include "CSCIx229.h"
#include "color.h"

struct RainDropDesc
{
	float x;
	float y;
	float z;
	float newx;
	float newy;
	float newz;
	int scale;
	int rotatex;
	int rotatez;
};

#ifdef __cplusplus
extern "C" {
#endif

//
// draw the cylinder. for example the stick holding the bubble.
//
void rainDrop(RainDropDesc &drop);

void initrain(int maxx, int maxy, int maxz, int scaleMin, int scaleMax, int rotatex, int rotatez, RainDropDesc *drops, int amount);

void drawrain(RainDropDesc * drops, int amount, float speed);
#ifdef __cplusplus
}   
#endif  

#endif //__CYLINDER_H__
