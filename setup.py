from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [Pybind11Extension("cum_mediane", ["src/interface.cpp", "src/cum_mediane.cpp"], cxx_std=17)]

setup(
    name="ift704-tp8-cum-mediane",
    version="1.0.0",
    author="Theotim Dumetz",
    description="Médiane cumulative en C++ avec interface NumPy et pybind11",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.9",
)
