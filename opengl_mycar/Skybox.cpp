//
//  Skybox.cpp
//  opengl_mycar
//
//  Created by sjnam on 12/13/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#include "Skybox.hpp"
#include <string>
#include <vector>
#include <GLUT/glut.h>


GLuint skytex[6];

unsigned char* *imgDatas;

GLenum  cube[6] = { GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
    GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
    GL_TEXTURE_CUBE_MAP_POSITIVE_X,
    GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
    GL_TEXTURE_CUBE_MAP_POSITIVE_Y
    };

Skybox::Skybox() {
    
    //load texture
    
    std::vector<std::string> skyboxFiles = {"Daylight Box_Back.bmp", "Daylight Box_Bottom.bmp", "Daylight Box_Front.bmp", "Daylight Box_Left.bmp", "Daylight Box_Right.bmp", "Daylight Box_Top.bmp"};
    
    int skymapCount = 6; //정육면체
    int imageSize = 512*512 * 3;
    imgDatas = (unsigned char**)malloc(sizeof(unsigned char*)*6);
    for (int i =0; i<skymapCount; i++) {
        imgDatas[i] = (unsigned char*)malloc(sizeof(unsigned char)*imageSize);
    }
    
    for (int i = 0; i < skymapCount; i++) {
        FILE *filePtr;
        unsigned char * imgData;
        imgData = (unsigned char*)malloc(sizeof(unsigned char)*imageSize);
        const char * str = skyboxFiles[i].c_str();
        printf("file name : %s", str);
        filePtr = fopen(str, "rb");
        if (filePtr == NULL)
        {
            printf("error\n");
        }
        int SizeX, SizeY, size;
        short int bpp;
        short int planes;
        fseek(filePtr, 18, SEEK_CUR);
        fread(&SizeX, 4, 1, filePtr);
        fread(&SizeY, 4, 1, filePtr);
        size = SizeX * SizeY * 3;
        fread(&bpp, 2, 1, filePtr);
        fread(&planes, 2, 1, filePtr);
        fseek(filePtr, 24, SEEK_CUR);
        int imageSize = 512*512 * 3;
        fread(imgData, sizeof(unsigned char), imageSize, filePtr);
        memcpy(imgDatas[i], imgData, sizeof(unsigned char)*imageSize);
        fclose(filePtr);
        
    }


    
    
    //glBindTexture(GL_TEXTURE_2D,0);
    //glBindTexture( GL_TEXTURE_2D, 0);

    glGenTextures( 6, skytex); //Create a Texture via ID
    for (int i=0; i<skymapCount; i++) {
        glBindTexture( GL_TEXTURE_2D, skytex[i]);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        
//        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_BGR, GL_UNSIGNED_BYTE, imgDatas[i]);
    }

    

    
}

void Skybox::draw() {
    
    int height, length, width = 3000;
    float x=0,y=0/2,z=0;
    int   i,j,vi;
    
    float mapSize = 2000.0f;
    
    float sb_vertices[8][3] = {
        {-mapSize, mapSize-200 ,mapSize}, {-mapSize,mapSize-200 ,-mapSize}, {-mapSize,-mapSize-200, mapSize},{-mapSize, -mapSize-200, -mapSize},{mapSize,mapSize-200, mapSize},
        {mapSize, mapSize-200, -mapSize},{mapSize,-mapSize-200, mapSize},{mapSize,-mapSize-200,-mapSize}};
    
    int sb_texcoords[4][2] = {{0,1},{1,1},{1,0},{0,0}};
    int sb_faces[6][4] = {{1,0,2,3},{3, 2, 6, 7}, {5, 4, 6, 7},
        {4, 0, 2, 6},{1, 5, 7, 3}, {1, 0, 4, 5}};
//    for(i=0;i<6;i++){
//        glBindTexture(GL_TEXTURE_2D, skytex[0]);
//        glBegin (GL_QUADS);
////        glColor3f(0.3, 0.4, 0.1);
//        for(j=0;j<4;j++){
//            vi = sb_faces[i][j];
//            glTexCoord2f(sb_texcoords[j][0], sb_texcoords[j][1]);
//            glVertex3f  (sb_vertices[vi][0],sb_vertices[vi][1],sb_vertices[vi][2]);
//        }
//        glEnd();
//    }
    
    glPushMatrix();
    //glPushAttrib(GL_TEXTURE_BIT);
    glEnable(GL_TEXTURE_2D);
    
    for(i=0;i<6;i++){
    glBindTexture(GL_TEXTURE_2D, skytex[i]);
    glBegin(GL_QUADS);

//    glColor3f(0.9, 0.3, 0.4);

        
        for (int j=0; j< 4; j++) {
            int vertexCount = sb_faces[i][j];
            float x = sb_vertices[vertexCount][0];
            float y = sb_vertices[vertexCount][1];
            float z = sb_vertices[vertexCount][2];
            
            glTexCoord2f(sb_texcoords[j][0], sb_texcoords[j][1]); glVertex3f(x, y, z);
        }
        
        glEnd();

        
    
    
    }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    

}