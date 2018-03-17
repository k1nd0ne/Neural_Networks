#include"Reseau.h"

using namespace std;

//Constructor
Reseau::Reseau(int nbLayers, std::vector<int> layerInformation){

 reseau = new vector<Layer*>(nbLayers); //init Layers;  
 this.nbLayers = nbLayers; 

 reseau[0] = new Layer(INPUT,layerInformation[0],1); 
 //To indicate that the first Layers is Always the Input layers
 
 reseau[layerInformation.size()-1] = new Layer(OUTPUT,layerInformation[layerInformation.size()-1],layerInformation[layerInformation.size()-2]); 
 //To indicate that the last layer is always the output layer.

 for(int i = 1; i < layerInformation.size()-1; i++){
   
	reseau[i] = new Layer(HIDDEN,layerInformation[i], layerInformation[i-1]);	//The others are just the 'Hidden' Layers
	
	}
}

//LEARNING AND BACKPROPAGATION METHOD//

vector<float> fire_all(vector<float> input) {

//à implémenter comme dirais dicky
}

void learn(vector<vector<vector<double>>> jeuxTest){
// à implémenter comme dirais dicky
return;
}
