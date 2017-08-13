/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTIOFSGLInputController.h
 * Author: demensdeum
 *
 * Created on August 12, 2017, 8:06 PM
 */

#ifndef FSEGTIOFSGLINPUTCONTROLLER_H
#define FSEGTIOFSGLINPUTCONTROLLER_H

#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>

class FSEGTIOFSGLInputController: public FSEGTInputController {
public:
    FSEGTIOFSGLInputController();
    FSEGTIOFSGLInputController(const FSEGTIOFSGLInputController& orig);
    virtual ~FSEGTIOFSGLInputController();
    
    virtual void pollKey(); 
    
private:

};

#endif /* FSEGTIOFSGLINPUTCONTROLLER_H */

