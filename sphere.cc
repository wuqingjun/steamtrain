#include "color.h"
#include "sphere.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//
// a function used to draw spheres: bubble and the bottom of the lamp.
//
void sphere(double x, 
	double y, 
	double z, 
	double r, 
	int startangle, 
	int endangle, 
	Color color, 
	bool isEmission, 
	int lightnum, 
	int ntex)
{
    double d = 1.0;
    glPushMatrix();
    
    glTranslated(x, y, z);
    glScaled(r, r, r);
    glColor3f(color.r, color.g, color.b);

    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    
    if(isEmission)
    {
    	glColor3f(1,1, 1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, white);
    	float bubbleposition[3] = {float(x), float(y), float(z)};
    	glLightfv(lightnum, GL_POSITION, bubbleposition);
    }
    else
    {
    	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
    }

    if(ntex >= 0)
    {
    	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, ntex);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     }
	else
	{	
    	glDisable(GL_TEXTURE_2D);
	}

    for(int j = startangle; j <= endangle; j += d)
    {
    	glBegin(GL_TRIANGLE_STRIP);
    	for(int i = 0; i <=360; i += d)
    	{
            	glNormal3f(Sin(j) * Sin(i), Cos(j), Sin(j) * Cos(i));
            if(ntex >= 0)
            {
                glTexCoord2f(rep * (float) i / 360, rep * (j - startangle) /(float) (endangle - startangle));
            }
	    glVertex3f(Sin(j) * Sin(i), Cos(j), Sin(j) * Cos(i));
            if(ntex >= 0)
            {
                glTexCoord2f(rep * (float) i / 360, rep * (j + d - startangle) /(float) (endangle - startangle));
            }
	    glVertex3f(Sin(j + d) * Sin(i), Cos(j +  d), Sin(j + d) * Cos(i));
    	}
    	glEnd();
    }

    if(ntex >= 0)
    {
    	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}
