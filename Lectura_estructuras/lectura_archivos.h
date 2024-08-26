// lectura_archivos.h
#ifndef LECTURA_ARCHIVOS_H
#define LECTURA_ARCHIVOS_H

struct Estudiante {
    int identificacion;
    char nombre[50];
    char tipo_examen[12];  // Puede ser "INICIAL" o "SUPLETORIO"
    float nota;
};

// Prototipos de las funciones
void crearArchivoBinario(const char* archivoSalida);
void procesarArchivo(const char* archivoEntrada);

#endif // LECTURA_ARCHIVOS_H
