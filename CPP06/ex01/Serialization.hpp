/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:39:16 by carmarqu          #+#    #+#             */
/*   Updated: 2025/04/14 21:46:12 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
	#define SERIALIZATION_HPP

#include <iostream>
#include <inttypes.h>

typedef struct t_data{
	
	int num;	
	
} Data;

class Serialization
{
	private:
		Serialization();
		Serialization(const Serialization &orig);
		Serialization &operator=(const Serialization &orig);
		~Serialization();
	
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
		
		
		
};


#endif