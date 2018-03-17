#ifndef FONCTIONS_H
#define FONCTIONS_H

#include<vector>

void printVec (std::vector<double> vec);
void printVec (std::vector<std::vector<double> > vec);
std::vector< std::vector <double> > getInput(char const * fileName);
std::vector <double> extractResult(std::vector< std::vector <double> > * input,unsigned int pos);
void swapVec (std::vector<std::vector<double> > * vec,std::vector <double> * result);


#endif
