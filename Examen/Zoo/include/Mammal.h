#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <string>

class Mammal : public Animal {
private:
    std::string furColor; // Couleur de la fourrure

public:
    // Constructeur par défaut
    Mammal();

    // Constructeur paramétré
    Mammal(std::string name, std::string color, std::string furColor, std::string diet,
           std::string habitat, std::string sounds, bool isPet, int age, double weight, double height);

    // Constructeur de copie
    Mammal(const Mammal& other);

    // Getter pour furColor
    std::string getFurColor() const;

    // Setter pour furColor
    void setFurColor(const std::string& newFurColor);

    // Override de la fonction printInfo
    void printInfo() const override;

    // Destructeur
    ~Mammal() override = default;
};

#endif // MAMMAL_H
