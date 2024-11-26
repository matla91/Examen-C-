#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"
#include <string>

class Reptile : public Animal {
private:
    std::string scalePattern; // Motif des écailles

public:
    // Constructeur par défaut
    Reptile();

    // Constructeur paramétré
    Reptile(std::string name, std::string color, std::string diet, std::string habitat,
            std::string sounds, bool isPet, int age, double weight, double height,
            std::string scalePattern);

    // Constructeur de copie
    Reptile(const Reptile& other);

    // Getter pour scalePattern
    std::string getScalePattern() const;

    // Setter pour scalePattern
    void setScalePattern(const std::string& newScalePattern);

    // Override de la fonction printInfo
    void printInfo() const override;

    // Destructeur
    ~Reptile() override = default;
};

#endif // REPTILE_H
