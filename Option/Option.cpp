#include<string>
#include"Option.h"
#include"Type.h"
#include<iostream>

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
Option::Option(int id, const string &intitul, const string &rac, const std::string &type, const string &description) : m_id(id), m_intitul(intitul), m_rac(rac), m_type(type), m_description(description) {}
/**
 * @method Option::GetOptionId
 * @return ID de l'option
 */
int Option::GetOptionId() const { return m_id; }
/**
 * @method Option::GetOptionType
 * @return Type d'option
 */
string Option::GetOptionType() const { return m_type.GetType(); }
/**
 * @method Option::GetOptionInt
 * @return Intitulé de l'option
 */
string Option::GetOptionInt() const { return m_intitul; }
/**
 * @method Option::GetOptionRac
 * @return Raccourci de l'option
 */
string Option::GetOptionRac() const { return m_rac; }

/**
 * @method Option::SetOptionType
 * @param  t                     Nouveau type d'option
 */
void Option::SetOptionType(std::string &t ) { m_type.SetType(t); }
/**
 * @method Option::SetOptionInt
 * @param  intitul              Nouveau Intitulé
 */
void Option::SetOptionInt(std::string &intitul) { m_intitul = intitul; }
/**
 * @method Option::SetOptionRac
 * @param  rac                  Nouveau Raccourci
 */
void Option::SetOptionRac(std::string &rac) { m_rac = rac; }

/**
 * @method Option::SetOptionRac
 * @param  os                  Flux
 * @return Flux
 *
 */
std::ostream& operator<<(std::ostream& os) const;
	os << m_intitul << " (" << m_rac <<")"<<" <";m_type.affiche(); cout <<"> ""\t"<<m_description<<std::endl;
}
