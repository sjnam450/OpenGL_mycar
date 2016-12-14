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
#include "Skybox.hpp"
#include "Tree.hpp"

#include <vector>


#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define WINDOW_X_OFFSET 100
#define WINDOW_Y_OFFSET 100


int floorListNum;



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
Skybox *skybox;
//Tree *tree;
std::vector<Tree> treeVector;



bool buffer[256]; //keyboard

void keyboard(unsigned char key, int x, int y);
void keyboardUp( int key, int x, int y );
void KeyOperations();
//void StructFloor (void);

void init() {
    /* select clearing color 	*/
    glClearColor(1.0, 1.0, 1.0, 0.0); //background
    glEnable ( GL_DEPTH_TEST );
    glClearDepth(1.0);
    
    //glEnable ( GL_CULL_FACE );
    
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
//    glEnable( GL_LIGHTING ); //조명을 사용할 것이다.
//    glEnable( GL_LIGHT0 ); //조명 중 0 번 조명을 사용할 것이다.
    
    GLfloat AmbientLightValue[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat DiffuseLightValue[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat SpecularLightValue[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat PositionLightValue[] = { 0.0f, 0.0f, 1.0f, 0.0f };
    
    
    
    
//    glLightfv( GL_LIGHT0, GL_AMBIENT, AmbientLightValue ); //Ambient 조명의 성질을 설정한다.
//    glLightfv( GL_LIGHT0, GL_DIFFUSE, DiffuseLightValue ); //Diffuse 조명의 성질을 설정한다.
//    glLightfv( GL_LIGHT0, GL_SPECULAR, SpecularLightValue ); //Specular 조명의 성질을 설정한다.
//    glLightfv( GL_LIGHT0, GL_POSITION, PositionLightValue ); //조명의 위치(광원)를 설정한다.
    
    glCullFace ( GL_BACK );
    myCamera->mode = WORLD;
    
    
    //glMatrixMode(GL_MODELVIEW);
    
    
    //StructFloor();
}



//Set Material Properties Specular, ambient, diffusion and shines
void SetMaterial(const GLfloat spec[],const GLfloat amb[],const GLfloat diff[], int shin)
{
    glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
    glMateriali(GL_FRONT, GL_SHININESS, shin);
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
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
    glPushMatrix();
    glLineWidth ( 2.0f );
    glColor3f(1,0,0); //red x
    glBegin(GL_LINE_LOOP);
    glVertex3f(-2000,0,0);
    glVertex3f(2000,0,0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0); //green y
    glVertex3f(0,-2000,0);
    glVertex3f(0,2000,0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,1); //blue z
    glVertex3f(0,0,-2000);
    glVertex3f(0,0,2000);
    glEnd();
    glPopMatrix();
    
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
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    draw_axis2 ( );
    glPopAttrib();
    glPopMatrix();
    

    
    glLoadIdentity();
    KeyOperations();
    
    //1.5 camera
    if (myCamera->mode == CAR) {
        myCamera->setBehindCar(car->currentPosition, car->directionalVector, car->degree);
    }
    else if (myCamera->mode == WORLD) {
        myCamera->viewDefault();
    }
    
    
//    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    
//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    glColor4f(0.75f, 0.75f, 0.75f, 1.0f);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//    glMateriali(GL_FRONT, GL_SHININESS, 10);


    
    //	2. draw track
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    track->draw_track(700, 600);
    glPopAttrib();
    glPopMatrix();

    //4.sky
//    skybox->draw();

    

    
    glPushMatrix();
    skybox->draw();
    glPopMatrix();
    //4. draw tree
    


    //tree->draw(); //so slow uu
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    for (int i=0; i<400; i++) {
        treeVector[i].draw();
    }
    glPopAttrib();
    glPopMatrix();
    
    //3. draw_car();
    glPushMatrix();
    car->draw_car();
    glPopMatrix();
    
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
        printf("left rotate\n");
        car->yaw(CAR_ROTATE::RIGHT);
    }

    if (buffer['r']) {
        printf("right rotate\n");
        car->pitch(CAR_ROTATE::UP);
    }
    
    if (buffer['f']) {
        printf("right rotate\n");
        car->pitch(CAR_ROTATE::DOWN);
    }

}


void keyboard(unsigned char key, int x, int y) {
    buffer[key] = true;
    
    if (key=='n') {
        myCamera->zoom += 0.01;
    }
    if (key=='m') {
        myCamera->zoom -= 0.01;
    }

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
    
    // 4.2 skymap
    skybox = new Skybox();
    
    //4.3 tree
    treeVector.reserve(400);
    
    //나무 위치 잡기
    for (int i; i<200; i++) {
        Tree *tree = new Tree();
        tree->setPos(300 * 0.5*i, -80, -200);
        treeVector.push_back(*tree);
    }
    
    for (int i=0; i<200; i++) {
        Tree *tree = new Tree();
        tree->setPos(300 * 0.5*i, -80, +200);
        treeVector.push_back(*tree);
    }

    
    
    
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


