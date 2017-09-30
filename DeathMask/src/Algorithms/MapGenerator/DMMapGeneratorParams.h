/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMMapGeneratorParams.h
 * Author: demensdeum
 *
 * Created on April 25, 2017, 10:34 AM
 */

#ifndef DMMAPGENERATORPARAMS_H
#define DMMAPGENERATORPARAMS_H

#include <FlameSteelEngineGameToolkit/Algorithms/MapGenerator/FSEGTMapGeneratorParams.h>
#include <FlameSteelFramework/FlameSteelEngineGameToolkit/Data/GameMap/FSEGTGameMapTile.h>

#include <vector>

using namespace std;

class DMMapGeneratorParams: FSEGTMapGeneratorParams {
public:
    DMMapGeneratorParams();
    DMMapGeneratorParams(const DMMapGeneratorParams& orig);
    virtual ~DMMapGeneratorParams();
    
    int freeTileIndex;
    int solidTileIndex;
    
    vector<shared_ptr<FSEGTGameMapTile> > tiles;
    
    int maxIterations;
    int maxLineLength;
    
    int minCursorSize;
    int maxCursorSize;
    
    int minFreeSpace;
    int maxFreeSpace;
    
    int difficulty;
    int gameplayObjectRespawnChance;
    
private:

};

#endif /* DMMAPGENERATORPARAMS_H */

