#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Game.h"


using namespace std;

/******************************************************
** function Game();
** description: functions gets rank from this class.
** Parameters: none
** Pre-conditions: this functions sets the hands for player
** Post-conditions: this functions sets the hands for comp.
******************************************************/

Game::Game(){
	
	set_hands_player();
	set_hands_comp();
}

/******************************************************
** function set_hand_player
** description: functions gets rank from this class.
** Parameters: none
** Pre-conditions: this functions gets the remove card
** Post-conditions: this functions return remove card
******************************************************/

void Game::set_hands_player(){

	d.Shuffle_card();

	for(int i = 0; i < 7; i++){
		
		Card one = this->d.remove_card();
		this->players[0].get_card(one);
		


	}

}

/******************************************************
** function get_rank();
** description: functions gets rank from this class.
** Parameters: none
** Pre-conditions: this functions gets the rank
** Post-conditions: this functions return the rank.
******************************************************/

int Game::end_game(){
	int temp = this->d.get_n_cards();
	return temp;
}

/******************************************************
** function set_hands_comp();
** description: sets shuffle cards.
** Parameters: none
** Pre-conditions: this functions show shows shuffle cards
** Post-conditions: this functions return the player array
******************************************************/

void Game::set_hands_comp(){

	d.Shuffle_card();

	for(int i = 0; i < 7; i++){

		Card two = this->d.remove_card();
		this->players[1].get_card(two);
		
	}

}

/******************************************************
** function show_p();
** description: functions shows player.
** Parameters: none
** Pre-conditions: this shows player
** Post-conditions: this functions shows player show.
******************************************************/

void Game::show_p(){


	cout << endl;
	cout << "this is the Player's hand: " << endl;

	players[0].get_hand();

}


/******************************************************
** function show_c();
** description: functions plays as computer hand.
** Parameters: none
** Pre-conditions: this functions gets the computer.
** Post-conditions: this functions outputs for computer.
******************************************************/

void Game::show_c(){

	cout << endl;
	cout << "this is the Computer's hand: " << endl;

	players[1].get_hand();

}


/******************************************************
** function player_turn();
** description: functions plays as player turn.
** Parameters: none
** Pre-conditions: this functions gets the player.
** Post-conditions: this functions outputs for player.
******************************************************/

void Game::player_turn(){

	int rank_input=0;
	int check=0;

	do{
	
		rank_input = players[0].rank_input();

	}while(players[0].playerhand_c(rank_input)==0);

	check = players[0].playerhand_c(rank_input);
	cout << check << endl;

	if(1 == players[1].playerhand_c(rank_input)){

		for(int i = 0; i < players[1].get_n_card();i++){
				
			Card a;
			a = players[1].add_c(rank_input,i);

			if(a.get_rank() == rank_input){

				players[0].get_card(a);

			}
		}
		players[1].remove_c(rank_input);

		cout << "The computer has the rank that you requested for" << endl;
	}else{

		cout << "The computer does not have the card, Go Fish" << endl;
		gofish_p();

	}
}

/******************************************************
** function computer_turn();
** description: functions plays as computer turn.
** Parameters: none
** Pre-conditions: this functions gets the computer.
** Post-conditions: this functions outputs for computer.
******************************************************/

void Game::computer_turn(){

  int rank_return=0;
  int check = 0;
  int tempp =0;
  int tempc = 0;
  srand(time(NULL));

  cout << endl;

  cout << "Computer's turn" << endl;
	for(int i=1;i<13;i++){
		tempc = players[0].playerhand_c(i);
		tempp = players[1].playerhand_c(i);
		
		if((tempp==1) && (tempc==1)){
			rank_return = i;
			
			break;
		}
	}
	
	// cout << "RANK RETURN BEFORE IF STATEMENT" << rank_return << endl;
	if(rank_return == 0){
		do{
			// cout << "RANK RETURN BEFORE RAND" << rank_return << endl;
			rank_return = rand()%12+1;
			// cout << "Computer, what rank are you fishing for: " << rank_return << endl;
			check = players[1].playerhand_c(rank_return);

		}while(players[1].playerhand_c(rank_return)==0);
	}
	// cout << "RANK AFTER IF STATEMENT" << rank_return << endl;

	check = players[0].playerhand_c(rank_return);
	//cout << check << endl;

	cout << "Computer requested for the rank: " << rank_return << endl;
	

	if(check == players[0].playerhand_c(rank_return)){

		for(int i = 0; i < players[0].get_n_card();i++){
				
			Card b;
			b = players[0].add_c(rank_return,i);

			if(b.get_rank() == rank_return){

				players[1].get_card(b);

			}
		}
		players[0].remove_c(rank_return);

		cout << "You have the rank computer requested for" << endl;
	}else{

		cout << "The player does not have the card, computer has to Go Fish" << endl;
		gofish_c();

	}

}

/******************************************************
** function gofish_p();
** description: remove card for player.
** Parameters: none
** Pre-conditions: this functions gets the rank
** Post-conditions: this functions remove_card and delete 
******************************************************/

void Game:: gofish_p(){

	Card deck_r = d.remove_card();
	players[0].get_card(deck_r);

}

/******************************************************
** function gofish_c();
** description: remove card for computer.
** Parameters: none
** Pre-conditions: this functions gets the rank
** Post-conditions: this functions remove_card and delete 
******************************************************/

void Game::gofish_c(){

	Card deck_rc = d.remove_card();
	players[0].get_card(deck_rc);	


}
