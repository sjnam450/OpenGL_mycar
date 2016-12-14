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
    
    /*
    int matcount = objData->materialCount;
    TGAFILE tgaFiles[matcount];
    for (int i=0; i<objData->materialCount; i++) {
        TGAFILE tgaFile;
        texLoad.LoadTGAFile(objData->materialList[i]->texture_filename, &tgaFile);
        //tex[i] = i;
        printf("tga file name : %s\n", objData->materialList[i]->texture_filename);
        memcpy(&tgaFiles[i], &tgaFile, sizeof(TGAFILE));
    }
    
    //glBindTexture(GL_TEXTURE_2D,0);
    //glBindTexture( GL_TEXTURE_2D, 0);
    glGenTextures( 3, tex); //Create a Texture via ID
    for (int i=0; i<objData->materialCount; i++) {
        //glGenTextures( 0, &tex[i]); //Create a Texture via ID
        //glGenTextures( 1, &tex[i]); //Create a Texture via ID
        glBindTexture( GL_TEXTURE_2D, tex[i]);
        //GL_BGRA_EXT
        //GL_RG2
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        
        
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, tgaFiles[i].imageWidth, tgaFiles[i].imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, tgaFiles[i].imageData );
        
    }
     */


    
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
        //objData->faceList[i]->
        count++;

        glBegin(GL_TRIANGLES);

        
        //objData->faceList
        //glver
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
