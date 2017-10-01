/*
 * FSEGTSprite.cpp
 *
 *  Created on: Sep 4, 2016
 *      Author: demensdeum
 */

#include <FlameSteelEngineGameToolkit/Data/Components/Sprite/FSEGTSprite.h>

FSEGTSprite::FSEGTSprite(shared_ptr<string> spriteFilePath) {

	this->spriteFilePath = spriteFilePath;
        
        width = 0;
        height = 0;
        
        framesCount = 0;
        frameIndex = 0;
        
        animationTick = 0;
        animationTickMax = 0;
}

void FSEGTSprite::updateAnimationTick() {
    
    if (animationTick < animationTickMax) {
        
        animationTick++;
    }
    else {
        
        //swap frame
        
        animationTick = 0;
        
        if (frameIndex < framesCount - 1) {
            
            frameIndex++;

        }
        else {
           
            frameIndex = 0;
            
        }
    }
}

FSEGTSprite::~FSEGTSprite() {
	// TODO Auto-generated destructor stub
}

