#include <iostream>
#include <fstream>
#include <cstring>

struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};

void escribirArchivoBinario(const char* nombreArchivo) {
    Estudiante estudiantes[3] = {
        {"Juan Perez", 20, 89.5},
        {"Maria Lopez", 22, 92.0},
        {"Carlos Ruiz", 19, 78.4}
    };

    std::ofstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        archivo.write(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
    }

    archivo.close();
}

void leerArchivoBinario(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
        return;
    }

    Estudiante estudiante;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nCalificación: " << estudiante.calificacion << std::endl;
        std::cout << "-------------------" << std::endl;
    }

    archivo.close();
}

void modificarArchivoBinario(const char* nombreArchivo) {
    std::fstream archivo(nombreArchivo, std::ios::in | std::ios::out | std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para modificación." << std::endl;
        return;
    }

    // Modificar la calificación del segundo estudiante (índice 1)
    archivo.seekp(sizeof(Estudiante) + offsetof(Estudiante, calificacion), std::ios::beg);
    float nuevaCalificacion = 95.0;
    archivo.write(reinterpret_cast<char*>(&nuevaCalificacion), sizeof(nuevaCalificacion));

    archivo.close();
}

void lecturaSelectiva(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para lectura selectiva." << std::endl;
        return;
    }

    // Leer solo el segundo estudiante (índice 1)
    archivo.seekg(sizeof(Estudiante), std::ios::beg);

    Estudiante estudiante;
    archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));

    std::cout << "Lectura selectiva - Segundo Estudiante:" << std::endl;
    std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nCalificación: " << estudiante.calificacion << std::endl;

    archivo.close();
}

int main() {
    const char* nombreArchivo = "estudiantes.bin";

    // 1. Escritura en archivo binario
    escribirArchivoBinario(nombreArchivo);

    // 2. Lectura del archivo binario
    std::cout << "Contenido original del archivo binario:" << std::endl;
    leerArchivoBinario(nombreArchivo);

    // 3. Modificación del archivo binario
    modificarArchivoBinario(nombreArchivo);

    // 4. Lectura después de la modificación
    std::cout << "Contenido del archivo binario después de la modificación:" << std::endl;
    leerArchivoBinario(nombreArchivo);

    // 5. Lectura selectiva
    lecturaSelectiva(nombreArchivo);

    return 0;
}
