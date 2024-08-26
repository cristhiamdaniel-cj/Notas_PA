#include <cctype>  // Para tolower
#include <fstream>
#include <iostream>
#include "con_restricciones.h"

// Función para calcular la longitud de la cadena
int calcularLongitud(const char* cadena) {
    int longitud = 0;
    while (*(cadena + longitud) != '\0') {
        longitud++;
    }
    return longitud;
}

// Función para limpiar la frase (eliminar espacios y convertir a minúsculas)
char* limpiarFrase(const char* frase) {
    int longitud = calcularLongitud(frase);
    int nuevoTamano = 0;

    // Contar los caracteres que no son espacios
    for (int i = 0; i < longitud; i++) {
        if (*(frase + i) != ' ') {
            nuevoTamano++;
        }
    }

    // Crear un nuevo arreglo dinámico para almacenar la frase limpia
    char* fraseLimpia = new char[nuevoTamano + 1];  // +1 para el carácter nulo
    int indice = 0;

    // Copiar los caracteres que no son espacios y convertir a minúsculas
    for (int i = 0; i < longitud; i++) {
        if (*(frase + i) != ' ') {
            *(fraseLimpia + indice) = std::tolower(*(frase + i));
            indice++;
        }
    }
    *(fraseLimpia + indice) = '\0';  // Termina la nueva cadena con el carácter nulo

    return fraseLimpia;
}

// Función para verificar si una frase es palíndroma
bool esPalindromo(const char* frase) {
    char* fraseLimpia = limpiarFrase(frase);
    int n = calcularLongitud(fraseLimpia);

    for (int i = 0; i < n / 2; i++) {
        if (*(fraseLimpia + i) != *(fraseLimpia + n - i - 1)) {
            delete[] fraseLimpia;
            return false;
        }
    }

    delete[] fraseLimpia;  // Liberar memoria dinámica
    return true;
}

// Función para contar líneas palíndromas en un archivo
int contarLineasPalindromas(const char* rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return -1;  // Indicador de error
    }

    char linea[256];
    int conteo = 0;
    while (archivo.getline(linea, 256)) {
        if (esPalindromo(linea)) {
            conteo++;
        }
    }

    archivo.close();
    return conteo;
}
