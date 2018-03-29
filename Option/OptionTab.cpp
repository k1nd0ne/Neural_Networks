#include"OptionTab.h"
#include"Option.h"
#include<exception>
#include<string>
#include<iostream>
/**
 * Constructeur par défauts
 * @method OptionTab::OptionTab
 */
OptionTab::OptionTab() : m_Tab(), m_nb_options(0) {}
/**
 * Ajoute une option
 * @method OptionTab::AddOption
 * @param  opt                  [description]
 */
void OptionTab::addOption(const Option &opt) {
	if (m_nb_options == 10) {
		std::cerr<<"Erreur lors de la création de l'option : nombre maximum d'option atteint"<<__FILE__<<__LINE__<<std::endl;
		std::terminate();
	}
	else {
		m_Tab[m_nb_options] = opt;
		m_nb_options++;
	}
}
/**
 * Affiche les options
 * @method OptionTab::PrintOptions
 */
void OptionTab::printOptions() const {
	std::cout << " Vos Option : "<<std::endl;
	for (size_t i = 0; i < m_nb_options; i++) {
		std::cout << m_Tab[i] << '\n';
	}
}
/**
 * @method OptionTab::GetOptionID
 * @param  opt                    Nom de l'option
 * @return                        ID de cette option
 */
int OptionTab::getOptionID(const std::string &opt) const{
	int i = 0;
	bool trouve = false;
	while (i < 10 && trouve == false ) {
		if (m_Tab[i].getOptionInt() == opt || m_Tab[i].getOptionRac() == opt) {
			trouve = true;
		}
		i++;
	}
	return m_Tab[i-1].getOptionID();
}
/**
 * @method OptionTab::GetArgument
 * @param  opt                    Nom de l'option
 * @return                        Argument de cette option
 */
std::string OptionTab::getArgument(const std::string &opt) const {
	int i = 0;
	bool trouve = false;
	while (i < 10 && trouve == false ) {
		if (m_Tab[i].getOptionInt() == opt || m_Tab[i].getOptionRac() == opt ) {
			trouve = true;
		}
		i++;
	}
	return m_Tab[i-1].getOptionType();
}
/**
 * @method OptionTab::getRaccour
 * @param  opt                   Nom de l'option
 * @return                       Raccourci de cette option
 */
std::string OptionTab::getRaccour(const std::string &opt) const {
	int i = 0;
	bool trouve = false;
	while (i < 10 && trouve == false ) {
		if (m_Tab[i].getOptionRac() == opt || m_Tab[i].getOptionInt() == opt ) {
			trouve = true;
		}
		i++;
	}
	return m_Tab[i-1].getOptionRac();
}
/**
 * @method OptionTab::getIntitul
 * @param  opt                   Nom de l'option
 * @return                       Intitulé de cette option
 */
std::string OptionTab::getIntitul(const std::string &opt) const {
	int i = 0;
	bool trouve = false;
	while (i < 10 && trouve == false ) {
		if (m_Tab[i].getOptionInt() == opt || m_Tab[i].getOptionRac() == opt) {
			trouve = true;
		}
		i++;
	}
	return m_Tab[i-1].getOptionInt();
}
