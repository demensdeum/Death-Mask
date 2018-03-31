/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTModel.cpp
 * Author: demensdeum
 * 
 * Created on April 19, 2017, 10:59 PM
 */

#include "FSEGTModelReference.h"

FSEGTModelReference::FSEGTModelReference(shared_ptr<string> modelFilePath) {
    
    this->modelFilePath = modelFilePath;
}

FSEGTModelReference::FSEGTModelReference(const FSEGTModelReference& ) {
}

FSEGTModelReference::~FSEGTModelReference() {
}
