/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMMapGenerator.h
 * Author: demensdeum
 *
 * Created on April 25, 2017, 10:33 AM
 */

#ifndef DMMAPGENERATOR_H
#define DMMAPGENERATOR_H

#include "DMMapGeneratorParams.h"
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>
#include <DeathMask/src/Data/GameMap/DMGameMap.h>

class DMMapGenerator {
public:
    DMMapGenerator();
    virtual ~DMMapGenerator();
    
    static shared_ptr<FSEGTGameMap> generate(shared_ptr<DMMapGeneratorParams> params, shared_ptr<FSEGTObjectsContext> objectsContext);

private:
    static void drawFreeTilesAtXY(shared_ptr<FSEGTGameMap> gameMap, shared_ptr<DMMapGeneratorParams> params, int cursorX, int cursorY);
};

#endif /* DMMAPGENERATOR_H */

