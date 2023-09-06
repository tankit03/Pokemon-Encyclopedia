/******************************************************
** Program: run_pokemon.cpp
** Author: Tanish Hupare
** Date: 10/23/2022
** Description: This program acts like a directory for Pokemon and has a lot of information regarding all types of Pokemon and it can sort it out through name, type, and their dex number.
** Input: The progam will able to take in information from the users choices for dex, style, and type.
** Output: this program will able to output the users pokedex searchs in terminal and also as text file.
******************************************************/

#include "pokemon.h"


int main(){

    string getinput;
    int st_input;
    int size;
    ifstream finput;
    Pokedex p;
    int go_again;
 
    text_file_input(getinput);

    string txt_string = ".txt";
    string file_output = getinput + txt_string;


    file_output.c_str();
   
    finput.open(file_output.c_str());

    if(!finput.is_open()){
        cout << "this file can't be opened, this program will terminate" << endl;
        return 0;
    }

    populate_pokedex_data(p, finput);

    do{

        print_option(p);

        cout << endl;
        cout << "Do you want to search through the Pokedex again ? (1 - yes or 0 - no):";
        cin >> go_again;
        Poke_again_error(go_again);
        

    }while(go_again == 1);

    delete_info(p);

    return 0; 
}