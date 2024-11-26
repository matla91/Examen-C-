#include "Zoo.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

// Initialisation de la capacité maximale
const int Zoo::MAX_CAPACITY = 100;

// Constructeur par défaut
Zoo::Zoo() : name("Unnamed Zoo") {}

// Constructeur paramétré
Zoo::Zoo(std::string zooName) : name(zooName) {}

// Constructeur de copie
Zoo::Zoo(const Zoo& other) : name(other.name) {
    for (Animal* animal : other.animals) {
        animals.push_back(animal); // Copie des pointeurs, pas des objets
    }
}

// Destructeur
Zoo::~Zoo() {
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

// Getter pour le nom du Zoo
std::string Zoo::getName() const {
    return name;
}

// Setter pour le nom du Zoo
void Zoo::setName(const std::string& newName) {
    name = newName;
}

// Liste des animaux dans le Zoo
void Zoo::listAnimals() const {
    if (animals.empty()) {
        std::cout << "The Zoo is empty!" << std::endl;
        return;
    }
    for (const Animal* animal : animals) {
        animal->printInfo();
        std::cout << "-------------------" << std::endl;
    }
}

// Ajouter un animal dans le Zoo
void Zoo::addAnimal(Animal* newAnimal) {
    if (animals.size() >= MAX_CAPACITY) {
        std::cout << "The Zoo is at full capacity!" << std::endl;
        delete newAnimal; // Éviter les fuites mémoire
        return;
    }

    // Vérifier si un animal avec le même nom existe déjà
    auto it = std::find_if(animals.begin(), animals.end(), [&](Animal* a) {
        return a->getName() == newAnimal->getName();
    });

    if (it != animals.end()) {
        std::cout << "An animal with the name '" << newAnimal->getName() << "' already exists in the Zoo!" << std::endl;
        delete newAnimal; // Éviter les fuites mémoire
        return;
    }

    // Ajouter l'animal en ordre alphabétique
    auto insertPos = std::lower_bound(animals.begin(), animals.end(), newAnimal, [](Animal* a, Animal* b) {
        return a->getName() < b->getName();
    });
    animals.insert(insertPos, newAnimal);
}

// Rechercher un animal par son nom
int Zoo::searchAnimalByName(const std::string& name) const {
    auto it = std::lower_bound(animals.begin(), animals.end(), name, [](Animal* a, const std::string& name) {
        return a->getName() < name;
    });

    if (it != animals.end() && (*it)->getName() == name) {
        return std::distance(animals.begin(), it);
    }
    return -1;
}

// Supprimer un animal par son nom
void Zoo::removeAnimalByName(const std::string& name) {
    int index = searchAnimalByName(name);
    if (index == -1) {
        std::cout << "No animal with the name '" << name << "' exists in the Zoo!" << std::endl;
        return;
    }

    delete animals[index]; // Libérer la mémoire
    animals.erase(animals.begin() + index); // Supprimer de la liste
    std::cout << "Animal '" << name << "' removed from the Zoo." << std::endl;
}

// Calculer l'âge moyen pour un type d'animal donné
double Zoo::averageAgeForType(const std::string& type) const {
    int totalAge = 0;
    int count = 0;

    for (Animal* animal : animals) {
        if ((type == "Mammal" && dynamic_cast<Mammal*>(animal)) ||
            (type == "Bird" && dynamic_cast<Bird*>(animal)) ||
            (type == "Reptile" && dynamic_cast<Reptile*>(animal))) {
            totalAge += animal->getAge();
            count++;
        }
    }

    if (count == 0) {
        std::cout << "No animals of type '" << type << "' found in the Zoo!" << std::endl;
        return 0.0;
    }

    return static_cast<double>(totalAge) / count;
}

//KNN
std::string Zoo::predictTypeWithKNN(Animal* newAnimal, int k, const std::string& type) {
    // Vérifier que le Zoo a des animaux
    if (animals.empty()) {
        std::cerr << "Error: The Zoo is empty, cannot predict the type!" << std::endl;
        return "Unknown";
    }

    if (type == "numerical") {
        // Préparer les données numériques
        std::vector<std::pair<double, double>> trainData;
        std::unordered_map<int, std::string> typeMapping; // Map index to animal type

        for (size_t i = 0; i < animals.size(); ++i) {
            trainData.emplace_back(animals[i]->getWeight(), animals[i]->getHeight());
            if (dynamic_cast<Mammal*>(animals[i])) typeMapping[i] = "Mammal";
            else if (dynamic_cast<Bird*>(animals[i])) typeMapping[i] = "Bird";
            else if (dynamic_cast<Reptile*>(animals[i])) typeMapping[i] = "Reptile";
        }

        // Préparer la cible
        std::pair<double, double> target = {newAnimal->getWeight(), newAnimal->getHeight()};

        // Utiliser KNNDouble
        KNNDouble knn(k);
        std::vector<int> neighbors = knn.findNearestNeighbours(trainData, target);

        std::cout << "Using numerical KNN:" << std::endl;
            for (int index : neighbors) {
                std::cout << "Neighbor index: " << index
                << ", Type: " << typeMapping[index]
                << ", Data: {weight: " << trainData[index].first
                << ", height: " << trainData[index].second << "}"
                << std::endl;
}

        // Compter les types parmi les voisins
        std::unordered_map<std::string, int> typeCounts;
        for (int index : neighbors) {
            typeCounts[typeMapping[index]]++;
        }

        // Retourner le type le plus fréquent
        std::string predictedType;
        int maxCount = 0;
        for (const auto& [animalType, count] : typeCounts) {
            if (count > maxCount) {
                maxCount = count;
                predictedType = animalType;
            }
        }

        return predictedType;

    } else if (type == "categorical") {
        // Préparer les données catégoriques
        std::vector<std::vector<std::string>> trainData;
        std::unordered_map<int, std::string> typeMapping;

        for (size_t i = 0; i < animals.size(); ++i) {
            trainData.push_back({animals[i]->getColor(), animals[i]->getDiet(), animals[i]->getHabitat(), animals[i]->getSounds()});
            if (dynamic_cast<Mammal*>(animals[i])) typeMapping[i] = "Mammal";
            else if (dynamic_cast<Bird*>(animals[i])) typeMapping[i] = "Bird";
            else if (dynamic_cast<Reptile*>(animals[i])) typeMapping[i] = "Reptile";
        }

        // Préparer la cible
        std::vector<std::string> target = {newAnimal->getColor(), newAnimal->getDiet(), newAnimal->getHabitat(), newAnimal->getSounds()};

        // Utiliser KNNString
        KNNString knn(k);
        std::vector<int> neighbors = knn.findNearestNeighbours(trainData, target);

        // Debugging : Afficher les voisins pour les données catégoriques
        std::cout << "Using categorical KNN:" << std::endl;
        for (int index : neighbors) {
            std::cout << "Neighbor index: " << index
                    << ", Type: " << typeMapping[index]
                    << ", Data: {color: " << trainData[index][0]
                    << ", diet: " << trainData[index][1]
                    << ", habitat: " << trainData[index][2]
                    << ", sounds: " << trainData[index][3] << "}"
                    << std::endl;
}

        // Compter les types parmi les voisins
        std::unordered_map<std::string, int> typeCounts;
        for (int index : neighbors) {
            typeCounts[typeMapping[index]]++;
        }

        // Retourner le type le plus fréquent
        std::string predictedType;
        int maxCount = 0;
        for (const auto& [animalType, count] : typeCounts) {
            if (count > maxCount) {
                maxCount = count;
                predictedType = animalType;
            }
        }

        return predictedType;
    }

    // Si le type n'est pas reconnu
    std::cerr << "Error: Invalid type parameter. Use 'numerical' or 'categorical'." << std::endl;
    return "Unknown";
}
