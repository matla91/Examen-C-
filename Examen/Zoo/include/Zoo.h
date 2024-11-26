#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <vector>
#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "KNN.h"
#include "KNNDouble.h"
#include "KNNString.h"

class Zoo {
private:
    std::string name;                // Nom du Zoo
    static const int MAX_CAPACITY;   // Capacité maximale du Zoo
    std::vector<Animal*> animals;    // Animaux dans le Zoo

public:
    // Constructeurs
    Zoo();
    explicit Zoo(std::string zooName);
    Zoo(const Zoo& other);

    // Destructeur
    ~Zoo();

    // Getters et setters pour le nom du Zoo
    std::string getName() const;
    void setName(const std::string& newName);

    // Liste des animaux dans le Zoo
    void listAnimals() const;

    // Ajouter un animal dans le Zoo
    void addAnimal(Animal* newAnimal);

    // Rechercher un animal par son nom
    int searchAnimalByName(const std::string& name) const;

    // Supprimer un animal par son nom
    void removeAnimalByName(const std::string& name);

    // Calculer l'âge moyen pour un type d'animal donné
    double averageAgeForType(const std::string& type) const;

    // Prédire le type d'animal avec KNN
    std::string predictTypeWithKNN(Animal* newAnimal, int k, const std::string& type);
};

#endif // ZOO_H
