#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include "Game.h"

using namespace std;

/******************************************************
** Program: Driver.cpp
** Author: Tanish Hupare
** Date: 11/07/2022
** Description: This program acts like a directory for Pokemon and has a lot of information regarding all types of Pokemon and it can sort it out through name, type, and their dex number.
** Input: The program takes in information for play again and rank input
** Output: the program run through the game and outputs the ranks & suits of cards of the player game.
******************************************************/


int main()
{
	Game g;
	int play = 0;
	int playagain;

	cout << "Do you want to play in cheat mode? (0-no 1-yes): " << endl;
	cin >> playagain;

	if(playagain == 1){
		do{

			g.show_p();
			g.show_c();
			g.player_turn();
			if(g.end_game() == 0){
				return 0;
			}

			g.computer_turn();
			g.show_c();
			if(g.end_game() == 0){
				return 0;
			}

		}while(play == 0);
	}

	if(playagain ==0){
		g.show_p();
		g.player_turn();
		if(g.end_game() == 0){
			return 0;
		}	

		g.computer_turn();
		if(g.end_game() == 0){
				
			cout << "_________________________________" << endl <<  "Game Over! Thanks for playing Jason. Hope you give me a good grade. Appreciate it G." << endl << "_________________________________";

			return 0;
		}	
	
	}

	

	return 0;

}