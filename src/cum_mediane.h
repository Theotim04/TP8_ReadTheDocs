#pragma once

#define SUCCESS 0
#define ERROR_DONNÉES_RÉPÉTÉES 1
#define ERROR_AUCUNE_DONNÉE 2
#define ERROR_DONNÉES_NON_FINIES 3

int cum_médiane(const double* données_ptr, const int taille, double* sortie_ptr);
