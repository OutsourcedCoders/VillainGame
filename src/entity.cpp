#include <allegro5/allegro.h>
#include <utility>
#include "entity.h"

namespace VillainGame{

	ALLEGRO_BITMAP* entity::draw(){
	return sprite;
	}

	std::pair<double, double> entity::getLocation(){
		return std::make_pair(x, y);
	}

	std::pair<double, double> entity::moveTo(std::pair<double, double> coordinates){
		std::pair<double, double> lastCoordinates = std::make_pair(x, y);
		this->x = coordinates.first;
		this->y = coordinates.second;
		return lastCoordinates;
	}

	int entity::takeDamage(int damageTaken){
		hp -= damageTaken;
		return hp;
	}

	bool entity::recoverHealth(int hpRecovered){
		if(hp + hpRecovered >= maxhp)
			return false;
		hp += hpRecovered;
		return true;
	}
}
