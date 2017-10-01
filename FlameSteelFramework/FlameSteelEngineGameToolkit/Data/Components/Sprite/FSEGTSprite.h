/*
 * FSEGTSprite.h
 *
 *  Created on: Sep 4, 2016
 *      Author: demensdeum
 */

#ifndef DATA_COMPONENTS_SPRITE_FSEGTSPRITE_H_
#define DATA_COMPONENTS_SPRITE_FSEGTSPRITE_H_

#include <FlameSteelCore/FSCObject.h>
#include <string>

#include <memory>

using namespace std;

class FSEGTSprite: public FSCObject {
public:
	FSEGTSprite(shared_ptr<string> spriteFilePath);

	virtual ~FSEGTSprite();

	shared_ptr<string> spriteFilePath;
        
        int width;
        int height;
        
        int framesCount;
        int frameIndex;
        
        int animationTick;
        int animationTickMax;
        
        void updateAnimationTick();
};

#endif /* DATA_COMPONENTS_SPRITE_FSEGTSPRITE_H_ */
