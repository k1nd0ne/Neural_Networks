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
	int GetOptionId() const;
	std::string GetOptionType() const;
	std::string GetOptionInt() const;
	std::string GetOptionRac() const;
	void SetOptionType(std::string &t);
	void SetOptionInt(std::string &intitul);
	void SetOptionRac(std::string &rac);
	std::ostream& operator<<(std::ostream& os) const;
};
#endif
