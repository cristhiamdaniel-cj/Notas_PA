#ifndef TENSION_ARTERIAL_CON_RESTRICCIONES_H
#define TENSION_ARTERIAL_CON_RESTRICCIONES_H

struct Medida {
    int sistolica;
    int diastolica;
};

struct Paciente {
    int cedula;
    Medida medidaMaxSistolica;
    Medida medidaMaxDiastolica;
    char advertencia[50];  // Mensaje de advertencia o seguimiento
};

Paciente* procesarMedidasConRestricciones(const char* nombreArchivo, int& cantidadPacientes);
void guardarPacientesEnBinarioConRestricciones(Paciente* pacientes, int cantidadPacientes, const char* nombreArchivo);

#endif // TENSION_ARTERIAL_CON_RESTRICCIONES_H
