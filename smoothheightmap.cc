#include "color.h"
#include "CSCIx229.h"
#include "smoothheightmap.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//
// draw circular surface.
//
void smoothheightmap(vector<vector<float> > & heightmap, float k, int ntimes)
{
	int M = heightmap.size();
	for(int n = 0; n < ntimes; ++n)
	{
	for(int i = 1; i < M - 1; ++i)
	{
		for(int j = 1; j < M - 1; ++j)
		{
			heightmap[i][j] = heightmap[i][j] * k + heightmap[i][j - 1] * (1 - k);
		}
	}	
	for(int i = 1; i < M - 1; ++i)
	{
		for(int j = 1; j < M - 1; ++j)
		{
			heightmap[j][i] = heightmap[j][i] * k + heightmap[j - 1][i] * (1 - k);
		}
	}
	}	
}
