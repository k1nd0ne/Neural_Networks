#ifndef _NEURONEB_H_
#define _NEURONEB_H_
#include"./Neurone.h"

class NeuroneB : public Neurone {
public:
  NeuroneB(int taille,FonctionActivation::EnumFonctionActivation fct); // Poids et biais random
  NeuroneB(int taille,std::vector<double> * x,double biais_w);
  void printWeight();
  void aleaWeights();
  void learn(std::vector<double> x,double o,double k, double mu);
  double fw_sum(std::vector<double> x)const;
  int getNbPoids();
};
#endif

/**
 *  La classe NeuroneB est represente des neurones particuliers
 *  dotés d'un biais, elle redefinie les fonctions ou le comportement
 *  est different a cause du biais,
 *  petit point sur les methodes "virtual" dans Neurone.h :
 *  Le mot clé virtual permet de declarer une fonction virtuelle
 *  en clair, quand on fait un heritage, on peut faire rentrer un Pointeur
 *  sur un objt fils dans un pointeur sur un objet pere, or, en faisant
 *  cela, on perd la vrai nature de l'objet, exemple si on cree un
 *  NeuroneB dans un pointeur Neurone, et que l'on appelle sa methode getWeight
 *  ce sera la methode de Neurone qui sera appellé, car pour le compilateur, on a un objet
 *  En mentionant que la methode de l'ojet pere est virtuelle, on dit au
 *  "Hey poto, je risque d'appeller cette methode depuis un objet qui semble etre
 *  Neurone, mais qui sera ptet un NeuroneB, donc attend de voir, et appelle la methode de la classe correspondante
 *  A terme ce sera super pratique : exemple
 *  On est dans Layer, on cree un pack de Neurone, a la creation, on choisit si ce sont des Neurone, ou des
 *  on les stocke quoi qu'il arrive dans un vector<Neurone*> et on pourra ensuite travailler de la meme maniere, qu'
 *  s'agisse de NeuroneB ou non.
 */
