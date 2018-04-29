#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<vector>
using namespace std;

void printVec1 (std::vector<double> vec){
  for (unsigned int i=0;i<vec.size();i++){
    std::cout<<vec[i]<<",";
  }
}

void printVec2 (std::vector<std::vector<double> > vec){
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
    cout << nbLignes<<endl << endl;
    cout << "fichier ouvert avec success" << endl;
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
  std::cerr << "\033[0;31m ERROR [ "<< "Can't open file" << " IN FILE " << __FILE__ << " AT LINE " << __LINE__ << " ] \n \033[0m";
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

int main(){
  vector< vector <double> > res = getInput("irisTraining.csv");
  printVec2(res);
  cout<<"++++++++++++++++++++++++++++"<<endl;
  vector <double> res2 = extractResult(&res,5);
  printVec1(res2);
  cout<<"++++++++++++++++++++++++++++"<<endl;
  printVec2(res);
  return 0;
}
