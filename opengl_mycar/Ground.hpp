//
//  Ground.hpp
//  opengl_mycar
//
//  Created by HuhYoonseok on 2016. 12. 15..
//  Copyright © 2016년 sjnam. All rights reserved.
//

#ifndef Ground_hpp
#define Ground_hpp

#include <stdio.h>

#include <stdio.h>
#include "TextureLoad.hpp"

class Ground {
    
    TextureLoad texLoad2;
    
public:
    Ground();
    void draw();
};


#endif /* Ground_hpp */
