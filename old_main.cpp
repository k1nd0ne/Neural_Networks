/**
 * \file main.cpp
 * \brief Programme de test
 */
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include"Neurone.h"
#include"fonctions.h"

using namespace std;

/**
 * Programme de test principal
 * @method main
 * @param  argc Nombre d'arguments
 * @param  argv Tableaux d'arguments
 * @return      Code de fin d'execution
 */
int main ( int argc, char ** argv){
  string input;
  int mode;
  string nomFichierTraining ="";
  string nomFichierTesting ="";
  vector< vector <double> > testtab;
  cout<<"Traitement de fichier ou exemple sur et / ou ('fichier' ou 'exemple' ):"<<endl;
  cin>>input;
  if (input == "exemple"){
    mode = 1;
  }
  else if ( input == "fichier"){
    mode = 2;
    cout<<"nom du fichier Training : "<<endl;
    cin>>nomFichierTraining;
    cout<<"nom du fichier Test : "<<endl;
    cin>>nomFichierTesting;
  }

  //des instructions logiques simples : et et ou a n entrees

  int n;
  srand (time(NULL));
  if ( mode == 1){
    bool estet;
    cout<<"Et/ou ? "<<endl;
    cin>>input;
    if (input == "et"){
      estet= true;
    }
    else if (input == "ou"){
      estet=false;
    }
    cout<<"Nombre d'entrees"<<endl;
    cin>>n;
    remove("../javascript/data");
    ofstream configfile("../javascript/data",ios::out);
    estet?configfile<<"ET"<<endl:configfile<<"OU"<<endl;
    testtab = generateInput(n,estet);
  }
  else if (mode == 2){
    const char * c = nomFichierTraining.c_str();
    testtab = getInput(c);

    //printVec(result);
  }
printVec(testtab);
  //extraction de la derniere colonne, le resultat attendu :
  vector <double> result = extractResult(&testtab);//a changer !!!

  vector<double> weights (testtab[0].size(),0.1);

  Neurone * boii = new Neurone(testtab[0].size());
boii->printWeight();
  double mu = 0.005;
  double meanError;
  cout<<"Training Started..."<<endl;
  for (unsigned int i=0; i < 50000; i ++){
    swapVec(&testtab,&result);
    meanError = 0;
    for (unsigned int j =0; j < result.size();j++){
      boii->learn(testtab[j],result[j],1.0,mu);
      meanError += (boii->fire(testtab[j],5)-result[j]);
      //boii->printWeight();
    }
    meanError /= result.size();
    if(i%1000 == 0)
    cout<<"Mean Error = "<<meanError<<endl;
  }
    cout<<"Mean Error = "<<meanError<<endl;
  cout<<"Training Complete"<<endl;
  cout<<"Weights :"<<endl;
  boii->printWeight();
  cout<<"Testing..."<<endl;
  vector<vector <double> > inputTest;
  vector<double > resultTest;
  if ( mode == 2 ){
      const char * c = nomFichierTesting.c_str();
    inputTest = getInput(c);
    resultTest = extractResult(&inputTest);
}
else if ( mode == 1){
  inputTest=vector<vector<double> >(testtab.size());
  for(unsigned int i = 0;i<testtab.size();i++){
    inputTest[i]=vector<double>(testtab[0].size());
    for(unsigned int j= 0;j<testtab[0].size();j++){
      inputTest[i][j] = testtab[i][j];
    }
  }
  //resultTest = extractResult(&inputTest);
  printVec(testtab);
printVec(inputTest);
resultTest=result;
//  printVec(resultTest);
}
  for (unsigned int j =0; j < resultTest.size();j++){
    cout<<"Expected : "<<resultTest[j]<<" - Got : "<<boii->fire(inputTest[j],5)<<endl;
  }


  return 0;
}
