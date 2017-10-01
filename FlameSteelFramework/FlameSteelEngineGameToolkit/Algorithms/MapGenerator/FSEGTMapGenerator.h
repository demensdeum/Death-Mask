/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTMapGenerator.h
 * Author: demensdeum
 *
 * Created on April 25, 2017, 9:11 AM
 */

#ifndef FSEGTMAPGENERATOR_H
#define FSEGTMAPGENERATOR_H

#include <memory>

#include <FlameSteelCore/FSCObjects.h>

#include <FlameSteelEngineGameToolkit/Data/GameMap/FSEGTGameMap.h>
#include <FlameSteelEngineGameToolkit/Algorithms/MapGenerator/FSEGTMapGeneratorParams.h>

using namespace std;

class FSEGTMapGenerator {
public:
    FSEGTMapGenerator();
    FSEGTMapGenerator(const FSEGTMapGenerator& orig);
    virtual ~FSEGTMapGenerator();
    
    void generate(shared_ptr<FSEGTMapGeneratorParams> params, shared_ptr<FSEGTGameMap> gameMap, shared_ptr<FSCObjects> gameObjects);
    
private:

};

#endif /* FSEGTMAPGENERATOR_H */

