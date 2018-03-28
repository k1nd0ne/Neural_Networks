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
    SIGMOID
  } EnumFonctionActivation;

private:
  EnumFonctionActivation fonctionActivation;
  FonctionActivation(EnumFonctionActivation fonctionActivation);
  double getValeurActivation(double sum, double k = 0) const;
  EnumFonctionActivation getEnumFonctionActivation() const;
};
#endif
