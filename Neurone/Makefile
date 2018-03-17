all : Neurone.o main.o fonctions.o
	g++ -Wall -std=c++11 Neurone.o main.o fonctions.o -o prog
Neurone.o : Neurone.cpp
	g++ -Wall -std=c++11 -c Neurone.cpp
main.o : main.cpp
	g++ -Wall -std=c++11 -c main.cpp
fonctions.o: fonctions.cpp
	g++ -Wall -std=c++11 -c fonctions.cpp
clean :
	rm *.o prog
