#include"./Neurone/Neurone.h"
#include"./Neurone/NeuroneB.h"
#include"./Layer/Layer.h"
#include"./Reseau/Reseau.h"
#include"./Common/fonctions.h"
#include"./Settings/Settings.h"
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
  char const * fileName = "./TrainingSets/spambase_57Attribs_2class.txt";
  settings Settings(fileName);
//  vector<int> archi (5);
  // archi[0]=4;
  // archi[1]=5;
  // archi[2]=5;
  // archi[3]=4;
  // archi[4]=3;
  vector<int> archi = (*Settings.getArchi());
  cout << "Affichage de l'architecture du reseau, Fermez pour commencer" << endl;
  displayArchi(archi);
  system("clear");
  Reseau * rezo = new Reseau(archi.size(),archi,1.0,0.01);
  std::vector<vector <vector <double> > > trainingettesting = getInputUltime(fileName,80);
  std::vector<vector<double> > training = trainingettesting[0];
  std::vector<vector<double> > testing = trainingettesting[1];
  int epoch = 5000;
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
    // if (temp==1)res = {0,1,0};
    // else if (temp==2)res = {0,0,1};
    // else res={1,0,0};
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
  // cout << "You can now interogate Boii" <<endl;
  // cout <<" Enter a series of digits to test it :" << endl;
  // cout << ">>";
  // double a,b,c,d;
  //int ligne = 0;
  int tmp = 0;
  int nberr = 0;
  int anciennenberr=0;
  //vector<double> testons (4);
  vector<double> result (Settings.getDifferentOutputs()->size());

  // while (tmp<100) {
  //   ligne = rand() % 150;
  //   // cin>>a>>b>>c>>d;
  //   // testons[0]=a;
  //   // testons[1]=b;
  //   // testons[2]=c;
  //   // testons[3]=d;
  //   cout<<"Test; input : ";
  //   printVec(testData[ligne][0]);
  //   cout<<" attendu : ";
  //   printVec(testData[ligne][1]);
  //   cout<<" recu : ";
  //   result= rezo->fire_all(testData[ligne][0]);
  //   print[0]= result[0]>result[1]&&result[0]>result[2]? 1 : 0;
  //   print[1]= result[1]>result[0]&&result[1]>result[2]? 1 : 0;
  //   print[2]= result[2]>result[0]&&result[2]>result[1]? 1 : 0;
  //   anciennenberr=nberr;
  //   nberr += print[0]==testData[ligne][1][0]&&print[1]==testData[ligne][1][1]&&print[2]==testData[ligne][1][2]? 0:1;
  //   printVec(print);
  //   if ( nberr > anciennenberr){
  //     cout<< "/!\\";
  //   }
  //   cout<<endl;
  //   tmp++;
  // }
  // cout<<"Nombre d'erreur : "<<nberr<<" / "<<tmp<<endl;



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
    // testing[i].pop_back();
    // if (temp==1)res = {0,1,0};
    // else if (temp==2)res = {0,0,1};
    // else res={1,0,0};
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
    // print[0]= result[0]>result[1]&&result[0]>result[2]? 1 : 0;
    // print[1]= result[1]>result[0]&&result[1]>result[2]? 1 : 0;
    // print[2]= result[2]>result[0]&&result[2]>result[1]? 1 : 0;
    anciennenberr=nberr;
    bool err = false;
    for(unsigned int l =0;l<print.size();l++){
      if (print[l]!=expectedRes[i][l]) err=true;
    }
    nberr += err;
    //nberr += print[0]==expectedRes[i][0]&&print[1]==expectedRes[i][1]&&print[2]==expectedRes[i][2]? 0:1;
    printVec(print);
    if ( nberr > anciennenberr){
      cout<< "\033[1;31m /!\\"<<"\033[0m";
    }
    cout<<endl;
    tmp++;
  }
  cout<<"Nombre d'erreur : "<<nberr<<" / "<<tmp<<endl;
  cout<<"Temps d'apprentissage : "<<delta<<" secondes"<<endl;
  return 0;
}
