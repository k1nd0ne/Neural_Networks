#include"./NeuroneB.h"

NeuroneB::NeuroneB(int taille,std::vector<double> * x, double biais_w){
    n = taille;
    w = x;
    w->push_back(biais_w);
}

NeuroneB::NeuroneB(int taille) {
  n = taille;
  aleaWeights();
}

void NeuroneB::printWeight(){
  Neurone::printWeight();
  std::cout << "biais = " << (*w)[n] << std::endl;
}

void NeuroneB::aleaWeights(){
  Neurone::aleaWeights();
  std::default_random_engine generator(std::random_device{}());
  std::normal_distribution<double> distribution(0.5,0.2);
  (*w).push_back(distribution(generator));
}

void NeuroneB::learn(std::vector<double> x,double o,double k, double mu){
  double sum = fw_sum(x);
  double res = fw_activate(sum,k);
  double derive = derive_activate(sum,k);
  for(int i=0; i<n; i++){
      (*w)[i]= (*w)[i]-  mu * (x[i]*derive*((o-res)*(-2)));
  }
  (*w)[n] = (*w)[n]-  mu * (1*derive*((o-res)*(-2)));
}

double NeuroneB::fw_sum(std::vector<double> x)const{
  double res = Neurone::fw_sum(x);
  res += (*w)[n];
  return res;
}
int NeuroneB::getNbPoids(){
  return n+1;
}
