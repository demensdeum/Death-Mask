#ifndef DEATHMASK_DEFINED
#define DEATHMASK_DEFINED

namespace DeathMaskGame {
	
	enum class Difficulty {

		easy,
		normal,
		hard	

	};

	enum ItemType {

		weapon,
		supply,
		questItem,
		synergyItem,
		deathMask,
		count
    
	};

	enum CreatureType {

		unknown,
		living,
		ghost,
		undead

	};

};

#endif