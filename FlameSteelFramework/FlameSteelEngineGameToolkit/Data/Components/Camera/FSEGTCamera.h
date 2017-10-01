/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTCamera.h
 * Author: demensdeum
 *
 * Created on February 19, 2017, 12:32 PM
 */

#ifndef FSEGTCAMERA_H
#define FSEGTCAMERA_H

#include <FlameSteelEngineGameToolkit/Data/Components/Vector/FSEGTVector.h>

#include <memory>

class FSEGTCamera: FSCObject {
public:
    FSEGTCamera();
    FSEGTCamera(const FSEGTCamera& orig);
    virtual ~FSEGTCamera();
    
    shared_ptr<FSEGTVector> position;
    shared_ptr<FSEGTVector> direction;
    shared_ptr<FSEGTVector> plane;
    
    void rotate(float diff);
    
    void setPosition(float x, float y);
    void setRotation(float angle);
    
    void reset();
    
private:

};

#endif /* FSEGTCAMERA_H */

