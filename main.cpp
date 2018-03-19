#include"./Neurone/Neurone.h"
#include"./Neurone/NeuroneB.h"
#include"./Layer/Layer.h"
#include"./Reseau/Reseau.h"
#include"./Common/fonctions.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<vector>
#include<cmath>
#include<stdlib.h>

using namespace std;

/*
Je propose de reprendre proprement sur un main vide a partir d'ici
*/
int main (int agrc, char * argv[]){
  vector<int> archi (3);
  archi[0]=4;
  archi[1]=3;
  archi[2]=3;
  Reseau * rezo = new Reseau(3,archi);
  double k = 1;
  std::vector<vector<double> > training = getInput("./TrainingSets/iris.csv");
  int epoch = 10;
  vector<double> res(3,0);
  int temp;
  vector<vector<vector<double> > > testData(training.size());
for (unsigned int i = 0; i < training.size(); i++){
  temp=(int)training[i][training[i].size()-1];
  training[i].pop_back();
cout<<temp<<" slt"<<endl;
    if (temp==1)res = {0,1,0};
    else if (temp==2)res = {0,0,1};
    else res={1,0,0};
  testData[i] = {training[i],res};
}
//printVec(testData);
  for(int i=0;i<epoch;i++){
    rezo->learn(testData);
  }
//  printVec(testData);
  double a,b,c,d;
  vector<double> testons (4);
  while (true) {
    cin>>a>>b>>c>>d;
    testons[0]=a;
    testons[1]=b;
    testons[2]=c;
    testons[3]=d;
    printVec(rezo->fire_all(testons,k));
  }
  //rezo->fire_all(//qqqqqq);

  return 0;
}
