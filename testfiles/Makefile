 all : fonctions.o Neurone.o main2.o
	g++ -Wall fonctions.o Neurone.o main2.o -o iris
Neurone.o : ../Neurone/Neurone.cpp
	g++ -Wall -c ../Neurone/Neurone.cpp
main2.o : main2.cpp
	g++ -Wall -c main2.cpp
fonctions.o : fonctions.cpp
		g++ -Wall -c fonctions.cpp
clean :
	rm *.o iris
