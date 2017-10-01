/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTText.h
 * Author: demensdeum
 *
 * Created on March 26, 2017, 8:13 PM
 */

#ifndef FSEGTTEXT_H
#define FSEGTTEXT_H

#include <FlameSteelCore/FSCObject.h>

#include <string>
#include <memory>

using namespace std;

class FSEGTText : public FSCObject {
public:
    FSEGTText();
    FSEGTText(const FSEGTText& orig);
    virtual ~FSEGTText();
    
    shared_ptr<string> fontResourceIdentifier;
    shared_ptr<string> text;
    
private:

};

#endif /* FSEGTTEXT_H */

