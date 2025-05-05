/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:05:49 by ncollign          #+#    #+#             */
/*   Updated: 2025/05/05 16:36:45 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;

	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			std::cout << "Learned a materia in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Cannot learn more materias: inventory full!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			std::cout << "MateriaSource creating a materia of type: " << type << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << "No materia of type " << type << " found" << std::endl;
    return (0);
}