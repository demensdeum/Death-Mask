/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSCResourceLoader.cpp
 * Author: demensdeum
 * 
 * Created on March 12, 2017, 9:28 AM
 */

#include "FSCResourcesLoader.h"
#include <iostream>

using namespace std;

FSCResourcesLoader::FSCResourcesLoader() {
}

FSCResourcesLoader::FSCResourcesLoader(const FSCResourcesLoader& ) {
}

void FSCResourcesLoader::loadURL(shared_ptr<string> , shared_ptr<FSCResourcesManager> ){
    
    cout << "FSCResourcesLoader: loadURL must be overridden." << endl;
    
    exit(1);
}

FSCResourcesLoader::~FSCResourcesLoader() {
}