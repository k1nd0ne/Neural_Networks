#ifndef _INPUTLAYER_H_
#define _INPUTLAYER_H_
#include "./Layer.h"

class InputLayer : public Layer {
public:
  InputLayer(int,FonctionActivation::EnumFonctionActivation fct);
  std::vector<double> fire(std::vector<double>, double);
};
#endif
