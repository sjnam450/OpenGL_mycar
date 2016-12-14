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

Skybox::Skybox() {
    
    //load texture
    
    std::vector<std::string> skyboxFiles = {"Daylight_Box_Back.bmp", "Daylight Box_Bottom.bmp", "Daylight Box_Front.bmp", "Daylight Box_Left.bmp", "Daylight Box_Right.bmp", "Daylight Box_Top.bmp"};

    unsigned char* imgData;
    FILE *filePtr;
    filePtr = fopen("Daylight Box_Top.bmp", "rb");
    if (filePtr == NULL)
    {
        printf("error\n");
    }
    //fseek(filePtr, 54, SEEK_CUR);
//    file = fopen(filePtr, "rb");
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

    
    int skymapCount = 6; //정육면체
//    TGAFILE tgaFiles[skymapCount];
//    for (int i=0; i<skymapCount; i++) {
//        TGAFILE tgaFile;
//        texLoad.LoadTGAFile((char *)skyboxFiles[i].c_str(), &tgaFile);
//        //tex[i] = i;
//        printf("tga file name : %s\n", (char *)skyboxFiles[i].c_str());
//        memcpy(&tgaFiles[i], &tgaFile, sizeof(TGAFILE));
//    }
    
    int imageSize = 512*512 * 3;
    imgData = (unsigned char*)malloc(sizeof(unsigned char)*imageSize);
    

    // Read the image data.
    fread(imgData, sizeof(unsigned char), imageSize, filePtr);

    fclose(filePtr);
    
    //glBindTexture(GL_TEXTURE_2D,0);
    //glBindTexture( GL_TEXTURE_2D, 0);
    glGenTextures( 6, skytex); //Create a Texture via ID
    for (int i=0; i<skymapCount; i++) {
        //glGenTextures( 0, &tex[i]); //Create a Texture via ID
        //glGenTextures( 1, &tex[i]); //Create a Texture via ID
        glBindTexture( GL_TEXTURE_2D, skytex[i]);
        //GL_BGRA_EXT
        //GL_RG2
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        
        
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData );
        
    }

    
}

void Skybox::draw() {
    
    int height, length, width = 3000;
    float x=0,y=0/2,z=0;
    int   i,j,vi;
    
    float sb_vertices[8][3] = {
        {500,500,-500},{500,500,+500},{500,-500,-500},{500,-500,+500},{-500,500,+500},
        {-500,500,-500},{-500,-500,+500},{-500,-500,-500}};
    
    int sb_texcoords[4][2] = {{1,1},{1,0},{0,0},{0,1}};
    int sb_faces[6][4] = {{3,2,1,0},{4,6,7,5},{0,4,5,3},
        {6,1,2,7},{0,1,6,4},{5,7,2,3}};
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

      glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glBindTexture(GL_TEXTURE_2D, 9);
//    glColor3f(0.9, 0.3, 0.4);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, +500.0, -500.0);
    
    glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 500.0, +500.0);
    
    glTexCoord2f(1.0, 1.0); glVertex3f(0.0, -500.0, 500.0);
    
    glTexCoord2f(1.0, 0.0); glVertex3f(0, -500.0, -500.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    

}