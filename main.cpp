#include "./Neurone/NeuroneB.h"
#include "./Common/fonctions.h"
#include "./Option/OptionTab.h"
#include "./Neurone/FonctionActivation.h"
#include "./Neurone/Neurone.h"
#include "./Reseau/Reseau.h"
#include "./Option/Option.h"
#include "./Layer/Layer.h"
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <time.h>
#include <string>
#include <cmath>

/**
* @method main
* @param  argc Nombre d'argument
* @param  argv Tableaux des arguments
* @return      Code de sortie : 0 si sortie normal
*/
int main (int argc, char **argv) {

  /* Initialisation des options */
  OptionTab opts;
  enum Options {HELP,VERSION,DEVS,INPUT,OFF,ARCHI,EPOCH,ETA,GRAD,FCT};
  opts.addOption(Option( HELP,       "--help","-h",     Type::NONE,  "show help"));
  opts.addOption(Option( VERSION,    "--version","-v",  Type::NONE,  "show the Neurone version"));
  opts.addOption(Option( DEVS,       "--devs","-d",     Type::NONE,  "display author's names"));
  opts.addOption(Option( INPUT,      "--input","-i",    Type::NONE,  "configure the network to run a specific trainingSet"));
  opts.addOption(Option( OFF,        "--autooff","-o",  Type::FLOAT, "set the percentage of error to stop (can slow the learning)"));
  opts.addOption(Option( ARCHI,      "--archi","-a",    Type::NONE,  "display the architecture of the current configuration"));
  opts.addOption(Option( EPOCH,      "--epoch","-e",    Type::INT,   "Configure the max number of epoch"));
  opts.addOption(Option( ETA,        "--eta","-lr",     Type::FLOAT, "Configure the learning rate"));
  opts.addOption(Option( GRAD,       "--gradiant","-gr",Type::INT,   "Configure the number of epoch before doing the backpropagation (error average)"));
  opts.addOption(Option( FCT,        "--function","-f", Type::INT,   "Configure the activation function"));
  /* Configuration par défaut */
  std::string filename = "iris.csv";
  bool archi = false;
  double eta = 0.01;
  int epoch = 5000;
  unsigned int gradiant = 1;
  float auto_off = 0;
  FonctionActivation::EnumFonctionActivation fct = FonctionActivation::SIGMOID;

  /* Reconfiguration du réseau selon les arguments */
  for(int i = 1; i < argc; i++) {
    switch(opts.getOptionID(argv[i])) {
      case HELP :
      std::cout << "Usage : ./launcher [OPTIONS] " << std::endl;
      std::cout << "Available options :" << std::endl;
      opts.printOptions();
      return 0;
      break;

      case VERSION :
      std::cout << "Neural Network : version 1.0 " << std::endl;
      return 0;
      break;

      case DEVS :
      std::cout << "This tool was created by: [in alpabetic order]"<<std::endl<<"Gaspard Coulet"<<std::endl<<"Félix Guyard"<<std::endl<<"Areski Himeur"<<std::endl<<"Lucas Picasarri-Arrieta"<<std::endl<<"Jean Maurice Raboude"<<std::endl;
      return 0;
      break;

      case INPUT :
      {
        int choice;
        if (argc>i+1&&isdigit(*argv[i+1])) {
          choice = atoi(argv[i+1]);
          i++;
        }
        else{
          std::cout << "Please chose a file from the following list : "<<std::endl;
          std::cout << "\033[1;36m | [1] Cancer \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [2] Iris \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [3] Spam1 \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [4] Spam2 \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [5] Colis \033[0m"<<std::endl;
          std::cout << "\033[1;33m | [6] Select a file...\033[0m  "<<std::endl;
          std::cout << "Choice : ";
          std::cin>>choice;
        }
        while(choice < 1 || choice > 6){
          std::cout << "\033[1;31m Wrong input, please make a valid choice :\033[0m  ";
          std::cin>>choice;
        }
        switch(choice) {
          case 1 :
          filename = "cancerTraining.csv";
          break;
          case 2 :
          filename = "iris.csv";
          break;
          case 3 :
          filename = "spambase_57Attribs_2class.txt";
          break;
          case 4 :
          filename = "spambase.data";
          break;
          case 5 :
          filename = "ecoli_7attribs_8class.txt";
          break;
          case 6 :
          std::cout << "Enter filename (has to be in the trainingSet dir) :";
          std::cin>>filename;
          break;
        }
      }
      break;

      case OFF :
      if (argc>i+1&&isdigit(*argv[i+1])) {
        auto_off = atof(argv[i+1]);
        std::cout << "Auto_off percentage has been set to " << auto_off << std::endl;
        i++;
      }
      else {
        std::cout << "Please specify Auto_off percentage : ";
        std::cin >> auto_off;
      }
      break;

      case ARCHI :
      archi = true;
      break;

      case EPOCH :
      if (argc>i+1&&isdigit(*argv[i+1])) {
        epoch = atoi(argv[i+1]);
        std::cout << "Epoch has been set to " << epoch << std::endl;
        i++;
      }
      else {
        std::cout << "Please specify number of epoch : ";
        std::cin >> epoch;
      }
      break;

      case ETA :
      if (argc>i+1&&isdigit(*argv[i+1])) {
        eta = atof(argv[i+1]);
        std::cout<<"The learning rate has been set to "<<eta<<std::endl;
        i++;
      }
      else {
        std::cout << "Please specify ETA : ";
        std::cin >> eta;
      }
      break;
      case GRAD :
      if(argc>i+1&&isdigit(*argv[i+1])) {
        gradiant = atoi(argv[i+1]);
        std::cout<<"The gradient descent as been set to "<<gradiant<<std::endl;
        i++;
      }
      else {
        std::cout << "Please specify the gradiant : ";
        std::cin >> gradiant;
      }
      break;
      default :
      std::cout << "\033[1;31mAn argument could not be recognized. Please use "<<argv[0]<<" --help"<<std::endl;
      return 1;
      break;

      case FCT :
      {
        int choice;
        if (argc>i+1&&isdigit(*argv[i+1])) {
          choice = atoi(argv[i+1]);
          i++;
        }
        else{
          std::cout << "Please chose a function from the following list : "<<std::endl;
          std::cout << "\033[1;36m | [1] IDENTITY \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [2] BINARYSTEP \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [3] SIGMOID \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [4] TAN \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [5] SIN \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [6] RELU \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [7] LRELU \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [8] PRELU \033[0m"<<std::endl;
          std::cout << "\033[1;36m | [9] ELU \033[0m"<<std::endl;
          std::cout << "Choice : ";
          std::cin>>choice;
        }
        while(choice < 1 || choice > 9){
          std::cout << "\033[1;31m No function, please make a valid choice :\033[0m  ";
          std::cin>>choice;
        }
        switch(choice) {
          case 1 :
          fct = FonctionActivation::IDENTITY;
          break;
          case 2 :
          fct = FonctionActivation::BINARYSTEP;
          break;
          case 3 :
          fct = FonctionActivation::SIGMOID;
          break;
          case 4 :
          fct = FonctionActivation::TAN;
          break;
          case 5 :
          fct = FonctionActivation::SIN;
          break;
          case 6 :
          fct = FonctionActivation::RELU;
          break;
          case 7 :
          fct = FonctionActivation::LRELU;
          break;
          case 8 :
          fct = FonctionActivation::PRELU;
          break;
          case 9 :
          fct = FonctionActivation::ELU;
          break;
        }
      }
      break;
    }
  }

  /* Lancement */
  startLauncher(filename,archi,epoch,eta,gradiant,fct,auto_off);

  return 0;
}
