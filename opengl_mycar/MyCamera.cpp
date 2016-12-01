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
    set(0,0,0,1,0,0,0,1,0); //Default
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
