/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:16:58 by ncollign          #+#    #+#             */
/*   Updated: 2025/05/05 16:23:52 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

Cure::Cure(const Cure &other) : AMateria(other)
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}