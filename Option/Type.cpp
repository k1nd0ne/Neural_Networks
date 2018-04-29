#include"./Type.h"
#include<iostream>
#include<string>
/**
* Constructeur par défaut
* @method Type::Type
*/
Type::Type() : m_type() {}

/**
* Constructeur avec arguments
* @method Type::Type
* @param  type       Nom du type
*/
Type::Type(Type::TypeEnum type) {
	m_type = type;
}

/**
 * Affiche dans le flux une chaine de caractére décrivant le type
 * @method Type::print
 * @param  os          Flux
 */
void Type::print(std::ostream& os) const {
	switch (m_type) {
		case NONE:
			os << "NONE";
			break;
		case INT:
			os << "ENTIER";
			break;
		case FLOAT:
			os << "REEL";
			break;
		case STRING:
			os << "STRING";
			break;
		default :
			std::cerr << "\033[0;31m ERROR [ "<< "Can't recognize option type" << " IN FILE " << __FILE__ << " AT LINE " << __LINE__ << " ] \n \033[0m";
			break;
			};
}

/**
* @method Type::setType
* @param  type          Nouveau type
*/
void Type::setType(Type::TypeEnum type) {
	m_type = type;
}

/**
* @method Type::getType
* @return Type
*/
Type::TypeEnum Type::getType() const {
	return m_type;
}

std::ostream& operator<<(std::ostream& os, Type t){
	t.print(os);
  return os;
}
