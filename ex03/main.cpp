/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:50:37 by ncollign          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:54 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testMateriaSource()
{
	std::cout << "\n=== MateriaSource Deep Copy Test ===\n";
	MateriaSource original;
	original.learnMateria(new Ice());
	original.learnMateria(new Cure());

	MateriaSource copy(original);

	AMateria* m1 = copy.createMateria("ice");
	AMateria* m2 = copy.createMateria("cure");

	delete m1;
	delete m2;
}

void testCharacterInventory()
{
	std::cout << "\n=== Character Inventory Test ===\n";
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* hero = new Character("Hero");
	Character* enemy = new Character("Enemy");

	// Remplir l'inventaire
	for (int i = 0; i < 5; i++)
	{
		AMateria* m = src->createMateria(i % 2 == 0 ? "ice" : "cure");
		if (m)
		{
			hero->equip(m);
			if (i >= 4)
				delete(m);
		}
	}

	// Utiliser chaque slot (certains seront vides)
	for (int i = 0; i < 4; ++i)
		hero->use(i, *enemy);

	// Une deep copy
	Character* clone = new Character(*hero);
	std::cout << "\n=== After Copy ===\n";
	for (int i = 0; i < 4; ++i)
		clone->use(i, *enemy);

	delete hero;
	delete clone;
	delete enemy;
	delete src;
}

void testUnequip()
{
	std::cout << "\n=== Unequip Test ===\n";
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	Character* hero = new Character("Hero");
	AMateria* m = src->createMateria("ice");

	hero->equip(m);
	hero->unequip(0);  // Le pointeur n’est pas delete ici, donc on doit le faire à la main
	delete m;

	delete hero;
	delete src;
}

int main()
{
	std::cout << "=== Comprehensive Tests ===\n" << std::endl;

	testMateriaSource();
	testCharacterInventory();
	testUnequip();

	std::cout << "\n=== Done ===\n";
	return 0;
}

