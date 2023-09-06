#ifndef pokemon_h
#define pokemon_h
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

struct Pokemon {

    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;

};

struct Pokedex {

    string trainer;
    int num_pokemon;
    Pokemon* dex;

};

void text_file_input(string &gettext);
Pokemon* create_pokemons(int num_p);
void populate_pokemon(Pokemon &Poke, ifstream &file_input);
void populate_pokedex_data(Pokedex &dex , ifstream &finput);
string* create_moves(int size);
void Output_terminal(Pokedex pokt, int num);
void output_file(Pokedex pokf, int num, ofstream &out);
void create_file(string &create_txt, ofstream &output_f);
void dex_input(Pokedex pdex);
void dex_input_file(Pokedex pdexf, ofstream &f_out);
void search_input(Pokedex psea);
void search_input_file(Pokedex psea, ofstream &f_out_s);
void type_input(Pokedex ptype);
void type_input_file(Pokedex ptype, ofstream &type_o);
void Poke_style(Pokedex p, int style_input, int c_input);
void delete_info(Pokedex &pdel);
void print_option(Pokedex pok);
void Poke_again_error(int &go_again_error);

#endif


