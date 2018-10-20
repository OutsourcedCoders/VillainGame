#ifndef ENTITY_H
#define ENTITY_H

namespace VillainGame{

	class entity{

	public:
		virtual ALLEGRO_BITMAP* draw() = 0;
		std::pair<double, double> getLocation();
		std::pair<double, double> moveTo(std::pair<double, double> coordinates);
		std::pair<double, double> moveTo(double x, double y);

	protected:
		ALLEGRO_BITMAP* sprite;
		double x;
		double y;
	};
}

#endif //ENTITY_H
