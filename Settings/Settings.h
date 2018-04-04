#ifndef SETTINGS_H
#define SETTINGS_H
#include<vector>

class settings{
private:
  int nbrHiddenLayers;
  std::vector<int>* archi;
  std::vector<double>* differentOutputs = new std::vector<double>;
public:
  int getNbrHiddenLayers();
  std::vector<int>* getArchi();
  std::vector<double>* getDifferentOutputs();
  settings(char const * fileName);

};

bool exists(double n,std::vector<double>* tab);

#endif
