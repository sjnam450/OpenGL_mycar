//
//  TextureLoad.hpp
//  opengl_mycar
//
//  Created by sjnam on 12/3/16.
//  Copyright © 2016 sjnam. All rights reserved.
//

#ifndef TextureLoad_hpp
#define TextureLoad_hpp

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    unsigned char imageTypeCode;
    short int imageWidth;
    short int imageHeight;
    unsigned char bitCount;
    unsigned char *imageData;
} TGAFILE;


class TextureLoad {
    
public:
    bool LoadTGAFile(char *filename, TGAFILE *tgaFile);
    
};

#endif /* TextureLoad_hpp */
