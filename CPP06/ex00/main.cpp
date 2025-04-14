/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:34:51 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 21:56:05 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool check_input(std::string str)
{
	for (unsigned long x = 0; x < str.size(); x++)
	{
		if(x > 1 && !std::isdigit(str[x]))
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	if(check_input(argv[1]))
		ScalarConverter::converter(argv[1]);
	else
		std::cout << "Insert a valid parameter!\n";
	return 0;
}