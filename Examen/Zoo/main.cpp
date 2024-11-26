#include "Zoo.h"
#include <iostream>

int main() {
    // Création d'un Zoo
    Zoo myZoo("Safari Park");

    // Ajout d'animaux au Zoo
    myZoo.addAnimal(new Mammal("Leo", "Golden", "Tawny", "Carnivore", "Savanna", "Roar", false, 5, 190, 120));
    myZoo.addAnimal(new Bird("Eagle", "Brown", "Carnivore", "Mountains", "Screech", false, 4, 6, 40, 220));
    myZoo.addAnimal(new Reptile("Python", "Green", "Carnivore", "Rainforest", "Hiss", false, 7, 50, 500, "Striped"));
    myZoo.addAnimal(new Mammal("Elephant", "Grey", "None", "Herbivore", "Grassland", "Trumpet", false, 10, 5000, 300));

    // Liste des animaux dans le Zoo
    std::cout << "\nAnimals in the Zoo:" << std::endl;
    myZoo.listAnimals();

    // Création d'un nouvel animal inconnu
    Animal* newAnimal = new Animal("Unknown", "Golden", "Carnivore", "Savanna", "Roar", false, 3, 200, 130);

    // Prédiction avec KNN - Données numériques
    std::cout << "\nPredicting type (numerical):" << std::endl;
    std::string predictedTypeNumerical = myZoo.predictTypeWithKNN(newAnimal, 3, "numerical");
    std::cout << "Predicted type (numerical): " << predictedTypeNumerical << std::endl;

    // Prédiction avec KNN - Données catégoriques
    std::cout << "\nPredicting type (categorical):" << std::endl;
    std::string predictedTypeCategorical = myZoo.predictTypeWithKNN(newAnimal, 3, "categorical");
    std::cout << "Predicted type (categorical): " << predictedTypeCategorical << std::endl;

    // Suppression d'un animal par son nom
    std::cout << "\nRemoving animal 'Eagle':" << std::endl;
    myZoo.removeAnimalByName("Eagle");

    // Liste après suppression
    std::cout << "\nAnimals in the Zoo after removal:" << std::endl;
    myZoo.listAnimals();

    // Calcul de l'âge moyen des Mammals
    std::cout << "\nCalculating average age for Mammals:" << std::endl;
    double averageAgeMammals = myZoo.averageAgeForType("Mammal");
    std::cout << "Average age of Mammals: " << averageAgeMammals << " years." << std::endl;

    // Libération de la mémoire pour le nouvel animal
    delete newAnimal;

    return 0;
}
