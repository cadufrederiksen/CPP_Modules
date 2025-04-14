/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:52:08 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 12:53:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class	BitcoinExchange
{
	private:
		std::map<std::string, double> _exchangeData; //serve para  armazenar o valor dos btc

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &orig);
		BitcoinExchange &operator=(const BitcoinExchange &orig);
		~BitcoinExchange();
		
		bool	getExchangeData(const std::string &file);
		void	returnValue(std::string date, double value);
		
};

#endif
