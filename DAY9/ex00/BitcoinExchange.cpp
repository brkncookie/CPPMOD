#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	infile("data.csv");
	std::string row:

	if (infile.fail())
		this->throw_err(INV_FILE, NULL, 0);
	std::getline(infile, row);
	while( std::getline(infile, row))
		this->data_csv[row.substr(0, 10)] = std::strtod(row.substr(11, line.length()).c_str(), NULL);
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
		this->throw_err(INV_FILE, NULL, 0);
	std::getline(infile, row);
	while(std::getline(infile, row))
		valid_row(row, quantity, date) ? this->format_print(quantity, date) : throw_err(BAD_INP, row, 0);
}

void	BitcoinExchange::throw_err(errors type, std::string bad_input, float bad_quantity)
{
	if (type == ARG_CNT)
		throw "Usage: ./btc file_as_input";
	else if (type == INV_FILE)
		throw "Cannot open file.";
	else if (type == BAD_INP)
		throw (std::string("Error: bad input => ") + bad_input).c_str();
	else if (type == BAD_NUM)
	{
		if (bad_quantity < 0)
			throw "Error: not a positive number.";
		else
			throw "Error: too large a number.";
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
	return (it != this->data_csv.begin() : (--it)->second ? it->second);
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
	if (day < 0 || day > 31 || month < 0 || month > 2021 || year < 2009 || year > 2023)
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

}
