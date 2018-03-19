#include<iostream>
#include"OptionTab.h"
#include"Option.h"
#include<string>
#include"../Neurone/Neurone.h"
#include"../Neurone/fonctions.h"
#include<time.h>
using namespace std;

int main (int argc, char **argv) {

	OptionTab opts;
 	opts.AddOption(Option(1,"--help","-h","NONE","show help"));
	opts.AddOption(Option(2,"--version","-v","NONE","show the Neurone version"));
	opts.AddOption(Option(3,"--devellopers","-d","NONE","display author's names"));
	opts.AddOption(Option(4,"--bias","-b","NONE","Activate the bias"));
	opts.AddOption(Option(5,"--inputs","-f","STRING","load a csv file containing data"));
if(argc == 1){
 cout << "No Options entered, Demo Started..."<<endl;
}
else {
	for(int i = 1; i != argc; i++) {
        if ((argv[i] == opts.GetIntitul(argv[i]) || argv[i] == opts.GetRaccour(argv[i]))) {
    switch(opts.GetOptionID(argv[i])) {
	case 1 :
	 cout << "Usage : ./prog [OPTIONS] " << endl;
	 cout << "Available options :" << endl;
	 opts.PrintOptions();
 	break;
	case 2 :
	cout << "Boiii Neurone version 1.0" << endl;
	break;
	case 3 :
		cout << "Gaspard Coulet,\nFélix Guyard,\nJean Maurice Raboude,\nAreski Himeur,\nLucas Picasarri-Arrieta.\n" << endl;
	break;
	case 4 :
	int choix = 0; int n = 0;
	do {
	cout << "Would you like to set the number of inputs ?" << endl;
	cout << "1.Yes."<<endl;
	cout << "2.No start the demo."<<endl;
	cout << "Choice : "<<endl;
	cin>>choix;
	}while(choix != 1 || choix != 2);
	if(choix == 1){
	cout << "Number of inputs : "<<endl;
	cin>>n;
	}
	else {
	cout << "Demo Starting with the following configuration : \n "
	<< "Numer of inputs : 2 \n" << "Boii will learn the AND gate"<<endl;
	}
	vector <vector <double>> TruthTable = generateInput(n, 1);
	Neurone * boii = new Neurone();

	default:
	break;


	}
}
else { cout << "no valid options found, demo starting..." << endl; }
}

}

return 0;

}
