#ifndef _OPTION_TAB_H_
#define _OPTION_TAB_H_
#include"Option.h"
#include"Type.h"
#include<string>
class OptionTab {
	private:
	Option m_Tab[10];
 	size_t m_nb_options;
	public:
	OptionTab();
	void addOption(const Option &opt);
	void printOptions() const;
	int getOptionID(const std::string &opt) const;
	Type::TypeEnum getArgument(const std::string &opt) const;
	std::string getRaccour(const std::string &opt) const;
	std::string getTypeOption(const std::string &opt) const;
	std::string getIntitul(const std::string &opt) const;
};
#endif
