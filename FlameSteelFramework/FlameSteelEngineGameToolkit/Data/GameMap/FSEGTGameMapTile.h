/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTGameMapTile.h
 * Author: demensdeum
 *
 * Created on April 25, 2017, 9:17 AM
 */

#ifndef FSEGTGAMEMAPTILE_H
#define FSEGTGAMEMAPTILE_H

#include <FlameSteelCore/FSCObject.h>

class FSEGTGameMapTile: FSCObject {
public:
    FSEGTGameMapTile();
    FSEGTGameMapTile(const FSEGTGameMapTile& orig);
    virtual ~FSEGTGameMapTile();
    
    bool isSolid;
    
private:

};

#endif /* FSEGTGAMEMAPTILE_H */

