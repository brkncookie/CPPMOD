#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

void	ScalarConverter::convert(std::string &str)
{
	double data = 0.0;

	if (ScalarConverter::valid_pseudo(str))
		format_print(data, &str);
	else if (ScalarConverter::valid_i(str, data) || ScalarConverter::valid_f(str, data) || ScalarConverter::valid_c(str, data))
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
		std::cout << "char: " << (std::isprint(ch) ? std::string("'") + std::string(&ch).erase(1) + std::string("'") : "Non displayable") << std::endl;
		if (in == INT_MIN && data != INT_MIN)
			std::cout << "int: " << "Non displayable" << std::endl;
		else
			std::cout << "int: " << in << std::endl;
		std::cout << "float: " << fl << (fl - in ? "f" : ".0f") << std::endl;
		std::cout << "double: " << data << (data -  in ? "" : ".0") << std::endl;
	}
}

bool	ScalarConverter::valid_i(std::string &str, double &data)
{
	long long	dig;
	long long	sig;
	int		inx;

	dig = 0;
	sig = (str[0] == '-' ? -1 : 1);
	inx = (str[0] == '-' || str[0] == '+');
	while (str[inx])
	{
		if (!std::isdigit(str[inx]))
			return (false);
		dig = dig * 10;
		dig = dig + (str[inx] - 48);
		if ((dig * sig) < INT_MIN || (dig * sig) > INT_MAX)
			return (false);
		inx++;
	}
	data = static_cast<double>(dig * sig);
	return (true);

}


bool	ScalarConverter::valid_f(std::string &str, double &data)
{
	char	*end_of_num;

	data = std::strtod(str.c_str(), &end_of_num);
	if (std::isnan(data) || std::isinf(data))
		return (false);
	if (!((end_of_num[0] == 'f' && !end_of_num[1]) || !end_of_num[0]))
			return (false);
	return (true);
}


bool	ScalarConverter::valid_c(std::string &str, double &data)
{
	if (str.length() == 1 && !(std::isdigit(str[0])))
	{
		data = static_cast<char>(str[0]);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::valid_pseudo(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		str.erase(str.end() - 1);
		return (true);
	}
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}
