//
//  Tree.hpp
//  opengl_mycar
//
//  Created by sjnam on 12/14/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "objLoader.h"
#include "Vector3.h"

class Tree {
    
    objLoader *objData;
    
public:
    Tree();
    void draw();
    void setPos(float x, float y, float z);
    
private:
    Vector3 curPos;

};

#endif /* Tree_hpp */
