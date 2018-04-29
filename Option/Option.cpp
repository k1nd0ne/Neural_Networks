#include<string>
#include"./Option.h"
#include".//Type.h"
#include<iostream>
using namespace std;
/**
* Constructeur d'option vide
* @method Option::Option
*/
Option::Option() : m_id(-1), m_intitul(), m_rac(), m_type(), m_description(){}
/**
 * Constructeur par arguments
 * @method Option::Option
 * @param  id             ID de l'option
 * @param  intitul        Intitulé de l'option
 * @param  rac            Raccourci de l'option
 * @param  type           Type d'option
 * @param  description    Description de l'option
 */
Option::Option(int id, const string &intitul, const string &rac, const Type::TypeEnum type, const string &description) : m_id(id), m_intitul(intitul), m_rac(rac), m_type(type), m_description(description) {}
/**
 * @method Option::GetOptionId
 * @return ID de l'option
 */
int Option::getOptionID() const { return m_id; }
/**
 * @method Option::GetOptionType
 * @return Type d'option
 */
Type::TypeEnum Option::getOptionType() const { return m_type.getType(); }
/**
 * @method Option::GetOptionInt
 * @return Intitulé de l'option
 */
string Option::getOptionInt() const { return m_intitul; }
/**
 * @method Option::GetOptionRac
 * @return Raccourci de l'option
 */
string Option::getOptionRac() const { return m_rac; }

/**
 * @method Option::SetOptionType
 * @param  t                     Nouveau type d'option
 */
void Option::setOptionType(Type::TypeEnum t ) { m_type.setType(t); }
/**
 * @method Option::SetOptionInt
 * @param  intitul              Nouveau Intitulé
 */
void Option::setOptionInt(std::string &intitul) { m_intitul = intitul; }
/**
 * @method Option::SetOptionRac
 * @param  rac                  Nouveau Raccourci
 */
void Option::setOptionRac(std::string &rac) { m_rac = rac; }

/**
 * Méthode d'affichage en complément de <<
 * @method print
 * @param  os    Flux
 */
void Option::print(std::ostream& os) const{
	os << m_intitul << " (" << m_rac <<")"<<" <" << m_type <<"> ""\t"<<m_description<<std::endl;
}

std::ostream& operator<<(std::ostream& os, Option o )
{
	o.print(os);
  return os;
}
