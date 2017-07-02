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

static int DMGameMapNoObjectId = -1;

class DMGameMap: public FSEGTGameMap {
public:
    DMGameMap();
    DMGameMap(const DMGameMap& orig);
    virtual ~DMGameMap();
    
    shared_ptr<FSCObject> revilObject;
    shared_ptr<FSCObject> exitObject;
    
    void setObjectIdAtXY(int objectId, int x, int y);    
    
    int objectIdAtXY(int x, int y);
    void removeObjectIdAtXY(int x, int y);    
    
private:

    int objectsMap[FSEGTGameMapWidth][FSEGTGameMapHeight];
    
};

#endif /* DMGAMEMAP_H */

