###############################################################################
#                                CONFIGURATION                                #
NAME = prog# <- Nom du compilateur
COMPIL = g++# <- Nom du compilateur
FLAGS = -Wall -std=c++11# <- Arguments de compilation pour chaque compilation
LIBRARY = # <- Arguments supplémentaires de compilation finale
###############################################################################
###############################################################################
#                                     MAIN                                    #
all : main common neurone layer reseau
	$(COMPIL) $(FLAGS) Neurone.o main.o fonctions.o Layer.o Reseau.o NeuroneB.o -o $(NAME) $(LIBRARY)
main : main.cpp
	$(COMPIL) $(FLAGS) -c main.cpp
###############################################################################
###############################################################################
#                                    COMMON                                   #
common : fonctions.o
fonctions.o: ./Common/fonctions.cpp
	$(COMPIL) $(FLAGS) -c ./Common/fonctions.cpp
###############################################################################
###############################################################################
#                                   NEURONE                                   #
neurone : Neurone.o NeuroneB.o
Neurone.o : ./Neurone/Neurone.cpp
	$(COMPIL) $(FLAGS) -c ./Neurone/Neurone.cpp
NeuroneB.o : ./Neurone/NeuroneB.cpp
	$(COMPIL) $(FLAGS) -c ./Neurone/NeuroneB.cpp
###############################################################################
###############################################################################
#                                    LAYER                                    #
layer : Layer.o
Layer.o : ./Layer/Layer.cpp
	$(COMPIL) $(FLAGS) -c ./Layer/Layer.cpp
###############################################################################
###############################################################################
#                                   RESEAU                                    #
reseau : Reseau.o
Reseau.o : ./Reseau/Reseau.cpp
	$(COMPIL) $(FLAGS) -c ./Reseau/Reseau.cpp
###############################################################################
###############################################################################
#                                   MODIFS                                    #
clean :
	rm *.o prog
debug: FLAGS += -O0 -g
debug: all
gdb: FLAGS += -O0 -g
gdb: LIBRARY += ; rm *.o ; gdb ./$(NAME)
gdb: all
run: LIBRARY += ; rm *.o ; ./$(NAME)
run: all
###############################################################################
