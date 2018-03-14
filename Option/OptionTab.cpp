#include"OptionTab.h"
#include"Option.h"
#include<exception>
#include<string>
#include<iostream>


	OptionTab::OptionTab() : m_Tab(), m_nb_options(0) {}

	void OptionTab::AddOption(const Option &opt) {
	if (m_nb_options == 10) {
	std::cerr<<"erreur lors de la création de l'option Nb max d'option atteint"<<std::endl;
	std::terminate();
	}
	else {


	m_Tab[m_nb_options] = opt;
	m_nb_options++;
	}
}

	void OptionTab::PrintOptions() const {
	std::cout << " Vos Option : "<<std::endl;
	for (size_t i = 0; i < m_nb_options; i++) {
	m_Tab[i].printOPT();
		}
   	}


	int OptionTab::GetOptionID(const std::string &opt) const{
	  int i = 0;
	  bool trouve = false;
		while (i < 10 && trouve == false ) {
		if (m_Tab[i].GetOptionInt() == opt || m_Tab[i].GetOptionRac() == opt) {
		trouve = true;
		}
		i++;
	}
		return m_Tab[i-1].GetOptionId();
	}

	std::string OptionTab::GetArgument(const std::string &opt) const {
	  int i = 0;
	  bool trouve = false;
		while (i < 10 && trouve == false ) {
		if (m_Tab[i].GetOptionInt() == opt || m_Tab[i].GetOptionRac() == opt ) {
		trouve = true;
		}
		i++;
	}
		return m_Tab[i-1].GetOptionType();
	}

	std::string OptionTab::GetRaccour(const std::string &opt) const {
	  int i = 0;
	  bool trouve = false;
		while (i < 10 && trouve == false ) {
		if (m_Tab[i].GetOptionRac() == opt || m_Tab[i].GetOptionInt() == opt ) {
		trouve = true;
		}
		i++;
	}
	return m_Tab[i-1].GetOptionRac();
	 }

	std::string OptionTab::GetIntitul(const std::string &opt) const {
	  int i = 0;
	  bool trouve = false;
		while (i < 10 && trouve == false ) {
		if (m_Tab[i].GetOptionInt() == opt || m_Tab[i].GetOptionRac() == opt) {
		trouve = true;
		}
		i++;
	}
	return m_Tab[i-1].GetOptionInt();
	 }
