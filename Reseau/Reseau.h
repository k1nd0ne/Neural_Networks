#ifndef _RESEAU_H_
#define _RESEAU_H_
#include<vector>
#include"../Neurone/Neurone.h"
#include"../Layer/Layer.h"
#include"../Common/fonctions.h"
class Reseau{


private:
  std::vector<double>input;
  std::vector<double>output;
  std::vector<Layer*> reseau; //Vector containing all the layers (input/hide/output)
  int nbLayers;	//indicating the number of layers you want;

 public:
  //Contructor
  Reseau(int,std::vector<int>); //A Network is a vector composed of Layers


  //Methods
  std::vector<double> fire_all(std::vector<double> input, double k);
  void learn(std::vector<std::vector<std::vector<double> > > jeuxTest);
  void backPropagation(std::vector<double> output, double k, double eta);

};

#endif
