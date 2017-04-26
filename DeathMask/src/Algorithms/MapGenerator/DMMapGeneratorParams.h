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

class DMMapGeneratorParams: FSEGTMapGeneratorParams {
public:
    DMMapGeneratorParams();
    DMMapGeneratorParams(const DMMapGeneratorParams& orig);
    virtual ~DMMapGeneratorParams();
    
    int freeTileIndex;
    int solidTileIndex;
    
    int maxIterations;
    int maxLineLength;
    
    int maxCursorSize;
    
private:

};

#endif /* DMMAPGENERATORPARAMS_H */

