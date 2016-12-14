//
//  Skybox.hpp
//  opengl_mycar
//
//  Created by sjnam on 12/13/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef Skybox_hpp
#define Skybox_hpp


#include <stdio.h>
#include "TextureLoad.hpp"

class Skybox {
    
    TextureLoad texLoad;
    
public:
    Skybox();
    void draw();
};

#endif /* Skybox_hpp */
