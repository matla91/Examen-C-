#include "Zoo.h"
#include <iostream>

int main() {
    // Cr�ation d'un Zoo
    Zoo myZoo("Safari Park");

    // Ajout d'animaux au Zoo
    myZoo.addAnimal(new Mammal("Leo", "Golden", "Tawny", "Carnivore", "Savanna", "Roar", false, 5, 190, 120));
    myZoo.addAnimal(new Bird("Eagle", "Brown", "Carnivore", "Mountains", "Screech", false, 4, 6, 40, 220));
    myZoo.addAnimal(new Reptile("Python", "Green", "Carnivore", "Rainforest", "Hiss", false, 7, 50, 500, "Striped"));
    myZoo.addAnimal(new Mammal("Elephant", "Grey", "None", "Herbivore", "Grassland", "Trumpet", false, 10, 5000, 300));

    // Liste des animaux dans le Zoo
    std::cout << "\nAnimals in the Zoo:" << std::endl;
    myZoo.listAnimals();

    // Cr�ation d'un nouvel animal inconnu
    Animal* newAnimal = new Animal("Unknown", "Golden", "Carnivore", "Savanna", "Roar", false, 3, 200, 130);

    // Pr�diction avec KNN - Donn�es num�riques
    std::cout << "\nPredicting type (numerical):" << std::endl;
    std::string predictedTypeNumerical = myZoo.predictTypeWithKNN(newAnimal, 3, "numerical");
    std::cout << "Predicted type (numerical): " << predictedTypeNumerical << std::endl;

    // Pr�diction avec KNN - Donn�es cat�goriques
    std::cout << "\nPredicting type (categorical):" << std::endl;
    std::string predictedTypeCategorical = myZoo.predictTypeWithKNN(newAnimal, 3, "categorical");
    std::cout << "Predicted type (categorical): " << predictedTypeCategorical << std::endl;

    // Suppression d'un animal par son nom
    std::cout << "\nRemoving animal 'Eagle':" << std::endl;
    myZoo.removeAnimalByName("Eagle");

    // Liste apr�s suppression
    std::cout << "\nAnimals in the Zoo after removal:" << std::endl;
    myZoo.listAnimals();

    // Calcul de l'�ge moyen des Mammals
    std::cout << "\nCalculating average age for Mammals:" << std::endl;
    double averageAgeMammals = myZoo.averageAgeForType("Mammal");
    std::cout << "Average age of Mammals: " << averageAgeMammals << " years." << std::endl;

    // Lib�ration de la m�moire pour le nouvel animal
    delete newAnimal;

    return 0;
}
