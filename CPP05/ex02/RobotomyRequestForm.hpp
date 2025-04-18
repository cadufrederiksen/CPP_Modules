/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:49 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 22:11:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP
	
#include "Bureaucrat.hpp"
#include <cstdlib> 

class RobotomyRequestForm : public AForm
{
	public:
		//RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &orig);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &orig);
		~RobotomyRequestForm();
		
		void execute(Bureaucrat const &executor) const;
};

#endif