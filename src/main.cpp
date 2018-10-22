/*
 * main.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: BensMacMini
 */
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "tilesystem/tile.h"
#include "tilesystem/spritesheet.h"
#include "troops/goon.h"

/**
 *
 * @authr Jasonface900
 * @return true if any of the error checks fail, false otherwise.
 *
 */
bool primaryerrorcheck(){
    if(!al_init()){
        std::cerr << "I couldn't initialize Allegro 5!";
        return true;
    }
    if(!al_install_keyboard()){
        std::cerr << "I couldn't install an appropriate keyboard driver!";
        return true;
    }

    if(!al_init_primitives_addon()){
        std::cerr << "I couln't initialize the primitives addon!";
        return true;
    }

    if(!al_init_image_addon()){
		std::cerr << "I couldn't initialize the images addon!";
		return true;
    }
    return false;
}

bool secondaryerrorcheck(ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* evq, ALLEGRO_DISPLAY* disp){
    if(!timer){
        std::cerr << "I couldn't create a timer!";
        return true;
    }

    if(!evq){
        std::cerr << "I couldn't create an event queue!";
        return true;
    }

    if(!disp){
        std::cerr << "I couldn't create a display!";
        return true;
    }

    return false;
}

int main(int argc, char* argv[]){
	//GIT HUB UPDATE COMMENT
    if(primaryerrorcheck()) // for checking stuff that can be initialized without creating an instance of it.
        return 1;

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* evq = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);

    if(secondaryerrorcheck(timer, evq, disp)) // for checking stuff that can only be initialized when created as an instance.
        return 1;

    al_register_event_source(evq, al_get_keyboard_event_source());
    al_register_event_source(evq, al_get_timer_event_source(timer));
    al_register_event_source(evq, al_get_display_event_source(disp));
    ALLEGRO_BITMAP* rawSpritesheet = al_load_bitmap("resources/img/sometile.png");

    VillainGame::spritesheet testSpritesheet(rawSpritesheet, 32, 16);
    VillainGame::tile* testTile = testSpritesheet.getTile(1);

    bool redraw = true;
    bool stop = false;
    ALLEGRO_EVENT event;
    al_start_timer(timer);
    while(true){
        al_wait_for_event(evq, &event);
        switch(event.type){
        case ALLEGRO_EVENT_TIMER:
            //do some fancy game stuff here!
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            stop = true;
            std::cout << "You closed the program regularly!" << std::endl;
            break;
        }

        if(stop){
            break;
        }

        if(redraw && al_is_event_queue_empty(evq)){
            al_clear_to_color(al_map_rgb(255, 0, 0));
            al_draw_bitmap(testTile->draw(), 0, 0, 0);
            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(evq);

    return 0;
}
