#ifndef TENSION_ARTERIAL_SIN_RESTRICCIONES_H
#define TENSION_ARTERIAL_SIN_RESTRICCIONES_H

#include <vector>

struct MedidaSinRestricciones {
    int sistolica;
    int diastolica;
};

struct PacienteSinRestricciones {
    int cedula;
    MedidaSinRestricciones medidaMaxSistolica;
    MedidaSinRestricciones medidaMaxDiastolica;
    char advertencia[50];
};

std::vector<PacienteSinRestricciones> procesarMedidasSinRestricciones(const char* nombreArchivo);
void guardarPacientesEnBinarioSinRestricciones(const std::vector<PacienteSinRestricciones>& pacientes, const char* nombreArchivo);

#endif // TENSION_ARTERIAL_SIN_RESTRICCIONES_H
