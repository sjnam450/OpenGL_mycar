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
    
//        glLoadIdentity();                // Reset The Projection Matrix
    
    glPushMatrix();
     glTranslatef(curPos[0], curPos[1], curPos[2]);
            glScaled(0.5, 0.5, 0.5);
    for (int i=0; i<objData->faceCount; i++) {
        //objData->faceList[i]->
        count++;
        //objData->materialList[objData->faceList[i]->material_index]-> ;
        int texIndex0 = (GLuint)objData->faceList[i]->material_index;
        
//        glEnable(GL_TEXTURE_2D);
        //            if (texIndex0 == -1 || texIndex0 == 0) {
        //                glBindTexture( GL_TEXTURE_2D, 2);
        //            }
        //            else if (texIndex0 == 1){
        //                glBindTexture( GL_TEXTURE_2D,  0);
        //            }
        //            else if(texIndex0 == 2) {
        //                glBindTexture( GL_TEXTURE_2D, 3);
        //            }
        //glBindTexture( GL_TEXTURE_2D, 0);
        
        
        glBegin(GL_TRIANGLES);
        
        glColor3f(0.3, 0.8, 0.4);


        //printf("mat inde %d %s\n", objData->faceList[i]->material_index, objData->materialList[texIndex0]->texture_filename);
        
        //            objData->materialList[objData->faceList[i]->material_index]->amb;
        //            objData->materialList[objData->faceList[i]->material_index]->diff;
        //            objData->materialList[objData->faceList[i]->material_index]->texture_filename;
        
        //objData->faceList
        //glver
        int vertexinde0 =  objData->faceList[i]->vertex_index[0];
        int vertexinde1 =  objData->faceList[i]->vertex_index[1];
        int vertexinde2 =  objData->faceList[i]->vertex_index[2];
        
        int normInde0 = objData->faceList[i]->normal_index[0];
        int normInde1 = objData->faceList[i]->normal_index[1];
        int normInde2 = objData->faceList[i]->normal_index[2];
        
        int textureInde0 = objData->faceList[i]->texture_index[0];
        int textureInde1 = objData->faceList[i]->texture_index[1];
        int textureInde2 = objData->faceList[i]->texture_index[2];
        
        
        
        
        //int vertexinde3 =  objData->faceList[i]->vertex_index[3];
        
        //int texIndex0 = (GLuint)objData->faceList[i]->material_index+1;
        //glBindTexture( GL_TEXTURE_2D, (GLuint)texIndex0 );
        //glBindTexture( GL_TEXTURE_2D, 1 );
        
        if (textureInde0 != -1) {
            
            
            GLfloat u1 = (GLfloat)objData->textureList[textureInde0]->e[0];
            GLfloat v1 = (GLfloat)objData->textureList[textureInde0]->e[1];
            glTexCoord2f(u1, v1);
            //printf("uv %f, %f, texture in : %d\n", u1, v1, texIndex0);
            
            
        }
        glVertex3f((GLfloat)objData->vertexList[vertexinde0]->e[0], (GLfloat)objData->vertexList[vertexinde0]->e[1], (GLfloat)objData->vertexList[vertexinde0]->e[2]);
//        glNormal3f((GLfloat)objData->normalList[vertexinde0]->e[0], (GLfloat)objData->normalList[vertexinde0]->e[1], (GLfloat)objData->normalList[vertexinde0]->e[2]);
        
        
        
        //glBindTexture( GL_TEXTURE_2D, (GLuint)texIndex1 );
        
        
        if (textureInde1 != -1) {
            
            GLfloat u2 = (GLfloat)objData->textureList[textureInde1]->e[0];
            GLfloat v2 = (GLfloat)objData->textureList[textureInde1]->e[1];
            glTexCoord2f(u2, v2);
            
            
        }
        
        
        glVertex3f((GLfloat)objData->vertexList[vertexinde1]->e[0], (GLfloat)objData->vertexList[vertexinde1]->e[1], (GLfloat)objData->vertexList[vertexinde1]->e[2]);
//        glNormal3f((GLfloat)objData->normalList[vertexinde1]->e[0], (GLfloat)objData->normalList[vertexinde1]->e[1], (GLfloat)objData->normalList[vertexinde0]->e[2]);
        //printf("uv %f, %f, texture in : %d\n", u1, v1, texIndex1);
        
        
        
        
        
        if (textureInde2 != -1) {
            //glBindTexture( GL_TEXTURE_2D, (GLuint)texIndex2 );
            GLfloat u3 = (GLfloat)objData->textureList[textureInde2]->e[0];
            GLfloat v3 = (GLfloat)objData->textureList[textureInde2]->e[1];
            glTexCoord2f(u3, v3);
            
            
        }
        
        glVertex3f((GLfloat)objData->vertexList[vertexinde2]->e[0], (GLfloat)objData->vertexList[vertexinde2]->e[1], (GLfloat)objData->vertexList[vertexinde2]->e[2]);
//        glNormal3f((GLfloat)objData->normalList[vertexinde2]->e[0], (GLfloat)objData->normalList[vertexinde2]->e[1], (GLfloat)objData->normalList[vertexinde2]->e[2]);
        //printf("uv %f, %f, texture in : %d\n", u1, v1, texIndex2);
        
        
        glEnd();
        glDisable(GL_TEXTURE_2D);
        
    }
//    printf("vertex cound : %d\n", count);
    glPopMatrix();



}
