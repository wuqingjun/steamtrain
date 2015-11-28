#ifndef __TUNNEL_H__	
#define __TUNNEL_H__

#include <vector>
#include "CSCIx229.h"
#include "color.h"


#ifdef __cplusplus
extern "C" {
#endif

//
// draw the cylinder. for example the stick holding the bubble.
//
void tunnel(double x, double y, double z, double ml, double mw, double mh, double tl, double th);

#ifdef __cplusplus
}   
#endif  

#endif //__CYLINDER_H__
