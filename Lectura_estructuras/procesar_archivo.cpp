// procesar_archivo.cpp
#include "lectura_archivos.h"
#include <iostream>
#include <fstream>
#include <cstring>

void procesarArchivo(const char* archivoEntrada) {
    std::ifstream archivoBinario(archivoEntrada, std::ios::binary);

    if (!archivoBinario) {
        std::cerr << "Error al abrir el archivo binario." << std::endl;
        return;
    }

    // Variables para almacenar temporalmente los estudiantes
    Estudiante* iniciales = nullptr;
    Estudiante* supletorios = nullptr;
    int contador_iniciales = 0, contador_supletorios = 0;
    float suma_iniciales = 0.0f, suma_supletorios = 0.0f;

    // Lectura del archivo binario
    Estudiante estudiante;
    while (archivoBinario.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        if (strcmp(estudiante.tipo_examen, "INICIAL") == 0) {
            Estudiante* nuevo_array = new Estudiante[contador_iniciales + 1];
            if (contador_iniciales > 0) {
                memcpy(nuevo_array, iniciales, contador_iniciales * sizeof(Estudiante));
                delete[] iniciales;
            }
            nuevo_array[contador_iniciales] = estudiante;
            iniciales = nuevo_array;
            suma_iniciales += estudiante.nota;
            contador_iniciales++;
        } else if (strcmp(estudiante.tipo_examen, "SUPLETORIO") == 0) {
            Estudiante* nuevo_array = new Estudiante[contador_supletorios + 1];
            if (contador_supletorios > 0) {
                memcpy(nuevo_array, supletorios, contador_supletorios * sizeof(Estudiante));
                delete[] supletorios;
            }
            nuevo_array[contador_supletorios] = estudiante;
            supletorios = nuevo_array;
            suma_supletorios += estudiante.nota;
            contador_supletorios++;
        }
    }

    archivoBinario.close();

    // Mostrar resultados en la consola
    std::cout << "INICIAL\n";
    for (int i = 0; i < contador_iniciales; ++i) {
        std::cout << iniciales[i].nombre << " " << iniciales[i].nota << "\n";
    }
    std::cout << "No. de exámenes: " << contador_iniciales << "\n";
    if (contador_iniciales > 0) {
        std::cout << "Promedio: " << suma_iniciales / contador_iniciales << "\n";
    }

    std::cout << "\nSUPLETORIO\n";
    for (int i = 0; i < contador_supletorios; ++i) {
        std::cout << supletorios[i].nombre << " " << supletorios[i].nota << "\n";
    }
    std::cout << "No. de exámenes: " << contador_supletorios << "\n";
    if (contador_supletorios > 0) {
        std::cout << "Promedio: " << suma_supletorios / contador_supletorios << "\n";
    }

    // Liberar memoria dinámica
    delete[] iniciales;
    delete[] supletorios;
}
