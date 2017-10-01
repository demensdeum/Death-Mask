/*
 * FSCMessage.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: demensdeum
 */

#include "FSCMessage.h"

FSCMessage::FSCMessage(shared_ptr<string> title, shared_ptr<string> text) {
    
	this->title = title;
	this->text = text;
        
}

shared_ptr<string> FSCMessage::getTitle() {
    
	return this->title;
}

shared_ptr<string> FSCMessage::getText() {
    
	return this->text;
}

FSCMessage::~FSCMessage() {
	// TODO Auto-generated destructor stub
}
