/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:58 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 22:20:14 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main ()
{
	FragTrap obj("hola");
	FragTrap outro(obj);
	ClapTrap test("name");
	
	test.attack("prueba");
	obj.highFivedGuys();
	outro.highFivedGuys();
}