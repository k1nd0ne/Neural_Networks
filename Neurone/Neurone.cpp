/**
 * \file neurone.cpp
 * \brief Classe Neurone
 */
#include"Neurone.h"
#include<vector>

/**
 * Constructeur avec biais et poids aléatoire (Loi normale centrée et réduite)
 * @method Neurone::Neurone
 * @param  taille           Nombre d'entrées
 */
Neurone::Neurone(int taille) {
  n = taille;
  biais = true;
  aleaWeights();
}

/**
 * Constructeur sans biais
 * @method Neurone::Neurone
 * @param  taille           Nombre d'entrées
 * @param  x                Vecteur de poids
 */
Neurone::Neurone(int taille, std::vector<double> * x){
    biais = false;
  w = x;
  n = taille;
}

/**
 * Constructeur avec biais
 * @method Neurone::Neurone
 * @param  taille           Nombre d'entrées
 * @param  x                Vecteur de poids
 * @param  biais_w          Valeur du biais
 */
Neurone::Neurone(int taille, std::vector<double> * x, double biais_w){
    biais = true;
    n = taille;
    w = x;
    w->push_back(biais_w);

}

/**
 * Méthode retournant  somme
 * @method Neurone::fire
 * @param  x             [description]
 * @param  k             [description]
 * @return               [description]
 */
double Neurone::fire(std::vector<double> x, double k)const{
  return fw_activate(fw_sum(x),k);
}

/**
 * Méthode de somme des valeurs du vecteur
 * @method Neurone::fw_sum
 * @param  x               Vecteur
 * @return                 Somme
 */
double Neurone::fw_sum(std::vector<double> x)const{
  double res=0;
  for(int i=0; i<n; i++){
      res += (x[i]) * (*w)[i];
  }

  if(biais){
        res += (*w)[n];
  }
  return res;
}

/**
 * Méthode d'activation
 * @method Neurone::fw_activate
 * @param  sum                  Valeur de la somme du vecteur (cf Neurone::fw_sum)
 * @param  k                    Valeur du biais
 * @return                      Valeur d'activation
 */
double Neurone::fw_activate(double sum, double k)const{
  return (1/(1+exp(-k*sum)));
}
/**
 * Méthode de dérivation
 * @method Neurone::derive_activate
 * @param  sum                      Valeur de la somme du vecteur (cf Neurone::fw_sum)
 * @param  k                        Valeur du biais
 * @return                          Valeur de dérivation
 */
double Neurone::derive_activate(double sum, double k)const{
  return (k*exp(-k*sum))* (1/(1+exp(-k*sum)*(1+exp(-k*sum))));
}

/**
 * Méthode d'apprentissage (cf Neurone::fw_sum, cf Neurone::fw_activate, cf Neurone::derive_activate)
 * @method Neurone::learn
 * @param  x              Vecteur de poids
 * @param  o              Valeur attendue
 * @param  k              Valeur du biais
 * @param  mu             Taux d'apprentissage | Learning rate
 */
void Neurone::learn(std::vector<double> x,double o,double k, double mu){
  double sum = fw_sum(x);
  double res = fw_activate(sum,k);
  double derive = derive_activate(sum,k);
  for(int i=0; i<n; i++){
      (*w)[i]= (*w)[i]-  mu * (x[i]*derive*((o-res)*(-2)));
  }
  if(biais){
      (*w)[n] = (*w)[n]-  mu * (1*derive*((o-res)*(-2)));
  }
}

/**
 * Affichage des poids
 * @method Neurone::printWeight
 */
void Neurone::printWeight(){
    for(int i=0; i<n; i++){
        std::cout << "w" << i << " = " << (*w)[i] << std::endl;
    }
    if(biais){
        std::cout << "biais = " << (*w)[n] << std::endl;
    }
}

/**
 * Méthode de génération de poids aléatoire selon une loi normale centrée réduite
 * @method Neurone::aleaWeights
 */
void Neurone::aleaWeights(){
  w = new std::vector<double> (n,0.0);
  std::default_random_engine generator(std::random_device{}());
  std::normal_distribution<double> distribution(0,1);
  for (int i=0; i<n; ++i) {
    (*w)[i] = distribution(generator);
  }
  if(biais){
    (*w).push_back(distribution(generator));
  }
}
