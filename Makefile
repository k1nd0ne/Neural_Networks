###############################################################################
#                                CONFIGURATION                                #
NAME = launcher# <- Nom du compilateur
COMPIL = g++# <- Nom du compilateur
FLAGS = -Wall -std=c++11# <- Arguments de compilation pour chaque compilation
LIBRARY = # <- Arguments supplémentaires de compilation finale
###############################################################################
###############################################################################
#                                     MAIN                                    #
all : main common neurone layer reseau settings option optionTab type
	$(COMPIL) $(FLAGS) Settings.o Neurone.o main.o fonctions.o Layer.o Reseau.o NeuroneB.o FonctionActivation.o InputLayer.o Option.o OptionTab.o Type.o -o $(NAME) $(LIBRARY);
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
#                                    SETTINGS                                   #
settings : Settings.o
Settings.o: ./Settings/Settings.cpp
	$(COMPIL) $(FLAGS) -c ./Settings/Settings.cpp
###############################################################################
###############################################################################
#                                   NEURONE                                   #
neurone : Neurone.o NeuroneB.o FonctionActivation.o
Neurone.o : ./Neurone/Neurone.cpp
	$(COMPIL) $(FLAGS) -c ./Neurone/Neurone.cpp
NeuroneB.o : ./Neurone/NeuroneB.cpp
	$(COMPIL) $(FLAGS) -c ./Neurone/NeuroneB.cpp
FonctionActivation.o : ./Neurone/FonctionActivation.cpp
	$(COMPIL) $(FLAGS) -c ./Neurone/FonctionActivation.cpp
###############################################################################
###############################################################################
#                                    LAYER                                    #
layer : Layer.o InputLayer.o
Layer.o : ./Layer/Layer.cpp
	$(COMPIL) $(FLAGS) -c ./Layer/Layer.cpp
InputLayer.o : ./Layer/InputLayer.cpp
	$(COMPIL) $(FLAGS) -c ./Layer/InputLayer.cpp
###############################################################################
###############################################################################
#                                   RESEAU                                    #
reseau : Reseau.o
Reseau.o : ./Reseau/Reseau.cpp
	$(COMPIL) $(FLAGS) -c ./Reseau/Reseau.cpp
###############################################################################
###############################################################################
option : Option.o
Option.o : ./Option/Option.cpp
	$(COMPIL) $(FLAGS) -c ./Option/Option.cpp
###############################################################################
###############################################################################
optionTab : OptionTab.o
OptionTab.o : ./Option/OptionTab.cpp
	$(COMPIL) $(FLAGS) -c ./Option/OptionTab.cpp
###############################################################################
###############################################################################
type : Type.o
Type.o : ./Option/Type.cpp
	$(COMPIL) $(FLAGS) -c ./Option/Type.cpp
#                                   MODIFS                                    #a

clean :
	rm *.o
mrproper :
	rm *.o launcher
debug: FLAGS += -O0 -g
debug: all
gdb: FLAGS += -O0 -g
gdb: LIBRARY += ; rm *.o ; gdb ./$(NAME)
gdb: all
run: LIBRARY += ; rm *.o ; ./$(NAME)
run: all
###############################################################################
