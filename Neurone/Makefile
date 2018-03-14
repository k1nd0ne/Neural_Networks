all : Neurone.o main.o fonctions.o
	g++ -Wall Neurone.o main.o fonctions.o -o prog 
Neurone.o : Neurone.cpp
	g++ -Wall -c Neurone.cpp 
main.o : main.cpp
	g++ -Wall -c main.cpp 
fonctions.o: fonctions.cpp
	g++ -Wall -c fonctions.cpp
clean :
	rm *.o prog
