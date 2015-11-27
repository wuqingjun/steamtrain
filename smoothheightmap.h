#ifndef __SMOOTH_HEIGHT_MAP__	
#define	__SMOOTH_HEIGHT_MAP__	
#include <vector>
using namespace std; 
//
// draw a square
// 
#ifdef __cplusplus
extern "C" {
#endif

void smoothheightmap(vector<vector<float> > & heightmap, float k, int ntimes);

#ifdef __cplusplus
}
#endif

#endif // __PILE_H__
