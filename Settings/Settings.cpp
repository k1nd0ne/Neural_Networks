#include "Settings.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdlib.h>

//#include "../Common/fonctions.h"

using namespace std;

int settings::getNbrHiddenLayers(){
  return nbrHiddenLayers;
}
vector<int>* settings::getArchi(){
  return archi;
}
vector<double>* settings::getDifferentOutputs(){
  return differentOutputs;
}
settings::settings(char const * fileName){
  cout<<"Number of Hidden Layers"<<endl;
  cin>>nbrHiddenLayers;
  archi = new vector<int>(nbrHiddenLayers+2);
  for(int i=0;i<nbrHiddenLayers;i++){
    cout<<"Number of Neurons in Layer "<<i+1<<endl;
    cin>>(*archi)[i+1];
  }

  ifstream in(fileName); //on veut aussi ouvrir pour connaitre la taille du fichier
  string ligne;
  int nbLignes = 0;
  while(std::getline(in, ligne))
  nbLignes++; //on compte les lignes...
  in.close(); //et on ferme le fichier
  ifstream fichier(fileName, ios::in);  // on ouvre le fichier en lecture

  if(fichier){
    vector< vector <double> > stock(nbLignes); //Tableau de chaine de caractère qui va contenir tout le fichier ligne par ligne.
    cout << "\033[1;36m file " << "\033[1;31m" << fileName << "\033[1;36m opened with success , nbLignes= " <<nbLignes<<"\033[0m"<< endl;
    string s;
    double temp = 1;
    string ligne;

    for (int j = 0; j < nbLignes; j++) {
      fichier>>ligne;
      stringstream ss(ligne);
      while (getline(ss, s, ',')) {  //strinsplit à partir du caractère ','
      temp = atof(s.c_str());
      stock[j].push_back(temp); //on stock chaque information dans une case.
    }
  }
  fichier.close();  // on ferme le fichier
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
  cerr << "Impossible d'ouvrir le fichier !" << endl;

}

}

bool exists(double n,vector<double>* tab){
  for(unsigned int i=0;i<tab->size();i++){
    if((*tab)[i]==n){
      return true;
    }
  }
  return false;
}
//petit test ---  g++ -Wall settings.cpp ../Common/fonctions.cpp -o prog
// int main(){
//   settings s("../TrainingSets/iris.csv");
//   printVec(*(s.getArchi()));
//   cout<<endl;
//   printVec(*(s.getDifferentOutputs()));
//   return 0;
// }
