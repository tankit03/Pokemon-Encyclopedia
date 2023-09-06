#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Player.h"

using namespace std;

/******************************************************
** function place_a_card(Card& c)
** description: the function output_cards the all the informations in it.
** Parameters: Card& c
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

void Player::place_a_card(Card& c){
	this->h.add_a_card(c);
	
}

/******************************************************
** function: get_card(Card& one_c);
** description: this functions brings add a card to get card.
** Parameters: Card& one_c
** Pre-conditions: function takes in Card one_c.
** Post-conditions: the functions holds add a card
******************************************************/

void Player::get_card(Card& one_c){

	this->h.add_a_card(one_c);

}

/******************************************************
** function get_n_card();
** description: the function output_cards the all the informations in it.
** Parameters: none
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

int Player::get_n_card(){

	return this->h.get_n_card();

	

}

/******************************************************
** function get_hand();
** description: the function output_cards the all the informations in it.
** Parameters: none
** Pre-conditions: functions has no pre_conditions 
** Post-conditions: the functions outputs output_cards.
******************************************************/

void Player::get_hand(){

	h.output_hand();

}

/******************************************************
** function delete_c(int rank);
** description: the functions deleted the card out of players hand.
** Parameters: none
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions returns remove_card(rank);
******************************************************/

Card Player::delete_c(int rank){

	return this-> h.remove_card(rank);



}

/******************************************************
** function ~player();
** description: the function output_cards the all the informations in it.
** Parameters: none
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions deleted array for player.
******************************************************/

Player::~Player(){

	if(this->books != NULL){
		delete [] this->books;
		this->books = NULL;
	}
}

/******************************************************
** function Player(const Player& m);
** description: the function output_cards the all the informations in it.
** Parameters: const Player& m
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

Player:: Player(const Player &m){

	this->h = m.h;
	this->n_books = m.n_books;

	this->books = new int [this->n_books];

	for(int i = 0; i < this->n_books; ++i){
		this->books[i] = m.books[i];
	}

}

/******************************************************
** function operator=(const Player &a)
** description: the function output_cards the all the informations in it.
** Parameters: const Player &a
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

Player& Player::operator=(const Player &a){

	this->h = a.h;
	this->n_books = a.n_books;

	if(this->books != NULL){
		delete [] this->books;
		this->books = NULL;
	} 

	this->books = new int [this->n_books];

	for(int i = 0; i < this->n_books; ++i){
		this->books[i] = a.books[i];
	}

	return *this;


}

/******************************************************
** function rank_input();
** description: the function gets the rank input.
** Parameters: none
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

int Player::rank_input(){

	
	int input_r;
	cout << "Player, what rank are you fishing for: ";
	cin >> input_r;
	
	return input_r;

}

/******************************************************
** function playerhand_c(int rank_c)
** description: the function output_cards the all the informations in it.
** Parameters: int rank_p
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs 1 or 0.
******************************************************/

int Player::playerhand_c(int rank_p){

	int yes = 0;

	for(int i = 0; i < h.get_n_card(); i++){

		if(rank_p == h.get_rank(i)){

			cout << endl;

			yes++;

		


			return yes;

			break;
		}

	}
}

/******************************************************
** function add_c(int rank, int i )
** description: the function output_cards the all the informations in it.
** Parameters: int rank, int i
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs put
******************************************************/

Card Player::add_c(int rank, int i){

	
	int bruh;
	bruh = h.get_rank(i);

		if(rank == h.get_rank(i)){

			Card put;

			put = h.get_card(i);

			return put;

		}

}

/******************************************************
** function remove_c(int rank);
** description: the function output_cards the all the informations in it.
** Parameters: int rank
** Pre-conditions: functions gets in informations in card
** Post-conditions: the functions outputs output_cards.
******************************************************/

Card Player::remove_c(int rank){

	for(int i = 0; i < h.get_n_card(); i++){

		if(rank == h.get_rank(i)){

			Card rem;

			rem = h.remove_card(rank);

			cout << "This card has been removed" << endl;

			return rem;

		}
	}
}





