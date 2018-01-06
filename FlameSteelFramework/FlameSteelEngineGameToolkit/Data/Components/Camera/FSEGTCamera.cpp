/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTCamera.cpp
 * Author: demensdeum
 * 
 * Created on February 19, 2017, 12:32 PM
 */

//#define DEGREES_TO_RADIANS(degrees)((M_PI * degrees)/180)

#include "FSEGTCamera.h"
#include <math.h>

FSEGTCamera::FSEGTCamera() {
    
    position = make_shared<FSEGTVector>();
    direction = make_shared<FSEGTVector>();
    plane = make_shared<FSEGTVector>();
}

void FSEGTCamera::rotate(float diff) {
    
    direction->rotate(diff);
    plane->rotate(diff);
}

void FSEGTCamera::setPosition(float x, float y) {
    
    position->x = x;
    position->y = y;
    
}

void FSEGTCamera::setRotation(float angle) {
    
    // euler
    
    angle += 180; // invert
    
    reset();
    //rotate(DEGREES_TO_RADIANS(angle));
}

void FSEGTCamera::reset() {
    
        direction->x = -1;
        direction->y = 0;
        
        plane->x = 0;
        plane->y = 0.66;    
}

FSEGTCamera::FSEGTCamera(const FSEGTCamera& ) {
}

FSEGTCamera::~FSEGTCamera() {
}
