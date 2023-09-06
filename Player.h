#ifndef Player_h
#define Player_h 
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Hand.h"
#include "Card.h"

class Player
{   
private:

	Hand h;
	int n_books;
	int* books;
	
public:
	~Player();
	Player(const Player&);
	Player& operator=(const Player&);

	void place_a_card(Card&);
	void get_card(Card&);
	void get_hand();
	int rank_input();
	int playerhand_c(int);
	Card delete_c(int);
	Card remove_c(int);
	Card add_c(int,int);
	int get_n_card();
};

#endif