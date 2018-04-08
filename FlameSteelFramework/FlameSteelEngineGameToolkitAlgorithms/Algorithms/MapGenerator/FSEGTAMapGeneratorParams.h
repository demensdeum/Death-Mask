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

#ifndef FSEGTAMAPGENERATORPARAMS_H
#define FSEGTAMAPGENERATORPARAMS_H

#include <vector>
#include <memory>

#include <FlameSteelCore/FSCObject.h>

using namespace std;

class FSEGTAMapGeneratorParams {
public:
    FSEGTAMapGeneratorParams();
    
    int freeTileIndex;
    int solidTileIndex;
    
    vector<shared_ptr<FSCObject> > tiles;
    
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

#endif

