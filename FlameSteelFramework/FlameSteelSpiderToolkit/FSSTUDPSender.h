/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UDPSender.h
 * Author: demensdeum
 *
 * Created on August 13, 2017, 8:33 PM
 */

#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <memory>
#include <string>

using namespace std;

class FSSTUDPSender {
public:
    FSSTUDPSender();
    FSSTUDPSender(const FSSTUDPSender& orig);
    virtual ~FSSTUDPSender();
    
    static void sendStringTo(shared_ptr<string> dataString, shared_ptr<string> address, int port);
    static void sendStringToDefault(shared_ptr<string> dataString);
    
private:

};

#endif /* UDPSENDER_H */

