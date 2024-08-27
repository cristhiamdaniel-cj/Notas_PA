#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include "tension_arterial_con_restricciones.h"

Paciente* procesarMedidasConRestricciones(const char* nombreArchivo, int& cantidadPacientes) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return nullptr;
    }

    Paciente* pacientes = nullptr;
    cantidadPacientes = 0;
    char linea[256];

    while (archivo.getline(linea, 256)) {
        int cedula;
        sscanf(linea, "%d;", &cedula);

        Medida medidaMaxSistolica = {INT_MIN, 0};
        Medida medidaMaxDiastolica = {0, INT_MIN};

        char* token = strtok(linea + 11, ",");
        while (token) {
            int sistolica, diastolica;
            sscanf(token, "%d-%d", &sistolica, &diastolica);

            if (sistolica > medidaMaxSistolica.sistolica) {
                medidaMaxSistolica = {sistolica, diastolica};
            }
            if (diastolica > medidaMaxDiastolica.diastolica) {
                medidaMaxDiastolica = {sistolica, diastolica};
            }

            token = strtok(nullptr, ",");
        }

        Paciente* tempPacientes = new Paciente[cantidadPacientes + 1];
        for (int i = 0; i < cantidadPacientes; i++) {
            tempPacientes[i] = pacientes[i];
        }

        tempPacientes[cantidadPacientes].cedula = cedula;
        tempPacientes[cantidadPacientes].medidaMaxSistolica = medidaMaxSistolica;
        tempPacientes[cantidadPacientes].medidaMaxDiastolica = medidaMaxDiastolica;

        if (medidaMaxSistolica.sistolica > 140 || medidaMaxDiastolica.diastolica > 95) {
            strcpy(tempPacientes[cantidadPacientes].advertencia, "ADVERTENCIA");
        } else if ((medidaMaxSistolica.sistolica >= 130 && medidaMaxSistolica.sistolica <= 140) ||
                   (medidaMaxDiastolica.diastolica >= 90 && medidaMaxDiastolica.diastolica <= 95)) {
            strcpy(tempPacientes[cantidadPacientes].advertencia, "SEGUIMIENTO");
        } else {
            strcpy(tempPacientes[cantidadPacientes].advertencia, "");
        }

        delete[] pacientes;
        pacientes = tempPacientes;
        cantidadPacientes++;
    }

    archivo.close();
    return pacientes;
}

void guardarPacientesEnBinarioConRestricciones(Paciente* pacientes, int cantidadPacientes, const char* nombreArchivo) {
    std::ofstream archivoBinario(nombreArchivo, std::ios::binary);
    if (!archivoBinario.is_open()) {
        std::cerr << "No se pudo abrir el archivo binario para escritura." << std::endl;
        return;
    }

    for (int i = 0; i < cantidadPacientes; ++i) {
        archivoBinario.write(reinterpret_cast<char*>(&pacientes[i]), sizeof(Paciente));
    }

    archivoBinario.close();
}
