all : Neurone.o main.o fonctions.o Layer.o Reseau.o NeuroneB.o
	g++ -Wall Neurone.o main.o fonctions.o Layer.o Reseau.o NeuroneB.o -o prog
Neurone.o : ./Neurone/Neurone.cpp
	g++ -Wall -std=c++11 -c ./Neurone/Neurone.cpp
Layer.o : ./Layer/Layer.cpp
	g++ -Wall -std=c++11 -c ./Layer/Layer.cpp
main.o : main.cpp
	g++ -Wall -std=c++11 -c main.cpp
fonctions.o: ./Common/fonctions.cpp
	g++ -Wall -c ./Common/fonctions.cpp
Reseau.o : ./Reseau/Reseau.cpp
	g++ -Wall -std=c++11 -c ./Reseau/Reseau.cpp
NeuroneB.o : ./Neurone/NeuroneB.cpp
	g++ -Wall -std=c++11 -c ./Neurone/NeuroneB.cpp
clean :
	rm *.o prog
