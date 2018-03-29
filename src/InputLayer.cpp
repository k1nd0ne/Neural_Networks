#include "../obj/InputLayer.h"
/**
 * Constructeur par taille
 * @method InputLayer::InputLayer
 * @param  taille                 Nombre de neurones dans le layer
 */
InputLayer::InputLayer(int taille){
  membres =std::vector<Neurone *> (taille);
  nbNeurone = taille;
  input=std::vector<double>(taille);
  output= std::vector<double>(taille);
  for (int i = 0; i < taille; i ++){
    membres[i] = new Neurone(1, new std::vector<double>(1,1));
  }
}
/**
 * Méthode de propagation en avant
 * @method InputLayer::fire
 * @param  input            Vecteur en entrées
 * @param  k                Coefficient de sigmoid
 * @return                  Valeur d'activation
 */
std::vector<double> InputLayer::fire(std::vector<double> input, double k){
  for (unsigned int i =0; i < input.size(); i ++){
    this->input[i] = input[i];
  }
  for (int i = 0 ; i < nbNeurone; i ++){
    output[i]=membres[i]->fire({input[i]},k); //faut il activer ou non? OUI!
  }
  return output;
}
