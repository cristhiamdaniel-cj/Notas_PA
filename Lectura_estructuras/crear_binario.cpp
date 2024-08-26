// crear_binario.cpp
#include "lectura_archivos.h"
#include <iostream>
#include <fstream>

void crearArchivoBinario(const char* archivoSalida) {
    std::ofstream archivoBinario(archivoSalida, std::ios::binary);

    if (!archivoBinario) {
        std::cerr << "Error al crear el archivo binario." << std::endl;
        return;
    }

    // Ejemplos de estudiantes
    Estudiante estudiantes[] = {
        {111111, "Roberto Muñoz", "INICIAL", 3.5},
        {222222, "María Benavidez", "SUPLETORIO", 2.8},
        {333333, "Yamile Zapata", "INICIAL", 4.6}
    };

    int numEstudiantes = sizeof(estudiantes) / sizeof(Estudiante);

    for (int i = 0; i < numEstudiantes; ++i) {
        archivoBinario.write(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
    }

    archivoBinario.close();

    std::cout << "Archivo binario creado exitosamente." << std::endl;
}
