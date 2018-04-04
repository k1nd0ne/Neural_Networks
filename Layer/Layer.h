#ifndef _LAYER_H_
#define _LAYER_H_
#include"../Neurone/Neurone.h"
#include"../Neurone/NeuroneB.h"
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
  Neurone * getNeurone(int index);
  virtual std::vector<double> fire(std::vector<double>, double);
  Layer(TypeLayer,int,int);
  int getNbNeurones();
  std::vector<double> getInput();
  std::vector<double> getOutput();
  void printWeight();
};
 #endif
