#include <iostream>
#include <string>
#include <vector>

// Estructura para almacenar la fecha de ingreso de un estudiante
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Estructura para almacenar la información del estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    Fecha fechaIngreso;
    std::vector<int> notas; // Uso dinámico para almacenar notas
};

// Función para mostrar la información de un estudiante mediante puntero
void mostrarEstudiante(const Estudiante* estudiante) {
    std::cout << "Nombre: " << estudiante->nombre << std::endl;
    std::cout << "Edad: " << estudiante->edad << std::endl;
    std::cout << "Fecha de Ingreso: " << estudiante->fechaIngreso.dia << "/"
              << estudiante->fechaIngreso.mes << "/"
              << estudiante->fechaIngreso.anio << std::endl;
    std::cout << "Notas: ";
    for (int nota : estudiante->notas) {
        std::cout << nota << " ";
    }
    std::cout << std::endl;
}

// Función para agregar una nota a un estudiante mediante puntero
void agregarNota(Estudiante* estudiante, int nota) {
    estudiante->notas.push_back(nota); // Acceso dinámico a las notas usando `->`
}

// Función para crear un estudiante y retornar un puntero
Estudiante* crearEstudiante(std::string nombre, int edad, Fecha fechaIngreso) {
    Estudiante* nuevoEstudiante = new Estudiante; // Memoria dinámica para el estudiante
    nuevoEstudiante->nombre = nombre;
    nuevoEstudiante->edad = edad;
    nuevoEstudiante->fechaIngreso = fechaIngreso;
    return nuevoEstudiante; // Retorna un puntero al estudiante
}

int main() {
    // Uso Estático de `struct`
    const int NUM_ESTUDIANTES = 3;
    Estudiante estudiantesEstaticos[NUM_ESTUDIANTES] = {
        {"Juan Perez", 20, {1, 8, 2021}, {85, 90}},
        {"Maria Lopez", 22, {15, 1, 2020}, {78, 88, 92}},
        {"Carlos Ruiz", 19, {10, 7, 2022}, {91, 85, 89}}
    };

    std::cout << "Información de Estudiantes (Estático):" << std::endl;
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        mostrarEstudiante(&estudiantesEstaticos[i]); // Pasamos el puntero
        std::cout << "-------------------" << std::endl;
    }

    // Uso Dinámico de `struct` con Punteros
    std::vector<Estudiante*> estudiantesDinamicos;

    estudiantesDinamicos.push_back(crearEstudiante("Ana Torres", 21, {5, 3, 2021}));
    estudiantesDinamicos.push_back(crearEstudiante("Luis Martinez", 23, {12, 9, 2019}));

    agregarNota(estudiantesDinamicos[0], 95); // Agregar nota usando puntero
    agregarNota(estudiantesDinamicos[1], 88);
    agregarNota(estudiantesDinamicos[1], 82);

    std::cout << "\nInformación de Estudiantes (Dinámico con Punteros):" << std::endl;
    for (Estudiante* estudiante : estudiantesDinamicos) {
        mostrarEstudiante(estudiante); // Pasamos el puntero
        std::cout << "-------------------" << std::endl;
    }

    // Liberar la memoria dinámica
    for (Estudiante* estudiante : estudiantesDinamicos) {
        delete estudiante; // Liberamos la memoria asignada dinámicamente
    }

    return 0;
}