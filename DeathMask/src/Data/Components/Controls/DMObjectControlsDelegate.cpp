/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMObjectControlsDelegate.cpp
 * Author: demensdeum
 * 
 * Created on August 20, 2017, 12:43 PM
 */

#include "DMObjectControlsDelegate.h"

DMObjectControlsDelegate::DMObjectControlsDelegate() {
}

DMObjectControlsDelegate::DMObjectControlsDelegate(const DMObjectControlsDelegate& ) {
}

shared_ptr<Object> DMObjectControlsDelegate::objectsControlsDelegateObjectAt(int , int ) {
    
	return shared_ptr<Object>();
}
    
void DMObjectControlsDelegate::objectsControlsDelegateDidPickObject(shared_ptr<Object> ) {
    
}

void DMObjectControlsDelegate::objectsControlsDelegateObjectDidUpdate(shared_ptr<Object> ) {
    
}

DMObjectControlsDelegate::~DMObjectControlsDelegate() {
}