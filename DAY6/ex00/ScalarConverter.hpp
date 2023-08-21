#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <limits>
#include <cstdlib>


class ScalarConverter
{
	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);
		static bool	valid_i(std::string &str, double &data);
		static bool	valid_c(std::string &str, double &data);
		static bool	valid_f(std::string &str, double &data);
		static bool	valid_pseudo(std::string &str);
		static void	format_print(double data, std::string *str);
	public:
		static void	convert(std::string &str);
};
