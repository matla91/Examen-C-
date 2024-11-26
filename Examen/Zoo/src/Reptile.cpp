#include "Reptile.h"
#include <iostream>

// Constructeur par défaut
Reptile::Reptile()
    : Animal(), scalePattern("Unknown") {}

// Constructeur paramétré
Reptile::Reptile(std::string name, std::string color, std::string diet, std::string habitat,
                 std::string sounds, bool isPet, int age, double weight, double height,
                 std::string scalePattern)
    : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height), scalePattern(scalePattern) {}

// Constructeur de copie
Reptile::Reptile(const Reptile& other)
    : Animal(other), scalePattern(other.scalePattern) {}

// Getter pour scalePattern
std::string Reptile::getScalePattern() const {
    return scalePattern;
}

// Setter pour scalePattern
void Reptile::setScalePattern(const std::string& newScalePattern) {
    scalePattern = newScalePattern;
}

// Override de la fonction printInfo
void Reptile::printInfo() const {
    std::cout << "Animal of type Reptile:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Age: " << age << " years old" << std::endl;
    std::cout << "This animal is " << (isPet ? "a pet" : "not a pet") << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
    std::cout << "Scale Pattern: " << scalePattern << std::endl;
}
