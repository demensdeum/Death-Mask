#ifndef DEATHMASK_DEFINED
#define DEATHMASK_DEFINED

namespace DeathMaskGame {
	
    namespace Difficulty {
    
        enum Difficulty {

            easy,
            normal,
            hard

        };
        
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

namespace WeaponType {

	enum WeaponType {

		pistol,
		shotgun,
		uzi,
		assaultRifle,
		gsd,
		count

	};

};

};

#endif
