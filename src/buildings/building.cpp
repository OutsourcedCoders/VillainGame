#include <utility>
#include <allegro5/allegro.h>
#include "building.h"

namespace VillainGame{
	building::building(){
		entity();
		tileLocation = 0;
		actionCooldown = 1000; //ms
		lastActionTime = 0; //ms
	}

	building::building(int tileLocation, int actionCooldown){
		entity();
		this->tileLocation = tileLocation;
		this->actionCooldown = actionCooldown;
	}

	void building::update(int64_t time){
		if(time - lastActionTime > actionCooldown)
			lastActionTime = time;
	}

}
