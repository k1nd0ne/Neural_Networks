#include"Reseau.h"

using namespace std;

//Constructor
Reseau::Reseau(int nbLayers, std::vector<int> layerInformation){

 this->nbLayers = nbLayers;
 reseau = std::vector<Layer*>(nbLayers);
 cout<<"Init du layer d'entree de tant de neurones: "<< layerInformation[0]<<endl;
 reseau[0] = new Layer(Layer::INPUT,layerInformation[0],1);
 //To indicate that the first Layers is Always the Input layers
 cout<<"Init du layer de sortie de tant de neurones: "<< layerInformation[layerInformation.size()-1]<<endl;
 reseau[layerInformation.size()-1] = new Layer(Layer::OUTPUT,layerInformation[layerInformation.size()-1],layerInformation[layerInformation.size()-2]);
 //To indicate that the last layer is always the output layer.

 for(unsigned int i = 1; i < layerInformation.size()-1; i++){

	reseau[i] = new Layer(Layer::HIDDEN,layerInformation[i], layerInformation[i-1]);	//The others are just the 'Hidden' Layers

	}
}

//LEARNING AND BACKPROPAGATION METHOD//

std::vector<double> Reseau::fire_all(std::vector<double> input, double k) {
for (int i = 0; i< nbLayers; i++){
  input = reseau[i]->fire(input, k);
}
return input;

}

void Reseau::learn(std::vector<vector<vector<double> > > jeuxTest){
  for(unsigned int i = 0; i<jeuxTest.size();i++){
      output=fire_all(jeuxTest[i][0],1.0); //lol c'est un k
      backPropagation(jeuxTest[i][1],1.0,0.0005);//lol c'est un eta
  }
}

void Reseau::backPropagation(std::vector<double> output, double k, double eta){
    /*On initialise dans un premier temps nos trois matrices 3d*/
    int NbNeuronesMax = 0;
    for(int l = nbLayers - 1; l>0; l--){
        int inter = reseau[l]->getNbNeurones();
        if(inter > NbNeuronesMax){
            NbNeuronesMax = inter;
        }
    }
    double*** derrdact;
    double*** dsig;
    double*** dact;
    derrdact = new double**[nbLayers];
    dsig = new double**[nbLayers];
    dact = new double**[nbLayers];
    for(int l = nbLayers - 1; l>0; l--){
        derrdact[l] = new double*[NbNeuronesMax];
        dsig[l] = new double*[NbNeuronesMax];
        dact[l] = new double*[NbNeuronesMax];
        for(int i=0; i<NbNeuronesMax; i++){
            derrdact[l][i] = new double[NbNeuronesMax];
            dsig[l][i] = new double[NbNeuronesMax];
            dact[l][i] = new double[NbNeuronesMax];
        }
    }
    cout<<"Backprop init : ok"<<endl;

    for(int l = nbLayers - 1; l>0; l--){
        cout<<"Debut backprop pour le layer"<<l<<endl;
        Layer* layerCourant = (reseau[l]);
        for(int n = 0; n < layerCourant->getNbNeurones(); n++){
            cout<<"Parcours du Neurone "<<n<<" de la couche "<<l<<endl;
            Neurone* neuroneCourant = (layerCourant->getNeurone(n));
            double s = neuroneCourant->fw_sum(layerCourant->getInput());
            cout<<"Traitement des poids : ";
            int debug =0;
            for(int i=0; i < neuroneCourant->getNbPoids(); i++){
                cout<<"|";
                dact[l][n][i] = (layerCourant->getInput())[i];
                dsig[l][n][i] = s*(1-s);
                if(l == nbLayers - 1){
                    derrdact[l][n][i] = -2*(output[n] - neuroneCourant->fw_activate(s,k));
                }
                else{
                    double inter = 0;
                    for(int j = 0; j < reseau[l+1]->getNbNeurones(); j++){
                        double wj = (*((reseau[l+1]->getNeurone(j)))->getWeight())[i];
                        inter += wj * derrdact[l+1][j][i] * dsig[l+1][j][i];
                    }
                    derrdact[l][n][i] = inter;
                }
                debug = i;
            }
            cout<<" "<<debug+1<<endl;
        }
    }

    for(int l = nbLayers - 1; l>0; l--){
        Layer* layerCourant = (reseau[l]);
        for(int n = 0; n < reseau[l]->getNbNeurones(); n++){
            Neurone* neuroneCourant = (layerCourant->getNeurone(n));
            for(int i=0; i < neuroneCourant->getNbPoids(); i++){
                (*neuroneCourant->getWeight())[i] = (*neuroneCourant->getWeight())[i] - eta*derrdact[l][n][i]*dsig[l][n][i]*dact[l][n][i];
            }
        }
    }
    // for(int l = nbLayers - 1; l>0; l--){
    //     for(int i=0; i<NbNeuronesMax; i++){
    //          delete[] derrdact[l][i];
    //          delete[] dsig[l][i];
    //          delete[] dact[l][i];
    //     }
    //     delete[] derrdact[l];
    //     delete[] dsig[l];
    //     delete[] dact[l];
    // }
    // delete[] derrdact;
    // delete[] dsig;
    // delete[] dact;
}
