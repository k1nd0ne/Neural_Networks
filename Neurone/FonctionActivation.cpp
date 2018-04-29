#include"./FonctionActivation.h"
#include <stdlib.h>
/**
 * Constructeur par défauts
 * @method FonctionActivation
 * @param  fonctionActivation Fonction activation à utiliser parmis l'enumération
 */
FonctionActivation::FonctionActivation(){
  this->fonctionActivation = SIGMOID;
}
/**
 * @method FonctionActivation::setFonctionActivation
 * @param  fonctionActivation                     Fonction activation à utiliser parmis l'enumération
 */
void FonctionActivation::setFonctionActivation(EnumFonctionActivation fonctionActivation){
  this->fonctionActivation = fonctionActivation;
}

/**
 * Constructeur
 * @method FonctionActivation
 * @param  fonctionActivation Fonction activation à utiliser parmis l'enumération
 */
FonctionActivation::FonctionActivation(EnumFonctionActivation fonctionActivation){
  this->fonctionActivation = fonctionActivation;
}

/**
 * @method getValeurActivation
 * @param  x                   Valeur de la variable
 * @param  k                   Constante de changement
 * @return                     Valeur d'activation
 */
double FonctionActivation::getValeurActivation(double x, double k) const{
  switch (fonctionActivation) {
    case IDENTITY:
      return x;
      break;
    case BINARYSTEP:
      return x>=0;
      break;
    case SIGMOID:
      return (1/(1+exp(-k*x)));
      break;
    case TAN:
      return ( (exp(x)-exp(-x)) / (exp(x)+exp(-x)));
      break;
    case SIN:
      return sin(x);
      break;
    case RELU:
      return x<0? 0 : x;
      break;
    case LRELU:
      return x<0? 0.01*x : x;
      break;
    case PRELU:
      return x<0? k*x : x;
      break;
    case ELU:
      return x<0? (k*(exp(x)-1)) : x;;
      break;
    default:
      return 0;
      break;
  }
}
/**
 * @method getValeurDerive
 * @param  x                   Valeur de la variable
 * @param  k                   Constante de changement
 * @return                     Valeur de la derivée
 */
double FonctionActivation::getValeurDerivee(double x, double k) const{
  switch (fonctionActivation) {
    case IDENTITY:
      return 1;
      break;
    case BINARYSTEP:
      return 0;
      break;
    case SIGMOID:
      return (k*exp(-k*x))* (1/(1+exp(-k*x)*(1+exp(-k*x))));
      break;
    case TAN:
      return 1 - pow(((exp(x)-exp(-x))/(exp(x)+exp(-x))),2);
      break;
    case SIN:
      return cos(x);
      break;
    case RELU:
      return x<0? 0 : 1;
      break;
    case LRELU:
      return x<0? 0.01 : 1;
      break;
    case PRELU:
      return x<0? k : 1;
      break;
    case ELU:
      return x<0? (k*(exp(x)-1)) + k : 1;
      break;
    default:
      return 0;
      break;
  }
}
