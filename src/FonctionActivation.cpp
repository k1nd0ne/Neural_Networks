#include"../obj/FonctionActivation.h"
/**
 * Constructeur
 * @method FonctionActivation
 * @param  fonctionActivation Fonction activation à utiliser parmis l'enumération
 */
FonctionActivation::FonctionActivation(EnumFonctionActivation fonctionActivation){
  this->fonctionActivation = fonctionActivation;
}
/**
 * @method getEnumFonctionActivation
 * @return Fonction activation utiliser parmis l'enumération
 */
FonctionActivation::EnumFonctionActivation FonctionActivation::getEnumFonctionActivation() const{return fonctionActivation;}
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
  }
}
