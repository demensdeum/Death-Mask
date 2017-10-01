/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTObjectContextDelegate.h
 * Author: demensdeum
 *
 * Created on May 1, 2017, 10:40 AM
 */

#ifndef FSEGTOBJECTCONTEXTDELEGATE_H
#define FSEGTOBJECTCONTEXTDELEGATE_H

#include <memory>

using namespace std;

class FSCObject;
class FSEGTObjectsContext;

class FSEGTObjectContextDelegate {
public:
    FSEGTObjectContextDelegate();
    FSEGTObjectContextDelegate(const FSEGTObjectContextDelegate& orig);
    virtual ~FSEGTObjectContextDelegate();
    
    virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
    virtual void objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
    virtual void objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context);
    
private:

};

#endif /* FSEGTOBJECTCONTEXTDELEGATE_H */

