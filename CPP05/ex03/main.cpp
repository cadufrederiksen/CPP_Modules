/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:40 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 22:08:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
    try 
    {
        Intern randomGuy;
        Bureaucrat bure(1, "Oliver");
        AForm *form = randomGuy.makeForm("shrubbery creation", "Dom pedro");
        bure.signForm(*form);
        form->execute(bure);
        delete form;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& c)
    {
        std::cerr << c.what() << std::endl;
    }
    
    return 0;
}