#ifndef	__TUBE_H__	
#define	__TUBE_H__ 

#include "CSCIx229.h"
#include "color.h"


#ifdef __cplusplus
extern "C" {
#endif

//
// draw the cylinder. for example the stick holding the bubble.
//
void pile(double r, double h, int degree, Color color);

#ifdef __cplusplus
}   
#endif  

#endif //__TUBE_H__
