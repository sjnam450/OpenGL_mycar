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
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    
    
    //glTranslatef(0, 0q, <#GLfloat z#>)
    
    glColor3f(0.3,0.3,0.6);
    
    Y = 0;
    for( y=0;y<=181;y+=1)
    {
        X=R1*cos(c*y);
        Z=R1*sin(c*y);
        //Z=-1;
        glVertex3f(X,Y,Z);
        
        X=R2*cos(c*y);
        Z=R2*sin(c*y);
        //Z=-1;
        glVertex3f(X,Y,Z);
    }
    glEnd();
    glPopMatrix();
}
