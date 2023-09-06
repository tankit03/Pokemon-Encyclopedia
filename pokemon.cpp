#include "pokemon.h"


/******************************************************
** function text_file_input(string &gettext
** description: this function gets text file and stores it into this functions.
** Parameters: string gettext
** Pre-conditions: the string name has to be declared in int main
** Post-conditions: then this function can be passed through reference.
******************************************************/

void text_file_input(string &gettext){

    cout << "Please input file name with Pokedex (don't type txt after file name): ";
    getline(cin, gettext);


}

/******************************************************
** function Pokemon* create_pokemons(int num_p)
** description: this functions is creating a dynamic function for the Pokemon struct which holds the dex.
** Parameters: int num_p
** Pre-conditions: this functions is passed through the struct of Pokemon and also through the main
** Post-conditions: this function then return a dynamic array of Poke_array.
******************************************************/

Pokemon* create_pokemons(int num_p){

    Pokemon* Poke_array = new Pokemon[num_p];

    return Poke_array;

}

/******************************************************
** function populate_pokemon(Pokemon &Poke, ifstream &file_input)
** description: this functions is reading through the dex txt file and storing it in a dynamic array.
** Parameters: Pokemon &Poke, ifstream &file_input 
** Pre-conditions: this functions is passed through the struct of Pokemon and also through the main
** Post-conditions: the function outputs the information thats stored in the struct.
******************************************************/

void populate_pokemon(Pokemon &Poke, ifstream &file_input);

/******************************************************
** function populate_pokedex_data(Pokedex &dex , ifstream &finput)
** description: this functions is reading through the dex txt file and storing it in a dynamic array into the dex directory.
** Parameters: Pokedex &dex , ifstream &finput
** Pre-conditions: this functions is passed through the struct of Pokemon and also through the main.
** Post-conditions: this function is storing the file input to size of pokemon and storing the array into the dex directory.
******************************************************/

void populate_pokedex_data(Pokedex &dex , ifstream &finput){

    int size_pokemon;
    finput >> size_pokemon;

    cout << "size of Pokemon: " << size_pokemon << endl;

    Pokemon* Poke_array =  create_pokemons(size_pokemon);

    dex.dex = Poke_array;
    dex.num_pokemon = size_pokemon;

    

    for(int i = 0; i < size_pokemon; i++){
        populate_pokemon(dex.dex[i],finput);
    }
}

/******************************************************
** function string* create_moves(int size)
** description: this functions is creating a dynamic array for create_move.
** Parameters: int size.
** Pre-conditions: this functions holds the dynamic array in the structs.
** Post-conditions: This function is creating a dynamic array for moves_array.
******************************************************/

string* create_moves(int size){

string* moves_array = new string[size];
return moves_array;

}

/******************************************************
** function populate_pokemon(Pokemon &Poke, ifstream &file_input)
** description: this function reads the information through the txt file and holds that information in the Pokemon struct.
** Parameters: Pokemon &Poke, ifstream &file_input
** Pre-conditions: this functions holds the dynamic array in the structs.
** Post-conditions: this function puts all the information in struct.
******************************************************/


void populate_pokemon(Pokemon &Poke, ifstream &file_input){

    file_input >> Poke.dex_num;
    file_input >> Poke.name;
    file_input >> Poke.type;
    file_input >> Poke.num_moves;

    string *num_moves = create_moves(Poke.num_moves);
    Poke.moves = num_moves;

    for( int i = 0; i < Poke.num_moves; i++){
        file_input >> Poke.moves[i];
    }

    cout << "The Dex Number: " << Poke.dex_num << endl;
    cout << "Pokemon: " << Poke.name << endl;
    cout << "type: " << Poke.type << endl; 
    cout << "Number of moves: " << Poke.num_moves << endl;
    
    for(int i = 0; i < Poke.num_moves; i++){
        cout << Poke.moves[i] << " ";
        cout << endl;
    }

    cout << endl;   

}

/******************************************************
** function Output_terminal(Pokedex pokt, int num)
** description: This function outputs the users picks in the terminal.
** Parameters: Pokedex pokt, int num
** Pre-conditions: this function needs to be declared in the main and struct
** Post-conditions: this function puts all the information in struct of Pokedex in the terminal.
******************************************************/

void Output_terminal(Pokedex pokt, int num){

    cout << endl;

    cout << "The Dex Number: " << pokt.dex[num].dex_num << endl;
    cout << "Pokemon: " << pokt.dex[num].name << endl;
    cout << "type: " << pokt.dex[num].type << endl; 
    cout << "Number of moves: " << pokt.dex[num].num_moves << endl;

    for(int i = 0; i < pokt.dex[num].num_moves; i++){
        cout << pokt.dex[num].moves[i] << " ";
        cout << endl;
    }
    cout << endl;
    

}

/******************************************************
** function output_file(Pokedex pokf, int num, ofstream &out)
** description: This function outputs the users picks in the text file.
** Parameters: Pokedex pokf, int num, ofstream &out
** Pre-conditions: this function needs to be declared in the main and struct.
** Post-conditions: this function puts all the information in struct of Pokedex in the text file.
******************************************************/



void output_file(Pokedex pokf, int num, ofstream &out){

    out << "The Dex Number: " << pokf.dex[num].dex_num << endl;
    out << "Pokemon: " << pokf.dex[num].name << endl;
    out << "type: " << pokf.dex[num].type << endl; 
    out << "Number of moves: " << pokf.dex[num].num_moves << endl;

    for(int i = 0; i < pokf.dex[num].num_moves; i++){
        out << pokf.dex[num].moves[i] << " ";
        out << endl;
    }

    out << endl;
}

/******************************************************
** function create_file(string &create_txt, ofstream &output_f)
** description: This function helps create a file and then its able to output the file.
** Parameters: string &create_txt, ofstream &output_f
** Pre-conditions: this function needs to be declared in the main and struct and also ofstream.
** Post-conditions: this functions creates a file and stores it into the directory.
******************************************************/

void create_file(string &create_txt, ofstream &output_f){

    cout << "You're now creating a file, please name it: ";
    cin.ignore();
    getline(cin, create_txt);

    string text = ".txt";
    
    string output_comb = create_txt + text;

    output_f.open(output_comb.c_str(), ios :: app);

    
    if(!output_f.is_open()){
        cout << "This file had error" << endl;
    }
}

/******************************************************
** function dex_input(Pokedex pdex)
** description: This function helps output the dex input from the user to the terminal
** Parameters: Pokedex pdex
** Pre-conditions: this function needs to be declared in the main.
** Post-conditions: this functions puts out what the user stuff in the output terminals.
******************************************************/

void dex_input(Pokedex pdex){
    
    int d_input;
    cin >> d_input;
        
    for(int i = 0; i < pdex.num_pokemon; i++){       

        if(d_input == pdex.dex[i].dex_num){
            Output_terminal(pdex, i);
           
        }
    }

    if((d_input >= pdex.num_pokemon)){
        cout << endl;
        cout << "no such type of dex input in Pokedex" << endl;
    }
}

/******************************************************
** function dex_input_file(Pokedex pdexf, ofstream &f_out)
** description: This function helps output the dex input from the user to the file.
** Parameters: Pokedex pdexf, ofstream &f_out
** Pre-conditions: this function needs to be declared in the main.
** Post-conditions: this functions puts out what the user stuff in the output file.
******************************************************/

void dex_input_file(Pokedex pdexf, ofstream &f_out){

    int dx_input;
    cin >> dx_input;

    for(int i = 0; i < pdexf.num_pokemon; i++){

        if(dx_input == pdexf.dex[i].dex_num){
            output_file(pdexf, i, f_out);    
         
        }
    }    

    if((dx_input >= pdexf.num_pokemon)){
        cout << endl;
        cout << "no such type of dex input in Pokedex" << endl;
    }

}

/******************************************************
** function search_input(Pokedex psea)
** description: This function helps output the name input from the user to the termnial.
** Parameters: Pokedex psea
** Pre-conditions: this function needs to be declared in the main.
** Post-conditions: this functions puts out what the user stuff in the output terminal.
******************************************************/

void search_input(Pokedex psea){

    string name_input;
    cin.ignore();
    getline(cin, name_input);
    int no_name = 0;
    
    

    for(int i = 0; i < psea.num_pokemon; i++){
        
        if(name_input == psea.dex[i].name){
            Output_terminal(psea, i);
            break;
        }  
        no_name++;
    }

    cout << no_name << endl;
    
    if( no_name == psea.num_pokemon){

        cout << endl;
        cout << "The inputed name doesn't work" << endl;
            
    }
}

/******************************************************
** function search_input_file(Pokedex psea, ofstream &f_out_s)
** description: This function helps output the name input from the user to the file.
** Parameters: Pokedex psea
** Pre-conditions: this function needs to be declared in the main.
** Post-conditions: this functions puts out what the user stuff in the output file.
******************************************************/

void search_input_file(Pokedex psea, ofstream &f_out_s){

    string sea_input;
    
    getline(cin, sea_input);
    int size;
    
    cout << sea_input << endl;

    for(int i = 0; i < psea.num_pokemon; i++){

        if(sea_input == psea.dex[i].name){
            output_file(psea, i, f_out_s);
            break;   
        }
        size++;
    }
    if(size == psea.num_pokemon){
        cout << endl;
        cout << "The inputed name doesn't work" << endl;
    }        
}

/******************************************************
** function search_input(Pokedex ptype)
** description: This function helps output the type input from the user to the file.
** Parameters: Pokedex ptype
** Pre-conditions: this function needs to be declared in the main.
** Post-conditions: this functions puts out what the user stuff in the output file.
******************************************************/

void type_input(Pokedex ptype){
    
    string type_input;
    cin.ignore();
    getline(cin, type_input);
    int size;

    for(int i = 0; i < ptype.num_pokemon; i++){

        if(type_input == ptype.dex[i].type){
            Output_terminal(ptype, i);
             
        }
        if(!(type_input == ptype.dex[i].type)){
            size++;
        }
    }
    if((size == ptype.num_pokemon)){
        cout << endl;
        cout << "The inputed type doesn't work" << endl;
    }
}

/******************************************************
** function type_input(Pokedex ptype, ofstream &type_o)
** description: This function helps output the name input from the user to the file.
** Parameters: Pokedex ptype, ofstream &type_o
** Pre-conditions: this function needs to be declared in the int main
** Post-conditions: this functions puts out what the user stuff in the output file.
******************************************************/

void type_input_file(Pokedex ptype, ofstream &type_o){

    string type_input;
    int size;
    
    getline(cin, type_input);
    cout << type_input << endl;

    for(int i = 0; i < ptype.num_pokemon; i++){

        if(type_input == ptype.dex[i].type){
            output_file(ptype, i, type_o);   
        }
        if(!(type_input == ptype.dex[i].type)){
            size++;
        }
        
    }
    if((size == ptype.num_pokemon)){
        cout << endl;
        cout << "The inputed type doesn't work" << endl;
    }        
}

/******************************************************
** function Poke_style(Pokedex p, int style_input, int c_input)
** description: this functions helps the user direct themselves into all the styles.
** Parameters: Pokedex p, int style_input, int c_input
** Pre-conditions: this function needs to be declared in the int main and also through the structs.
** Post-conditions: this functions helps the user direct themselves into all the styles.
******************************************************/

void Poke_style(Pokedex p, int style_input, int c_input){

    string create_txt;
    ofstream file;

    cout << "Which format do you want to search through the Pokedex" << endl; 
    cout << "1. Search by dex number" << endl;
    cout << "2. Search by name" << endl;
    cout << "3. Search by type" << endl;
    cout << "Input here: ";
    cin >> style_input;

    if(c_input == 1){
        create_file(create_txt, file);
    }

    cout << endl;

    switch(style_input){
        case 1:{

            if(c_input == 0){
                cout << "Please input the dex number: ";
                dex_input(p);
            }
            if(c_input == 1){  
                cout << "Please input the dex number: ";
                dex_input_file(p, file);
            }

        break;
        };

        case 2:{
            
            if(c_input == 0){
                cout << "Please input a name: ";
                search_input(p);
            }
            if(c_input == 1){
                cout << "Please input a name: "; 
                search_input_file(p, file);
            }
            break;
        };
        case 3:{
            if(c_input == 0){
                cout << "Please input a type: ";
                type_input(p);
            }
            if(c_input == 1){
                cout << "Please input a type: ";
                type_input_file(p, file);

            }
            break;
        };
    }
}

/******************************************************
** function delete_info(Pokedex &pdel)
** description: this functions helps delete the memeorey allocated to the heap of dynamic memeory.
** Parameters: Pokedex &pdel
** Pre-conditions: this function needs to go through the structs.
** Post-conditions: this functions deletes the dynamic memeory from the struct.
******************************************************/

void delete_info(Pokedex &pdel){

    for(int i = 0; i < pdel.num_pokemon; i++){

        delete [] pdel.dex[i].moves;
        pdel.dex[i].moves = NULL;
    }

    delete [] pdel.dex;
    pdel.dex = NULL;

}

/******************************************************
** function  print_option(Pokedex pok)
** description: this functions go into the case for 0 and 1 to print terminal and file.
** Parameters: Pokedex pok
** Pre-conditions:  this function needs to be declared in the int main and also through the structs.
** Post-conditions: this functions go into the case for 0 and 1 to print terminal and file.
******************************************************/

void print_option(Pokedex pok){

    int st_input;

    cout << "Welcome to The Pokedox " << endl;

    cout << endl;

    int choice_input;
    cout << "Do you want to print it on a terminal (Type 0) or output it as written file (Type 1): ";
    cin >> choice_input;

        switch(choice_input){
            case 0: 
                cout << "Print on terminal" << endl;
                Poke_style(pok,st_input, choice_input);
                
                break;
            case 1:
                cout << "Print this out as a text file" << endl;
                Poke_style(pok,st_input, choice_input);
                break;
        }
}

/******************************************************
** function  Poke_again_error(int &go_again_error)
** description: this functions go into the case for 0 and 1 to print terminal and file.
** Parameters: int &go_again_error.
** Pre-conditions:  this function needs to be decalred in int main.
** Post-conditions: this function outputs the right input the do while loop.
******************************************************/

void Poke_again_error(int &go_again_error){

    while( go_again_error != 0 && go_again_error != 1){
        cout << "This is the wrong input please type 1(yes) or 0(no): ";
        cin >> go_again_error;
        cin.clear();
    }
}