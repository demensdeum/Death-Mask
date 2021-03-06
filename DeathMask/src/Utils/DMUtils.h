/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMUtils.h
 * Author: demensdeum
 *
 * Created on August 19, 2017, 5:08 PM
 */

#ifndef DMUTILS_H
#define DMUTILS_H

#include <FlameSteelEngineGameToolkit/Data/Components/SurfaceMaterial/SurfaceMaterial.h>
#include <DeathMask/src/Data/Components/GameplayProperties/DMGameplayProperties.h>
#include <DeathMask/src/Data/Components/Controls/DMObjectControlsDelegate.h>
#include <DeathMask/src/Data/Components/Controls/DMObjectControls.h>
#include <DeathMask/src/Data/Components/Item/ItemProperties.h>
#include <memory>

using namespace std;
using namespace DeathMaskGame;
using namespace FlameSteelEngine::GameToolkit;

namespace DeathMaskGame {

class ZombieControls;

};

class FSEGTText;

class DMUtils {
public:
	DMUtils();
	DMUtils(const DMUtils& orig);
	virtual ~DMUtils();
    
	static shared_ptr<DMGameplayProperties> getObjectGameplayProperties(shared_ptr<Object> object);
	static shared_ptr<DMObjectControls> getObjectControls(shared_ptr<Object> object);
	static shared_ptr<ItemProperties> getObjectItemProperties(shared_ptr<Object> object);
	static shared_ptr<FSEGTText> getObjectLabel(shared_ptr<Object> object);
	static shared_ptr<ZombieControls> getObjectZombieControls(shared_ptr<Object> object);
	static shared_ptr<SurfaceMaterial> getWeaponHUDImageSurfaceMaterial(shared_ptr<Object> object);
    
	static void step(shared_ptr<Object> object, shared_ptr<DMObjectControlsDelegate> delegate);
    
private:

};

#endif /* DMUTILS_H */

