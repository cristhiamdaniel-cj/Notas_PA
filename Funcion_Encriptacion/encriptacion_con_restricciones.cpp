#include "encriptacion_con_restricciones.h"
#include <cctype>  // Para tolower

// Función para encriptar un carácter
char encriptarConRestriccion(char c) {
    if (std::isalpha(c)) {
        if (std::islower(c)) {
            return 'z' - (c - 'a');  // Encripta minúsculas
        } else {
            return 'Z' - (c - 'A');  // Encripta mayúsculas
        }
    }
    return c;  // Retorna el carácter original si no es alfabético
}

// Función para desencriptar un carácter
char desencriptarConRestriccion(char c) {
    return encriptarConRestriccion(c);  // La encriptación es reversible
}

// Función para procesar un mensaje usando un apuntador a función
void procesarMensaje(const char* input, char* output, char (*func)(char)) {
    while (*input != '\0') {
        *output = func(*input);
        input++;
        output++;
    }
    *output = '\0';  // Termina la cadena con carácter nulo
}
