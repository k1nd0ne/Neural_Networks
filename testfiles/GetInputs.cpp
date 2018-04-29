#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<vector>
using namespace std;
void printVec (std::vector<std::vector<double> > vec){
  for (unsigned int i=0;i<vec.size();i++){
    for (unsigned int j=0;j<vec[i].size();j++){
      std::cout<<vec[i][j]<<",";
    }
    std::cout<<endl<<"----------"<<std::endl;
  }
}

int main(void){

        ifstream fichier("irisTraining.csv", ios::in);  // on ouvre le fichier en lecture
	 			ifstream in("irisTraining.csv"); //on veut aussi ouvrir pour connaitre la taille du fichier
        string ligne;
     	 	int nbLignes = 0;
    	 	while(std::getline(in, ligne))
         nbLignes++; //on compte les lignes...
         in.close(); //et on ferme le fichier

        if(fichier){
					vector< vector <double> > stock(nbLignes); //Tableau de chaine de caractère qui va contenir tout le fichier ligne par ligne.
					cout << nbLignes<<endl << endl;
					cout << "fichier ouvert avec success" << endl;
					string s;
					double temp = 0;
					string ligne;

	  			for (int j = 0; j < nbLignes; j++) {
						fichier>>ligne;
						stringstream ss(ligne);
						while (getline(ss, s, ',')) {  //strinsplit à partir du caractère ','
							temp = ::atof(s.c_str());
							stock[j].push_back(temp); //on stock chaque information dans une case.
						}
							}

					printVec(stock); //fonction d'affichage d'une matrice pour voir si tout va bien.
					fichier.close();  // on ferme le fichier
					}
					else {
            std::cerr << "\033[0;31m ERROR [ "<< "Can't open file" << " IN FILE " << __FILE__ << " AT LINE " << __LINE__ << " ] \n \033[0m";
						 }


        return 0;

}
