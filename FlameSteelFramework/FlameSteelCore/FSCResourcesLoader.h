/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSCResourceLoader.h
 * Author: demensdeum
 *
 * Created on March 12, 2017, 9:28 AM
 */

#ifndef FSCRESOURCELOADER_H
#define FSCRESOURCELOADER_H

#include "FSCResource.h"
#include "FSCResourcesManager.h"

class FSCResourcesLoader {
public:
    FSCResourcesLoader();
    FSCResourcesLoader(const FSCResourcesLoader& orig);
    virtual ~FSCResourcesLoader();
    
    virtual void loadURL(shared_ptr<string> url, shared_ptr<FSCResourcesManager> resourcesManager);    
    
private:

};

#endif /* FSCRESOURCELOADER_H */

