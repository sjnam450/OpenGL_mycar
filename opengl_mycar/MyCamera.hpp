//
//  MyCamera.hpp
//  opengl_mycar
//
//  Created by sjnam on 12/1/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef MyCamera_hpp
#define MyCamera_hpp

#include "Vector3.h"

enum CAMERA_MODE {
        WORLD = 0,
        CAR = 1
};


class MyCamera {
    
        
public:
    MyCamera(void);
    MyCamera( float positionX, float positionY, float positionZ,
           float viewX,     float viewY,     float viewZ,
           float upVectorX, float upVectorY, float upVectorZ);
    ~MyCamera(void);
    void set( float positionX, float positionY, float positionZ,
             float viewX,     float viewY,     float viewZ,
             float upVectorX, float upVectorY, float upVectorZ);
    void set( Vector3 position, Vector3 view);
    void setBehindCar(Vector3 carPosition, Vector3 carDirectionalVec);
    void viewDefault();
    
    CAMERA_MODE mode;
    
    
    Vector3 currentPosition;
    Vector3 viewVector;
    Vector3 upVector;
    
};
#endif /* MyCamera_hpp */
