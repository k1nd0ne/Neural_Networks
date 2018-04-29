#ifndef _NEURONE_H_
#define _NEURONE_H_
#include<iostream>
#include<math.h>
#include<vector>
#include<random>
#include "FonctionActivation.h"

class Neurone {
protected:
  std::vector<double> * w;
  int n;
  FonctionActivation fonctionActivation;
public:
  Neurone();
  Neurone(int taille,FonctionActivation::EnumFonctionActivation fct);
  Neurone(int taille, std::vector<double> * x,FonctionActivation::EnumFonctionActivation fct);
  virtual double fw_sum(std::vector<double> x)const;
  double fw_activate(double sum, double k)const;
  double derive_activate(double sum, double k)const;
  virtual double fire(std::vector<double> x, double k) const;
  virtual void learn(std::vector<double> x,double o,double k, double mu);
  virtual void printWeight();
  virtual void aleaWeights();
  std::vector<double> * getWeight();
  virtual int getNbPoids();
};
#endif
