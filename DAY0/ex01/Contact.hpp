#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>


class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string GetFN(void);
		std::string GetLN(void);
		std::string GetNN(void);
		std::string GetPN(void);
		std::string GetDS(void);

		std::string fn;
		std::string ln;
		std::string nn;
		std::string pn;
		std::string ds;
};
