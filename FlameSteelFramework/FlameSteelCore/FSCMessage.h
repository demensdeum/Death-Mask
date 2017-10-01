/*
 * FSCMessage.h
 *
 *  Created on: Jul 30, 2016
 *      Author: demensdeum
 */

#ifndef FSCMESSAGE_H_
#define FSCMESSAGE_H_

/*! FSCMessage - class used to send messages between objects */

#include "FSCObject.h"

#include <memory>

using namespace std;

class FSCMessage: public FSCObject {
public:
	FSCMessage(shared_ptr<string> title, shared_ptr<string> text);

	/*! FSCMessage - get message title @return title*/
        
	shared_ptr<string> getTitle();

	/*! FSCMessage - get message text @return text*/
        
	shared_ptr<string> getText();

	virtual ~FSCMessage();

private:
	shared_ptr<string> title;
	shared_ptr<string> text;
};

#endif /* FSCMESSAGE_H_ */
