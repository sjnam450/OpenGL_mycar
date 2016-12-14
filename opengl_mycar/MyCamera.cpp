//
//  MyCamera.cpp
//  opengl_mycar
//
//  Created by sjnam on 12/1/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#include "MyCamera.hpp"


MyCamera::MyCamera(void)
{    
    //set(0,0,0,1,0,0,0,1,0); //Default
    set(10.0f, 5.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);  //sjnam default
    zoom = 1;
}

MyCamera::~MyCamera(void)
{
}

MyCamera::MyCamera( float positionX, float positionY, float positionZ,
               float viewX,     float viewY,     float viewZ,
               float upVectorX, float upVectorY, float upVectorZ)
{
    set(  positionX,  positionY,  positionZ,
        viewX,      viewY,      viewZ,
        upVectorX,  upVectorY,  upVectorZ);
}

void MyCamera::set( float positionX, float positionY, float positionZ,
                 float viewX,     float viewY,     float viewZ,
                 float upVectorX, float upVectorY, float upVectorZ)
{
    //
    Vector3 Position    = Vector3(positionX, positionY, positionZ);
    Vector3 View        = Vector3(viewX, viewY, viewZ);
    Vector3 UpVector    = Vector3(upVectorX, upVectorY, upVectorZ);
    
    //
    currentPosition = Position;
    viewVector     = View;
    upVector = UpVector;
}

void MyCamera::set( Vector3 position, Vector3 view)
{
    
    currentPosition = position;
    viewVector     = view;
    upVector = Vector3(0,1,0);
}

void MyCamera::setBehindCar(Vector3 carPosition, Vector3 carDirectionalVec, float degree) {
    float radian = -degree*PI/180.0f ;
    gluLookAt (carPosition.v[0]-cos(radian)*60, 30, carPosition.v[2]-sinf(radian)*60,
               carPosition.v[0] ,  0, carPosition.v[2],
               0.0f, 1.0f, 0.0f );
   
}

void MyCamera::viewDefault() {
    gluLookAt (2000*zoom, 2000.0f*zoom, 2000.0f*zoom, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );
}
