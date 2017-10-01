/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTCursor.h
 * Author: demensdeum
 *
 * Created on February 19, 2017, 12:42 PM
 */

#ifndef FSEGTCURSOR_H
#define FSEGTCURSOR_H

#include <FlameSteelCore/FSCObject.h>

class FSEGTCursor: FSCObject {
public:
    FSEGTCursor();
    FSEGTCursor(const FSEGTCursor& orig);
    virtual ~FSEGTCursor();
    
    int x;
    int y;
    
private:

};

#endif /* FSEGTCURSOR_H */

