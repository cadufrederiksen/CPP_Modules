/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:33:56 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 18:35:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN default construcor called" << std::endl;
}

RPN &RPN::operator=(const RPN &orig)
{
	if (this != &orig)
		_dq = orig._dq;
	std::cout << "RPN copy operator called" << std::endl;
	return *this;
}

RPN::RPN(const RPN &orig)
{
	*this = orig;
	std::cout << "RPN copy contructor called" << std::endl;
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

void	RPN::addDeque(std::string str)
{	
	int flag = 0;
	
	for (unsigned long x = 0; x < str.size(); x++)
	{
		
		if (str[x] != ' ')
		{
			if (std::isdigit(str[x]))
			{
				_dq.push_back(str[x] - '0');//adc  so numeros ao _dq
				flag += 1;
			}
			else if (flag < 2 && x <= 3)
			{
				std::cout << "Invalid format\n";
				exit(1);
			}
			else
				calculate(str[x]);
		}
	}
	std::cout << _dq[0] << std::endl;
}

int		RPN::calculate(char op)
{
	if (_dq.size() < 2)
	{
		std::cout << "Invalid format\n";
		exit(1);
	}
	
	int result;
	int v2 = _dq.back();
	_dq.pop_back();
		int v1 = _dq.back();
	_dq.pop_back();// a conta eh feita pelos numeros mais a direita

	switch (op)
	{
		case '*':
		result = v1 * v2;
		break;
		case '-':
		result = v1 - v2;
		break;
		case '+':
		result = v1 + v2;
		break;
		case '/':
		if (v2 == 0)
		{
			std::cerr << "Error" << std::endl;
			exit(0);
		}
		result = v1 / v2;
		break;
	}
	if (result > 2147483647 || result < -2147483647)
	{
		std::cout << "Result is out of the range" << std::endl;
		exit(1);		
	}
	_dq.push_back(result);
	return 1;
}