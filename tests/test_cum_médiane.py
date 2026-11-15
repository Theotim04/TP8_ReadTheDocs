import numpy as np
import pytest
import cum_mediane


def test_cinq_données_diapo():
    données = np.array([2, 3, 0, 1, 5], dtype=float)
    attendues = np.array([2, 2.5, 2, 1.5, 2], dtype=float)
    np.testing.assert_allclose(cum_mediane.cum_médiane(données), attendues)


def test_données_répétées():
    with pytest.raises(ValueError, match="répétées"):
        cum_mediane.cum_médiane(np.array([2, 3, 2], dtype=float))


@pytest.mark.parametrize("données", [np.array([]), np.array([[1, 2], [3, 4]])])
def test_tableau_invalide(données):
    with pytest.raises(ValueError):
        cum_mediane.cum_médiane(données)


@pytest.mark.parametrize("valeur", [np.nan, np.inf, -np.inf])
def test_valeur_non_finie(valeur):
    with pytest.raises(ValueError, match="finies"):
        cum_mediane.cum_médiane(np.array([1, valeur], dtype=float))


def test_valeurs_négatives():
    données = np.array([-5, 2, -1, 7], dtype=float)
    attendues = np.array([-5, -1.5, -1, 0.5], dtype=float)
    np.testing.assert_allclose(cum_mediane.cum_médiane(données), attendues)


def test_numpy_non_contigu():
    données = np.array([2, 99, 3, 99, 0, 99, 1, 99, 5], dtype=float)[::2]
    np.testing.assert_allclose(cum_mediane.cum_médiane(données), [2, 2.5, 2, 1.5, 2])
