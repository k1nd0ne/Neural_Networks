#include"./NeuroneB.h"
/**
 * Constructeur du Neurone avec biais
 * @method NeuroneB::NeuroneB
 * @param  taille             Taille du neurone
 * @param  x                  Vecteur de poids
 * @param  biais_w            Valeur du biais
 */
NeuroneB::NeuroneB(int taille,std::vector<double> * x, double biais_w){
    n = taille;
    w = x;
    w->push_back(biais_w);
}

/**
 * Constructeur du Neurone avec biais
 * @method NeuroneB::NeuroneB
 * @param  taille             Taille du neurone
 */
NeuroneB::NeuroneB(int taille) {
  n = taille;
  aleaWeights();
}

/**
 * Affichage des poids
 * @method NeuroneB::printWeight
 */
void NeuroneB::printWeight(){
  Neurone::printWeight();
  std::cout << "biais = " << (*w)[n] << std::endl;
}

/**
 * Génération aléatoire des poids
 * @method NeuroneB::aleaWeights
 */
void NeuroneB::aleaWeights(){
  w = new std::vector<double> (n,0.8);
  std::default_random_engine generator(std::random_device{}());
  std::normal_distribution<double> distribution(0,1);
  for (int i=0; i<n; i++) {
    (*w)[i] = distribution(generator);
  }
  w->push_back(distribution(generator));
}

/**
  * Méthode d'apprentissage (cf Neurone::fw_sum, cf Neurone::fw_activate, cf Neurone::derive_activate)
  * @method Neurone::learn
  * @param  x              Vecteur de poids
  * @param  o              Valeur attendue
  * @param  k              Valeur du biais
  * @param  mu             Taux d'apprentissage | Learning rate
 */
void NeuroneB::learn(std::vector<double> x,double o,double k, double mu){
  double sum = fw_sum(x);
  double res = fw_activate(sum,k);
  double derive = derive_activate(sum,k);
  for(int i=0; i<n; i++){
      (*w)[i]= (*w)[i]-  mu * (x[i]*derive*((o-res)*(-2)));
  }
  (*w)[n] = (*w)[n]-  mu * (1*derive*((o-res)*(-2)));
}

/**
 * Méthode de somme du vecteur de poids
 * @method NeuroneB::fw_sum
 * @param  x                Vecteur de poids
 * @return                  Somme des poids
 */
double NeuroneB::fw_sum(std::vector<double> x)const{
  double res = Neurone::fw_sum(x);
  res += (*w)[n];
  return res;
}

/**
 * @method NeuroneB::getNbPoids
 * @return Nombre de poids
 */
int NeuroneB::getNbPoids(){
  return n+1;
}
