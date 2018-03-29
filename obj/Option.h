#ifndef _OPTION_H_
#define _OPTION_H_
#include<string>
#include"Type.h"
class Option {
	private :
	int m_id;
	std::string m_intitul,m_rac;
	Type m_type;
	std::string m_description;
	public :
	Option();
	Option(int id, const std::string &intitul, const std::string &m_rac, const std::string &type, const std::string &m_description);
	int getOptionID() const;
	std::string getOptionType() const;
	std::string getOptionInt() const;
	std::string getOptionRac() const;
	void setOptionType(std::string &t);
	void setOptionInt(std::string &intitul);
	void setOptionRac(std::string &rac);
	void print(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, Option o);
#endif
