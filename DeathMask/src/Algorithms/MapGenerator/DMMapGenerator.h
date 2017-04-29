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

#include <FlameSteelEngineGameToolkit/Algorithms/MapGenerator/FSEGTMapGenerator.h>
#include <DeathMask/src/Algorithms/MapGenerator/DMMapGeneratorParams.h>

class DMMapGenerator: FSEGTMapGenerator {
public:
    DMMapGenerator();
    DMMapGenerator(const DMMapGenerator& orig);
    virtual ~DMMapGenerator();
    
    virtual shared_ptr<FSEGTGameMap> generate(shared_ptr<DMMapGeneratorParams> params);
    
private:

    void drawFreeTilesAtXY(shared_ptr<FSEGTGameMap> gameMap, int cursorX, int cursorY, int minCursorSize, int maxCursorSize, int freeTileIndex);
};

#endif /* DMMAPGENERATOR_H */

