#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include "Deck.h"

using namespace std;

/******************************************************
** function deck::deck();
** description: this functions gets the number of cards and splits it into 13 cards
** Parameters: none
** Pre-conditions: needs the use this
** Post-conditions: functions creates a deck for number of cards
******************************************************/

Deck::Deck(){

    this->n_cards = 52;

    for (int i = 0; i < this->n_cards; ++i){
        
        this->cards[i] = Card(i%13, i/13);
        
    }

}

/******************************************************
** function: shuffle_cards();
** description: this functions shuffles card.
** Parameters: none
** Pre-conditions: functions needs srand(NULL)
** Post-conditions: the functions shuffles the deck
******************************************************/

void Deck::Shuffle_card(){

    srand(time(NULL));

    for(int i = 0; i < 52; i++){

        swap(cards[rand()%52],cards[rand()%52]);
        // cards[i].output_Card();

    }

}

/******************************************************
** function remove_card()
** description: this functions removes the card of the deck.
** Parameters: none
** Pre-conditions: the function points to n_cards.
** Post-conditions: the function returns the cards array with the removed array.
******************************************************/

Card& Deck::remove_card(){
    this->n_cards --;
    return this->cards[this->n_cards];

}

/******************************************************
** function get_n_cards();
** description: this functions the gets the number of cards through the card class
** Parameters: none
** Pre-conditions: functions points to the get_n_cards.
** Post-conditions: this functions returns the number of cards
******************************************************/

int Deck::get_n_cards(){
    cout << this->n_cards; 
    return this->n_cards;
}