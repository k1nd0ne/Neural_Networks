#ifndef _LAYER_H_
#define _LAYER_H_
#include"../Neurone/Neurone.h"
#include"../Neurone/NeuroneB.h"
#include "../Neurone/FonctionActivation.h"
#include<vector>

class Layer {
public:
  enum TypeLayer {
    INPUT,
    OUTPUT,
    HIDDEN
  };
protected:
  double k;
  int nbNeurone;
  std::vector<Neurone *> membres;
  std::vector<double> input;
  std::vector<double> output;
  TypeLayer type;
public:
  Layer();
  Layer(TypeLayer,int,int,FonctionActivation::EnumFonctionActivation);
  Neurone * getNeurone(int index);
  virtual std::vector<double> fire(std::vector<double>, double);
  int getNbNeurones();
  std::vector<double> getInput();
  std::vector<double> getOutput();
  void printWeight();
};
 #endif
