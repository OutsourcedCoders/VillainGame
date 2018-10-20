#include <allegro5/allegro.h>
#include <utility>
#include "entity.h"

namespace VillainGame{
	std::pair<double, double> entity::getLocation(){
		return std::make_pair(x, y);
	}

	std::pair<double, double> entity::moveTo(std::pair<double, double> coordinates){
		this->x = coordinates.first;
		this->y = coordinates.second;
	}
}
