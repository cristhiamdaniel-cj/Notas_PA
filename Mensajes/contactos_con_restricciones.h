#ifndef CONTACTOS_CON_RESTRICCIONES_H
#define CONTACTOS_CON_RESTRICCIONES_H

#include <cstring> // Para funciones de manipulación de cadenas

// Estructura para gestionar contactos con restricciones
struct ContactoConRestricciones {
    char nombre[50];
    char** mensajes;
    int numMensajes;
};

// Funciones para gestionar los contactos con restricciones
void agregarMensajeConRestricciones(ContactoConRestricciones*& contactos, int& numContactos, const char* nombreContacto, const char* mensaje);
void mostrarMensajesConRestricciones(const ContactoConRestricciones* contactos, int numContactos);
void liberarMemoriaContactos(ContactoConRestricciones*& contactos, int& numContactos);

#endif // CONTACTOS_CON_RESTRICCIONES_H
