/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:17:35 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/28 14:49:31 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== Animals ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== WrongAnimals ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << wrongCat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    wrongCat->makeSound(); // appelle WrongAnimal::makeSound() à cause de l'absence de virtual
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
