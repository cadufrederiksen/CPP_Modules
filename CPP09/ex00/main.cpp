/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:02:13 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/07 17:03:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool check_input(std::string date, std::string rate)
{
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	
	for (int x = 0; x < 3; x++)
	{
		if (!std::isdigit(year[x]))
			return false;
		if (x < 2 && !std::isdigit(month[x]) && !std::isdigit(day[x]))
			return false; 
	}
	
	int y = std::stoi(year); 
	int m = std::stoi(month);
	int d = std::stoi(day);
	
	if (m < 1 || m > 12 || d < 1 || d > 31 || y < 2009)
		return false; 
		
	for (char c : rate)
	{
		if (!std::isdigit(c) && c != '.')
			return false;	
	}


	return true;
}

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	std::string line, date, pipe, rate;
	bool firstflag = true;
	 
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (!btc.getExchangeData("data.csv") || !infile.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		if (firstflag)
		{
			if (line != "date | value")
			{
				std::cerr << "Wrong first line in the input file" << std::endl;
				return (1);
			}
			firstflag = false;
		}	
		else if (iss >> date >> pipe >> rate)//separa os valores de line por espaço, na respectiva ordem
		{
			if (!check_input(date, rate) || pipe != "|")
				std::cerr << "Error: Bad input => " << date << std::endl;
			else if (std::stod(rate) > 2147483647)
				std::cerr << "Error: too large number." << std::endl;
			else if (std::stod(rate) < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				btc.returnValue(date, std::stod(rate));
		}
		else
		{
			std::cerr << "Error: Bad input => " << date << std::endl;
			return (1);
		}	

	
	}
	infile.close();
}