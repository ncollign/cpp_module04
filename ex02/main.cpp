/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:17:35 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/28 17:09:30 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Basic animal tests ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nSounds:" << std::endl;
    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n=== Deep copy tests ===" << std::endl;
    Dog basicDog;
    basicDog.getBrain()->setIdea(0, "Catch the ball!");
	basicDog.getBrain()->setIdea(1, "Eat!");


    Dog copyDog = basicDog;

    std::cout << "\nIdea 0 (basicDog): " << basicDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1 (basicDog): " << basicDog.getBrain()->getIdea(1) << std::endl;
	std::cout << "Idea 2 (basicDog): " << basicDog.getBrain()->getIdea(2) << std::endl;
    std::cout << "Idea 0 (copyDog): " << copyDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1 (copyDog): " << copyDog.getBrain()->getIdea(1) << std::endl;
	std::cout << "Idea 2 (copyDog): " << copyDog.getBrain()->getIdea(2) << std::endl;

    basicDog.getBrain()->setIdea(0, "Sleep...");

    std::cout << "\nAfter modifying basicDog's brain:" << std::endl;
    std::cout << "Idea 0 (basicDog): " << basicDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1 (basicDog): " << basicDog.getBrain()->getIdea(1) << std::endl;
	std::cout << "Idea 2 (basicDog): " << basicDog.getBrain()->getIdea(2) << std::endl;
    std::cout << "Idea 0 (copyDog): " << copyDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1 (copyDog): " << copyDog.getBrain()->getIdea(1) << std::endl;
	std::cout << "Idea 2 (copyDog): " << copyDog.getBrain()->getIdea(2) << std::endl;

    return (0);
}
