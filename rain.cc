#include <cmath>
#include "color.h"
#include "rain.h"
#include "cover.h"
#include "sphere.h"
#include "cube.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



extern float rep;
extern float shinyvec[1];
extern unsigned int texture[20];
extern float rainspeed;

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

void Normalise(XYZ * p)
{
	double sr = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
	p->x = p->x / sr;
	p->y = p->y / sr;
	p->z = p->z / sr;
}


/*



   Create a triangular facet approximation to a sphere
   Return the number of facets created.
   The number of facets will be (4^iterations) * 8
*/
int CreateNSphere(FACET3 *f,int iterations)
{
   int i,it;
   double a;
   XYZ p[6] = {0,0,1,  0,0,-1,  -1,-1,0,  1,-1,0,  1,1,0, -1,1,0};
   XYZ pa,pb,pc;
   int nt = 0,ntold;

   /* Create the level 0 object */
   a = 1 / sqrt(2.0);
   for (i=0;i<6;i++) {
      p[i].x *= a;
      p[i].y *= a;
   }
   f[0].p1 = p[0]; f[0].p2 = p[3]; f[0].p3 = p[4];
   f[1].p1 = p[0]; f[1].p2 = p[4]; f[1].p3 = p[5];
   f[2].p1 = p[0]; f[2].p2 = p[5]; f[2].p3 = p[2];
   f[3].p1 = p[0]; f[3].p2 = p[2]; f[3].p3 = p[3];
   f[4].p1 = p[1]; f[4].p2 = p[4]; f[4].p3 = p[3];
   f[5].p1 = p[1]; f[5].p2 = p[5]; f[5].p3 = p[4];
   f[6].p1 = p[1]; f[6].p2 = p[2]; f[6].p3 = p[5];
   f[7].p1 = p[1]; f[7].p2 = p[3]; f[7].p3 = p[2];
   nt = 8;

   if (iterations < 1)
      return(nt);

   /* Bisect each edge and move to the surface of a unit sphere */
   for (it=0;it<iterations;it++) {
      ntold = nt;
      for (i=0;i<ntold;i++) {
         pa.x = (f[i].p1.x + f[i].p2.x) / 2;
         pa.y = (f[i].p1.y + f[i].p2.y) / 2;
         pa.z = (f[i].p1.z + f[i].p2.z) / 2;
         pb.x = (f[i].p2.x + f[i].p3.x) / 2;
         pb.y = (f[i].p2.y + f[i].p3.y) / 2;
         pb.z = (f[i].p2.z + f[i].p3.z) / 2;
         pc.x = (f[i].p3.x + f[i].p1.x) / 2;
         pc.y = (f[i].p3.y + f[i].p1.y) / 2;
         pc.z = (f[i].p3.z + f[i].p1.z) / 2;
         Normalise(&pa);
         Normalise(&pb);
         Normalise(&pc);
         f[nt].p1 = f[i].p1; f[nt].p2 = pa; f[nt].p3 = pc; nt++;
         f[nt].p1 = pa; f[nt].p2 = f[i].p2; f[nt].p3 = pb; nt++;
         f[nt].p1 = pb; f[nt].p2 = f[i].p3; f[nt].p3 = pc; nt++;
         f[i].p1 = pa;
         f[i].p2 = pb;
         f[i].p3 = pc;
      }
   }

   return(nt);
}

//
// 
//
void rainDrop(RainDropDesc &drop)
{
	glPushMatrix();
	glTranslated(drop.newx, drop.newy, drop.newz);
	glRotatef(drop.rotatex, 1, 0, 0);
	glRotatef(drop.rotatez, 0, 0, 1);
	glScaled(drop.scale, drop.scale, drop.scale);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glDepthMask(0);
	if(drop.shape)
	{
//		cover(0, 30, 0.3, Color(0.8, 0.9, 0.95, 0.8));
//		sphere(0, -0.3, 0, 0.173, 90, 180, Color(0.8, 0.9, 0.95, 0.8), false, -1, -1, 1); 
	}
	else
	{
	
	FACET3 facets[32];

	CreateNSphere(facets, 1);
		glColor4f(0.8, 0.9, 0.95, 0.8);

		for(int i = 0; i< 32; ++i)
		{
	        glBegin(GL_POLYGON);
            glVertex3f(facets[i].p1.x , facets[i].p1.y , facets[i].p1.z );
            glVertex3f(facets[i].p2.x , facets[i].p2.y , facets[i].p2.z );
            glVertex3f(facets[i].p3.x , facets[i].p3.y , facets[i].p3.z );
			glEnd();
		}
/*
		glColor4f(0.8, 0.9, 0.95, 0.8);

		glBegin(GL_LINES);


		glVertex3f(0, 0.4, 0);
		glVertex3f(0, 0, 0);	
		glEnd();
*/
	}
	glDisable(GL_BLEND);
	glDepthMask(1);
	glPopMatrix();
}

void initrain(int maxx, int maxy, int maxz, int scaleMin, int scaleMax, int rotatex, int rotatez, RainDropDesc *drops, int amount)
{
	for(int i = 0; i < amount; ++i)
	{
		if(rand() % 10 == 1)
		{
			drops[i].shape = 1;
		}
		int x = rand() % maxx * (rand() % 2 ? -1 : 1);
		int y = (rand() % maxy + 800); 
		int z = rand() % maxz * (rand() % 2 ? -1 : 1);
		int scale = rand() % scaleMax + scaleMin;
		drops[i].newx = drops[i].x = x;
		drops[i].newy = drops[i].y = y;
		drops[i].newz = drops[i].z = z;
		drops[i].scale = scale;
		drops[i].rotatex = rotatex;
		drops[i].rotatez = rotatez;
	}	
}

void drawrain(RainDropDesc * drops, int amount, float speed)
{
	double dist = speed * 60;	
	for(int i = 0; i < amount; ++i)
	{
		drops[i].newx += dist * Sin(15) * Cos(15); 
		drops[i].newy += -dist * Cos(15); 
		drops[i].newz += -dist * Sin(15) * Sin(15); 
		if(drops[i].newy < 0)
		{
			drops[i].newx = drops[i].x;	
			drops[i].newy = drops[i].y;	
			drops[i].newz = drops[i].z;	
		}
		rainDrop(drops[i]);
	}
	

}
