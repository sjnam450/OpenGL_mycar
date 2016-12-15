//
//  Track.hpp
//  opengl_mycar
//
//  Created by sjnam on 12/2/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef Track_hpp
#define Track_hpp

#include "Vector3.h"

#define c 3.14/180


class Track {
    
public:
    Track();
    ~Track(void);
    void draw_track(float R1,float R2);
};

#endif /* Track_hpp */
