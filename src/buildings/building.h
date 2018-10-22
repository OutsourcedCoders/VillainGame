#ifndef BUILDING_H
#define BUILDING_H

#include "../entity.h"


namespace VillainGame{
	class building{
	public:
		building();
		building(int tileLocation, int actionCooldown);
		void update(int64_t);

	protected:
		int tileLocation;
		int actionCooldown; //ms
		int lastActionTime; //ms
	};
}

#endif // BUILDING_H
