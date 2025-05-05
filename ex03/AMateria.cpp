/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:03:01 by ncollign          #+#    #+#             */
/*   Updated: 2025/05/05 16:46:03 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return(_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "*default materia use effect *" << std::endl;
}