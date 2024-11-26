#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string name;
    std::string color;
    std::string diet;
    std::string habitat;
    std::string sounds;
    bool isPet;
    int age;
    double weight;
    double height;

public:
    // Constructeurs
    Animal();
    Animal(std::string name, std::string color, std::string diet, std::string habitat, std::string sounds,
           bool isPet, int age, double weight, double height);
    Animal(const Animal& other); // Constructeur de copie

    // Destructeur
    virtual ~Animal();

    // Méthodes
    virtual void printInfo() const;
    void makeSound() const;

    // Getters
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    std::string getDiet() const { return diet; }
    std::string getHabitat() const { return habitat; }
    std::string getSounds() const { return sounds; }
    bool getIsPet() const { return isPet; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setColor(const std::string& newColor) { color = newColor; }
    void setDiet(const std::string& newDiet) { diet = newDiet; }
    void setHabitat(const std::string& newHabitat) { habitat = newHabitat; }
    void setSounds(const std::string& newSounds) { sounds = newSounds; }
    void setIsPet(bool newIsPet) { isPet = newIsPet; }
    void setAge(int newAge) { age = newAge; }
    void setWeight(double newWeight) { weight = newWeight; }
    void setHeight(double newHeight) { height = newHeight; }
};

#endif // ANIMAL_H
