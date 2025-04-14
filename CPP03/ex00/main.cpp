/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:58 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 22:30:31 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	
	ClapTrap obj("obj");
	
	obj.attack("hola");
	

	obj.takeDamage(10);
	obj.attack("hola");
	obj.takeDamage(10);
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.beRepaired(7);
}