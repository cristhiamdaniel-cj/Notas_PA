#include "encriptacion_sin_restricciones.h"
#include <cctype>  // Para funciones de manipulación de caracteres

// Función para encriptar un carácter
char encriptarSinRestriccion(char c) {
    if (std::isalpha(c)) {
        c = std::tolower(c);  // Convertir a minúscula
        return 'z' - (c - 'a');  // Encripta usando la tabla dada
    }
    return c;  // Retorna el carácter original si no es alfabético
}

// Función para encriptar un mensaje
std::string encriptarMensaje(const std::string& mensaje) {
    std::string resultado;
    for (char c : mensaje) {
        resultado += encriptarSinRestriccion(c);
    }
    return resultado;
}
