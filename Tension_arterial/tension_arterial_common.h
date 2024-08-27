#ifndef TENSION_ARTERIAL_COMMON_H
#define TENSION_ARTERIAL_COMMON_H

struct Medida {
    int sistolica;
    int diastolica;
};

struct Paciente {
    char cedula[20];  // Para con restricciones
    Medida maxima_sistolica;
    Medida maxima_diastolica;
    char estado[20];  // Para con restricciones
};

#endif // TENSION_ARTERIAL_COMMON_H
