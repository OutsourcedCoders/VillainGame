#ifndef TROOP_H
#define TROOP_H

namespace VillainGame{
	class troop :public entity{
	public:
		bool attack(int64_t time);
		int changeMoveSpeed(int moveSpeed);
		void switchTarget(entity* target);


	protected:
		int moveSpeed;
		int attackRange;
		int attackDamage;
		int attackSpeed;
		int lastAttackTime;
		entity* target;

	private:

	};
}

#endif // TROOP_H
