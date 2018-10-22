#ifndef TILE_H
#define TILE_H

#include <vector>

class spritesheet;

namespace VillainGame{
	class tile{
	public:
		tile();
		tile(ALLEGRO_BITMAP* sprite, int tileID, std::vector<bool> flags);
		ALLEGRO_BITMAP* draw();


	protected:
		ALLEGRO_BITMAP* sprite;
		int tileID;
		int w = 32;
		int h = 16;
		std::vector<bool> flags;
		//flag1 = collidable
		//flag2 = liquid
		//flag3 = does damage
	};
}

#endif // TILE_H
