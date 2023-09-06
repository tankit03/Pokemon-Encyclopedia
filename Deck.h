#ifndef Deck_h
#define Deck_h 
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <string>

#include "Card.h"

class Deck {

private:
    Card cards[52]; //A full deck of cards
    int n_cards; // Number of cards remaining in the deck.
public:
    Deck();
    Card& remove_card();
    void Shuffle_card();
    int get_n_cards();
    // must have constructors, destructor, accessors, and mutators
};

#endif