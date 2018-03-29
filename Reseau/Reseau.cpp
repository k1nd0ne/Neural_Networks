#include"Reseau.h"

using namespace std;

/**
 * Constructeur
 * @method Reseau::Reseau
 * @param  nbLayers          Nombre de couche
 * @param  layerInformation  Vecteur descriptif de chaque layer
 * @param  k                 constante k dont depends la sigmoide
 * @param  eta               coefficient d'evolution
 */
Reseau::Reseau(int nbLayers, std::vector<int> layerInformation,double k,double eta) {
  this->eta = eta;
  this->k = k;
  input=std::vector<double>(layerInformation[0]);
  output=std::vector<double>(layerInformation[layerInformation.size()-1]);
  this->nbLayers = nbLayers;
  reseau = std::vector<Layer*>(nbLayers);
  cout << "\033[1;33m| Number of layers : \033[0m" << nbLayers << endl;
  cout << "\033[1;33m| Creating Input Layer \033[0m\n";
  reseau[0] = new InputLayer(layerInformation[0]);
  cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << 0 <<" : " << layerInformation[0] << endl;
  cout << "\033[1;33m| Creating Hidden + Output Layers \033[0m\n\n";
  for(unsigned int i = 1; i < layerInformation.size()-1; i++){
    reseau[i] = new Layer(Layer::HIDDEN,layerInformation[i], layerInformation[i-1]);	//The others are just the 'Hidden' Layers
    cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << i <<" : " << layerInformation[i] << endl;
  }
  reseau[layerInformation.size()-1] = new Layer(Layer::OUTPUT,layerInformation[layerInformation.size()-1],layerInformation[layerInformation.size()-2]);
  cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << layerInformation.size()-1 <<" : " << layerInformation[layerInformation.size()-1] << endl;
}
/**
 * Fire général
 * @method Reseau::fire_all
 * @param  input            Vecteur d'entrée
 * @return                  Valeur d'activation
 */
std::vector<double> Reseau::fire_all(std::vector<double> input) {
  for (int i = 0; i< nbLayers; i++){
    input = reseau[i]->fire(input, k);
  }
  for (unsigned int i = 0; i < output.size(); i ++){
    output[i]=input[i];
  }
  return output;
}
/**
 * Affichage des poids
 * @method Reseau::printWeight
 */
void Reseau::printWeight(){
  for (int i = 0; i < nbLayers;i++){
    std::cout<<"\n----------------------------------\nLayer : "<<i<<"\n----------------------------------\n";
    reseau[i]->printWeight();
  }
}
/**
 * Méthode d'apprentissage
 * @method Reseau::learn
 * @param  jeuxTest      Vecteur de vecteur de vecteur : décrivant en jeuxTest[i][0]
 *  le vecteur d'entrée et en jeuxTest[i][1] la sortie attendue
 */
void Reseau::learn(std::vector<std::vector<std::vector<double> > > jeuxTest){
  for(unsigned int i = 0; i<jeuxTest.size();i++){
    output=fire_all(jeuxTest[i][0]);
    backPropagation(jeuxTest[i][1]);
  }
}

/**
 * Méthode de propagation en arriére
 * @method Reseau::backPropagation
 * @param  output                  Sortie
 * @param  k                       Valeur du coefficient
 * @param  eta                     Valeur d'eta
 */
 void Reseau::backPropagation(std::vector<double> output){
   /*On initialise dans un premier temps nos trois matrices 3d*/
   std::vector<std::vector<std::vector<double> > > derrdact(nbLayers-1);
   std::vector<std::vector<std::vector<double> > > dsig(nbLayers-1);
   std::vector<std::vector<std::vector<double> > > dact(nbLayers-1);
   for(int l = 1; l<nbLayers; l++){
     derrdact[l-1] = std::vector<std::vector<double> >(reseau[l]->getNbNeurones());
     dsig[l-1] = std::vector<std::vector<double> >(reseau[l]->getNbNeurones());
     dact[l-1] = std::vector<std::vector<double> >(reseau[l]->getNbNeurones());
     for(int i=0; i<reseau[l]->getNbNeurones(); i++){
       derrdact[l-1][i] = std::vector<double>(reseau[l]->getNeurone(0)->getNbPoids());
       dsig[l-1][i] = std::vector<double>(reseau[l]->getNeurone(0)->getNbPoids());
       dact[l-1][i] = std::vector<double>(reseau[l]->getNeurone(0)->getNbPoids());
     }
   }
   for(int l = nbLayers - 1; l>0; l--){
     Layer* layerCourant = reseau[l];
     for(int n = 0; n < layerCourant->getNbNeurones(); n++){
       Neurone* neuroneCourant = (layerCourant->getNeurone(n));
       double s = neuroneCourant->fw_sum(layerCourant->getInput());
       for(int i=0; i < neuroneCourant->getNbPoids(); i++){
         if(i<neuroneCourant->getNbPoids()-1){
           dsig[l-1][n][i] = (layerCourant->getInput())[i];
         }
         else{
           dsig[l-1][n][i] = 1;
         }
         dact[l-1][n][i] = (k*exp(-k*s))* (1/(1+exp(-k*s)*(1+exp(-k*s))));
         if(l == nbLayers - 1){
           derrdact[l-1][n][i] = -2*(output[n] - neuroneCourant->fw_activate(s,k));
         }
         else{
           double inter = 0;
           for(int j = 0; j < reseau[l+1]->getNbNeurones(); j++){
             double wj = (*((reseau[l+1]->getNeurone(j)))->getWeight())[n];
             inter += wj * derrdact[l][j][n] * dact[l][j][n];
           }
           derrdact[l-1][n][i] = inter;
         }
       }
     }
   }
   for(int l = nbLayers - 1; l>0; l--){
     Layer* layerCourant = (reseau[l]);
     for(int n = 0; n < reseau[l]->getNbNeurones(); n++){
       Neurone* neuroneCourant = (layerCourant->getNeurone(n));
       for(int i=0; i < neuroneCourant->getNbPoids(); i++){
         vector<double> * w = neuroneCourant->getWeight();
         (*w)[i] = (*w)[i] - eta*derrdact[l-1][n][i]*dsig[l-1][n][i]*dact[l-1][n][i];
       }
     }
   }
 }
