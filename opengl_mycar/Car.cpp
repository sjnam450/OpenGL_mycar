//
//  Car.cpp
//  opengl_mycar
//
//  Created by sjnam on 11/23/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#include "Car.hpp"



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
    
    car_opengl=glGenLists(1);
    glNewList(car_opengl, GL_COMPILE);
    {
        glShadeModel(GL_SMOOTH);
        glBegin(GL_TRIANGLES);
        
        
        //glBindTexture(<#GLenum target#>, <#GLuint texture#>)
//        objData->materialList
//        glMaterialfv(GL_FRONT, GL_AMBIENT, mtlList.at(objList.at(objLoop).material).ambient);
//        glMaterialfv(GL_FRONT, GL_DIFFUSE, mtlList.at(objList.at(objLoop).material).diffuse);
//        glMaterialfv(GL_FRONT, GL_SPECULAR, mtlList.at(objList.at(objLoop).material).specular);
//        glMaterialf(GL_FRONT, GL_SHININESS, mtlList.at(objList.at(objLoop).material).shinyness);
        
        for (int i=0; i<objData->faceCount; i++) {
            //objData->faceList[i]->
            count++;
//            GLfloat x = (GLfloat)objData->vertexList[i]->e[0];
//            GLfloat y = (GLfloat)objData->vertexList[i]->e[1];
//            GLfloat z = (GLfloat)objData->vertexList[i]->e[2];
//            
//            //TODO :: TEXTURE MAPPING
//            
//            glVertex3f(x,y,z);
            
//            GLfloat xn = (GLfloat)objData->normalList[i]->e[0];
//            GLfloat yn = (GLfloat)objData->normalList[i]->e[1];
//            GLfloat zn = (GLfloat)objData->normalList[i]->e[2];
            
            printf("mat inde %d\n", objData->faceList[i]->material_index == 0);
            
            //objData->faceList
            //glver
            int vertexinde0 =  objData->faceList[i]->vertex_index[0];
            int vertexinde1 =  objData->faceList[i]->vertex_index[1];
            int vertexinde2 =  objData->faceList[i]->vertex_index[2];
            int vertexinde3 =  objData->faceList[i]->vertex_index[3];
//            printf("vi : %d, %d, %d, %d\n", vertexinde0, vertexinde1, vertexinde2, vertexinde3);
            
            glVertex3f((GLfloat)objData->vertexList[vertexinde0]->e[0], (GLfloat)objData->vertexList[vertexinde0]->e[1], (GLfloat)objData->vertexList[vertexinde0]->e[2]);

            glVertex3f((GLfloat)objData->vertexList[vertexinde1]->e[0], (GLfloat)objData->vertexList[vertexinde1]->e[1], (GLfloat)objData->vertexList[vertexinde1]->e[2]);

            glVertex3f((GLfloat)objData->vertexList[vertexinde2]->e[0], (GLfloat)objData->vertexList[vertexinde2]->e[1], (GLfloat)objData->vertexList[vertexinde2]->e[2]);
            
            glNormal3f((GLfloat)objData->normalList[vertexinde0]->e[0], (GLfloat)objData->normalList[vertexinde0]->e[1], (GLfloat)objData->normalList[vertexinde0]->e[2]);

            glNormal3f((GLfloat)objData->normalList[vertexinde1]->e[0], (GLfloat)objData->normalList[vertexinde1]->e[1], (GLfloat)objData->normalList[vertexinde0]->e[2]);

            glNormal3f((GLfloat)objData->normalList[vertexinde2]->e[0], (GLfloat)objData->normalList[vertexinde2]->e[1], (GLfloat)objData->normalList[vertexinde2]->e[2]);
        }
        
        //printf("vertex cound : %d\n", count);
        glEnd();
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

    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};    
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glColor4f(0.75f, 0.75f, 0.75f, 1.0f);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMateriali(GL_FRONT, GL_SHININESS, 10);
    
    //glColor3f(0.2,0.4,0.1);
    glTranslatef(currentPosition.v[0], currentPosition.v[1], currentPosition.v[2]);
    glRotatef(270, 0.0, 1.0 ,0.0);
    
    //this point
    //glRotatef(directionalVector.angleSigned(Vector3(1,0,0))*_180_OVER_PI, 0.0, 1.0 ,0.0);
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

