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

using namespace std;
double axeslen = 95;
double asp = 1.0;
#define PI 3.14159265

double upx = 0;
double upy = 0;
double upz = -1.0;
double fov = 120.0;
double ph = 0; //2;
double th = 0; //102;
double dim = 500;
double windowsize = 450;
int mode = 0;
int smooth = 0;
int ambient = 30;
int diffuse   = 100;  
int specular  =   0;  
int shininess =   0;  
float shinyvec[1] = { 0.0};
int local = 1;
unsigned int texture[20];
float rep = 1.0;
int texturebase = 6;
float lh = 30;
int animation = 1;
float h2 = 0;

double	ex = 0;
double	ez = 0;
double  ey = 0;
const int H = 6;
const int M = pow(2, H) + 1;
vector<vector<float> > heightmap(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap2(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap3(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap4(M, vector<float>(M, 0.0));
vector<vector<float> > mountainheightmap5(M, vector<float>(M, 0.0));
float white[] = {1, 1, 1, 1};
float black[] = {0, 0, 0, 1};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
	glShadeModel(smooth ? GL_SMOOTH : GL_FLAT); 
	glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);

    if(mode)
    {
		ex = 3 * dim * Sin(ph);
		ez = 5.0 * dim * Cos(ph);
		ey = 2.5* dim * Sin(th); 
    	gluLookAt(ex, ey, ez, 0, 0, 0, upx, upy, upz);
    }
    else
    {
    	glRotatef(ph,1,0,0);
    	glRotatef(th,0,1,0);
    }    

	glTranslated(0, -200,0);
	sun(300, 600, 300, 50, Color(1, 1, 1, 1), GL_LIGHT0);
	train(0, 0, 0, 100, 100, 100);
	glPushMatrix();
	glScaled(100, 100, 100);
	glTranslated(0, -0.82, -0.5);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	tunnel(-5.1, -0.1, -2.0, 9, 9, 9, 2, 2);	
	mountain(mountainheightmap, -14, -0.1, 0, 8, 8, 8);	
	mountain(mountainheightmap2, 9, -0.1, 7, 8, 8, 8);	
	mountain(mountainheightmap3, 7, -0.1, 0, 8, 8, 8);	
	mountain(mountainheightmap4, -20, -0.1, 0, 8, 8, 8);	
	mountain(mountainheightmap5, -15, -0.1, -10, 8, 8, 8);	
	glPopMatrix();
	raleway(20, .3, .7, 0.3, Color(0, 0, 0, 1));
	glRotated(30, 0, 1, 0);
	raleway(20, .3, .7, 0.3, Color(0, 0, 0, 1));
	glPopMatrix();

    ErrCheck("in display...");
    glFlush();
    glutSwapBuffers();
}

void project()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(mode)
    {
		gluPerspective(fov, asp, 1000, 0.001);
    }
    else
    {
    	glOrtho(-1.5 * dim * asp, 1.5 * dim * asp, -1.5 * dim, 1.5 * dim , 1.5 * dim, -1.5 * dim);
    }
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


void specialKeys( int key, int x, int y ) {
    if (key == GLUT_KEY_RIGHT)
        th += 3;
    else if (key == GLUT_KEY_LEFT)
        th -= 3;
    else if (key == GLUT_KEY_UP)
       	ph += 3;
    else if (key == GLUT_KEY_DOWN)
        ph -= 3;
    
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
		mode = (mode + 1) % 2;
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
    else if(ch == 'T')
    {
		texturebase += 1;
    }
    else if(ch == 't')
    {
		texturebase -= 1;
    }
    else if(ch == 'x')
    {
		upx = 1; upy = 0; upz = 0;
    }
    else if(ch == 'y')
    {
		upy = 1; upx = 0; upz = 0;
    }
    else if(ch == 'z')
    {
		upz = 1; upx = 0; upy = 0;
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
    glutInitWindowSize(windowsize, windowsize);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow ("Homework 6 - Texture By Qingjun Wu");
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    setupRC();
    glutMainLoop();
    ErrCheck("main...");
    
    return 0;
}
