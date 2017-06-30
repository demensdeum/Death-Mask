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

void DMGameMap::setObjectIdAtXY(int objectIndex, int x, int y) {
    
    objectsMap[x][y] = objectIndex;
    
}

int DMGameMap::objectIdAtXY(int x, int y) {
    
    return objectsMap[x][y];
    
}

void DMGameMap::removeObjectIdAtXY(int x, int y) {
    
    objectsMap[x][y] = DMGameMapNoObjectId;
}

DMGameMap::DMGameMap(const DMGameMap& orig) {
}

DMGameMap::~DMGameMap() {
}

