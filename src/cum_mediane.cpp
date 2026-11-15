#include "cum_mediane.h"
#include <cmath>
#include <iterator>
#include <set>

int cum_médiane(const double* données_ptr, const int taille, double* sortie_ptr) {
    if (taille < 1) return ERROR_AUCUNE_DONNÉE;

    std::set<double> données_triées;
    std::set<double>::iterator médiane = données_triées.end();

    for (int indice = 0; indice < taille; ++indice) {
        const double valeur = données_ptr[indice];
        if (!std::isfinite(valeur)) return ERROR_DONNÉES_NON_FINIES;

        auto [position, insérée] = données_triées.insert(valeur);
        if (!insérée) return ERROR_DONNÉES_RÉPÉTÉES;

        const int taille_courante = static_cast<int>(données_triées.size());
        if (taille_courante == 1) médiane = position;
        else if (taille_courante % 2 == 0 && valeur < *médiane) --médiane;
        else if (taille_courante % 2 != 0 && valeur > *médiane) ++médiane;

        sortie_ptr[indice] = taille_courante % 2 != 0 ? *médiane : (*médiane + *std::next(médiane)) / 2.0;
    }
    return SUCCESS;
}
