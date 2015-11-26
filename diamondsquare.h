#ifndef	__DIAMONDSQUARE_H__
#define __DIAMONDSQUARE_H__

#include <vector>
#include "CSCIx229.h"
#include "color.h"
using namespace std;


#ifdef __cplusplus
extern "C" {
#endif

//
// draw the cylinder. for example the stick holding the bubble.
//
void diamondsquare(vector<vector<float> > &res, float rate, int M, int a, int b, int c, int d);

#ifdef __cplusplus
}   
#endif  

#endif //__CYLINDER_H__
