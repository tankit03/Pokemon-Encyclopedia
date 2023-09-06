#ifndef Hand_h
#define Hand_h 
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Card.h"

class Hand {
 
 private:
      Card* cards; // An array of cards in hand
      int n_cards; // Number of cards in the hand.

 public:
      Hand();
      ~Hand();
      Hand(const Hand&);
     Hand& operator=(const Hand&);



      void add_a_card(Card&); 
      void hand_output();
      void output_hand();
      int get_n_card();
      int get_rank(int);
      Card get_card(int);
      Card remove_card(int);
      
 // must have constructors, destructor, accessors, and mutators
};

#endif