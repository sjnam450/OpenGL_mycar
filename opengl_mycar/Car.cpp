//
//  Car.cpp
//  opengl_mycar
//
//  Created by sjnam on 11/23/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#include "Car.hpp"


GLuint tex[3];

Car::Car() {
    currentPosition =  Vector3(0, 0, 0);
    directionalVector = Vector3(1, 0, 0);
    speed = 3.0f;
    degree = 0.0f;
    pitch_degree =0.0f;
    totalDistance = 0.0f;
    
    objData = new objLoader();
    objData->load("Police_car.obj");
    
    
    printf("Number of vertices: %i\n", objData->vertexCount);
    printf("Number of vertex normals: %i\n", objData->normalCount);
    printf("Number of texture coordinates: %i\n", objData->textureCount);
    
    
    
    
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
    
}

void Car::move() {
    
    currentPosition.v[0] += directionalVector.v[0] * speed;
    currentPosition.v[2] += directionalVector.v[2] * speed;
    
    totalDistance += speed;
    printf("car pos %f, %f, %f, %f\nd", currentPosition.v[0], currentPosition.v[1], currentPosition.v[2], totalDistance);
}

void Car::moveback() {
    
    currentPosition.v[0] -= directionalVector.v[0] * speed;
    currentPosition.v[2] -= directionalVector.v[2] * speed;
    printf("car pos %f, %f, %f\nd", currentPosition.v[0], currentPosition.v[1], currentPosition.v[2]);
}

void Car::pitch(CAR_ROTATE rotate) {
    if (rotate ==  CAR_ROTATE::UP)
        pitch_degree += 1.5 * 1;
    else if(rotate == CAR_ROTATE::DOWN)
        pitch_degree += 1.5  * -1;
}

// Robot rotation
void Car::yaw(CAR_ROTATE rotate)
{
    if (rotate ==  CAR_ROTATE::LEFT)
        degree += 1.5 * 1;
    else
        degree += 1.5  * -1;
    
    rotateMatUtil(directionalVector, degree);
    directionalVector.normalize(); //Keep vector normalized
    printf("car direct vector %f, %f, %f\nd", directionalVector.v[0], directionalVector.v[1], directionalVector.v[2]);
}

void Car::init_car() {

    int count=0;
    //TGAFILE tgaFile1, tgaFile2, tgaFile3;
    //            objData->materialList[objData->faceList[i]->material_index]->texture_filename;
    


    
    car_opengl=glGenLists(1);
    glNewList(car_opengl, GL_COMPILE);
    {
        glShadeModel(GL_SMOOTH);
//        objData->materialList
//        glMaterialfv(GL_FRONT, GL_AMBIENT, mtlList.at(objList.at(objLoop).material).ambient);
//        glMaterialfv(GL_FRONT, GL_DIFFUSE, mtlList.at(objList.at(objLoop).material).diffuse);
//        glMaterialfv(GL_FRONT, GL_SPECULAR, mtlList.at(objList.at(objLoop).material).specular);
//        glMaterialf(GL_FRONT, GL_SHININESS, mtlList.at(objList.at(objLoop).material).shinyness);
        
        
        
        for (int i=0; i<objData->faceCount; i++) {
            //objData->faceList[i]->
            count++;
            //objData->materialList[objData->faceList[i]->material_index]-> ;
            int texIndex0 = (GLuint)objData->faceList[i]->material_index;
            
            glEnable(GL_TEXTURE_2D);
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

            if (texIndex0 == -1) {
                glBindTexture( GL_TEXTURE_2D, 0);
            }
            else if (texIndex0 == 0){
                glBindTexture(GL_TEXTURE_2D, 1 );
            }

            else if (texIndex0 == 1){
                glBindTexture(GL_TEXTURE_2D, 2 );
            }

            else if (texIndex0 == 2){
                glBindTexture(GL_TEXTURE_2D, 3 );
            }
            else {
                int a;
            }

            glBegin(GL_TRIANGLES);
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
                printf("uv %f, %f, texture in : %d\n", u1, v1, texIndex0);
                

            }
            glVertex3f((GLfloat)objData->vertexList[vertexinde0]->e[0], (GLfloat)objData->vertexList[vertexinde0]->e[1], (GLfloat)objData->vertexList[vertexinde0]->e[2]);
            glNormal3f((GLfloat)objData->normalList[vertexinde0]->e[0], (GLfloat)objData->normalList[vertexinde0]->e[1], (GLfloat)objData->normalList[vertexinde0]->e[2]);
            
            
            
            //glBindTexture( GL_TEXTURE_2D, (GLuint)texIndex1 );
            
            
            if (textureInde1 != -1) {
                
                GLfloat u2 = (GLfloat)objData->textureList[textureInde1]->e[0];
                GLfloat v2 = (GLfloat)objData->textureList[textureInde1]->e[1];
                glTexCoord2f(u2, v2);
                
                
            }
            
            
            glVertex3f((GLfloat)objData->vertexList[vertexinde1]->e[0], (GLfloat)objData->vertexList[vertexinde1]->e[1], (GLfloat)objData->vertexList[vertexinde1]->e[2]);
            glNormal3f((GLfloat)objData->normalList[vertexinde1]->e[0], (GLfloat)objData->normalList[vertexinde1]->e[1], (GLfloat)objData->normalList[vertexinde0]->e[2]);
            //printf("uv %f, %f, texture in : %d\n", u1, v1, texIndex1);

            

            
            
            if (textureInde2 != -1) {
                //glBindTexture( GL_TEXTURE_2D, (GLuint)texIndex2 );
                GLfloat u3 = (GLfloat)objData->textureList[textureInde2]->e[0];
                GLfloat v3 = (GLfloat)objData->textureList[textureInde2]->e[1];
                glTexCoord2f(u3, v3);
                
                
            }
            
            glVertex3f((GLfloat)objData->vertexList[vertexinde2]->e[0], (GLfloat)objData->vertexList[vertexinde2]->e[1], (GLfloat)objData->vertexList[vertexinde2]->e[2]);
            glNormal3f((GLfloat)objData->normalList[vertexinde2]->e[0], (GLfloat)objData->normalList[vertexinde2]->e[1], (GLfloat)objData->normalList[vertexinde2]->e[2]);
            //printf("uv %f, %f, texture in : %d\n", u1, v1, texIndex2);
        
            
            glEnd();
            glDisable(GL_TEXTURE_2D);
            
        }
        printf("vertex cound : %d\n", count);
        
        
    }
    glEndList();
    
}


void Car::SetMaterial2(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{
    
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, shin);
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}

void Car::draw_car() {
    
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    
    //glColor3f(0.2,0.4,0.1);
    glTranslatef(currentPosition.v[0], currentPosition.v[1], currentPosition.v[2]);
    glRotatef(270, 0.0, 1.0 ,0.0);
    
    //this point
    glRotatef(degree, 0.0, 1.0 ,0.0);
    glRotatef(pitch_degree, 0.0, 0.0 ,1.0);

    glScalef(0.1, 0.1, 0.1);
    glCallList(car_opengl);
    //myObject.draw();
    
    glPopMatrix();
}


void Car::rotate() {
    
}


void Car::rotateMatUtil(Vector3 &retVec, float angle) {
    
    float radian = -angle*PI/180.0f ;
    
    Vector3 vec = Vector3(1, 0, 0);
    float tempX = vec[0] * cosf(radian) + vec[2] * -sinf(radian);
    float tempZ = vec[0] * sinf(radian) + vec[2] * cosf(radian);
    vec[0] = tempX;
    vec[2] = tempZ;
    retVec = vec;

}

