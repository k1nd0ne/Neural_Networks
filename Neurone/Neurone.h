#include<iostream>
#include<math.h>
#include<vector>
#include <random>
#ifndef _NEURONE_H_
#define _NEURONE_H_

class Neurone {
private:
    bool biais;
  std::vector<double> * w; //Pointeur sur un vecteur contenant les poids desirés
  int n; //Nombre d'entrées
  double fw_sum(std::vector<double> x)const; //Fonction de somme des xi,wi
  double fw_activate(double sum, double k)const; //Fonction d'activation Sigmoïd
  double derive_activate(double sum, double k)const;
public:

//Constructeur
Neurone(int taille); //poids aléatoires
Neurone(int taille, std::vector<double> * x);
Neurone(int taille, std::vector<double> * x, double biais_w);

//Méthodes

double fire(std::vector<double> x, double k) const; //Déclenche le neurone et produit une réponse.

void learn(std::vector<double> x,double o,double k, double mu); //Fonction d'apprentissage(modification des poids en fonction des différents résultat récupérés/attendu)

void printWeight();

void aleaWeights();

};

#endif
