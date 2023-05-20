#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter	&ScalarConverter::operaotr=(const ScalarConverter &obj)
{
	(void)obj;
}

void	ScalarConverter::convert(std::string &str)
{
	double data;

	if (this->valid_pseudo(str))
		format_print(data, &str);
	else if (this->valid_i(str, data) || this->valid_f(str, data) || this->valid_c(str, data))
		format_print(data, NULL);
	else
		std::cout << "Invalid Conversion" << std::endl;
}

void	ScalarConverter::format_print(double data, std::string *str)
{
	char	ch;
	int	in;
	float	fl;

	if (str)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << *str << "f" << std::endl;
		std::cout << "double: " << *str << std::endl;
	}
	else
	{
		ch = static_cast<char>(data);
		in = static_cast<int>(data);
		fl = static_cast<float>(data);
		std::cout << "char: " << (std::isprint(ch) ? "'" << ch << "'" : "Non displayable") << std::endl;
		std::cout << "int: " << in << std::endl;
		std::cout << "float: " << fl << (fl - in ? "f" : ".0f") << std::endl;
		std::cout << "double: " << data << (data -  in ? "" : ".0") << std::endl;
	}
}

bool	ScalarConverter::valid_i(std::string &str, double &data)
{

}


bool	ScalarConverter::valid_f(std::string &str, double &data)
{

}


bool	ScalarConverter::valid_c(std::string &str, double &data)
{
	if (std.length() == 1 && !(std::isdigit(s[0])))
		(data = static_cast<char>(std), return (true));
	return (false);

}

bool	ScalarConverter::valid_pseudo(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		(str.pop_back(), return (true));
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}
