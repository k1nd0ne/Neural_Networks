#include<iostream>
#include"OptionTab.h"
#include"Option.h"
#include<string>
#include<time.h>  
using namespace std;

int main (int argc, char **argv) {
	OptionTab opts;
	opts.addOption(Option(1,"--help","-h","NONE","show help"));
	opts.addOption(Option(2,"--version","-v","NONE","show the Neurone version"));
	opts.addOption(Option(3,"--devellopers","-d","NONE","display author's names"));
	opts.addOption(Option(4,"--latex","-l","NONE","Generate a latex output to watch the network configuration"));
	opts.addOption(Option(5,"--inputs","-f","STRING","load a csv file containing data"));
	if(argc == 1){
		cout << "No Options entered, Demo Started..."<<endl;
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
					default:
					break;


				}
			}
			else { cout << "no valid options found, demo starting..." << endl; }
		}

	}

	return 0;

}
