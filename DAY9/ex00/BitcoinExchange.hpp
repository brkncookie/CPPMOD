#pragma once

#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>

typedef enum e_errs
{
	ARG_CNT,
	INV_FILE,
	BAD_INP,
	BAD_NUM
} errors;

class BitcoinExchange
{
	private:
		std::map<std::string, float> data_csv;
		float	value_at_date(std::string &date);
		bool	valid_numeric(std::string &num);
		bool	valid_dmy(int day, int month, int year);
		bool	valid_row(std::string &row, float &quantity, std::string &date);
		void	format_print(float quantity, std::string &date);
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void	calculate_input(char *filename);
		void	throw_err(errors type, std::string bad_input, float bad_quantity);
};
