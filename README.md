# TP8 Médiane cumulative

Package Python avec un algorithme C++ et une interface `pybind11`.

La documentation reprend la structure minimale du modèle **py-pkgs-cookiecutter** présenté dans le tutoriel [Python Packages](https://py-pkgs.org/03-how-to-package-a-python#hosting-documentation-online), en utilisant le thème `sphinx_rtd_theme`.

## Tester la documentation sur Windows

Depuis la racine du projet, dans le terminal PowerShell de VS Code :

```powershell
conda activate ift704_tp8
$env:CL = "/utf-8"
python -m pip install -v .
python -m pip install -r docs/requirements.txt
python -m sphinx -b html docs docs/_build/html
start .\docs\_build\html\index.html
```

## Publier sur Read the Docs

1. Créer un dépôt GitHub **public** et déposer les fichiers extraits de cette archive à la racine du dépôt, en conservant `.readthedocs.yml`.
2. Se connecter à [Read the Docs](https://readthedocs.org/) avec GitHub.
3. Choisir **Import a Project** et sélectionner le dépôt, ou **Import Manually** avec son URL.
4. Garder la branche `main`, puis sélectionner **Build version**.
5. Après une construction réussie, cliquer sur **View Docs** et copier l'URL publique dans la section **Extra points** du rapport TP8.

Le site n'est pas encore en ligne tant que ces étapes ne sont pas terminées.

Ce projet conserve `setuptools` pour compiler le C++ : contrairement au package entièrement Python du tutoriel, il n'utilise pas Poetry.
