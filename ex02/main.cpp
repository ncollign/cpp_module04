/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:17:35 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/28 17:18:56 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Testing Dog and Cat ===" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
	//const Animal* meta = new Animal();
	// Interdit car classe abstraite (virtuelle)

    std::cout << "\nTypes:" << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n=== Testing deep copy Dog ===" << std::endl;
    Dog basicDog;
    basicDog.getBrain()->setIdea(0, "Chase the cat!");
    basicDog.getBrain()->setIdea(1, "Eat a bone!");

    Dog copiedDog = basicDog;

    std::cout << "\nIdeas before modifying:" << std::endl;
    std::cout << "basicDog idea 0: " << basicDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "copiedDog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    basicDog.getBrain()->setIdea(0, "Sleep...");

    std::cout << "\nIdeas after modifying basicDog:" << std::endl;
    std::cout << "basicDog idea 0: " << basicDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "copiedDog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}
