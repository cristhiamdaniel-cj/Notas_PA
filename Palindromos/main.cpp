#include <iostream>
#include "con_restricciones.h"
#include "sin_restricciones.h"

int main() {
    // Ejemplo usando funciones con restricciones
    char fraseConRestricciones[100];

    std::cout << "Introduce una frase (con restricciones): ";
    std::cin.getline(fraseConRestricciones, 100);

    if (esPalindromo(fraseConRestricciones)) {
        std::cout << "La frase es palíndroma (con restricciones)." << std::endl;
    } else {
        std::cout << "La frase no es palíndroma (con restricciones)." << std::endl;
    }

    // Ejemplo usando funciones sin restricciones
    std::string fraseSinRestricciones;

    std::cout << "Introduce una frase (sin restricciones): ";
    std::getline(std::cin, fraseSinRestricciones);

    if (esPalindromo(fraseSinRestricciones)) {
        std::cout << "La frase es palíndroma (sin restricciones)." << std::endl;
    } else {
        std::cout << "La frase no es palíndroma (sin restricciones)." << std::endl;
    }

    return 0;
}
