//
//  hw6.cc
//  texture and lighting 
//
//  Created by Qingjun Wu on 10/23/2015.
//  Copyright © 2015 wade wu. All rights reserved.
//

#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "CSCIx229.h"
#include <string>
#include "color.h"
#include "train.h"
#include "raleway.h"
#include "diamondsquare.h"
#include "smoothheightmap.h"
#include "mountain.h"
#include "tunnel.h"
#include "sun.h"
#include "ground.h"

using namespace std;
double axeslen = 95;
double asp = 1.0;
#define PI 3.14159265

double atx = 0, aty = 0, atz = 0;
double fov = 120.0;
int ph = -30;
int th = -30;
int dim = 1000;
double windowsize = 650;
int mode = 0;
int smooth = 0;
int ambient = 30;
int diffuse   = 100;  
int specular  =   0;  
int shininess =   0;  
float shinyvec[1] = { 0.0};
int local = 1;
float rep = 1.0;
float lh = 30;
int animation = 1;
int ntexWood = -1;
int ntexGrass = -1;
int ntexMetal = -1;
int ntexBricks = -1;
int ntexRock = -1;
int ntexMountain = -1;
int ntexDesert = 1;
bool axes = true;
float h2 = 0;
const int H = 6;
const int M = pow(2, H) + 1;
vector<vector<float> > heightmap(pow(2, 6) + 1, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap2(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap3(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap4(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap5(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap6(M, vector<float>(M, 0.0));
float white[] = {1, 1, 1, 1};
float black[] = {0, 0, 0, 1};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
	glShadeModel(smooth ? GL_SMOOTH : GL_FLAT); 
	glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);

    if(mode)
    {
		double ex = atx - 2 * dim * Sin(th) * Cos(ph);
		double ey = aty + 2 * dim        * Sin(ph);
		double ez = atz + 2 * dim * Cos(th) * Cos(ph);
    	gluLookAt(ex, ey, ez, atx, aty, atz, 0, 1, 0);
    }
    else
    {
    	glRotatef(ph,1,0,0);
    	glRotatef(th,0,1,0);
    }    

	sun(300, 100, 200, 50, Color(1, 1, 1, 1), GL_LIGHT0);
	train(0, 0, 0, 100, 100, 100);
	glPushMatrix();
	glScaled(100, 100, 100);
	glTranslated(0, -0.82, -0.5);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	tunnel(-6.5, -0.15, -10.5, 12, 12, 9, 2, 2);	
	mountain(mountainheightmap3, 5.4, -0.15, -12, 12, 12, 8);	
	glPushMatrix();
	glRotatef(30, 0, 1, 0);
	mountain(mountainheightmap4, -20.5, -0.15, -10, 15, 15, 8);	
	mountain(mountainheightmap5, -20.5, -0.15, -23, 15, 15, 5);	
	glPopMatrix();
	mountain(mountainheightmap5, 1, -0.15, -2.5, 12, 12, 5);	
	mountain(mountainheightmap3, 1, -0.15, -28.5, 18, 18, 9);	
	ground(0, -0.1, 0, 28, 28, Color(0.9, 0.3, 0.3, 1));
	glPopMatrix();
	raleway(60, .3, .7, 0.3, Color(0, 0, 0, 1));
	glTranslated(9, 0, 0);
	glRotated(30, 0, 1, 0);
	raleway(60, .3, .7, 0.3, Color(0, 0, 0, 1));
	glPopMatrix();

   glColor3f(1,1,1);
   if (axes)
   {
      glBegin(GL_LINES);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(300,0.0,0.0);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(0.0,300,0.0);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(0.0,0.0,300);
      glEnd();

      glRasterPos3d(300,0.0,0.0);
      Print("X");
      glRasterPos3d(0.0,300,0.0);
      Print("Y");
      glRasterPos3d(0.0,0.0,300);
      Print("Z");
   }

	glWindowPos2d(5, 5);	
	Print("mode=%d, dim=%d, th=%d, ph=%d", mode, dim, th, ph);

    ErrCheck("in display...");
    glFlush();
    glutSwapBuffers();
}

void project()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.5 * dim * asp, 2.5 * dim * asp, -2.5 * dim, 2.5 * dim , 2.5 * dim, -2.5 * dim);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    ErrCheck("project...");
}

void changeSize(GLsizei w, GLsizei h)
{
    if(h==0)
    {
        h = 1;
    }
    asp = (h >0) ? (double)w/h: 1;
    glViewport(0, 0, w, h);
    project();
}

void specialKeys(int key,int x,int y)
{
   if (key == GLUT_KEY_RIGHT)
      th += 5;
   else if (key == GLUT_KEY_LEFT)
      th -= 5;
   else if (key == GLUT_KEY_UP)
      ph += 5;
   else if (key == GLUT_KEY_DOWN)
      ph -= 5;
   else if (key == GLUT_KEY_PAGE_DOWN)
      dim += 10;
   else if (key == GLUT_KEY_PAGE_UP)
      dim -= 10;
   th %= 360;
   ph %= 360;
   project();	
   glutPostRedisplay();
}

void keyboard(unsigned char ch, int x, int y)
{
    if(ch == 'a')
    {
    	animation = (animation + 1) % 2;	
    }	
    else if(ch == 'H')
    {
		h2 += 5;
    }
    else if(ch == 'h')
    {
		h2 -= 5;
    }
    else if(ch == 'V')
    {
		fov += 1.0;
    }
    else if(ch == 'v')
    {
		fov -= 1.0;
    }
    else if(ch == 'm')
    {
		mode = (mode + 1) % 3;
    }
    else if(ch == 's')
    {
		smooth = (smooth + 1) % 2;
    }
    else if(ch == 'N')
    {
		shininess += 1;
    } 
    else if(ch == 'n')
    {
		shininess -= 1;	
    }
    else if(ch == 'r')
    {
		rep -= 0.1;
	if(rep <0) {rep = 0;}
    }
    else if(ch == 'R')
    {
		rep += 0.1;
    }
    else if(ch == 27)
    {
        exit(0);
    }

    if(shininess > 0)
    {
		shininess %= 8;
    }
    
    shinyvec[0] = shininess<0 ? 0 : pow(2.0,shininess); 
    project();
    glutPostRedisplay();
}

void idle()
{
  if(animation)
  {
   	double t = glutGet(GLUT_ELAPSED_TIME)/1600.0;
   	lh = fmod(90 *t, 360.0);
   	glutPostRedisplay();
  }
}
void setupRC()
{
	glClearColor(0, 0, 0, 1.0);
	//glClearColor(1, 1, 1, 1.0);
}


void loadTexture()
{
	ntexWood = LoadTexBMP("./images/wood2.bmp");
	ntexGrass = LoadTexBMP("./images/grass.bmp");
	ntexMetal = LoadTexBMP("./images/metal.bmp");
	ntexBricks = LoadTexBMP("./images/brick.bmp");
	ntexRock = LoadTexBMP("./images/rock1.bmp");
	ntexMountain = LoadTexBMP("./images/mountain.bmp");
	ntexDesert = LoadTexBMP("./images/desert2.bmp");
}

int main(int argc, char** argv)
{
	diamondsquare(heightmap, 0.95, M, 9, 0, 0, M - 1, M - 1); 	
	smoothheightmap(heightmap, 0.9, 23);
	diamondsquare(mountainheightmap, 0.95, M, 5, 0, 0, M - 1, M - 1); 	
	smoothheightmap(mountainheightmap, 0.9, 23);
	diamondsquare(mountainheightmap2, 0.95, M, 5, 0, 0, M - 1, M - 1); 	
	smoothheightmap(mountainheightmap2, 0.9, 23);
	diamondsquare(mountainheightmap3, 0.95, M, 5, 0, 0, M - 1, M - 1); 	
	smoothheightmap(mountainheightmap3, 0.9, 23);
	diamondsquare(mountainheightmap4, 0.95, M, 5, 0, 0, M - 1, M - 1); 	
	smoothheightmap(mountainheightmap4, 0.9, 23);
	diamondsquare(mountainheightmap5, 0.95, M, 5, 0, 0, M - 1, M - 1); 	
	smoothheightmap(mountainheightmap5, 0.9, 23);
	diamondsquare(mountainheightmap6, 0.95, M, 9, 0, 0, M - 1, M - 1); 	
	smoothheightmap(mountainheightmap6, 0.9, 23);
    glutInitWindowSize(windowsize, windowsize);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow ("Homework 6 - Texture By Qingjun Wu");
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
	loadTexture();

    setupRC();
    glutMainLoop();
    ErrCheck("main...");
    
    return 0;
}
