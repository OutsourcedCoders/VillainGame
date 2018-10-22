#include <allegro5/allegro.h>
#include <utility>
#include <cmath>
#include "goon.h"

namespace VillainGame{
	goon::goon(){
		ground();
	}

	goon::goon(int hp){
		ground();
		this->hp = hp;
	}

	goon::goon(int hp, int attackDamage, int attackSpeed){
		ground();
		this->hp = hp;
		this->attackDamage = attackDamage;
		this->attackSpeed = attackSpeed;
	}

	goon::goon(int hp, int attackDamage, int attackSpeed, int cost){
		ground();
		this->hp = hp;
		this->attackDamage = attackDamage;
		this->attackSpeed = attackSpeed;
		this->cost = cost;
	}
}
