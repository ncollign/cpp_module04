/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:50:37 by ncollign          #+#    #+#             */
/*   Updated: 2025/05/05 16:30:57 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    // Création d'une source de materias
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Création d'un personnage
    ICharacter* me = new Character("me");

    // Création d'une materia de type "ice"
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    // Création d'une materia de type "cure"
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Utilisation des materias
    ICharacter* bob = new Character("bob");

    me->use(0, *bob); // utilise la materia "ice" sur bob
    me->use(1, *bob); // utilise la materia "cure" sur bob

    // Nettoyage
    delete bob;
    delete me;
    delete src;

    return 0;
}
