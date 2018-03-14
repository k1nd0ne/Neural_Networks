#include"Neurone.h"
#include<vector>
Neurone::Neurone(int taille, std::vector<double> * x){
    biais = false;
  w = x;
  n = taille;
}

Neurone::Neurone(int taille, std::vector<double> * x, double biais_w){
    biais = true;
    n = taille;
    w = x;
    w->push_back(biais_w);

}

Neurone::Neurone(int taille) {
  n = taille;
 biais = true;
aleaWeights();
}

double Neurone::fire(std::vector<double> x, double k)const{
  return fw_activate(fw_sum(x),k);
}
double Neurone::fw_sum(std::vector<double> x)const{
  double res=0;
  for(int i=0; i<n; i++){
      res += (x[i]) * (*w)[i];
  }

  if(biais){
        res += (*w)[n];
  }
  return res;
}

double Neurone::fw_activate(double sum, double k)const{
  return (1/(1+exp(-k*sum)));
}
double Neurone::derive_activate(double sum, double k)const{
  return (k*exp(-k*sum))* (1/(1+exp(-k*sum)*(1+exp(-k*sum))));
}

void Neurone::learn(std::vector<double> x,double o,double k, double mu){
  double sum = fw_sum(x);
  double res = fw_activate(sum,k);
  double derive = derive_activate(sum,k);
  for(int i=0; i<n; i++){
      (*w)[i]= (*w)[i]-  mu * (x[i]*derive*((o-res)*(-2)));
  }
  if(biais){
      (*w)[n] = (*w)[n]-  mu * (1*derive*((o-res)*(-2)));
  }
}
void Neurone::printWeight(){
    for(int i=0; i<n; i++){
        std::cout << "w" << i << " = " << (*w)[i] << std::endl;
    }
    if(biais){
        std::cout << "biais = " << (*w)[n] << std::endl;
    }
}

void Neurone::aleaWeights(){
  w = new std::vector<double> (n,0.0);
  std::default_random_engine generator(std::random_device{}());
  std::normal_distribution<double> distribution(0.5,0.2);
  for (int i=0; i<n; ++i) {
    (*w)[i] = distribution(generator);
  }
  if(biais){
    (*w).push_back(distribution(generator));
  }
}
