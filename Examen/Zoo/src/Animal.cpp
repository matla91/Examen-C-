#include "Animal.h"
#include <iostream>

// Constructeur par défaut
Animal::Animal()
    : name("Unknown"), color("Unknown"), diet("Unknown"), habitat("Unknown"),
      sounds("Unknown"), isPet(false), age(0), weight(0.0), height(0.0) {}

// Constructeur paramétré
Animal::Animal(std::string name, std::string color, std::string diet, std::string habitat, std::string sounds,
               bool isPet, int age, double weight, double height)
    : name(name), color(color), diet(diet), habitat(habitat), sounds(sounds),
      isPet(isPet), age(age), weight(weight), height(height) {}

// Constructeur de copie
Animal::Animal(const Animal& other)
    : name(other.name), color(other.color), diet(other.diet), habitat(other.habitat), sounds(other.sounds),
      isPet(other.isPet), age(other.age), weight(other.weight), height(other.height) {}

// Destructeur
Animal::~Animal() {}

// Méthode pour afficher les informations de l'animal
void Animal::printInfo() const {
    std::cout << "Animal of unknown type:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Age: " << age << " years old" << std::endl;
    std::cout << "This animal is " << (isPet ? "a pet" : "not a pet") << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
}

// Méthode pour produire le son de l'animal
void Animal::makeSound() const {
    std::cout << "This animal makes the sound: " << sounds << std::endl;
}
