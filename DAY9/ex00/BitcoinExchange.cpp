#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	infile("data.csv");
	std::string row;

	if (infile.fail())
	{
		this->throw_err(INV_FILE, "NULL", 0);
		std::exit(EXIT_FAILURE);
	}
	std::getline(infile, row);
	if (infile.eof() || row != std::string("date,exchange_rate"))
	{
		this->throw_err(INV_FILE, "NULL", 0);
		std::exit(EXIT_FAILURE);
	}
	while(std::getline(infile, row))
		this->data_csv[row.substr(0, 10)] = std::strtod(row.substr(11, row.length()).c_str(), NULL);
}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this->data_csv = obj.data_csv;
	return (*this);
}

void	BitcoinExchange::calculate_input(char *filename)
{
	std::string	row;
	std::string	date;
	float		quantity;
	std::ifstream	infile(filename);

	if (infile.fail())
	{
		this->throw_err(INV_FILE, "NULL", 0);
		std::exit(EXIT_FAILURE);
	}
	std::getline(infile, row);
	if (infile.eof() || row != std::string("date | value"))
	{
		this->throw_err(INV_FILE, "NULL", 0);
		std::exit(EXIT_FAILURE);
	}
	while(std::getline(infile, row) && !(quantity = 0))
		valid_row(row, quantity, date) ? this->format_print(quantity, date) : throw_err(BAD_INP, row, quantity);
}

void	BitcoinExchange::throw_err(errors type, std::string bad_input, float bad_quantity)
{
	if (type == ARG_CNT)
		std::cout << "Usage: ./btc file_as_input" << std::endl;
	else if (type == INV_FILE)
		std::cout <<  "Cannot open file." << std::endl;
	else if (type == BAD_INP && (bad_quantity >= 0 && bad_quantity <= 9999))
		std::cout << "Error: bad input => " <<  bad_input << std::endl;
	else if (type == BAD_NUM)
	{
		if (bad_quantity < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
	}
}

/* PRIVATE METHODS */

void	BitcoinExchange::format_print(float quantity, std::string &date)
{
	std::cout << date << " => " << quantity << " = " << this->value_at_date(date) * quantity << std::endl;
}


float BitcoinExchange::value_at_date(std::string &date)
{
	std::map<std::string, float>::iterator it = this->data_csv.upper_bound(date);
	return (it != this->data_csv.begin() ? (--it)->second : it->second);
}


bool	BitcoinExchange::valid_numeric(std::string &num)
{
	size_t inx;

	inx = 0;
	while (inx < num.length())
		if (!std::isdigit(num[inx++]))
			return (false);
	return (true);
}

bool	BitcoinExchange::valid_dmy(int day, int month, int year)
{
	if (day < 0 || day > 31 || month < 0 || month > 12 || year < 2009 || year > 2023)
		return (false);
	if (month == 11 || month == 9 || month == 6 || month == 4)
		return (day <= 30);
	if (month == 2 && ((!(year % 4) && (year % 100)) || !(year % 400)))
		return (day <= 29);
	else if (month == 2)
		return (day <= 28);
	return (true);
}

bool BitcoinExchange::valid_row(std::string &row, float &quantity, std::string &date)
{
	std::stringstream strm0;
	std::stringstream strm1;
	std::string	str0;
	std::string	str1;
	char	*endptr = NULL;

	int	day = 0;
	int	month = 0;
	int	year = 0;

	strm0.str(row);
	strm0 >> str0;

	/* to validate the date part in the file*/
	strm1.str(str0);
	std::getline(strm1, str1, '-');
	if (!str1.empty() && !valid_numeric(str1))
		return (false);
	year = std::strtol(str1.c_str(), NULL, 10);
	std::getline(strm1, str1, '-');
	if (!str1.empty() && !valid_numeric(str1))
		return (false);
	month = std::strtol(str1.c_str(), NULL, 10);
	std::getline(strm1, str1, '-');
	if (!str1.empty() && !valid_numeric(str1))
		return (false);
	day = std::strtol(str1.c_str(), NULL, 10);
	if (std::getline(strm1, str1, '-') || !valid_dmy(day, month, year))
		return (false);
	date = str0;

	/* check if we got a metal pipe */
	strm0 >> str0;
	if (!str0.empty() && str0[0] != '|')
		return (false);
	else if (str0.empty())
		return (false);
	/* get what is after the metal pipe */
	strm0 >> str0;
	if (!str0.empty())
		quantity = strtod(str0.c_str(), &endptr);
	if (*endptr)
		return (false);
	else if (quantity < 0 || quantity > 9999)
		return (this->throw_err(BAD_NUM, "NULL", quantity), false);
	if (!strm0.eof())
		return (false);
	return (true);
}
