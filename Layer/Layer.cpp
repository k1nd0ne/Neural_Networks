#include"Layer.h"
/*
prend en parametre un index I, renvoie le neurone numero I du Layer

*/

Neurone * Layer::getNeurone (int index){
  return membres[index];
}
/*
prend en parametres le vecteur d'entree, et fait feu dans cette couche
*/
// std::vector<double> Layer::fire(std::vector<double> in, double){
//   input = in;
//   for ( int i =0; i < nbNeurone; i ++){
//     output[i] = membres[i]->fire(input,k);// K A MODIFIER
//   }
//   return output;
// }
/*
constructeur, prend en parametres le type du layer, et nombre de neurones le composant, et le nombre d'input de chaque neurone
*/
Layer::Layer(TypeLayer type,int nbneur, int nbinput):nbNeurone(nbneur)
{
  std::cout<<"Creation "<<std::endl;
  membres = std::vector<Neurone*>(nbneur);
  for (int i =0; i < nbneur; i ++){
    membres[i]= new Neurone(nbinput);
    //membres[i].aleaWeights();//ON peut changer ca en faisant un call d'alea weight direct dans le constructeur de neurone
  }
}
int Layer::getNbNeurones(){
    return nbNeurone;
}

std::vector<double> Layer::getInput(){
    return input;
}

std::vector<double> Layer::fire(std::vector<double> input, double k) {
  this->input = input;
  output = std::vector<double>(nbNeurone);
  for (int i = 0; i < nbNeurone; i++){
    output[i] = membres[i]->fw_activate(membres[i]->fw_sum(input),k);
  }
return output;
}
