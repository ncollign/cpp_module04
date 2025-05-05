/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:34:51 by ncollign          #+#    #+#             */
/*   Updated: 2025/05/05 16:27:24 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i])
				delete(_inventory[i]);
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			delete(_inventory[i]);
	}
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i] == NULL)
			{
				_inventory[i] = m;
				std::cout << _name << " equipped materia in slot " << i << std::endl;
				return ;
			}
		}
		std::cout << _name << " cannot equip materia: inventory is full ! " << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		return ;
	if (_inventory[idx])
	{
		std::cout << _name << " unequipped materia from slot " << idx << std::endl;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}