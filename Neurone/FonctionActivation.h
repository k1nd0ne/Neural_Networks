#ifndef _FONCTIONACTIVATION_H_
#define _NEURONE_H_
#include<math.h>
/**
 * L'objectif ce cette classe et d'être appeller pour l'activation
 * et donc changer plus facilement la fonction d'activation pour le test.
 */
class FonctionActivation {
public:
  typedef enum {
    IDENTITY,
    BINARYSTEP,
    SIGMOID,
    TAN,
    SIN,
    ELU
  } EnumFonctionActivation;

private:
  EnumFonctionActivation fonctionActivation;

public:
  FonctionActivation();
  FonctionActivation(EnumFonctionActivation fonctionActivation);

  void setFonctionActivation(EnumFonctionActivation fonctionActivation);
  double getValeurActivation(double sum, double k = 0) const;
  double getValeurDerivee(double sum, double k = 0) const;
};
#endif
