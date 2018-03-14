#include<string>
#include"Option.h"
#include"Type.h"
#include<iostream>
using namespace std;
	Option::Option() : m_id(-1), m_intitul(), m_rac(), m_type(), m_description(){}
	
	Option::Option(int id, const string &intitul, const string &rac, const std::string &type, const string &description) : m_id(id), m_intitul(intitul), m_rac(rac), m_type(type), m_description(description) {}
	
	int Option::GetOptionId() const { return m_id; }	
	string Option::GetOptionType() const { return m_type.GetType(); }
	string Option::GetOptionInt() const { return m_intitul; }
	string Option::GetOptionRac() const { return m_rac; }
	
	void Option::SetOptionType(std::string &t ) { m_type.SetType(t); }
	void Option::SetOptionInt(std::string &intitul) { m_intitul = intitul; }
	void Option::SetOptionRac(std::string &rac) { m_rac = rac; }
	void Option::printOPT() const {
	cout << m_intitul << " (" << m_rac <<")"<<" <";m_type.affiche(); cout <<"> ""\t"<<m_description<<endl;
} 
