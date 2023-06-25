#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* ok = new Animal();
	Animal* cat = new Cat();
	Animal* dog = new Dog();
	WrongAnimal* lol = new WrongCat();

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << lol->getType() << std::endl;

	ok->makeSound();
	cat->makeSound();
	dog->makeSound();
	lol->makeSound();

	delete(ok);
	delete(cat);
	delete(dog);
	delete(lol);
}
