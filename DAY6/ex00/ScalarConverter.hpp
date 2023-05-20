#include <iostream>

class ScalarConverter
{
	private:
		bool	valid_i(std::string str, double &data);
		bool	valid_c(std::string str, double &data);
		bool	valid_f(std::string str, double &data);
		bool	valid_pseudo(std::string str);
		void	format_print(double data, std::string *str);
	public:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);
		static void	convert(std::string &str);
}
