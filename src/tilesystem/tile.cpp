#include <allegro5/allegro.h>
#include <vector>
#include <iostream>
#include "tile.h"

namespace VillainGame{
	tile::tile(){
		sprite = al_create_bitmap(32, 16);
		std::vector<char> flags = {false, false, false};
		tileID = -1;
	}

	tile::tile(ALLEGRO_BITMAP* sprite, int tileID, std::vector<bool> flags){
		this->sprite = sprite;
		this->flags = flags;
		this->tileID = tileID;
	}

	ALLEGRO_BITMAP* tile::draw(){
		return sprite;
	}
}
