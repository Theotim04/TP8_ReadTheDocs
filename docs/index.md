# TP8 Médiane cumulative

Package Python utilisant un algorithme C++ pour calculer la médiane cumulative d'un tableau NumPy.

## Installation

Dans le dossier du projet :

```console
pip install -v .
```

## Utilisation

```python
import numpy as np
import cum_mediane

données = np.array([2, 3, 0, 1, 5], dtype=float)
cum_mediane.cum_médiane(données)
# array([2. , 2.5, 2. , 1.5, 2. ])
```

## Documentation

La référence ci-dessous reprend directement la docstring de la fonction exposée avec `pybind11`.

```{toctree}
:maxdepth: 1

api
```
