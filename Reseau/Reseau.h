#ifndef _RESEAU_H_
#define _RESEAU_H_
#include<vector>
#include"../Neurone/Neurone.h"
#include"../Layer/Layer.h"

class Reseau{


private:
  std::vector<Layer*> reseau; //Vector containing all the layers (input/hide/output)
  int nbLayers;	//indicating the number of layers you want;

 public:
  //Contructor
  Reseau(int,std::vector<int>); //A Network is a vector composed of Layers


  //Methods
  std::vector<float> fire_all(std::vector<float> input);
  void learn(std::vector<std::vector<std::vector<double>>> jeuxTest);


};

#endif
