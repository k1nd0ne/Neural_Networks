#ifndef _NEURONE_H_
#define _NEURONE_H_
#include<iostream>
#include<math.h>
#include<vector>
#include<random>
//Iris-setosa = 0
// Iris-versicolor = 1
//Iris-virginica = 2
class Neurone {
protected:
  std::vector<double> * w; //Pointeur sur un vecteur contenant les poids desirés
  int n; //Nombre d'entrées
public:
  virtual double fw_sum(std::vector<double> x)const; //Fonction de somme des xi,wi
  double fw_activate(double sum, double k)const; //Fonction d'activation Sigmoïd
protected:
  double derive_activate(double sum, double k)const;

public:
//Constructeur
Neurone();
Neurone(int taille); //poids aléatoires
Neurone(int taille, std::vector<double> * x);//poid fixes
//Méthodes
virtual double fire(std::vector<double> x, double k) const; //Déclenche le neurone et produit une réponse.
virtual void learn(std::vector<double> x,double o,double k, double mu); //Fonction d'apprentissage(modification des poids en fonction des différents résultat récupérés/attendu)
virtual void printWeight();
std::vector<double> * getWeight();
virtual void aleaWeights();
virtual int getNbPoids();
};
#endif
