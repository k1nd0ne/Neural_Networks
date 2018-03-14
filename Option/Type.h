#ifndef _TYPE_H
#define _TYPE_H
#include<string>
#include<iostream>
class Type {


private :
	std::string m_type;
public :
	Type();
	Type(std::string type); 	
	void affiche() const;
	void SetType(std::string type);
	std::string GetType() const;
};
#endif
