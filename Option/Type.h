#ifndef _TYPE_H
#define _TYPE_H
#include<string>
#include<iostream>

class Type {
public:
	enum TypeEnum {
		NONE,
		INT,
		FLOAT,
		STRING
	};
	private :
	Type::TypeEnum m_type;
	public :
	Type();
	Type(Type::TypeEnum type);
	void print(std::ostream& os) const;
	void setType(Type::TypeEnum type);
	Type::TypeEnum getType() const;
};
std::ostream& operator<<(std::ostream& os, Type t);
#endif
