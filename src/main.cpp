#include"../obj/Neurone.h"
#include"../obj/NeuroneB.h"
#include"../obj/Layer.h"
#include"../obj/Reseau.h"
#include"../obj/fonctions.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int main (int agrc, char * argv[]){
  vector<int> archi (5);
  archi[0]=4;
  archi[1]=5;
  archi[2]=5;
  archi[3]=4;
  archi[4]=3;
  system("clear");
  Reseau * rezo = new Reseau(5,archi,1.0,0.01);
  std::vector<vector<double> > training = getInput("./TrainingSets/iris.csv");
  int epoch = 1000;
  vector<double> res(2,0);
  int temp;
  vector<vector<vector<double> > > testData(training.size());
  for (unsigned int i = 0; i < training.size(); i++){
    temp=(int)training[i][training[i].size()-1];
    training[i].pop_back();
    if (temp==1)res = {0,1,0};
    else if (temp==2)res = {0,0,1};
    else res={1,0,0};
    testData[i] = {training[i],res};
  }

  cout << "Learning Starting..."<<endl;
  double pourcentage;
  for(int i=0;i<epoch;i++){
    pourcentage = (((double)i/(double)epoch)*100);
    rezo->learn(testData);
    std::cout<< (int)pourcentage << "% (" << i << " epoch )\r"<< std::flush;
  }
  cout << "\r\033[1;36m 100% \033[0m";
  cout << "<\033[1;33m DONE \033[0m>         "<<endl;
  cout << "\033[1;36m Learning Completed \033[0m" << endl;
  cout << "Displaying last recorded weights..." << endl;
  sleep(2);
  rezo->printWeight();
  // cout << "You can now interogate Boii" <<endl;
  // cout <<" Enter a series of digits to test it :" << endl;
  // cout << ">>";
  // double a,b,c,d;
  int ligne = 0;
  int tmp = 0;
  int nberr = 0;
  int anciennenberr=0;
  vector<double> testons (4);
  vector<double> result (3);
  vector<double> print (3);
  while (tmp<100) {
    ligne = rand() % 150;
    // cin>>a>>b>>c>>d;
    // testons[0]=a;
    // testons[1]=b;
    // testons[2]=c;
    // testons[3]=d;
    cout<<"Test; input : ";
    printVec(testData[ligne][0]);
    cout<<" attendu : ";
    printVec(testData[ligne][1]);
    cout<<" recu : ";
    result= rezo->fire_all(testData[ligne][0]);
    print[0]= result[0]>result[1]&&result[0]>result[2]? 1 : 0;
    print[1]= result[1]>result[0]&&result[1]>result[2]? 1 : 0;
    print[2]= result[2]>result[0]&&result[2]>result[1]? 1 : 0;
    anciennenberr=nberr;
    nberr += print[0]==testData[ligne][1][0]&&print[1]==testData[ligne][1][1]&&print[2]==testData[ligne][1][2]? 0:1;
    printVec(print);
    if ( nberr > anciennenberr){
      cout<< "/!\\";
    }
    cout<<endl;
    tmp++;
  }
  cout<<"Nombre d'erreur : "<<nberr<<" / "<<tmp<<endl;
  return 0;
}
