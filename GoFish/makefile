# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

fish: go_fish.o player.o deck.o card.o
	g++ -o fish go_fish.o player.o deck.o card.o

go_fish.o: go_fish.cpp player.h deck.h card.h
	g++ -c go_fish.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

deck.o: deck.cpp deck.h
	g++ -c deck.cpp

card.o: card.cpp card.h
	g++ -c card.cpp