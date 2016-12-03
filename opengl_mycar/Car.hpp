//
//  Car.hpp
//  opengl_mycar
//
//  Created by sjnam on 11/23/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#ifndef _180_OVER_PI
#define  _180_OVER_PI   57.29577951308232087665461840231273527024
#endif


#include "Vector3.h"
#include "objLoader.h"
#include "TextureLoad.hpp"


//const GLfloat WhiteColor4[]  = { 1.0, 1.0, 1.0, 1.0 };
//const GLfloat BlackColor4[]  = { 0.0, 0.0, 0.0, 1.0 };
//const GLfloat Gray7Color4[]  = { 0.7, 0.7, 0.7, 1.0 };
//const GLfloat Gray5Color4[]  = { 0.5, 0.5, 0.5, 1.0 };
//const GLfloat Gray4Color4[]  = { 0.4, 0.4, 0.4, 1.0 };


#define PI 3.141592653589793238462643

enum CAR_ROTATE{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3
};
class Car {

public:
    Car();
    void move();
    void moveback();
    void rotate();
    void yaw(CAR_ROTATE rotate);
    void pitch(CAR_ROTATE rotate);
    void init_car();
    void draw_car();
    
    void SetMaterial2(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[]);
    
    float degree; //x축을 바라보며 1,0,0 방향벡터로 클럭와이즈로 각도계산을 한다
    float pitch_degree;
    float totalDistance;
    
    Vector3 currentPosition;
    Vector3 directionalVector;
    objLoader *objData;
    GLuint car_opengl;
    float speed;
    TextureLoad texLoad;
    
private:
    void rotateMatUtil(Vector3 &retVec, float angle);
    
};

#endif /* Car_hpp */
