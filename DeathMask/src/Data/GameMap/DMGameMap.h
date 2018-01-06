/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameMap.h
 * Author: demensdeum
 *
 * Created on May 11, 2017, 10:20 AM
 */

#ifndef DMGAMEMAP_H
#define DMGAMEMAP_H

#include <FlameSteelEngineGameToolkit/Data/GameMap/FSEGTGameMap.h>

static const int DMGameMapNoObjectId = -1;

static const int DMGameMapMaxLayers = 2;

static const int DMFloorLayer = 0;
static const int DMGameObjectsLayer = 1;

class DMGameMap: public FSEGTGameMap {
public:
    DMGameMap();
    virtual ~DMGameMap();
    
    shared_ptr<FSCObject> revilObject;
    shared_ptr<FSCObject> exitObject;
    
    void setObjectIdAtXY(int objectId, int x, int y, int layer);    
    
    int objectIdAtXY(int x, int y, int layer);
    void removeObjectIdAtXY(int x, int y, int layer);
    
private:

    int objectsMap[FSEGTGameMapWidth][FSEGTGameMapHeight][DMGameMapMaxLayers];
    
};

#endif /* DMGAMEMAP_H */

