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

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define WINDOW_X_OFFSET 100
#define WINDOW_Y_OFFSET 100




// Sets timer for refresh the display
void Timer_sj(int extra)
{
    printf("refresh\n");
    glutPostRedisplay();
    glutTimerFunc(30,Timer_sj,0);
}

void display() {
    //	1. clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
//    //	2. draw axis
//    draw_axis ( );
//    
//    myObject.draw ( );
    
    //	4. swap buffers
    glutSwapBuffers ();
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
    
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
//    init ();
    glutDisplayFunc(display);
//    glutMouseFunc (mouse);
//    glutMotionFunc (motion);
//    glutKeyboardFunc (keyboard);
    glutTimerFunc(0,Timer_sj,0);
    glutMainLoop();

    
    

    //glutMainLoop();
    return 0;
}


