#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename T>
class KNN {
protected:
    int k; // Nombre de voisins

public:
    // Constructeur par défaut
    KNN() : k(3) {} // Par défaut, on prend k = 3

    // Constructeur paramétré
    KNN(int kVal) : k(kVal) {}

    // Getter pour 'k'
    int getK() const { return k; }

    // Fonction pour trouver les k plus proches voisins
    std::vector<int> findNearestNeighbours(const std::vector<T>& trainData, const T& target) {
        std::vector<std::pair<double, int>> distances;

        // Calculer la similarité entre le target et chaque élément de trainData
        for (int i = 0; i < trainData.size(); ++i) {
            double similarity = similarityMeasure(trainData[i], target);
            distances.emplace_back(similarity, i);
        }

        // Trier les distances par ordre croissant (plus grande similarité en premier)
        std::sort(distances.begin(), distances.end());

        // Récupérer les indices des k plus proches voisins
        std::vector<int> neighbors;
        for (int i = 0; i < k && i < distances.size(); ++i) {
            neighbors.push_back(distances[i].second);
        }

        return neighbors;
    }

    // Méthode virtuelle pure pour mesurer la similarité
    virtual double similarityMeasure(const T& a, const T& b) const = 0;

    // Virtual destructor
    virtual ~KNN() {}
};
