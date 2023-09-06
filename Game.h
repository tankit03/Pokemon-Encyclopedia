#ifndef Game_h
#define Game_h 
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>


#include "Deck.h"
#include "Player.h"

class Game {
 private:
   Deck d;
   Player players[2];

 public:
 
   Game();
   void set_hands_player();
   void set_hands_comp();
   void show_p();
   void show_c();
   void player_turn();
   void computer_turn(); 
   void gofish_p();
   void gofish_c();
   int end_game();
   
    // void Print_deck();
    // must have constructors, destructor, accessors, and mutators
};

#endif