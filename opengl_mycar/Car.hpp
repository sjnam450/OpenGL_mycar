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

//#define GL_CALLLIST_CAR     1

#define PI 3.141592653589793238462643

enum CAR_ROTATE{
    LEFT = 0,
    RIGHT = 1
};
class Car {

public:
    Car();
    void move();
    void moveback();
    void rotate();
    void yaw(CAR_ROTATE rotate);
    void init_car();
    void draw_car();
    
    float degree; //x축을 바라보며 1,0,0 방향벡터로 클럭와이즈로 각도계산을 한다
    
    
    Vector3 currentPosition;
    Vector3 directionalVector;
    objLoader *objData;
    GLuint car_opengl;
    float speed;
    
private:
    void rotateMatUtil(Vector3 &retVec, float angle);
    
};

#endif /* Car_hpp */
