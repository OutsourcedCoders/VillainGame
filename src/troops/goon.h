#ifndef GOON_H
#define GOON_H

#include "ground.h"

namespace VillainGame{
	class goon: public ground{
	public:
		goon();
		goon(int hp);
		goon(int hp, int attackDamage,int attackSpeed);
		goon(int hp, int attackDamage, int attackSpeed, int cost);
	};
}

#endif // GOON_H
