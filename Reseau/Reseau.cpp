#include"Reseau.h"

using namespace std;

//Constructor
Reseau::Reseau(int nbLayers, std::vector<int> layerInformation){

  this->nbLayers = nbLayers;
 reseau = std::vector<Layer*>(nbLayers);
 cout << "\033[1;33m| Number of layers : \033[0m" << nbLayers << endl;
 cout << "\033[1;33m| Creating Input Layer \033[0m\n";
 reseau[0] = new InputLayer(layerInformation[0]);
 cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << 0 <<" : " << layerInformation[0] << endl;
 //To indicate that the first Layers is Always the Input layers
 // for(unsigned int i = 0; i < layerInformation.size(); i++){
   //   cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << i <<" : " << layerInformation[i] << endl;
 // }

 //To indicate that the last layer is always the output layer.
      cout << "\033[1;33m| Creating Hidden + Output Layers \033[0m\n\n";
 for(unsigned int i = 1; i < layerInformation.size()-1; i++){

   reseau[i] = new Layer(Layer::HIDDEN,layerInformation[i], layerInformation[i-1]);    //The others are just the 'Hidden' Layers
   cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << i <<" : " << layerInformation[i] << endl;
 }
 reseau[layerInformation.size()-1] = new Layer(Layer::OUTPUT,layerInformation[layerInformation.size()-1],layerInformation[layerInformation.size()-2]);
 cout << "\033[1;33m| Number of Neurone on Layer number \033[0m " << layerInformation.size()-1 <<" : " << layerInformation[layerInformation.size()-1] << endl;
}

//LEARNING AND BACKPROPAGATION METHOD//

std::vector<double> Reseau::fire_all(std::vector<double> input, double k) {
  for (int i = 0; i< nbLayers; i++){
    input = reseau[i]->fire(input, k);
  }
  return input;

}
void Reseau::printWeight(){
  for (int i = 0; i < nbLayers;i++){
  std::cout<<"\n----------------------------------\nLayer : "<<i<<"\n----------------------------------\n";
    reseau[i]->printWeight();
  }
}

void Reseau::learn(std::vector<vector<vector<double> > > jeuxTest){
  for(unsigned int i = 0; i<jeuxTest.size();i++){
    output=fire_all(jeuxTest[i][0],1.0); //lol c'est un k
    backPropagation(jeuxTest[i][1],1.0,0.05);//lol c'est un eta ( le com a la fin de backprop, lui passe)
  }
}

void Reseau::backPropagation(std::vector<double> output, double k, double eta){
  /*On initialise dans un premier temps nos trois matrices 3d*/
  std::vector<std::vector<std::vector<double> > > derrdact(nbLayers-1);
  std::vector<std::vector<std::vector<double> > > dsig(nbLayers-1);
  std::vector<std::vector<std::vector<double> > > dact(nbLayers-1);
  for(int l = 1; l<nbLayers; l++){
    derrdact[l-1] = std::vector<std::vector<double> >(reseau[l]->getNbNeurones());
    dsig[l-1] = std::vector<std::vector<double> >(reseau[l]->getNbNeurones());
    dact[l-1] = std::vector<std::vector<double> >(reseau[l]->getNbNeurones());
    for(int i=0; i<reseau[l]->getNbNeurones(); i++){
      derrdact[l-1][i] = std::vector<double>(reseau[l]->getNeurone(0)->getNbPoids()+1);
      dsig[l-1][i] = std::vector<double>(reseau[l]->getNeurone(0)->getNbPoids()+1);
      dact[l-1][i] = std::vector<double>(reseau[l]->getNeurone(0)->getNbPoids()+1);
    }
  }
  //cout<<"Backprop init : ok"<<endl;
  for(int l = nbLayers - 1; l>0; l--){
    //  cout<<"Debut backprop pour le layer"<<l<<endl;
    Layer* layerCourant = reseau[l];
    for(int n = 0; n < layerCourant->getNbNeurones(); n++){
      //    cout<<"Parcours du Neurone "<<n<<" de la couche "<<l<<endl;
      Neurone* neuroneCourant = (layerCourant->getNeurone(n));
      double s = neuroneCourant->fire(layerCourant->getInput(),1);
      //  cout<<"Traitement des poids : ";
    //  int debug =0;
      for(int i=0; i < neuroneCourant->getNbPoids(); i++){ //getNbPoids()+1
        //      cout<<"|";
          if(i<neuroneCourant->getNbPoids()-1){
              dact[l-1][n][i] = (layerCourant->getInput())[i];
          }
          else{
              dact[l-1][n][i] = 1;
          }
        dsig[l-1][n][i] = s*(1-s);
        if(l == nbLayers - 1){
          derrdact[l-1][n][i] = -2*(output[n] - neuroneCourant->fw_activate(s,k));
        }
        else{
          double inter = 0;
          for(int j = 0; j < reseau[l+1]->getNbNeurones(); j++){
            double wj = (*((reseau[l+1]->getNeurone(j)))->getWeight())[i];
            inter += wj * derrdact[l][j][i] * dsig[l][j][i];
          }
          derrdact[l-1][n][i] = inter;
        }
      //  debug = i;
      }
      //cout<<" "<<debug+1<<endl;
    }
  }
  //printTab(derrdact);
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
