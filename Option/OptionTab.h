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
	void AddOption(const Option &opt);
	void PrintOptions() const;
	int GetOptionID(const std::string &opt) const;
	std::string GetArgument(const std::string &opt) const;
	std::string GetRaccour(const std::string &opt) const;
	std::string GetTypeOption(const std::string &opt) const;
	std::string GetIntitul(const std::string &opt) const;
};
#endif
