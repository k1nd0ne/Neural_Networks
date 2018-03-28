#include "./InputLayer.h"

InputLayer::InputLayer(int taille){
  membres =std::vector<Neurone *> (taille);
  nbNeurone = taille;
  for (int i = 0; i < taille; i ++){
    membres[i] = new Neurone(1, new std::vector<double>(1,1));
  }
}
std::vector<double> InputLayer::fire(std::vector<double> input, double k){
  output = std::vector<double> ( nbNeurone);
  for (int i = 0 ; i < nbNeurone; i ++){
    output[i]=membres[i]->fw_sum(input);
  }
  return output;
}
