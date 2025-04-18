/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:54 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 18:13:43 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig)
{
	*this = orig;
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &orig)
{
	if (this != &orig)
		_exchangeData = orig._exchangeData;
	std::cout << "BitcoinExchange copy operator called" << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

bool BitcoinExchange::getExchangeData(const std::string &file)
{
	std::ifstream infile(file.c_str());
	std::string date, value, line;
	if (!infile.is_open())
		return false;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		if (line == "date,exchange_rate")
			continue ; //pula uma linha do bucle
		else if (std::getline(iss, date, ',') && std::getline(iss, value) && std::isdigit(line[0]))
			this->_exchangeData[date] = std::atoi(value.c_str());
		else
			std::cerr << "Error parsing the line " << line << std::endl;
	}
	return true;
}

void BitcoinExchange::returnValue(std::string date, double value)
{
	std::map<std::string, double>::iterator it = _exchangeData.find(date);
	double price;
	
	if (it != _exchangeData.end())
		price = it->second;
	else //find() devuelve end() si no encontra o valor 
	{
		it = _exchangeData.upper_bound(date);
		if (it != _exchangeData.begin())
			it--;
		price = it->second;
	}
	std::cout << date << " => " << value << " => " << price * value << std::endl;
}
