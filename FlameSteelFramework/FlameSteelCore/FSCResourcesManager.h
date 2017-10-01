/*
 * FSCResourcesManager.h
 *
 *  Created on: Jan 16, 2017
 *      Author: demensdeum
 */

#ifndef FSCRESOURCESMANAGER_H_
#define FSCRESOURCESMANAGER_H_

#include "FSCObject.h"
#include "FSCResource.h"

#include <memory>
#include <map>


class FSCResourcesManager: public FSCObject {
public:
	FSCResourcesManager();

	shared_ptr<FSCResource> getResourceByName(shared_ptr<string> name);
	void setResourceWithName(shared_ptr<string> name, shared_ptr<FSCResource> resource);

	void clear();

	virtual ~FSCResourcesManager();

private:
	map<string, shared_ptr<FSCResource> > resourcesMap;

};

#endif /* FSCRESOURCESMANAGER_H_ */
