/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTGameMap.h
 * Author: demensdeum
 *
 * Created on April 25, 2017, 9:18 AM
 */

#ifndef FSEGTGAMEMAP_H
#define FSEGTGAMEMAP_H

#include <memory>
#include <vector>

#include <FlameSteelCore/FSCObject.h>


#include <FlameSteelCore/FSCObject.h>

using namespace std;

const int FSEGTGameMapWidth = 64;
const int FSEGTGameMapHeight = 64;

class FSEGTGameMap: public FSCObject {
public:
    FSEGTGameMap();
    FSEGTGameMap(const FSEGTGameMap& orig);
    virtual ~FSEGTGameMap();
    
    int width;
    int height;
    
    shared_ptr<FSCObject> getTileAtXY(int tileX, int tileY);
    void setTileAtXY(int tileIndex, int tileX, int tileY);
    
    void addTile(shared_ptr<FSCObject> tile);
    
    int getTileIndexAtXY(int tileX, int tileY);
    
private:

    int map[FSEGTGameMapWidth][FSEGTGameMapHeight];
    
    vector<shared_ptr<FSCObject> > tiles;
    
};

#endif /* FSEGTGAMEMAP_H */

