#ifndef ENTITY_H
#define ENTITY_H

#include "tilesystem/tile.h"

namespace VillainGame{

	class entity{
	public:
		entity();
		ALLEGRO_BITMAP* draw();
		std::pair<double, double> getLocation();
		std::pair<double, double> moveTo(std::pair<double, double> coordinates);
		std::pair<double, double> moveTo(double x, double y);
		int takeDamage(int damageTaken);
		bool recoverHealth(int hpRecovered);

	protected:
		tile* sprite;
		double x;
		double y;
		int hp, maxhp;
		int cost;
		char team;
	};
}

#endif //ENTITY_H
