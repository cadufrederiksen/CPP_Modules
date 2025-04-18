/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:20:20 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 18:35:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
	#define RPN_HPP
	
#include <iostream>
#include <deque>
#include <cstdlib>

class RPN
{
	private:
		std::deque<int> _dq;
	
	public:
		RPN();
		RPN(const RPN &orig);
		RPN &operator=(const RPN &orig);
		~RPN();
		
		void	addDeque(std::string str);
		int		calculate(char op);
};

#endif