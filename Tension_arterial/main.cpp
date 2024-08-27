#include "tension_arterial_con_restricciones.h"
#include "tension_arterial_sin_restricciones.h"
#include "crear_archivos.h"
#include <iostream>
#include <fstream>

void leerArchivoBinarioConRestricciones(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    Paciente paciente;
    std::cout << "Contenido de " << nombreArchivo << ":" << std::endl;
    while (archivo.read(reinterpret_cast<char*>(&paciente), sizeof(Paciente))) {
        std::cout << "Cedula: " << paciente.cedula << std::endl;
        std::cout << "Medida con mayor sistolica: " << paciente.medidaMaxSistolica.sistolica
                  << "-" << paciente.medidaMaxSistolica.diastolica << std::endl;
        std::cout << "Medida con mayor diastolica: " << paciente.medidaMaxDiastolica.sistolica
                  << "-" << paciente.medidaMaxDiastolica.diastolica << std::endl;
        std::cout << "Advertencia: " << paciente.advertencia << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

    archivo.close();
}

void leerArchivoBinarioSinRestricciones(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    PacienteSinRestricciones paciente;
    std::cout << "Contenido de " << nombreArchivo << ":" << std::endl;
    while (archivo.read(reinterpret_cast<char*>(&paciente), sizeof(PacienteSinRestricciones))) {
        std::cout << "Cedula: " << paciente.cedula << std::endl;
        std::cout << "Medida con mayor sistolica: " << paciente.medidaMaxSistolica.sistolica
                  << "-" << paciente.medidaMaxSistolica.diastolica << std::endl;
        std::cout << "Medida con mayor diastolica: " << paciente.medidaMaxDiastolica.sistolica
                  << "-" << paciente.medidaMaxDiastolica.diastolica << std::endl;
        std::cout << "Advertencia: " << paciente.advertencia << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

    archivo.close();
}

int main() {
    // Crear archivo medidas.txt si no existe
    crearArchivoMedidas();

    // Procesar medidas con restricciones
    int cantidadPacientesCon = 0;
    Paciente* pacientesConRestricciones = procesarMedidasConRestricciones("medidas.txt", cantidadPacientesCon);
    if (pacientesConRestricciones != nullptr) {
        guardarPacientesEnBinarioConRestricciones(pacientesConRestricciones, cantidadPacientesCon, "Pacientes_con_restricciones.dat");
        // Leer y mostrar el archivo binario con restricciones
        leerArchivoBinarioConRestricciones("Pacientes_con_restricciones.dat");
        // Liberar memoria dinámica
        delete[] pacientesConRestricciones;
    }

    // Procesar medidas sin restricciones
    std::vector<PacienteSinRestricciones> pacientesSinRestricciones = procesarMedidasSinRestricciones("medidas.txt");
    if (!pacientesSinRestricciones.empty()) {
        guardarPacientesEnBinarioSinRestricciones(pacientesSinRestricciones, "Pacientes_sin_restricciones.dat");
        // Leer y mostrar el archivo binario sin restricciones
        leerArchivoBinarioSinRestricciones("Pacientes_sin_restricciones.dat");
    }

    return 0;
}
