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
#include "objLoader.h"
#include "Car.hpp"


#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define WINDOW_X_OFFSET 100
#define WINDOW_Y_OFFSET 100

objLoader *objData;
GLuint elephant;
float elephantrot;
int mode; //0 car, 1 is eye bird

int floorListNum;

const GLfloat WhiteColor4[]  = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat BlackColor4[]  = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat Gray7Color4[]  = { 0.7, 0.7, 0.7, 1.0 };
const GLfloat Gray5Color4[]  = { 0.5, 0.5, 0.5, 1.0 };
const GLfloat Gray4Color4[]  = { 0.4, 0.4, 0.4, 1.0 };



//texture
//glTexture m_FloorTexture;

Car *car;

void keyboard(unsigned char key, int x, int y);
void StructFloor (void);


void init() {
    /* select clearing color 	*/
    glClearColor(1.0, 1.0, 1.0, 0.0); //background
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//    
//    glEnable ( GL_DEPTH_TEST );
//    glClearDepth(1.0);
//    
//    glEnable ( GL_CULL_FACE );
//    glCullFace ( GL_BACK );
//    
//    
//    /* initialize viewing values  */
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
        mode = 1;
    
    StructFloor();
//    
    //    glOrtho(-100.0, 100.0, -100.0, 100.0, -500.0, 500.0);
    //    gluLookAt (30.0f, 10.0f,10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );  //카메라
    
    //glOrtho(-100.0, 100.0, -100.0, 100.0, -500.0, 500.0);
    //gluLookAt (30, 10.0f, 10.0f, 0.0f, 00.0f, 00.0f, 0.0f, 1.0f, 0.0f );
    elephant=glGenLists(1);
}

void init_car() {
    glPointSize(2.0);
    int count=0;
    glNewList(elephant, GL_COMPILE);
    {
        //glPushMatrix();
        
        
        glBegin(GL_TRIANGLES);
        //glColor3f(0.2, 0.5, 0.1);
        
        //glScalef(0.5,0.5,0.5);
        //glbi
        //        while(!(feof(fp)))
        //        {
        //            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
        //            if(read==4&&ch=='v')
        //            {
        //                glVertex3f(x,y,z);
        //            }
        //        }
        for (int i=0; i<objData->vertexCount; i++) {
            //objData->faceList[i]->
            count++;
            GLfloat x = (GLfloat)objData->vertexList[i]->e[0];
            GLfloat y = (GLfloat)objData->vertexList[i]->e[1];
            GLfloat z = (GLfloat)objData->vertexList[i]->e[2];
            //t(<#GLenum target#>, <#GLuint texture#>)
            
            //objData->textureList[i]->e
            glVertex3f(x,y,z);
        }
        //printf("vertex cound : %d\n", count);
        glEnd();
    }
    
    //glPopMatrix();
    glEndList();

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

void draw_car() {
    
    //floor
//    glPushMatrix();
//    glPushAttrib(GL_TEXTURE_BIT|GL_CURRENT_BIT|GL_ENABLE_BIT|GL_LIGHTING_BIT);
//    //glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
//    glCallList(floorListNum);
//    //glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
//    glPopAttrib();
//    glPopMatrix();
    
    
    
    glPushMatrix();
//    glTranslatef(0,-40.00,-105);
//    glColor3f(1.0,0.23,0.27);
    
    
    glScalef(0.01, 0.01, 0.01);
    //glTranslatef(car->currentPosition.v[0], car->currentPosition.v[1], car->currentPosition.v[2]);
    glTranslatef(50, 0, 0);
    //glRotatef(elephantrot,0,1,0);
    
    //glCallList(elephant);
    
    
    
    glBegin(GL_POINTS);
    //glColor3f(0.2, 0.5, 0.1);
    
    //glScalef(0.5,0.5,0.5);
    //glbi
    //        while(!(feof(fp)))
    //        {
    //            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
    //            if(read==4&&ch=='v')
    //            {
    //                glVertex3f(x,y,z);
    //            }
    //        }
    
    for (int i=0; i<objData->vertexCount; i++) {
        //objData->faceList[i]->
    //    count++;
        GLfloat x = (GLfloat)objData->vertexList[i]->e[0];
        GLfloat y = (GLfloat)objData->vertexList[i]->e[1];
        GLfloat z = (GLfloat)objData->vertexList[i]->e[2];
        //t(<#GLenum target#>, <#GLuint texture#>)
        
        //objData->textureList[i]->e
        glVertex3f(x,y,z);
    }
    //printf("vertex cound : %d\n", count);
    glEnd();
    
    
    
    
    glPopMatrix();
    elephantrot=elephantrot+0.6;
    if(elephantrot>360)elephantrot=elephantrot-360;
    
    
    
//    glPointSize(2.0f);
//    glBegin(GL_POINTS);
//    glColor3f(0.3, 0.5, 0.1);
//    for (int i=0; i<objData->vertexCount; i++) {
//        glVertex3dv(&objData->vertexList[i]->e[0]);
//        glVertex3dv(&objData->vertexList[i]->e[1]);
//        glVertex3dv(&objData->vertexList[i]->e[2]);
//    }
//    glEnd();


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
    glVertex3f(-500,0,0);
    glVertex3f(500,0,0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0); //green y
    glVertex3f(0,-500,0);
    glVertex3f(0,500,0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,1); //blue z
    glVertex3f(0,0,-500);
    glVertex3f(0,0,500);
    glEnd();
    
}

void display() {
    //	1. clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    //glMatrixMode(GL_PROJECTION);
    draw_axis2 ( );
    glLoadIdentity();
    printf("car position : %f, %f, %f\n", car->currentPosition.v[0], car->currentPosition.v[1], car->currentPosition.v[2]);
    //1.5 camera
    
    //gluLookAt (0.0f, 0.0f, 0.0f, 1000.0f, 1000.0f, 1000.0f, 0.0f, 1.0f, 0.0f );
    if (mode ==0) {
        
        gluLookAt (car->currentPosition.v[0]-3, car->currentPosition.v[1], car->currentPosition.v[2]-3,
                   car->currentPosition.v[0]-10, car->currentPosition.v[1]+10, car->currentPosition.v[2]-10,
                   0.0f, 1.0f, 0.0f );
      //  gluLookAt (20.0f, 10.0f,20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );
    }
    else if (mode == 1) {
            gluLookAt (0.0f, 0.0f, 0.0f, 100, 100, 100, 0.0f, 1.0f, 0.0f );
    }

    
//    //	2. draw axis
    
    draw_car();
    
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

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
            //trans + (X, Y, Z)
        case 'z':
            printf("z input\n");
            car->currentPosition.v[2] -= 5.0f;
            break;
            
        case 'p':
            printf("p input\n");
            mode = 1;
            break;
            
        case 'q':
            printf("q input\n");
            mode = 0;
            break;

    
        default:
            break;

    }
}

int main(int argc,  char ** argv) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//    glutInitWindowPosition(WINDOW_X_OFFSET, WINDOW_Y_OFFSET);
//    glutInit(&argc, argv);
//    glutCreateWindow("OpenGL Robot");
//    glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) >> 1,glutGet(GLUT_WINDOW_HEIGHT) >> 1);
    
    
#pragma mark --
#pragma mark Todo
    //1. OBJ LOADER ADD
    objData = new objLoader();
    //objData->load("Police_car.obj");
    //objData->load("Apple.obj");
    objData->load("porsche.obj");
    
    
    printf("Number of vertices: %i\n", objData->vertexCount);
    printf("Number of vertex normals: %i\n", objData->normalCount);
    printf("Number of texture coordinates: %i\n", objData->textureCount);
    
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
    car->currentPosition = Vector3(0, 0, 0);
    // 4. camera object init
    // 5. light system init
    init();
    init_car();

    glutDisplayFunc(display);
//    glutMouseFunc (mouse);
//    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    glutTimerFunc(0,Timer_sj,0);
    glutMainLoop();


    return 0;
}


