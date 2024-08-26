#include "contactos_sin_restricciones.h"
#include <iostream>

// Función para agregar un mensaje sin restricciones
void agregarMensajeSinRestricciones(std::vector<ContactoSinRestricciones>& contactos, const std::string& nombreContacto, const std::string& mensaje) {
    for (auto& contacto : contactos) {
        if (contacto.nombre == nombreContacto) {
            contacto.mensajes.push_back(mensaje);
            return;
        }
    }

    ContactoSinRestricciones nuevoContacto = {nombreContacto, {mensaje}};
    contactos.push_back(nuevoContacto);
}

// Función para mostrar mensajes sin restricciones
void mostrarMensajesSinRestricciones(const std::vector<ContactoSinRestricciones>& contactos) {
    for (const auto& contacto : contactos) {
        std::cout << "Nombre del Contacto: " << contacto.nombre << std::endl;
        std::cout << "Número de mensajes enviados: " << contacto.mensajes.size() << std::endl;
        std::cout << "Mensajes enviados:" << std::endl;
        for (size_t i = 0; i < contacto.mensajes.size(); ++i) {
            std::cout << i << ": " << contacto.mensajes[i] << std::endl;
        }
        std::cout << std::endl;
    }
}
