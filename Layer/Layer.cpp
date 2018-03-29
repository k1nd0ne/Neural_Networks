#include"./Layer.h"

/**
 * Constructeur par défauts
 * @method Layer::Layer
 */
Layer::Layer(){}
/**
 * Constructeur avec arguments
 * @method Layer::Layer
 * @param  type         Type de layer
 * @param  nbneur       Nombre de neurone
 * @param  nbinput      Nombre d'entrée par neurone
 */
Layer::Layer(TypeLayer type,int nbneur, int nbinput):nbNeurone(nbneur)
{
  membres = std::vector<Neurone*>(nbneur);
  input=std::vector<double>(nbinput);
  output= std::vector<double>(nbneur);
    for (int i =0; i < nbneur; i ++){
      membres[i]= new NeuroneB(nbinput);
  }
}
/**
* @method Layer::getNeurone
* @param  index             index
* @return                   Neurone
*/
Neurone * Layer::getNeurone (int index){
  return membres[index];
}
/**
 * Affiche les poids
 * @method Layer::printWeight
 */
void Layer::printWeight(){
  for (int i =0; i < nbNeurone;i++){
    std::cout<<"Neurone numero : "<<i<<std::endl;
    membres[i]->printWeight();
  }
}
/**
 * @method Layer::getNbNeurones
 * @return Nombre de neurones
 */
int Layer::getNbNeurones(){
    return nbNeurone;
}
/**
 * @method Layer::getInput
 * @return Retourne le vecteur d'entrées
 */
std::vector<double> Layer::getInput(){
    return input;
}
std::vector<double> Layer::getOutput(){
    return output;
}

/**
 * Propagation en avant
 * @method Layer::fire
 * @param  input       Vecteur en entrées
 * @param  k           Coefficient de sigmoid
 * @return             Vecteur des valeurs d'activations
 */
std::vector<double> Layer::fire(std::vector<double> input, double k) {
  for (unsigned int i =0; i < input.size(); i ++){
    this->input[i] = input[i];
  }
  for (int i = 0; i < nbNeurone; i++){
    output[i] = membres[i]->fw_activate(membres[i]->fw_sum(input),k);
  }
return output;
}
