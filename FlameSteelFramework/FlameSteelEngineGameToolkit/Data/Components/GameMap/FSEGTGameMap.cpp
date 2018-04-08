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

static const int FSEGTGameMapNoMapTile = -1;

FSEGTGameMap::FSEGTGameMap() {
    
    width = FSEGTGameMapWidth;
    height = FSEGTGameMapHeight;
    
}

FSEGTGameMap::FSEGTGameMap(const FSEGTGameMap& ) {
}

shared_ptr<FSCObject> FSEGTGameMap::getTileAtXY(int tileX, int tileY) {

    auto tileIndex = this->getTileIndexAtXY(tileX, tileY);
    
	if (tileIndex == FSEGTGameMapNoMapTile) {

		return shared_ptr<FSCObject>();

	}

	unsigned int unsignedTileIndex = tileIndex;

	if (unsignedTileIndex >= tiles.size()) {

		return shared_ptr<FSCObject>();

	}

    return tiles[tileIndex];

}

void FSEGTGameMap::setTileAtXY(int tileIndex, int tileX, int tileY) {
    
    map[tileX][tileY] = tileIndex;
    
}

int FSEGTGameMap::getTileIndexAtXY(int tileX, int tileY) {
    
	if (tileX < 0) {

		return FSEGTGameMapNoMapTile;

	}

	if (tileX >= width) {

		return FSEGTGameMapNoMapTile;

	}

	if (tileY < 0) {

		return FSEGTGameMapNoMapTile;

	}

	if (tileY >= height) {

		return FSEGTGameMapNoMapTile;

	}

    return map[tileX][tileY];
    
}

void FSEGTGameMap::addTile(shared_ptr<FSCObject> tile) {
    
    tiles.push_back(tile);
    
}

FSEGTGameMap::~FSEGTGameMap() {
}
