/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:38 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 22:15:29 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("name"), _grade(150)
{
	std::cout << "Bureaucrat default contructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &orig)
{
	if (this != &orig)
	{
		this->_grade = orig._grade;
		this->_name = orig._name;
	}
	std::cout << "Bureaucrat copy operator called" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = orig;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::IncrementGrade(int value)
{
	if (_grade - value < 1)
		throw Bureaucrat::GradeTooHighException();
	else 
		_grade -= value;
}

void Bureaucrat::DecrementGrade(int value)
{
	if (_grade + value > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += value;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getGrade() << ", Bureaucrat grade " << obj.getGrade();
	return (os);
}
