#ifndef SETTINGS_H
#define SETTINGS_H
#include<vector>

class Settings{
private:
  int nbrHiddenLayers;
  std::vector<int>* archi;
  std::vector<double>* differentOutputs = new std::vector<double>;
public:
  Settings(char const * fileName);
  int getNbrHiddenLayers();
  std::vector<int>* getArchi();
  std::vector<double>* getDifferentOutputs();

};

bool exists(double n,std::vector<double>* tab);

#endif
