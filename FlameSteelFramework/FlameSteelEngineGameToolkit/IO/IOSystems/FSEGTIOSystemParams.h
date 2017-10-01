/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTIOSystemParams.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 1:29 PM
 */

#ifndef FSEGTIOSYSTEMPARAMS_H
#define FSEGTIOSYSTEMPARAMS_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTObjectsContext.h>

#include <memory>

using namespace std;

class FSEGTIOSystemParams {
public:
    FSEGTIOSystemParams();
    FSEGTIOSystemParams(const FSEGTIOSystemParams& orig);
    virtual ~FSEGTIOSystemParams();
    
    shared_ptr<FSEGTObjectsContext> objectsContext;
    
private:

};

#endif /* FSEGTIOSYSTEMPARAMS_H */

