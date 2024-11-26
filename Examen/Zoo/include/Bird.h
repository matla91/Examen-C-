#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <string>

class Bird : public Animal {
private:
    double wingspan; // Envergure des ailes en cm

public:
    // Constructeur par défaut
    Bird();

    // Constructeur paramétré
    Bird(std::string name, std::string color, std::string diet, std::string habitat,
         std::string sounds, bool isPet, int age, double weight, double height, double wingspan);

    // Constructeur de copie
    Bird(const Bird& other);

    // Getter pour wingspan
    double getWingspan() const;

    // Setter pour wingspan
    void setWingspan(double newWingspan);

    // Override de la fonction printInfo
    void printInfo() const override;

    // Destructeur
    ~Bird() override = default;
};

#endif // BIRD_H
