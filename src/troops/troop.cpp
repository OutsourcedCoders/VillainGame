#include <allegro5/allegro.h>
#include <utility>
#include <cmath>
#include "troop.h"

namespace VillainGame{
	troop::troop(){
		entity();
		moveSpeed = 1;
		attackRange = 1;
		attackDamage = 2;
		attackSpeed = 1500; //ms
		target = nullptr;
	}

	int troop::changeMoveSpeed(int moveSpeed){
		int lastMoveSpeed = this->moveSpeed;
		this->moveSpeed = moveSpeed;
		return lastMoveSpeed;
	}

	void troop::switchTarget(entity* target){
		this->target = target;
	}

	bool troop::attack(int64_t time){
		if(time - lastAttackTime <= attackSpeed)
			return false;

		int enemyX = target->getLocation().first;
		int enemyY = target->getLocation().second;
		int distanceFromTarget = std::sqrt(std::pow(x - enemyX, 2) + std::pow(y - enemyY, 2));

		if(distanceFromTarget >= attackRange)
			return false;
		target->takeDamage(attackDamage);
		return true;
	}
}
