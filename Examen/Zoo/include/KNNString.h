#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class KNNString : public KNN<std::vector<std::string>> {
public:
    // Constructeurs
    KNNString() : KNN() {}
    KNNString(int kVal) : KNN(kVal) {}

    // Implémentation de la mesure de similarité (Distance de Levenshtein)
    double similarityMeasure(const std::vector<std::string>& a, const std::vector<std::string>& b) const override {
        // Vérifier que les vecteurs ont la même taille
        if (a.size() != b.size()) {
            std::cerr << "Error: Vectors must have the same size for comparison." << std::endl;
            return std::numeric_limits<double>::max();
        }

        double totalDistance = 0.0;

        // Calculer la distance pour chaque paire de chaînes correspondantes
        for (size_t i = 0; i < a.size(); ++i) {
            totalDistance += levenshteinDistance(a[i], b[i]);
        }

        return totalDistance; // La similarité totale est la somme des distances individuelles
    }

private:
    // Calcul de la distance de Levenshtein entre deux chaînes
    int levenshteinDistance(const std::string& s1, const std::string& s2) const {
        size_t len1 = s1.size();
        size_t len2 = s2.size();

        // Initialiser la matrice de distances
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        // Initialisation des cas de base
        for (size_t i = 0; i <= len1; ++i) dp[i][0] = i;
        for (size_t j = 0; j <= len2; ++j) dp[0][j] = j;

        // Remplir la matrice de distances
        for (size_t i = 1; i <= len1; ++i) {
            for (size_t j = 1; j <= len2; ++j) {
                int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                dp[i][j] = std::min({dp[i - 1][j] + 1,    // Suppression
                                     dp[i][j - 1] + 1,    // Insertion
                                     dp[i - 1][j - 1] + cost}); // Substitution
            }
        }

        return dp[len1][len2]; // La distance entre les deux chaînes
    }
};
