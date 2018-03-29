#include "../obj/fonctions.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include<cmath>

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

void printVec (std::vector<std::vector<std::vector<double> > > vec){
  std::cout<<"<";
  for(unsigned int k =0; k < vec.size();k++){
    std::cout<<"<";
  for (unsigned int i=0;i<vec[k].size();i++){
    std::cout<<"<";
    for (unsigned int j=0;j<vec[k][i].size();j++){
      std::cout<<vec[k][i][j];
      if ( j != vec[k][i].size()-1){
        std::cout<<",";
      }
    }
    std::cout<<">";
    if ( i != vec[k].size()-1){
      std::cout<<",";
    }
    //std::cout<<endl<<"----------"<<std::endl;
  }
std::cout<<">"<<(k!=vec.size() ? " ":">")<<endl;}
}

vector< vector <double> > getInput(char const * fileName){

  ifstream in(fileName); //on veut aussi ouvrir pour connaitre la taille du fichier
  string ligne;
  int nbLignes = 0;
  while(std::getline(in, ligne))
  nbLignes++; //on compte les lignes...
  in.close(); //et on ferme le fichier
  ifstream fichier(fileName, ios::in);  // on ouvre le fichier en lecture

  if(fichier){
    vector< vector <double> > stock(nbLignes); //Tableau de chaine de caractère qui va contenir tout le fichier ligne par ligne.
    cout << "\033[1;36m file " << "\033[1;31m" << fileName << "\033[1;36m open with succes , nbLignes= " <<nbLignes<<"\033[0m"<< endl;
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
  swapVec(&stock);//melange du vecteur extrait du fichier
  fichier.close();  // on ferme le fichier
  return stock;
}
else {
  cerr << "Impossible d'ouvrir le fichier !" << endl;
  vector< vector <double> > stock(nbLignes);
  return stock;
}

}

vector <double> extractResult(vector< vector <double> > * input){
  vector<double> res(input->size());
  unsigned int pos =((*input)[0].size())-1;
  for(unsigned int i=0;i<input->size();i++){
    res[i]=(*input)[i][pos];
    (*input)[i].pop_back();
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
void swapVec (std::vector<std::vector<double> > * input){
  unsigned int r;
  for (unsigned int i=0;i<input->size();i++){
    do{
      r = rand()%input->size();
    }while(r == i);
    (*input)[i].swap((*input)[r]);
  }
}
unsigned int int_to_int(unsigned k) {
  if (k == 0) return 0;
  if (k == 1) return 1;                       /* schlagué */
  return (k % 2) + 10 * int_to_int(k / 2);
}

std::vector<std::vector<double> > generateInput(int n, bool estet){
  int nbtest = (int)pow(2,n);
vector< vector < double > >  testtab(nbtest, vector<double>(n,0));
/* Ici on initialise des jeux de valeurs d'entrainement, on creer toutes les combinaisons possibles de 0 et de 1 sur n caracteres, et on associe une
valeur attendue comme resultat, on defini naturellement dès le debut ( second parametre du programme ) s'il s'agit d'un ET ou d'un OU
On crée ainsi jouyeusement les jeux test, qui sont ensuite affichés, si vous voulez verifier que tout va bien*/
for (int i =0; i < nbtest; i ++){
  int tmp = i;
  tmp = int_to_int(tmp);
  for (int j =0; j < n; j ++){
    testtab[i][j]= (tmp/(int)pow(10,n-1-j)==1?1 : 0) ;
    tmp = tmp- (testtab[i][j]==1? (int)pow(10,n-1-j): 0);
  }
  if ( !estet && i > 0){
    testtab[i].push_back(1);
  }
  else if ( !estet) {
    testtab[i].push_back(0);
  }
  cout << "Serie I :";
  for (int k =0; k < n; k ++){
    cout<<testtab[i][k];
  }
  if (estet && i == nbtest-1){
    testtab[i].push_back(1);
  }
  else if ( estet){
    testtab[i].push_back(0);
  }
  cout<<" o : "<<testtab[i][testtab[i].size()-1]<<endl;
}
return testtab;
}
