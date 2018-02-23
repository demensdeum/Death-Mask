/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMFactory.cpp
 * Author: demensdeum
 * 
 * Created on May 7, 2017, 9:18 PM
 */

#include "DMFactory.h"
#include "GameplayProperties/DMGameplayProperties.h"

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

DMFactory::DMFactory() {
}

DMFactory::DMFactory(const DMFactory& ) {
}

shared_ptr<FSCObject> DMFactory::makeCorruptedCityObject() {

    auto corruptedCity = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("corrupted city"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/maps/corruptedCity"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);

	return corruptedCity;

}

shared_ptr<FSCObject> DMFactory::makeRevilObject() {

    auto revil = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("revil"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/revil/revil"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);

    auto gameplayProperties = make_shared<DMGameplayProperties>();

    gameplayProperties->setClassIdentifier(make_shared<string>("death mask gameplay properties"));
    gameplayProperties->setInstanceIdentifier(make_shared<string>("death mask gameplay properties"));

    gameplayProperties->setMaxHealth(10);
    gameplayProperties->healFull();

    revil->addComponent(gameplayProperties);

    return revil;
}

shared_ptr<FSCObject> DMFactory::makeMaskObject() {

    auto mask = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("mask"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/mask/mask"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);

    return mask;
}

shared_ptr<FSCObject> DMFactory::makeAdventurerObject() {

    auto revil = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("adventurer"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/revil/revil"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);

    auto gameplayProperties = make_shared<DMGameplayProperties>();

    gameplayProperties->setClassIdentifier(make_shared<string>("death mask gameplay properties"));
    gameplayProperties->setInstanceIdentifier(make_shared<string>("death mask gameplay properties"));

    gameplayProperties->setMaxHealth(10);
    gameplayProperties->healFull();

    revil->addComponent(gameplayProperties);

    return revil;
}

shared_ptr<FSCObject> DMFactory::makeExitObject() {
    
    auto exit = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("exit"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/exit/exit"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);    
    
    return exit;
}

shared_ptr<FSCObject> DMFactory::makeCrate() {
    
    auto crate = FSEGTFactory::makeOnSceneObject(
            make_shared<string>("scene object"),
            make_shared<string>("crate"),
            make_shared<string>(),
            make_shared<string>("./data/graphics/models/crate/crate"),
            0, 0, 0,
            1, 1, 1,
            0, 0, 0,
            0);
    
    return crate;
}

DMFactory::~DMFactory() {
}
