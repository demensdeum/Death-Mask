/*
 * FSEGTRenderer.h
 *
 *  Created on: Aug 6, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTRENDERER_H_
#define FSEGTRENDERER_H_

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOSystem.h>
#include <FlameSteelCore/FSCObject.h>

#include <memory>

using namespace std;

class FSEGTRenderer : public FSCObject, public FSEGTObjectContextDelegate {
public:
    FSEGTRenderer();

    virtual void initialize();

    virtual void render(shared_ptr<FSEGTGameData> gameData);

    virtual void beforeStop();

    virtual void blankScreen();

    virtual void updateScreen();

    shared_ptr<FSEGTIOSystem> ioSystem;

    virtual ~FSEGTRenderer();

    virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);

    virtual void addRenderID(int id);
    
    virtual void cleanRenderIDs();
};

#endif /* FSEGTRENDERER_H_ */
