#ifndef	__GROUND_H__	
#define __GROUND_H__

#include "CSCIx229.h"
#include "color.h"


#ifdef __cplusplus
extern "C" {
#endif

//
// draw the cylinder. for example the stick holding the bubble.
//
void ground(double x, double y, double z, double l, double w, Color color);

#ifdef __cplusplus
}   
#endif  

#endif //__CYLINDER_H__
