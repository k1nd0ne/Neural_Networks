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
#include<unistd.h>
using namespace std;

/*
Je propose de reprendre proprement sur un main vide a partir d'ici
*/
int main (int agrc, char * argv[]){
  vector<int> archi (2);
  archi[0]=4;
  archi[1]=1;
//  archi[2]=3;
  system("clear");
  Reseau * reseau = new Reseau(2,archi);
  double k = 1;
  std::vector<vector<double> > training = getInput("./TrainingSets/iris.csv");
  int epoch = 10000;
  vector<double> res(1,0);
  int temp;
  vector<vector<vector<double> > > testData(training.size());
for (unsigned int i = 0; i < training.size(); i++){
  temp=(int)training[i][training[i].size()-1];
  training[i].pop_back();
  if (temp==1)res = {1};
  // else res = {0};
    // if (temp==1)res = {0,1,0};
    // else if (temp==2)res = {0,0,1};
    // else res={1,0,0};
  testData[i] = {training[i],res};
}
//printVec(testData);
 string charg = "#";
 reseau->printWeight();
 cout << "Learning Starting..."<<endl;
 double pourcentage;
 for(int i=0;i<epoch;i++){
   //swapVec(&training,&res);
   pourcentage = (((double)i/(double)epoch)*100);
   reseau->learn(testData);
   std::cout<< (int)pourcentage << "% (" << i << " epoch )\r"<< std::flush;
   }
 cout << "\r\033[1;36m 100% \033[0m";
 cout << "<\033[1;33m DONE \033[0m>         "<<endl;
 cout << "\033[1;36m Learning Completed \033[0m" << endl;
 cout << "Displaying last recorded weights..." << endl;
// sleep(2);
 reseau->printWeight();
//  printVec(testData);
// cout << "Press any key to continue...";
// system("read -s -N 1"); // Continues when pressed a key like windows
// system("clear");
 cout << "You can now interogate Boii" <<endl;
 cout <<" Enter a series of digits to test it :" << endl;
 cout << ">>";
 double a,b,c,d;
  vector<double> testons (4);
  while (true) {
    cin>>a>>b>>c>>d;
    testons[0]=a;
    testons[1]=b;
    testons[2]=c;
    testons[3]=d;
    printVec(reseau->fire_all(testons,k));
  }
  //reseau->fire_all(//qqqqqq);

  return 0;
}
