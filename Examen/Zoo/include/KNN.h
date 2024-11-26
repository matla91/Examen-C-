#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename T>
class KNN {
protected:
    int k; // Nombre de voisins

public:
    // Constructeur par d�faut
    KNN() : k(3) {} // Par d�faut, on prend k = 3

    // Constructeur param�tr�
    KNN(int kVal) : k(kVal) {}

    // Getter pour 'k'
    int getK() const { return k; }

    // Fonction pour trouver les k plus proches voisins
    std::vector<int> findNearestNeighbours(const std::vector<T>& trainData, const T& target) {
        std::vector<std::pair<double, int>> distances;

        // Calculer la similarit� entre le target et chaque �l�ment de trainData
        for (int i = 0; i < trainData.size(); ++i) {
            double similarity = similarityMeasure(trainData[i], target);
            distances.emplace_back(similarity, i);
        }

        // Trier les distances par ordre croissant (plus grande similarit� en premier)
        std::sort(distances.begin(), distances.end());

        // R�cup�rer les indices des k plus proches voisins
        std::vector<int> neighbors;
        for (int i = 0; i < k && i < distances.size(); ++i) {
            neighbors.push_back(distances[i].second);
        }

        return neighbors;
    }

    // M�thode virtuelle pure pour mesurer la similarit�
    virtual double similarityMeasure(const T& a, const T& b) const = 0;

    // Virtual destructor
    virtual ~KNN() {}
};
