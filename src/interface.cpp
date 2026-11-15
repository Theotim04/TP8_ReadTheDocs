#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <limits>
#include <stdexcept>
#include "cum_mediane.h"

namespace py = pybind11;

py::array_t<double> cum_médiane_python(py::array_t<double, py::array::c_style | py::array::forcecast> données) {
    const py::buffer_info entrée = données.request();
    if (entrée.ndim != 1) throw py::value_error("Le tableau doit avoir une dimension");
    if (entrée.size > std::numeric_limits<int>::max()) throw py::value_error("Le tableau est trop grand");

    const int taille = static_cast<int>(entrée.size);
    py::array_t<double> sortie(taille);
    const py::buffer_info résultat = sortie.request();
    const double* données_ptr = static_cast<const double*>(entrée.ptr);
    double* sortie_ptr = static_cast<double*>(résultat.ptr);

    const int statut = cum_médiane(données_ptr, taille, sortie_ptr);
    if (statut == ERROR_DONNÉES_RÉPÉTÉES) throw py::value_error("Données répétées dans le tableau");
    if (statut == ERROR_AUCUNE_DONNÉE) throw py::value_error("Le tableau ne peut pas être vide");
    if (statut == ERROR_DONNÉES_NON_FINIES) throw py::value_error("Les valeurs doivent être finies");
    if (statut != SUCCESS) throw std::runtime_error("Erreur pendant le calcul de la médiane cumulative");
    return sortie;
}

PYBIND11_MODULE(cum_mediane, module) {
    module.doc() = "Calcul des médianes cumulatives avec un algorithme C++ en O(N log N).";
    module.def("cum_médiane", &cum_médiane_python, R"doc(
Calcule la médiane de chaque préfixe d'un tableau NumPy.

Parameters
----------
données : numpy.ndarray
    Tableau unidimensionnel de nombres convertibles en double, sans doublons.

Returns
-------
numpy.ndarray
    Médiane des 1, 2, ..., N premières valeurs du tableau.

Raises
------
ValueError
    Si le tableau est vide, multidimensionnel, contient une valeur non finie
    ou des données répétées.

Examples
--------
>>> import numpy as np
>>> import cum_mediane
>>> cum_mediane.cum_médiane(np.array([2, 3, 0, 1, 5], dtype=float))
array([2. , 2.5, 2. , 1.5, 2. ])
)doc", py::arg("données"));
}
