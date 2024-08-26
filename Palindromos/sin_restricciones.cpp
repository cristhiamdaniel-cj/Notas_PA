#include <string>
#include <algorithm>  // Para std::tolower
#include "sin_restricciones.h"

// Función para eliminar los espacios y convertir la frase a minúsculas
std::string limpiarFrase(const std::string& frase) {
    std::string fraseLimpia;
    for (char c : frase) {
        if (c != ' ') {
            fraseLimpia += std::tolower(c);
        }
    }
    return fraseLimpia;
}

// Función para verificar si una frase es palíndroma
bool esPalindromo(const std::string& frase) {
    std::string fraseLimpia = limpiarFrase(frase);
    int n = fraseLimpia.length();

    for (int i = 0; i < n / 2; i++) {
        if (fraseLimpia[i] != fraseLimpia[n - i - 1]) {
            return false;
        }
    }
    return true;
}
