#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include "Card.h"

using namespace std;

/******************************************************
** function card();
** description: the function initizalizes suits and rank
** Parameters: none
** Pre-conditions: this functions gets the suits and rank from card.
** Post-conditions: initizalizes suits and rank
******************************************************/

Card::Card(){

    this->suit = -1;
    this->rank = -1;

}

/******************************************************
** function Card(int r, int s);
** description: this functions sets the rank and suits in this cpp file.
** Parameters: int r, int s
** Pre-conditions: the functions points the Card.
** Post-conditions: the functions sets the rank to r and s to be called later.
******************************************************/

Card::Card(int r, int s){
	this->rank = r; 
	this->suit = s;
}

/******************************************************
** function get_rank();
** description: functions gets rank from this class.
** Parameters: none
** Pre-conditions: this functions gets the rank
** Post-conditions: this functions return the rank.
******************************************************/

int Card::get_rank(){

    return this->rank;
}

/******************************************************
** function get_suit();
** description: this functions sets the suits.
** Parameters: none
** Pre-conditions: functions gets suit for cpp
** Post-conditions: this functions returns the suits
******************************************************/

int Card::get_suit(){

    return this->suit;

}

/******************************************************
** function set_rank(int rank_c);
** description: this functions sets the rank and suits in this cpp file.
** Parameters: int rank_c
** Pre-conditions: the functions points the rank
** Post-conditions: this functions suits the rank.
******************************************************/

void Card::set_rank(int rank_c){
    this->rank = rank_c;
}

/******************************************************
** function set_suit(int suit_c);
** description: this functions sets the suits
** Parameters: int suit_c
** Pre-conditions: the functions points the Card.
** Post-conditions: the functions sets the suit.
******************************************************/

void Card::set_suit(int suit_c){
    this-> suit = suit_c;
}

/******************************************************
** function map_suit();
** description: this functions returns and sets suits.
** Parameters: none
** Pre-conditions: this functions gets the number
** Post-conditions: this functions ouputs the suit of suits.
******************************************************/

string Card::map_suit(){

    string suit_s;
    suit_s = to_string(get_suit());

    if(this->suit == 0){
        suit_s = "Hearts";
    }
    if(this->suit == 1){
        suit_s = "Diamonds";
    }
    if(this->suit == 2){
        suit_s = "Clubs";
    }
    if(this->suit == 3){
        suit_s = "Spades";
    }
    return suit_s;
}

/******************************************************
** function map_rank();
** description: this functions just sets the rank and suits and number.
** Parameters: none
** Pre-conditions: the functions points the Card.
** Post-conditions: this functions return the rank
******************************************************/

string Card::map_rank(){

    string rank_m;
    rank_m = to_string(get_rank());

    if(rank_m == "11"){
        rank_m = "Jack";
        return rank_m;
    }
    else if(rank_m == "12"){
        rank_m = "Queen";
        return rank_m;
    }
    else if(rank_m == "0"){
        rank_m = "King";
        return rank_m;
    }
    else if(rank_m == "1"){
        rank_m = "Ace";
        return rank_m;
    }
    else{
        return rank_m;
    }

}

/******************************************************
** function output_card();
** description: this functions sets the rank and suits in this cpp file.
** Parameters: none
** Pre-conditions: this functions outputs the output_Card();
** Post-conditions: this functions ouputs the suits and rank.
******************************************************/

void Card::output_Card(){

    cout << endl << "Suit: " << map_suit() << endl << "Rank: " << map_rank() << endl;

}
