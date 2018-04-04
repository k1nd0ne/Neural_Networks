/* Libs and Object */
#include<iostream>
#include"./Option/OptionTab.h"
#include"./Option/Option.h"
#include"./Neurone/Neurone.h"
#include"./Neurone/NeuroneB.h"
#include"./Layer/Layer.h"
#include"./Reseau/Reseau.h"
#include"./Common/fonctions.h"
#include<string>
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<cmath>

using namespace std;

int main (int argc, char **argv) {
 OptionTab opts;
 opts.addOption(Option(1,"--help","-h","NONE","show help"));
 opts.addOption(Option(2,"--version","-v","NONE","show the Neurone version"));
 opts.addOption(Option(3,"--devellopers","-d","NONE","display author's names"));
 opts.addOption(Option(4, "--input","-i","NONE","configure the network to run iris trainingSet"));
 opts.addOption(Option(5, "--archi","-a","NONE","display the architecture of the current configuration"));
 opts.addOption(Option(6, "--epoch","-e","NONE","Configure the number of epoch (int)"));
  string filename = "iris.csv";
  bool archi;
  int epoch = 5000;
  if(argc == 1){
   cout << "No Options entered, Demo Started..."<<endl;
   startLauncher(filename,true,epoch);
  }
  else {
    for(int i = 1; i != argc; i++) {
	if ((argv[i] == opts.getIntitul(argv[i]) || argv[i] == opts.getRaccour(argv[i]))) {
		switch(opts.getOptionID(argv[i])) {
		  case 1 :
		  cout << "Usage : ./prog [OPTIONS] " << endl;
		  cout << "Available options :" << endl;
		  opts.printOptions();
		  break;

		  case 2 :
		  cout << "Neural Network version 1.0 " << endl;
		  break;

		  case 3 :
		  cout << "Gaspard Coulet,\nFélix Guyard,\nJean Maurice Raboude,\nAreski Himeur,\nLucas Picasarri-Arrieta.\n" << endl;
		  break;

 		  case 4 :
		  int choice;
		  cout << "Please chose a file from the following list : "<<endl;
		  cout << " \033[1;36m  1.Cancer \033[0m "<<endl;
		  cout << "  \033[1;36m 2.Iris \033[0m "<<endl;
		  cout << "  \033[1;36m 3.Spam1 \033[0m"<<endl;
      cout << "  \033[1;36m 4.Spam2 \033[0m"<<endl;
	    cout << "  \033[1;36m 5.Colis \033[0m"<<endl;
		  cout << " \033[1;33m  6.I want to use my own file...\033[0m  "<<endl;
		  cout << "Choice : ";
		  cin>>choice;
		  while(choice < 1 || choice > 6){
		    cout << "\033[1;31mWrong input, please make a valid choice :\033[0m  ";cin>>choice;
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
		   	cout << "Enter filename (has to be in the trainingSet dir) :";
			cin>>filename;

		  break;
		  }
		  break;

   		case 5 :
		  archi = true;
		  break;
      case 6 :

      cout << "Please precise the number of epoch : ";
      cin>>epoch;
      cout << "epoch has been set to " << epoch << endl;
      break;
      default :
      break;



		}
	}
	else { cout << "no valid options found, see ./launch -h for help" << endl; }
    }
    startLauncher(filename,archi,epoch);

       }
return 0;
}
