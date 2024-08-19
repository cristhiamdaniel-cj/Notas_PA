#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

// Versión con std::string
bool esPalindromoString(const std::string& cadena) {
    std::string invertida = cadena;
    std::reverse(invertida.begin(), invertida.end()); // Invertir la cadena
    return cadena == invertida;
}

// Versión con apuntadores dinámicos
bool esPalindromoChar(const char* cadena) {
    int longitud = std::strlen(cadena);
    char* invertida = new char[longitud + 1]; // +1 para el carácter nulo

    // Invertir la cadena
    for (int i = 0; i < longitud; ++i) {
        invertida[i] = cadena[longitud - 1 - i];
    }
    invertida[longitud] = '\0'; // Terminar la cadena con el carácter nulo

    bool resultado = std::strcmp(cadena, invertida) == 0;

    delete[] invertida; // Liberar memoria
    return resultado;
}

int main() {
    std::string cadenaString;
    char cadenaChar[100];

    std::cout << "Ingrese una cadena (para std::string y char*): ";
    std::getline(std::cin, cadenaString); // Leer cadena en std::string

    std::strcpy(cadenaChar, cadenaString.c_str()); // Copiar la cadena a char*

    // Verificación usando std::string
    if (esPalindromoString(cadenaString)) {
        std::cout << "[std::string] La cadena es un palíndromo." << std::endl;
    } else {
        std::cout << "[std::string] La cadena no es un palíndromo." << std::endl;
    }

    // Verificación usando apuntadores dinámicos
    if (esPalindromoChar(cadenaChar)) {
        std::cout << "[char*] La cadena es un palíndromo." << std::endl;
    } else {
        std::cout << "[char*] La cadena no es un palíndromo." << std::endl;
    }

    return 0;
}
