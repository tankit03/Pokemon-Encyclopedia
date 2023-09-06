CC=g++
EXE_FILE=poke_run

all: $(EXE_FILE)

$(EXE_FILE): run_pokemon.o pokemon.h pokemon.cpp
	$(CC) run_pokemon.o pokemon.cpp -o $(EXE_FILE)

driver.o: pokemon.h pokemon.cpp
	$(CC) -c run_pokemon.cpp
clean:
	
	rm -f *.o $(EXE_FILE)