/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UDPSender.cpp
 * Author: demensdeum
 * 
 * Created on August 13, 2017, 8:33 PM
 */

#include "FSSTUDPSender.h"

#ifdef DEATH_MASK_BOOST_ENABLED

#include "boost/asio.hpp"

using namespace boost::asio;

#endif

FSSTUDPSender::FSSTUDPSender() {
}

FSSTUDPSender::FSSTUDPSender(const FSSTUDPSender& ) {
}

void FSSTUDPSender::sendStringTo(shared_ptr<string> , shared_ptr<string> , int ) {

    #ifdef DEATH_MASK_BOOST_ENABLED
    io_service io_service;
    ip::udp::socket socket(io_service);
    ip::udp::endpoint remote_endpoint;

    socket.open(ip::udp::v4());

    remote_endpoint = ip::udp::endpoint(ip::address::from_string(address.get()->c_str()), port);

    auto bufferString = dataString->c_str();
    
    boost::system::error_code err;
    socket.send_to(buffer(bufferString, strlen(bufferString)+1), remote_endpoint, 0, err);

    socket.close();
#endif
}

void FSSTUDPSender::sendStringToDefault(shared_ptr<string> dataString) {
    
    FSSTUDPSender::sendStringTo(dataString, make_shared<string>("127.0.0.1"), 9000);
    
}

FSSTUDPSender::~FSSTUDPSender() {
}