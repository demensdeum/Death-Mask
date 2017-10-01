/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTModel.h
 * Author: demensdeum
 *
 * Created on April 19, 2017, 10:59 PM
 */

#ifndef FSEGTMODEL_H
#define FSEGTMODEL_H

#include <FlameSteelCore/FSCObject.h>

#include <string>

class FSEGTModel: public FSCObject {
public:
    FSEGTModel(shared_ptr<string> modelFilePath);
    FSEGTModel(const FSEGTModel& orig);
    virtual ~FSEGTModel();
    
    shared_ptr<string> modelFilePath; 
    
private:


};

#endif /* FSEGTMODEL_H */

