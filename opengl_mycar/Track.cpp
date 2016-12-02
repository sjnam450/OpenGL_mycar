//
//  Track.cpp
//  opengl_mycar
//
//  Created by sjnam on 12/2/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#include "Track.hpp"

Track::Track() {
    
}


void Track::draw_track(float R1,float R2) {
    float X,Y,Z;
    int  y;
    Y = 0;
    glPushMatrix();
    glColor3f(0.3,0.3,0.6);
    
    glTranslatef(-1200, 0, 0);
    
    glBegin(GL_QUAD_STRIP);
    for (y=0; y<=2401; y++) {
        X = y;
        Z = -50;
        glVertex3f(X,Y,Z);
        
        Z = 50;
        glVertex3f(X,Y,Z);
        
    }
    glEnd();
    
    //glLoadIdentity();
    glTranslatef(2400, 0, 50 + R2);
    //glTranslatef(10, 0, 10);
    glBegin(GL_QUAD_STRIP);
    
  
    for( y=-90;y<=91;y+=1) {
        X=R1*cos(c*y);
        Z=R1*sin(c*y);
        glVertex3f(X,Y,Z);
        
        X=R2*cos(c*y);
        Z=R2*sin(c*y);
        glVertex3f(X,Y,Z);
    }
    glEnd();

    
    glTranslatef(-2400, 0, 650);
    glBegin(GL_QUAD_STRIP);
    for (y=0; y<=2400; y++) {
        X = y;
        Z = -50;
        glVertex3f(X,Y,Z);
        
        Z = 50;
        glVertex3f(X,Y,Z);
        
    }
    glEnd();

    glTranslatef(0, 0, -650);
    glBegin(GL_QUAD_STRIP);
    
    
    for( y=90;y<=271;y+=1) {
        X=R1*cos(c*y);
        Z=R1*sin(c*y);
        glVertex3f(X,Y,Z);
        
        X=R2*cos(c*y);
        Z=R2*sin(c*y);
        glVertex3f(X,Y,Z);
    }
    glEnd();
    
    
//    Y = 0;
//    for( y=0;y<=181;y+=1)
//    {
//        X=R1*cos(c*y);
//        Z=R1*sin(c*y);
//        //Z=-1;
//        glVertex3f(X,Y,Z);
//        
//        X=R2*cos(c*y);
//        Z=R2*sin(c*y);
//        //Z=-1;
//        glVertex3f(X,Y,Z);
//    }
    glEnd();
    glPopMatrix();
}
