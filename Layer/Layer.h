#ifndef _LAYER_H_
#define _LAYER_H_
#include"../Neurone/Neurone.h"
#include<vector>

class Layer {
public:
enum TypeLayer {
  INPUT,
  OUTPUT,
  HIDDEN
};
private:
  double k;
  int nbNeurone;
  std::vector<Neurone *> membres;
  std::vector<double> input;
  std::vector<double> output;
  TypeLayer type;

public:
  Neurone * getNeurone(int index);
  std::vector<double> fire(std::vector<double>, double);
  Layer(TypeLayer,int,int);
  int getNbNeurones();
  std::vector<double> getInput();




};
 // for (int i = 0; i < nbNeuronne; i++){
 //   (for int j =0; j input.size(); j++){
 //      double stock = input[j] * ( 1- input[j]);
 //      if ( i == nbNeuronne-1){
 //        (membres[j]->getWeight())[j]=(membres[j]->getWeight())[j] - mu * (attendu[j] -output[i][j]);
 //      }
 //      else {
 //
 //      }
 //   }
 // }
 #endif
