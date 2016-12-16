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
//    
//    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    
//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    glColor4f(0.75f, 0.75f, 0.75f, 1.0f);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//    glMateriali(GL_FRONT, GL_SHININESS, 10);
    
    glColor3f(0.3,0.3,0.3);

    glPushMatrix();
    glTranslatef(-1200, 0, 0);

    glBegin(GL_QUAD_STRIP);
    for (y=0; y<=2401; y++) {
        X = y;
        Z = -50;
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
        
        Z = 50;
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
        
    }
    glEnd();
    glPopMatrix();
    
    //glLoadIdentity();
    glPushMatrix();
    glTranslatef(1200, 0, 50 + R2);
    //glTranslatef(10, 0, 10);
    glBegin(GL_QUAD_STRIP);
  
    for( y=-90;y<=91;y+=1) {
        X=R1*cos(c*y);
        Z=R1*sin(c*y);
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
        
        X=R2*cos(c*y);
        Z=R2*sin(c*y);
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
    }
    glEnd();
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(-1200, 0, 1300);
    glBegin(GL_QUAD_STRIP);
    for (y=0; y<=2400; y++) {
        X = y;
        Z = -50;
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
        Z = 50;
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
        
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1200, 0, 650);
    glBegin(GL_QUAD_STRIP);
    
    
    for( y=90;y<=271;y+=1) {
        X=R1*cos(c*y);
        Z=R1*sin(c*y);
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
        
        X=R2*cos(c*y);
        Z=R2*sin(c*y);
        glVertex3f(X,Y,Z);
        glNormal3f(0, 1, 0);
    }
    glEnd();
    glPopMatrix();
}
