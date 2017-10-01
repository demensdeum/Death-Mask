/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTIOSDLSystemParams.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 2:41 PM
 */

#ifndef FSEGTIOSDLSYSTEMPARAMS_H
#define FSEGTIOSDLSYSTEMPARAMS_H

#include <memory>

#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOSystemParams.h>

using namespace std;

class FSEGTIOGenericSystemParams: public FSEGTIOSystemParams {
public:
    FSEGTIOGenericSystemParams();
    FSEGTIOGenericSystemParams(const FSEGTIOGenericSystemParams& orig);
    virtual ~FSEGTIOGenericSystemParams();
    
    shared_ptr<string> title;
    
    int width;
    int height;
    
private:

};

#endif /* FSEGTIOSDLSYSTEMPARAMS_H */

