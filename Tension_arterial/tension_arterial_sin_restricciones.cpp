#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <climits>
#include <cstring>
#include "tension_arterial_sin_restricciones.h"

std::vector<PacienteSinRestricciones> procesarMedidasSinRestricciones(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return {};
    }

    std::vector<PacienteSinRestricciones> pacientes;
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        int cedula;
        char puntoComa;
        stream >> cedula >> puntoComa;

        PacienteSinRestricciones paciente;
        paciente.cedula = cedula;
        paciente.medidaMaxSistolica = {INT_MIN, 0};
        paciente.medidaMaxDiastolica = {0, INT_MIN};

        std::string medidasStr;
        while (std::getline(stream, medidasStr, ',')) {
            int sistolica, diastolica;
            std::sscanf(medidasStr.c_str(), "%d-%d", &sistolica, &diastolica);

            if (sistolica > paciente.medidaMaxSistolica.sistolica) {
                paciente.medidaMaxSistolica = {sistolica, diastolica};
            }
            if (diastolica > paciente.medidaMaxDiastolica.diastolica) {
                paciente.medidaMaxDiastolica = {sistolica, diastolica};
            }
        }

        if (paciente.medidaMaxSistolica.sistolica > 140 || paciente.medidaMaxDiastolica.diastolica > 95) {
            strcpy(paciente.advertencia, "ADVERTENCIA");
        } else if ((paciente.medidaMaxSistolica.sistolica >= 130 && paciente.medidaMaxSistolica.sistolica <= 140) ||
                   (paciente.medidaMaxDiastolica.diastolica >= 90 && paciente.medidaMaxDiastolica.diastolica <= 95)) {
            strcpy(paciente.advertencia, "SEGUIMIENTO");
        } else {
            strcpy(paciente.advertencia, "");
        }

        pacientes.push_back(paciente);
    }

    archivo.close();
    return pacientes;
}

void guardarPacientesEnBinarioSinRestricciones(const std::vector<PacienteSinRestricciones>& pacientes, const char* nombreArchivo) {
    std::ofstream archivoBinario(nombreArchivo, std::ios::binary);
    if (!archivoBinario.is_open()) {
        std::cerr << "No se pudo abrir el archivo binario para escritura." << std::endl;
        return;
    }

    for (const auto& paciente : pacientes) {
        archivoBinario.write(reinterpret_cast<const char*>(&paciente), sizeof(PacienteSinRestricciones));
    }

    archivoBinario.close();
}
