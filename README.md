# Pokemon Catalog Program

## Overview

Professor Oak needs a Pokemon catalog program to manage the information about the Pokemon he's been discovering. This program will allow users to search for Pokemon data, display it, and even add new Pokemon to the catalog. Here's a detailed description of the program:

## Usage

1. **Initial User Input**:
   - When starting the program, the user will be prompted for the name of the file containing Pokemon information.
   - If the provided file does not exist, the program will display an error message and quit.

2. **Searching and Printing**:
   - Once the program starts, users will be presented with different ways to display Pokedex information.
   - After choosing an option, users can decide whether to print the information to the screen or write it to a file.
   - If writing to a file, users will be prompted for a file name. If the file exists, data will be appended; otherwise, a new file will be created.

3. **Available Options**:
   - **Search by Dex Number**:
     - Users can search for a Pokemon by its Pokedex number.
     - If a matching Pokemon is found, its data will be displayed or written to a file.
     - If no matching Pokemon is found, an error message will be displayed.

   - **Search by Name**:
     - Users can search for a Pokemon by its name.
     - If a matching Pokemon is found, its data will be displayed or written to a file.
     - If no matching Pokemon is found, an error message will be displayed.

   - **Search by Type**:
     - Users can search for Pokemon by type.
     - All Pokemon with the specified type will be displayed or written to a file.
     - If no Pokemon has the requested type, an error message will be displayed.

   - **Add New Pokemon** (Extra Credit - Optional):
     - Users can add a new Pokemon to the catalog.
     - They will be prompted to enter all necessary information for the new Pokemon.
     - The Pokedex will dynamically increase in size to store the new data.

   - **Quit**:
     - Users can exit the program.

4. **Continued Operation**:
   - The program will continue to search and print/write data until the user chooses to quit.

## Program Structure

### Structs

1. **Pokedex Struct**:
   - Used to hold information from the dex.txt file, including the trainer's name, the number of Pokemon, and an array of Pokemon data.

2. **Pokemon Struct**:
   - Used to store information about a single Pokemon, including its Pokedex number, name, type, number of moves, and an array of moves.

### Functions

1. `Pokemon* create_pokemons(int size)`:
   - Dynamically allocates an array of Pokemon objects of the requested size.

2. `void populate_pokedex_data(Pokedex&, ifstream&)`:
   - Fills a Pokedex object with data read from the dex.txt file.

3. `string* create_moves(int size)`:
   - Dynamically allocates an array of moves (strings) of the requested size.

4. `void populate_pokemon(Pokemon&, ifstream&)`:
   - Fills a single Pokemon object with data read from the dex.txt file.

5. `void delete_info(Pokedex&)`:
   - Deletes all dynamically allocated memory used to store Pokemon data.

## Enjoy Managing the Pokemon Catalog!

Have a great time using the Pokemon catalog program to explore Pokemon data, search for your favorites, and even add new Pokemon to the Pokedex (if you're up for the extra challenge)!
