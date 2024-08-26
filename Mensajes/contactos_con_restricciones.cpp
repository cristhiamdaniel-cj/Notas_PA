#include "contactos_con_restricciones.h"
#include <iostream>

// Función para agregar un mensaje con restricciones
void agregarMensajeConRestricciones(ContactoConRestricciones*& contactos, int& numContactos, const char* nombreContacto, const char* mensaje) {
    // Buscar el contacto
    for (int i = 0; i < numContactos; ++i) {
        if (strcmp(contactos[i].nombre, nombreContacto) == 0) {
            // Agregar mensaje al contacto existente
            char** nuevosMensajes = new char*[contactos[i].numMensajes + 1];
            for (int j = 0; j < contactos[i].numMensajes; ++j) {
                nuevosMensajes[j] = contactos[i].mensajes[j];
            }
            nuevosMensajes[contactos[i].numMensajes] = new char[strlen(mensaje) + 1];
            strcpy(nuevosMensajes[contactos[i].numMensajes], mensaje);
            delete[] contactos[i].mensajes;
            contactos[i].mensajes = nuevosMensajes;
            contactos[i].numMensajes++;
            return;
        }
    }

    // Si el contacto no existe, agregar un nuevo contacto
    ContactoConRestricciones* nuevosContactos = new ContactoConRestricciones[numContactos + 1];
    for (int i = 0; i < numContactos; ++i) {
        nuevosContactos[i] = contactos[i];
    }
    strcpy(nuevosContactos[numContactos].nombre, nombreContacto);
    nuevosContactos[numContactos].mensajes = new char*[1];
    nuevosContactos[numContactos].mensajes[0] = new char[strlen(mensaje) + 1];
    strcpy(nuevosContactos[numContactos].mensajes[0], mensaje);
    nuevosContactos[numContactos].numMensajes = 1;

    delete[] contactos;
    contactos = nuevosContactos;
    numContactos++;
}

// Función para mostrar mensajes con restricciones
void mostrarMensajesConRestricciones(const ContactoConRestricciones* contactos, int numContactos) {
    for (int i = 0; i < numContactos; ++i) {
        std::cout << "Nombre del Contacto: " << contactos[i].nombre << std::endl;
        std::cout << "Número de mensajes enviados: " << contactos[i].numMensajes << std::endl;
        std::cout << "Mensajes enviados:" << std::endl;
        for (int j = 0; j < contactos[i].numMensajes; ++j) {
            std::cout << j << ": " << contactos[i].mensajes[j] << std::endl;
        }
        std::cout << std::endl;
    }
}

// Función para liberar la memoria asignada dinámicamente para los contactos
void liberarMemoriaContactos(ContactoConRestricciones*& contactos, int& numContactos) {
    for (int i = 0; i < numContactos; ++i) {
        for (int j = 0; j < contactos[i].numMensajes; ++j) {
            delete[] contactos[i].mensajes[j];
        }
        delete[] contactos[i].mensajes;
    }
    delete[] contactos;
    contactos = nullptr;
    numContactos = 0;
}
