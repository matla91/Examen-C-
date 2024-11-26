#include <iostream>
#include <vector>
#include <cmath>
#include <utility> // Pour std::pair

class KNNDouble : public KNN<std::pair<double, double>> {
public:
    // Constructeurs
    KNNDouble() : KNN() {} // Appel du constructeur par d�faut de KNN
    KNNDouble(int kVal) : KNN(kVal) {}

    // Impl�mentation de la mesure de similarit� (distance Euclidienne)
    double similarityMeasure(const std::pair<double, double>& a, const std::pair<double, double>& b) const override {
        double weightDiff = a.first - b.first;   // Diff�rence des poids
        double heightDiff = a.second - b.second; // Diff�rence des tailles
        return std::sqrt(weightDiff * weightDiff + heightDiff * heightDiff); // Distance Euclidienne
    }

};
