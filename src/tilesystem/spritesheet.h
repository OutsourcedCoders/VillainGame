#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "tile.h"

namespace VillainGame{
	class spritesheet{
	public:
		spritesheet(std::string filename, int tileWidth, int tileHeight);
		spritesheet(ALLEGRO_BITMAP* rawSpritesheet, int tileWidth, int tileHeight);
		ALLEGRO_BITMAP* getRawSprite(int tileID);
		ALLEGRO_BITMAP* getRawSprite(int x, int y);
		ALLEGRO_BITMAP* getRawSprite(std::pair<int, int> coordinates);
		tile* getTile(int tileID);
		tile* getTile(int tileNumX, int tileNumY);
		tile* getTile(std::pair<int, int> coordinates);

	private:
		ALLEGRO_BITMAP* rawSpritesheet;
		int tileWidth;
		int tileHeight;
		int widthInTiles;
		int heightInTiles;
	};
}

#endif // SPRITESHEET_H
