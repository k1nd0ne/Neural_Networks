#include "Settings.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdlib.h>

/**
* Constructeur
* @method settings::settings
* @param  fileName           Nom du fichier
*/
Settings::Settings(char const * fileName){
  std::cout<<"Number of Hidden Layers : ";
  std::cin>>nbrHiddenLayers;
  archi = new std::vector<int>(nbrHiddenLayers+2);
  for(int i=0;i<nbrHiddenLayers;i++){
    std::cout<<" | Number of Neurons in Layer "<<i+1<<" : ";
    std::cin>>(*archi)[i+1];
  }

  /**
  * Counter
  */
  std::ifstream in(fileName);
  std::string ligne;
  int nbLignes = 0;
  while(std::getline(in, ligne)){
    nbLignes++;
  }
  in.close();

  /**
  * Parser
  */
  std::ifstream fichier(fileName, std::ios::in);
  if(fichier){
    std::vector< std::vector <double> > stock(nbLignes); // Tableau de chaine de caractère qui va contenir tout le fichier ligne par ligne.
    std::cout << "\033[1;36m file " << "\033[1;31m" << fileName << "\033[1;36m opened with success , nbLignes= " <<nbLignes<<"\033[0m"<< std::endl;
    std::string s;
    double temp = 1;
    std::string ligne;

    for (int j = 0; j < nbLignes; j++) {
      fichier>>ligne;
      std::stringstream ss(ligne);
      /** strinsplit à partir du caractère ',' */
      while (getline(ss, s, ',')) {
        temp = atof(s.c_str());
        stock[j].push_back(temp); // On stock chaque information dans une case.
      }
    }
    fichier.close();
    (*archi)[0] = (stock[0].size())-1;
    for (unsigned int i = 0; i < stock.size(); i++){
      temp=stock[i][stock[i].size()-1];
      if (!(exists(temp,differentOutputs))){
        differentOutputs->push_back(temp);
      }
    }
    (*archi)[(archi->size())-1] = (differentOutputs->size());
  }
  else {
    std::cerr << "\033[0;31m ERROR [ "<< "Can't open file" << " IN FILE " << __FILE__ << " AT LINE " << __LINE__ << " ] \n \033[0m";
  }
}

/**
* @method settings::getNbrHiddenLayers
* @return Nombre de Layers "caché"
*/
int Settings::getNbrHiddenLayers(){
  return nbrHiddenLayers;
}

/**
* @method settings::getArchi
* @return Architecture
*/
std::vector<int>* Settings::getArchi(){
  return archi;
}

/**
* @method settings::getDifferentOutputs
* @return DifferentOutputs
*/
std::vector<double>* Settings::getDifferentOutputs(){
  return differentOutputs;
}

/**
* @method exists
* @param  n      Valeur
* @param  tab    Vecteur
* @return        True si Valeur n et dans Vecteur tab
*/
bool exists(double n,std::vector<double>* tab){
  for(unsigned int i=0;i<tab->size();i++){
    if((*tab)[i]==n){
      return true;
    }
  }
  return false;
}
