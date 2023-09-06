#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include "Hand.h" 

using namespace std;

/******************************************************
** function Hand();
** description: the function initizalizes n_card.
** Parameters: none
** Pre-conditions: this functions gets n_cards and cards.
** Post-conditions: initizalizes N-cards and cards.
******************************************************/

Hand::Hand(){
	this->n_cards = 0;
	this->cards = NULL;
}

/******************************************************
** function get_n_card();
** description: the function n_cards
** Parameters: none
** Pre-conditions: this functions gets the n_cards.
** Post-conditions: this functions returns n_cards.
******************************************************/

int Hand::get_n_card(){

	return n_cards;

}

/******************************************************
** function get_card();
** description: the function get_cards and array.
** Parameters: none
** Pre-conditions: This functions returns array of cards.
** Post-conditions: returns cards[i]
******************************************************/

Card Hand::get_card(int i){

	return this->cards[i];

}

/******************************************************
** function Hand(const Hand& h);
** description: the function is aoo and is copy constructor.
** Parameters: const Hand& h
** Pre-conditions: this functions takes n_cards.
** Post-conditions: this functions returns h.cards[i]
******************************************************/

Hand::Hand(const Hand& h){

	this->n_cards = h.n_cards;

	this->cards = new Card [this->n_cards];
	for(int i = 0; i < this->n_cards; i++){

		this->cards[i] = h.cards[i];

	}

}

/******************************************************
** function card();
** description: the function initizalizes suits and rank
** Parameters: none
** Pre-conditions: this functions gets the suits and rank from card.
** Post-conditions: initizalizes suits and rank
******************************************************/

Hand& Hand::operator=(const Hand& h){

	this->n_cards = h.n_cards;

	if(this->cards != NULL){

		delete[] this->cards;

	}

	this->cards = new Card [this->n_cards];

	for(int i = 0; i < this->n_cards; i++){

		this->cards[i] = h.cards[i];

	}
	return *this;
}

/******************************************************
** function get_rank(int in)
** description: the function gets the rank.
** Parameters: int in
** Pre-conditions: this functions gets rank.
** Post-conditions: this functions return the rank
******************************************************/

int Hand::get_rank(int in){

	return this->cards[in].get_rank();

}

/******************************************************
** function Hand();
** description: the function initizalizes suits and rank
** Parameters: none
** Pre-conditions: this functions gets the suits and rank from card.
** Post-conditions: initizalizes suits and rank
******************************************************/

Hand::~Hand() {
	if (this->cards != NULL){
		delete [] this->cards;
		this->cards = NULL;
	}
}

/******************************************************
** function add_a_card(Card& c);
** description: the function initizalizes suits and rank
** Parameters: Card& c
** Pre-conditions: this functions gets in informations of cards and adds to array
** Post-conditions: functions shows the dynamic array.
******************************************************/

void Hand::add_a_card(Card& c){
	//allocate a new array of Card objects with the size + 1
	Card* new_arr = new Card [this->n_cards + 1];

	

	//copy all objects from the old array (cards) into the new array
	for (int i = 0; i < this->n_cards; ++i)
	{
		new_arr[i] = this->cards[i]; // AOO of Card 
	}

	//add the new Card object c into index n_cards
	new_arr[this->n_cards] = c;

	//free the cards array (old array)
	if(this->cards != NULL){
		delete [] this->cards;
	}
	//set cards array to the new array
	this->cards = new_arr;

	//increment the n_cards
	this->n_cards++;
}

/******************************************************
** function output_hand();
** description: the function output_cards the all the informations in it.
** Parameters: none
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

void Hand::output_hand(){

	for(int i = 0; i < this->n_cards; i++){

		
		this->cards[i].output_Card();

		

	}
}

/******************************************************
** function remove_card(int rank)
** description: this functions removes the card from the deck and the hand.
** Parameters: int rank
** Pre-conditions: this funcitons gets the rank input
** Post-conditions: the functions removes the card.
******************************************************/

Card Hand::remove_card(int rank){

		int i = 0;
		
		

		while(i < this->n_cards){
			if(cards[i].get_rank() == rank){
				if(i < (this->n_cards - 1)){
					for(int j = i; j < (n_cards - 1); j++){
						this->cards[j] = this->cards[j+1];
					}
				}
				this->n_cards--;
			}
			else i++;
		}
}


