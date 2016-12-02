//
//  main.cpp
//  opengl_mycar
//
//  Created by sjnam on 11/17/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

//#include <GLKit/glex>
#include <GLUT/glut.h>
#include <iostream>
//#include "objLoader.h"
#include "Car.hpp"
#include "MyCamera.hpp"
#include "Track.hpp"


#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define WINDOW_X_OFFSET 100
#define WINDOW_Y_OFFSET 100


int floorListNum;

const GLfloat WhiteColor4[]  = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat BlackColor4[]  = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat Gray7Color4[]  = { 0.7, 0.7, 0.7, 1.0 };
const GLfloat Gray5Color4[]  = { 0.5, 0.5, 0.5, 1.0 };
const GLfloat Gray4Color4[]  = { 0.4, 0.4, 0.4, 1.0 };


typedef float Point3DF[3];
typedef int Point3DI[3];

float colors[9][3] = {{0, 0, 0},		//	White
    {0, 0, 0 },		//	Black
    {1, 0, 0 },		//	Red
    {0, 1, 0 },		//	Green
    {0, 0, 1 },		//	Blue
    {0, 1, 1 },		//	Cyan
    {1, 0, 1 },		//	Magenta
    {1, 1, 0},
    {1, 0.5, 0}
};	//	Yellow


//texture
//glTexture m_FloorTexture;

Car *car;
MyCamera *myCamera;
Track *track;

bool buffer[256]; //keyboard

void keyboard(unsigned char key, int x, int y);
void keyboardUp( int key, int x, int y );
void KeyOperations();
void StructFloor (void);

void init() {
    /* select clearing color 	*/
    glClearColor(1.0, 1.0, 1.0, 0.0); //background
    glEnable ( GL_DEPTH_TEST );
    glClearDepth(1.0);
    
    glEnable ( GL_CULL_FACE );
    glCullFace ( GL_BACK );
    myCamera->mode = WORLD;
    
    
    //glMatrixMode(GL_MODELVIEW);
    
    
    StructFloor();
}



//Set Material Properties Specular, ambient, diffusion and shines
void SetMaterial(const GLfloat spec[],const GLfloat amb[],const GLfloat diff[], int shin)
{
    glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
    glMateriali(GL_FRONT, GL_SHININESS, shin);
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}

void StructFloor (void)
{
    int i, j,jj,ii;
    GLfloat x0=-10, z0=-10, x1=1, z1=1;
    int count=15;       // Number of division of the flor block
    int repeat=20;      // Repeat number of floor block
    
    floorListNum=glGenLists(1);
    glNewList(floorListNum,GL_COMPILE);
    SetMaterial(Gray7Color4,Gray7Color4,Gray4Color4,128);
    //    if( m_FloorTexture.TextureID )
    //    {
    //        glEnable(GL_TEXTURE_2D);
    //        glBindTexture(GL_TEXTURE_2D, m_FloorTexture.TextureID);			// Select Texture
    //    }
    glBegin(GL_QUADS);
    
    glNormal3f( 0.f,  1.f, 0.f);
    for(jj = 1; jj <= repeat; jj++)
        for(ii = 1; ii <= repeat; ii++)
            for(j = 0; j < count; j++)
                for(i = 0; i < count; i++)
                {
                    //glTexCoord2f(i * 1.f/count, j * 1.f/count);
                    glVertex3f(x0+x1*ii + i * x1 * 1.f/count,
                               0.0,
                               z0+z1*jj + j * z1 * -1.f/count);
                    //glTexCoord2f((i + 1) * 1.f/count, j * 1.f/count);
                    glVertex3f(x0+x1*ii + (i + 1) * x1 * 1.f/count,
                               0.0,
                               z0+z1*jj + j * z1 * -1.f/count);
                    //glTexCoord2f((i + 1) * 1.f/count, (j + 1) * 1.f/count);
                    glVertex3f(x0+x1*ii + (i + 1) * x1 * 1.f/count,
                               0.0,
                               z0+z1*jj + (j + 1) * z1 * -1.f/count);
                    //glTexCoord2f(i * 1.f/count, (j + 1) * 1.f/count);
                    glVertex3f(x0+x1*ii + i * x1 * 1.f/count,
                               0.0,
                               z0+z1*jj + (j + 1) * z1 * -1.f/count);
                }
    glEnd();
    
    //        if( m_FloorTexture.TextureID ) glDisable(GL_TEXTURE_2D);
    glEndList();
}


// Sets timer for refresh the display
void Timer_sj(int extra)
{
    //printf("refresh\n");
    glutPostRedisplay();
    glutTimerFunc(30,Timer_sj,0);
}

void draw_axis2 ( )
{
    glLineWidth ( 2.0f );
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0); //red x
    glVertex3f(-2000,0,0);
    glVertex3f(2000,0,0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0); //green y
    glVertex3f(0,-2000,0);
    glVertex3f(0,2000,0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,1); //blue z
    glVertex3f(0,0,-2000);
    glVertex3f(0,0,2000);
    glEnd();
    
}

//Resize display
void Reshape(GLint newWidth, GLint newHeight)
{
    glViewport(0,0, (GLsizei)newWidth, (GLsizei)newHeight);
    
    glMatrixMode(GL_PROJECTION);     // Select The Projection Matrix
    glLoadIdentity();                // Reset The Projection Matrix
    // Calculate The Aspect Ratio And Set The Clipping Volume
    if (newHeight == 0) newHeight = 1; // Zero-division prevention
    gluPerspective(30.0f, (GLfloat)newWidth/(GLfloat)newHeight, 0.1, 100.0);
    
    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
}

void display() {
    //	1. clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    //glMatrixMode(GL_PROJECTION);
    draw_axis2 ( );
    glLoadIdentity();
    KeyOperations();
    
    //1.5 camera
    if (myCamera->mode == CAR) {
        myCamera->setBehindCar(car->currentPosition, car->directionalVector, car->degree);
    }
    else if (myCamera->mode == WORLD) {
        myCamera->viewDefault();
    }

    
//	2. draw track
    track->draw_track(700, 600);
    
    //draw_car();
    car->draw_car();
    
//    glPolygonMode(GL_FRONT,GL_FILL);
//    glPolygonMode(GL_BACK,GL_LINE);
    
    //glPushMatrix();
    //glTranslatef(0.25, 0, 0);
    //draw_car();
    //glPopMatrix();
    //draw_car();
//    
//    myObject.draw ( );
    
    
    //	4. swap buffers
    glutSwapBuffers ();
}

void KeyOperations() {
    
    if (buffer['w']) {
        printf("w input\n");
        car->move();
        
    }
    if (buffer['w']) {
        printf("w input\n");
        car->move();
        
    }
    if (buffer['s']) {
        printf("s input\n");
        car->moveback();
        
    }
    if (buffer['p']) {
        printf("p input\n");
        myCamera->mode = WORLD;
    }
    if (buffer['q']) {
        printf("q input\n");
        myCamera->mode = CAR;
    }
    if (buffer['a']) {
        printf("left rotate\n");
        car->yaw(CAR_ROTATE::LEFT);
    }
    if (buffer['d']) {
        printf("right rotate\n");
        car->yaw(CAR_ROTATE::RIGHT);
    }
}


void keyboard(unsigned char key, int x, int y) {
    buffer[key] = true;
}

void keyboardUp(unsigned char key, int x, int y )
{
    buffer[key] = false;
}

int main(int argc,  char ** argv) {

#pragma mark --
#pragma mark Todo
    
    //2. load texture
//    GLuint tex;
//    glGenTextures(1, &tex);
//    glBindTexture(GL_TEXTURE_2D, tex);
    
    
    //glut init
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    
    
    // 3. car object init
    car = new Car();
    
    // 4. camera object init
    myCamera = new MyCamera();
    
    // 4.1 track
    track = new Track();
    
    
    
    
    // 5. light system init
    init();
    car->init_car();
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-100.0, 100.0, -100.0, 100.0, -500.0, 500.0);
    //glOrtho(0.0f, 800, 600, 0.0, 0.0, 1.0);
    gluPerspective(70.0f, (GLfloat)800/(GLfloat)600, 0.1, 10000.0);

    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutKeyboardFunc (keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(0,Timer_sj,0);
    glutMainLoop();


    return 0;
}


