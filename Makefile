#Compilation
GCC      = g++
FLAGS    = -Wall -pedantic -std=c++11 -g -O0
LIBS      = #put special libs here

#Fichiers
PROGPATH = ./
PROGNAME = $(PROGPATH)launcher #Nom de l'application
SRCDIR   = src/
SRC      = main.cpp Neurone.cpp Reseau.cpp Layer.cpp NeuroneB.cpp fonctions.cpp InputLayer.cpp
L        =
OBJDIR   = obj/
OBJ      = $(patsubst %.cpp, $(OBJDIR)%.o, $(SRC))
THIS     = Makefile

#Shell
RM     = @rm -fv
CLEAR  = @clear
MSG    = @echo -e

#Cibles
all : $(PROGNAME)

$(OBJDIR)%.o : $(SRCDIR)%.cpp
	@mkdir -pv $(OBJDIR)
	$(GCC) $(FLAGS) $(INC) $(L) -c -o $@ $<

$(PROGNAME) : $(OBJ)
	$(GCC) $(FLAGS) $(L) $^ -o $@ $(LIBS)

#Nettoyage
clean :
	$(MSG) "Nettoyage des fichiers"
	$(RM) $(OBJDIR)*.o
	$(RM) $(PROGNAME)
