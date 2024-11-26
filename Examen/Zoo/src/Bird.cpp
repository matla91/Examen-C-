#include "Bird.h"
#include <iostream>

// Constructeur par défaut
Bird::Bird()
    : Animal(), wingspan(0.0) {}

// Constructeur paramétré
Bird::Bird(std::string name, std::string color, std::string diet, std::string habitat,
           std::string sounds, bool isPet, int age, double weight, double height, double wingspan)
    : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height), wingspan(wingspan) {}

// Constructeur de copie
Bird::Bird(const Bird& other)
    : Animal(other), wingspan(other.wingspan) {}

// Getter pour wingspan
double Bird::getWingspan() const {
    return wingspan;
}

// Setter pour wingspan
void Bird::setWingspan(double newWingspan) {
    wingspan = newWingspan;
}

// Override de la fonction printInfo
void Bird::printInfo() const {
    std::cout << "Animal of type Bird:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Age: " << age << " years old" << std::endl;
    std::cout << "This animal is " << (isPet ? "a pet" : "not a pet") << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
    std::cout << "Wingspan: " << wingspan << " cm" << std::endl;
}
