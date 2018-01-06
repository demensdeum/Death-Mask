/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMGameMap.cpp
 * Author: demensdeum
 * 
 * Created on May 11, 2017, 10:20 AM
 */

#include "DMGameMap.h"

DMGameMap::DMGameMap() {
    
}

void DMGameMap::setObjectIdAtXY(int objectIndex, int x, int y, int layer) {
    
    objectsMap[x][y][layer] = objectIndex;
    
}

int DMGameMap::objectIdAtXY(int x, int y, int layer) {
    
    if (x < 0) {
        
        return DMGameMapNoObjectId;
        
    }
    
    if (y < 0) {
        
        return DMGameMapNoObjectId;
        
    }
    
    if (x >= this->width) {
        
        return DMGameMapNoObjectId;
                
    }
    
    if (y >= this->height) {
        
        return DMGameMapNoObjectId;
        
    }
    
    return objectsMap[x][y][layer];
    
}

void DMGameMap::removeObjectIdAtXY(int x, int y, int layer) {
    
    objectsMap[x][y][layer] = DMGameMapNoObjectId;
}

DMGameMap::~DMGameMap() {
}