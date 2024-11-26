#include "Mammal.h"
#include <iostream>

// Constructeur par défaut
Mammal::Mammal()
    : Animal(), furColor("Unknown") {}

// Constructeur paramétré
Mammal::Mammal(std::string name, std::string color, std::string furColor, std::string diet,
               std::string habitat, std::string sounds, bool isPet, int age, double weight, double height)
    : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height), furColor(furColor) {}

// Constructeur de copie
Mammal::Mammal(const Mammal& other)
    : Animal(other), furColor(other.furColor) {}

// Getter pour furColor
std::string Mammal::getFurColor() const {
    return furColor;
}

// Setter pour furColor
void Mammal::setFurColor(const std::string& newFurColor) {
    furColor = newFurColor;
}

// Override de la fonction printInfo
void Mammal::printInfo() const {
    std::cout << "Animal of type Mammal:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Fur Color: " << furColor << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Age: " << age << " years old" << std::endl;
    std::cout << "This animal is " << (isPet ? "a pet" : "not a pet") << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
}
