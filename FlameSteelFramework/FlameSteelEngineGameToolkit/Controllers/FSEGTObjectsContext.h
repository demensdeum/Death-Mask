/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTObjectsController.h
 * Author: demensdeum
 *
 * Created on April 30, 2017, 8:17 PM
 */

#ifndef FSEGTOBJECTSCONTROLLER_H
#define FSEGTOBJECTSCONTROLLER_H

#include <memory>

#include <FlameSteelCore/FSCObjects.h>
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectContextDelegate.h>

using namespace std;

class FSEGTObjectsContext : public std::enable_shared_from_this<FSEGTObjectsContext> {
public:
    FSEGTObjectsContext();
    virtual ~FSEGTObjectsContext();
    
    shared_ptr<FSCObjects> objects;
    
    void removeAllObjects();
    
    void addObject(shared_ptr<FSCObject> object);
    void updateObject(shared_ptr<FSCObject> object);
    void removeObject(shared_ptr<FSCObject> object);
    
    void subscribe(shared_ptr<FSEGTObjectContextDelegate> delegate);
    void unsubscribe(shared_ptr<FSEGTObjectContextDelegate> delegate);
    
private:

    vector<shared_ptr<FSEGTObjectContextDelegate> > subscribers;
    
};

#endif /* FSEGTOBJECTSCONTROLLER_H */

