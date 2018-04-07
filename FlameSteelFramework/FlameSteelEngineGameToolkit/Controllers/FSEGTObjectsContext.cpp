/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTObjectsController.cpp
 * Author: demensdeum
 * 
 * Created on April 30, 2017, 8:17 PM
 */

#include "FSEGTObjectsContext.h"

FSEGTObjectsContext::FSEGTObjectsContext() {
}

void FSEGTObjectsContext::removeAllObjects() {  
    
    objects->removeAllObjects();
    
    for (auto subscriber : subscribers) {
        
        subscriber->objectsContextAllObjectsRemoved(shared_from_this());
        
    }    
}

void FSEGTObjectsContext::addObject(shared_ptr<FSCObject> object) {
    
    objects->addObject(object);
    
    for (auto subscriber : subscribers) {
        
        subscriber->objectsContextObjectAdded(shared_from_this(), object);
        
    }
}

void FSEGTObjectsContext::updateObject(shared_ptr<FSCObject> object) {
    
    for (auto subscriber : subscribers) {
        
        subscriber->objectsContextObjectUpdate(shared_from_this(), object);
        
    }    
}

void FSEGTObjectsContext::removeObject(shared_ptr<FSCObject> ) {
    
}

void FSEGTObjectsContext::subscribe(shared_ptr<FSEGTObjectContextDelegate> delegate) {
    
    subscribers.push_back(delegate);
    
}

void FSEGTObjectsContext::unsubscribe(shared_ptr<FSEGTObjectContextDelegate> delegate) {
    
    for (uint i = 0; i < subscribers.size(); i++) {
        
        auto subscriber = subscribers.at(i);
        
        if (subscriber.get() == delegate.get()) {
         
            subscribers.erase(subscribers.begin(),subscribers.begin() + 1);
            
        }
    }
}

FSEGTObjectsContext::~FSEGTObjectsContext() {
}