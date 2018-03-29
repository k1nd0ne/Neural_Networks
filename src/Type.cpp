#include"Type.h"
#include<iostream>
#include<string>
	Type::Type() : m_type() {}

	Type::Type(std::string type) {

	if ( type == "NONE" ) {
	m_type = type;
	}

	else if( type == "ENTIER") {
	m_type = type;
	}

	else if (type == "REEL") {
	m_type = type; }

	else if (type == "STRING") {
	m_type = type; }

	else { 	std::cerr<<"TYPE INCONNUE AU BATAILLONS MON AMI"<<std::endl; }
	}

	void Type::affiche() const {
	std::cout<<m_type;
	}
	void Type::setType(std::string type) { 
	m_type = type; 
	}

	std::string Type::getType() const {
		return m_type;
	}
