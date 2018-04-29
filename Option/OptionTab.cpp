#include"./OptionTab.h"
#include"./Option.h"
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
		std::cerr << "\033[0;31m ERROR [ "<< "Error when trying to create an option, to many options created" << " IN FILE " << __FILE__ << " AT LINE " << __LINE__ << " ] \n \033[0m";
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
Type::TypeEnum OptionTab::getArgument(const std::string &opt) const {
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
