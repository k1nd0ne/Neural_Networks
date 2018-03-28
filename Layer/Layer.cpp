#include"./Layer.h"
/*
prend en parametre un index I, renvoie le neurone numero I du Layer

*/
Layer::Layer(){}
Neurone * Layer::getNeurone (int index){
  return membres[index];
}
/*
constructeur, prend en parametres le type du layer, et nombre de neurones le composant, et le nombre d'input de chaque neurone
*/
Layer::Layer(TypeLayer type,int nbneur, int nbinput):nbNeurone(nbneur)
{

  membres = std::vector<Neurone*>(nbneur);

    for (int i =0; i < nbneur; i ++){
      membres[i]= new NeuroneB(nbinput);
      //membres[i].aleaWeights();//ON peut changer ca en faisant un call d'alea weight direct dans le constructeur de neurone
  }
}
void Layer::printWeight(){
  for (int i =0; i < nbNeurone;i++){
    std::cout<<"Neurone numero : "<<i<<std::endl;
    membres[i]->printWeight();
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
