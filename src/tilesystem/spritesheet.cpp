#include <string>
#include <utility>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include "spritesheet.h"

namespace VillainGame{
	spritesheet::spritesheet(std::string filename, int tileWidth, int tileHeight){
		const char* filenameC = filename.c_str();
		rawSpritesheet = al_load_bitmap(filenameC);
		this->tileWidth = tileWidth;
		this->tileHeight = tileHeight;
		heightInTiles = al_get_bitmap_height(this->rawSpritesheet) / this->tileHeight;
		widthInTiles = al_get_bitmap_width(this->rawSpritesheet) / this->tileWidth;
	}

	spritesheet::spritesheet(ALLEGRO_BITMAP* rawSpritesheet, int tileWidth, int tileHeight){
		this->rawSpritesheet = rawSpritesheet;
		this->tileWidth = tileWidth;
		this->tileHeight = tileHeight;
		heightInTiles = al_get_bitmap_height(this->rawSpritesheet) / this->tileHeight;
		widthInTiles = al_get_bitmap_width(this->rawSpritesheet) / this->tileWidth;
	}

	ALLEGRO_BITMAP* spritesheet::getRawSprite(int tileID){
		int tileY = (tileHeight * ((tileID - 1) % heightInTiles)) - 1;
		int tileX = (tileWidth * ((tileID - 1) % widthInTiles)) - 1;
		return al_create_sub_bitmap(rawSpritesheet, tileX, tileY, tileWidth -1, tileHeight - 1);
	}

	ALLEGRO_BITMAP* spritesheet::getRawSprite(int tileNumX, int tileNumY){
		int tileY = tileNumY * tileHeight;
		int tileX = tileNumX * tileWidth;
		return al_create_sub_bitmap(rawSpritesheet, tileX, tileY, tileWidth - 1, tileHeight - 1);
	}

	ALLEGRO_BITMAP* spritesheet::getRawSprite(std::pair<int, int> coordinates){
		return getRawSprite(coordinates.first, coordinates.second);
	}

	tile* spritesheet::getTile(int tileID){
		std::vector<bool> flags = {false, false, false};
		tile* tempTile= new tile(getRawSprite(tileID), tileID, flags);
		return tempTile;
	}

	tile* spritesheet::getTile(int tileNumX, int tileNumY){
		std::vector<bool> flags = {false, false, false};
		int tileID = (tileNumX * widthInTiles) + (tileNumY * heightInTiles);
		tile* tempTile = new tile(getRawSprite(tileNumX, tileNumY), tileID, flags);
		return tempTile;
	}
}
