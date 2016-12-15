//
//  Tree.cpp
//  opengl_mycar
//
//  Created by sjnam on 12/14/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#include "Tree.hpp"
#include <GLUT/GLUT.h>


Tree::Tree() {
    objData = new objLoader();
    objData->load("low poly tree.obj");
    
    printf("Number of vertices: %i\n", objData->vertexCount);
    printf("Number of vertex normals: %i\n", objData->normalCount);
    printf("Number of texture coordinates: %i\n", objData->textureCount);
}

void Tree::setPos(float x, float y, float z) {
    curPos.set(x, y, z);
}

void Tree::draw() {
    
    int count=0;
    glPushMatrix();
    
    
    
    glTranslatef(curPos[0], curPos[1], curPos[2]);
    glScaled(0.5, 0.5, 0.5);

    glColor3f(0.3, 0.8, 0.4);
    for (int i=0; i<objData->faceCount; i++) {
        count++;

        glBegin(GL_TRIANGLES);
        int vertexinde0 =  objData->faceList[i]->vertex_index[0];
        int vertexinde1 =  objData->faceList[i]->vertex_index[1];
        int vertexinde2 =  objData->faceList[i]->vertex_index[2];
        glVertex3f((GLfloat)objData->vertexList[vertexinde0]->e[0], (GLfloat)objData->vertexList[vertexinde0]->e[1], (GLfloat)objData->vertexList[vertexinde0]->e[2]);
        glNormal3f(0, 1, 0);
        
        glVertex3f((GLfloat)objData->vertexList[vertexinde1]->e[0], (GLfloat)objData->vertexList[vertexinde1]->e[1], (GLfloat)objData->vertexList[vertexinde1]->e[2]);
        glNormal3f(0, 1, 0);
        
        glVertex3f((GLfloat)objData->vertexList[vertexinde2]->e[0], (GLfloat)objData->vertexList[vertexinde2]->e[1], (GLfloat)objData->vertexList[vertexinde2]->e[2]);
        glNormal3f(0, 1, 0);
        glEnd();
    }

    glPopMatrix();



}
