#include <iostream>
#include <vector>
#include <cmath>
#include <utility> // Pour std::pair

class KNNDouble : public KNN<std::pair<double, double>> {
public:
    // Constructeurs
    KNNDouble() : KNN() {} // Appel du constructeur par défaut de KNN
    KNNDouble(int kVal) : KNN(kVal) {}

    // Implémentation de la mesure de similarité (distance Euclidienne)
    double similarityMeasure(const std::pair<double, double>& a, const std::pair<double, double>& b) const override {
        double weightDiff = a.first - b.first;   // Différence des poids
        double heightDiff = a.second - b.second; // Différence des tailles
        return std::sqrt(weightDiff * weightDiff + heightDiff * heightDiff); // Distance Euclidienne
    }

};
