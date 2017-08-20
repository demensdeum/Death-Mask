/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMObjectControls.cpp
 * Author: demensdeum
 * 
 * Created on August 20, 2017, 12:38 PM
 */

#include "DMObjectControls.h"

DMObjectControls::DMObjectControls(shared_ptr<FSCObject> object) {
    
    this->object = object;
    
}

DMObjectControls::DMObjectControls(const DMObjectControls& orig) {
}

void DMObjectControls::step(shared_ptr<DMObjectControlsDelegate> delegate) {
    
    
    
}

DMObjectControls::~DMObjectControls() {
}

