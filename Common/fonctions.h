#ifndef FONCTIONS_H
#define FONCTIONS_H

#include<vector>
#include<unistd.h>
#include<string>

void printVec (std::vector<double> vec);
void printVec (std::vector<int> vec);
void printVec (std::vector<std::vector<double> > vec);
std::vector< std::vector <double> > getInput(char const * fileName);
std::vector <double> extractResult(std::vector< std::vector <double> > * input);
void swapVec (std::vector<std::vector<double> > * vec,std::vector <double> * result);
unsigned int int_to_int(unsigned k);
std::vector<std::vector<double > > generateInput (int n, bool estet);
void printVec (std::vector<std::vector<std::vector<double> > > vec);
void swapVec (std::vector<std::vector<double> > * input);
std::vector < std::vector <std::vector <double> > > getInputUltime(char const * fileName,float pourcentage);
unsigned int findIndMax(std::vector<double> vec);
void displayArchi(std::vector<int> info);
void startLauncher(std::string file, bool arch,int ep);
#endif
