/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTGameMap.cpp
 * Author: demensdeum
 * 
 * Created on April 25, 2017, 9:18 AM
 */

#include "FSEGTGameMap.h"

FSEGTGameMap::FSEGTGameMap() {
    
    width = FSEGTGameMapWidth;
    height = FSEGTGameMapHeight;
    
}

FSEGTGameMap::FSEGTGameMap(const FSEGTGameMap& orig) {
}

shared_ptr<FSEGTGameMapTile> FSEGTGameMap::getTileAtXY(int tileX, int tileY) {

    auto tileIndex = this->getTileIndexAtXY(tileX, tileY);
    
    return tiles[tileIndex];

}

void FSEGTGameMap::setTileAtXY(int tileIndex, int tileX, int tileY) {
    
    map[tileX][tileY] = tileIndex;
    
}

int FSEGTGameMap::getTileIndexAtXY(int tileX, int tileY) {
    
    return map[tileX][tileY];
    
}

bool FSEGTGameMap::isTileAtXYSolid(int tileX, int tileY) {
    
    auto tile = this->getTileAtXY(tileX, tileY);
    
    return tile->isSolid;
    
}

void FSEGTGameMap::addTile(shared_ptr<FSEGTGameMapTile> tile) {
    
    tiles.push_back(tile);
    
}

FSEGTGameMap::~FSEGTGameMap() {
}

