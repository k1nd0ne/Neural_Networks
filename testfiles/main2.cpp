#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include"../Neurone/Neurone.h"
#include "fonctions.h"

using namespace std;

int main(){
  srand (time(NULL));
  vector< vector <double> > input = getInput("irisTraining.csv");
  vector <double> result = extractResult(&input,5);
  //printVec(result);
  vector<double> weights (4,0.1);
  Neurone * boii = new Neurone(4,&weights);

  double mu = 0.005;
  double meanError;
  cout<<"Training Started..."<<endl;
  for (unsigned int i=0; i < 10000; i ++){
  //  swapVec(&input,&result);
    meanError = 0;
    for (unsigned int j =0; j < result.size();j++){
      boii->learn(input[j],result[j],5,mu);
      meanError += (boii->fire(input[j],5)-result[j]);
     //boii->printWeight();
    }
   meanError /= result.size();
   if(i%1000 == 0)
    cout<<"Mean Error = "<<meanError<<endl;
  }
  cout<<"Training Complete"<<endl;
  cout<<"Weights :"<<endl;
  boii->printWeight();
  cout<<"Testing..."<<endl;
  vector< vector <double> > inputTest = getInput("irisTest1.csv");
  vector <double> resultTest = extractResult(&inputTest,5);
  for (unsigned int j =0; j < resultTest.size();j++){
  cout<<"Expected : "<<resultTest[j]<<" - Got : "<<boii->fire(inputTest[j],5)<<endl;
  }

  return 0;
}
