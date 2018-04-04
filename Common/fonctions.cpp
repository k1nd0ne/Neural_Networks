#include "fonctions.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include<cmath>
#include"../Neurone/Neurone.h"
#include"../Neurone/NeuroneB.h"
#include"../Layer/Layer.h"
#include"../Reseau/Reseau.h"
#include"../Common/fonctions.h"
#include"../Settings/Settings.h"
using namespace std;

void printVec (std::vector<double> vec){
  for (unsigned int i=0;i<vec.size();i++){
    std::cout<<vec[i]<<",";
  }
}
void printVec (std::vector<int> vec){
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

unsigned int findIndMax(vector<double> vec){
  double max = vec[0];
  unsigned int indMax=0;
  for(unsigned int i=0;i<vec.size();i++){
    if(vec[i]>max){
      max=vec[i];
      indMax = i;
    }
  }
  return indMax;
}


 vector < vector <vector <double> > > getInputUltime(char const * fileName,float pourcentage){

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
  swapVec(&stock);//melange du vecteur extrait du fichier
  fichier.close();  // on ferme le fichier
  int tailleTraining = (int)((pourcentage/100) * nbLignes);
  int tailleTesting = nbLignes - tailleTraining;
  vector< vector <vector <double> > > result(2);
  for(int i=0;i<tailleTraining;i++){
    result[0].push_back(stock[i]);
  }
  for(int i=0;i<tailleTesting;i++){
    result[1].push_back(stock[i+tailleTraining]);
  }
  return result;
}
else {
  cerr << "Impossible d'ouvrir le fichier !" << endl;
  vector< vector < vector <double> > > result(2);
  return result;
}

}
void displayArchi(std::vector<int> info){
string endline = "network.draw()";
string begin = "network = DrawNN( [";
string dyNeuron= " ";
    for (unsigned int i = 0; i <= info.size()-2; i++){
      dyNeuron = to_string(info[i]) +",";
      begin+=dyNeuron;
    }
    dyNeuron = to_string(info[info.size()-1]);
    begin += dyNeuron +"] )";

system("sed -i '$ d' Archi.py");
system("sed -i '$ d' Archi.py");

    ofstream fichier("Archi.py", ios::app);  //déclaration du flux et ouverture du fichier

            if(fichier)  // si l'ouverture a réussi
            {
                    fichier<< begin <<"\n";
                    fichier<<endline;
                    fichier.close();  // on referme le fichier
            }
            else  { // sinon
                    cerr << "Erreur à l'ouverture !" << endl;
                  }
system("python Archi.py");
}
void  startLauncher(string file, bool arch, int ep) {
  string newfile= "./TrainingSets/"+file;
  const char * fileName = newfile.c_str();
  settings Settings(fileName);
  vector<int> archi = (*Settings.getArchi());
  cout << "Affichage de l'architecture du reseau, Fermez pour commencer" << endl;
  if(arch == true){
  displayArchi(archi);
  }
  system("clear");
  Reseau * rezo = new Reseau(archi.size(),archi,1.0,0.01);
  std::vector<vector <vector <double> > > trainingettesting = getInputUltime(fileName,80);
  std::vector<vector<double> > training = trainingettesting[0];
  std::vector<vector<double> > testing = trainingettesting[1];
  int epoch = ep;
  vector<double> res(Settings.getDifferentOutputs()->size());
  int temp;
  vector<vector<vector<double> > > testData(training.size());
    cout<< "\033[1;33m"<<endl;
    cout<<"--------------------------------"<<endl;
  for(unsigned int k=0;k<Settings.getDifferentOutputs()->size();k++){
    vector<double> mapVect(Settings.getDifferentOutputs()->size(),0);
    cout<<(*Settings.getDifferentOutputs())[k]<<" has been mapped to {" ;
    for(unsigned int z=0;z<mapVect.size();z++){
      if(z==k)cout<<"1," ;
      else cout<<"0," ;
    }
    cout<<"}"<<endl;

  }

  cout<<"--------------------------------"<<endl;
  cout<<"\033[0m"<<endl;
  for (unsigned int i = 0; i < training.size(); i++){
    temp=(int)training[i][training[i].size()-1];
    training[i].pop_back();
    for(unsigned int j=0;j<Settings.getDifferentOutputs()->size();j++){
      if(temp==(*Settings.getDifferentOutputs())[j]){
        res[j]=1;
      }
      else res[j]=0;
    }
    testData[i] = {training[i],res};
  }

  cout << "Learning Starting..."<<endl;
  double pourcentage;
  int deb = time(NULL);
  for(int i=0;i<epoch;i++){
    pourcentage = (((double)i/(double)epoch)*100);
    swapVec(&testData[0]);
    rezo->learn(testData);
    std::cout<< (int)pourcentage << "% (" << i << " epoch )\r"<< std::flush;
  }
  int delta = time(NULL)-deb;
  cout << "\r\033[1;36m 100% \033[0m";
  cout << "<\033[1;33m DONE \033[0m>         "<<endl;
  cout << "\033[1;36m Learning Completed \033[0m" << endl;
  cout << "Displaying last recorded weights..." << endl;
  sleep(2);
  rezo->printWeight();
  int tmp = 0;
  int nberr = 0;
  int anciennenberr=0;
  vector<double> result (Settings.getDifferentOutputs()->size());



  //new test with values unknown to the neural network
  std::vector<vector<double> > expectedRes(testing.size());
  for (unsigned int i = 0; i < testing.size(); i++){
    temp=(int)testing[i][testing[i].size()-1];
    for(unsigned int j=0;j<Settings.getDifferentOutputs()->size();j++){
      if(temp==(*Settings.getDifferentOutputs())[j]){
        res[j]=1;
      }
      else res[j]=0;
    }
    expectedRes[i]=res;
  }

  for(unsigned int i=0;i<testing.size();i++){
    cout<<"Test; input : ";
    printVec(testing[i]);
    cout<<" attendu : ";
    printVec(expectedRes[i]);
    cout<<" recu : ";
    result= rezo->fire_all(testing[i]);
    vector<double> print (Settings.getDifferentOutputs()->size(),0);
    print[findIndMax(result)]=1;

    anciennenberr=nberr;
    bool err = false;
    for(unsigned int l =0;l<print.size();l++){
      if (print[l]!=expectedRes[i][l]) err=true;
    }
    nberr += err;


    printVec(print);
    if ( nberr > anciennenberr){
      cout<< "\033[1;31m /!\\"<<"\033[0m";
    }
    cout<<endl;
    tmp++;
  }
  cout<<"\033[1;33mNombre d'erreur : \033[0m \033[1;32m"<<(nberr/tmp)*100<<"\% \033[0m --->("<<nberr<<" / "<<tmp<<")"<<endl;
  cout<<"\033[1;33mTemps d'apprentissage : \033[1;33m"<<delta<<" secondes \033[0m"<<endl;

}
