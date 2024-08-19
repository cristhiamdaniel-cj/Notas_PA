#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Función para mostrar todas las tareas
void mostrarTareas(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de tareas para lectura." << std::endl;
        return;
    }

    std::string tarea;
    int numeroTarea = 1;
    while (std::getline(archivo, tarea)) {
        std::cout << numeroTarea << ". " << tarea << std::endl;
        numeroTarea++;
    }

    archivo.close();
}

// Función para agregar una nueva tarea
void agregarTarea(const std::string& nombreArchivo, const std::string& nuevaTarea) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de tareas para escritura." << std::endl;
        return;
    }

    archivo << nuevaTarea << std::endl;
    archivo.close();
}

// Función para marcar una tarea como completada
void completarTarea(const std::string& nombreArchivo, int numeroTarea) {
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de tareas para lectura." << std::endl;
        return;
    }

    std::ofstream archivoTemporal("temporal.txt");
    std::string tarea;
    int contador = 1;

    while (std::getline(archivoEntrada, tarea)) {
        if (contador == numeroTarea) {
            tarea += " [COMPLETADA]";
        }
        archivoTemporal << tarea << std::endl;
        contador++;
    }

    archivoEntrada.close();
    archivoTemporal.close();

    std::remove(nombreArchivo.c_str());
    std::rename("temporal.txt", nombreArchivo.c_str());
}

int main() {
    const std::string nombreArchivo = "tareas.txt";
    int opcion;

    do {
        std::cout << "1. Mostrar tareas\n2. Agregar tarea\n3. Completar tarea\n4. Salir\nElige una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea residual

        if (opcion == 1) {
            mostrarTareas(nombreArchivo);
        } else if (opcion == 2) {
            std::string nuevaTarea;
            std::cout << "Escribe la nueva tarea: ";
            std::getline(std::cin, nuevaTarea);
            agregarTarea(nombreArchivo, nuevaTarea);
        } else if (opcion == 3) {
            int numeroTarea;
            std::cout << "Número de tarea a completar: ";
            std::cin >> numeroTarea;
            completarTarea(nombreArchivo, numeroTarea);
        }

    } while (opcion != 4);

    return 0;
}