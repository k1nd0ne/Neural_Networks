#ifndef _RESEAU_H_
#define _RESEAU_H_
#include<vector>
#include"../Neurone/Neurone.h"
#include"../Common/fonctions.h"
#include"../Layer/InputLayer.h"

class Reseau{
private:
  std::vector<double>input;
  std::vector<double>output;
  std::vector<std::vector<std::vector<double> > > dsig;
  std::vector<std::vector<std::vector<double> > > dact;
  std::vector<std::vector<std::vector<double> > > derrdact;
  std::vector<Layer*> reseau; //Vector containing all the layers (input/hide/output)
  double eta;
  double k;
  int nbLayers;	//indicating the number of layers you want;
 public:
  //Contructor
  Reseau(int,std::vector<int>,double,double); //A Network is a vector composed of Layers


  //Methods
  std::vector<double> fire_all(std::vector<double> input);
  void learn(std::vector<std::vector<std::vector<double> > > jeuxTest);
  void backPropagation(std::vector<double> output);
  void printWeight();
};
#endif
