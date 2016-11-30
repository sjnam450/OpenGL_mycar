//
//  Car.hpp
//  opengl_mycar
//
//  Created by sjnam on 11/23/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp


#include "Vector3.h"

class Car {

    
    
public:
    Car();
    void move(float speed);
    void rotate(float speed);
    
    Vector3 currentPosition;
    
    
};

#endif /* Car_hpp */
