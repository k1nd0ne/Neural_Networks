#include "fonctions.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void printVec (std::vector<double> vec){
  for (unsigned int i=0;i<vec.size();i++){
    std::cout<<vec[i]<<",";
  }
}

void printVec (std::vector<std::vector<double> > vec){
  for (unsigned int i=0;i<vec.size();i++){
    for (unsigned int j=0;j<vec[i].size();j++){
      std::cout<<vec[i][j]<<",";
    }
    std::cout<<endl<<"----------"<<std::endl;
  }
}

vector< vector <double> > getInput(char const * fileName){

  ifstream fichier(fileName, ios::in);  // on ouvre le fichier en lecture
  ifstream in(fileName); //on veut aussi ouvrir pour connaitre la taille du fichier
  string ligne;
  int nbLignes = 0;
  while(std::getline(in, ligne))
  nbLignes++; //on compte les lignes...
  in.close(); //et on ferme le fichier

  if(fichier){
    vector< vector <double> > stock(nbLignes); //Tableau de chaine de caractère qui va contenir tout le fichier ligne par ligne.
    cout << "fichier ouvert avec success , nbLignes= " <<nbLignes<< endl;
    string s;
    double temp = 0;
    string ligne;

    for (int j = 0; j < nbLignes; j++) {
      fichier>>ligne;
      stringstream ss(ligne);
      while (getline(ss, s, ',')) {  //strinsplit à partir du caractère ','
      temp = ::atof(s.c_str());
      stock[j].push_back(temp); //on stock chaque information dans une case.
    }
  }

  fichier.close();  // on ferme le fichier
  return stock;
}
else {
  cerr << "Impossible d'ouvrir le fichier !" << endl;
  vector< vector <double> > stock(nbLignes);
  return stock;
}

}

vector <double> extractResult(vector< vector <double> > * input,unsigned int pos){
  vector<double> res(input->size());
  for(unsigned int i=0;i<input->size();i++){
    res[i]=(*input)[i][pos-1];
    (*input)[i].erase((*input)[i].begin()+(pos-1));
  }
  return res;
}

void swapVec (std::vector<std::vector<double> > * input, std::vector <double> * result){
  unsigned int r;
  for (unsigned int i=0;i<input->size();i++){
    do{
      r = rand()%input->size();
    }while(r == i);
    (*input)[i].swap((*input)[r]);
    iter_swap(result->begin() + i ,result->begin() + r);
  }
}
void printTab(double*** t){
   int size1 = *(&t + 1) - t;
   int size2 = *(&t[0] + 1) - t[0];
   int size3 = *(&t[0][0] + 1) - t[0][0];
  for(int i=0;i<size1;i++){
    for(int j=0;i<size2;j++){
      for(int k=0;i<size3;k++){
        cout<<t[i][j][k];<<",";
      }
      cout<<endl;
    }
    cout<<endl<<"-------------------"<<endl;
  }
}
