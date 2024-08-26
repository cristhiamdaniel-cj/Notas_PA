#ifndef CONTACTOS_SIN_RESTRICCIONES_H
#define CONTACTOS_SIN_RESTRICCIONES_H

#include <string>
#include <vector>

// Estructura para gestionar contactos sin restricciones
struct ContactoSinRestricciones {
    std::string nombre;
    std::vector<std::string> mensajes;
};

// Funciones para gestionar los contactos sin restricciones
void agregarMensajeSinRestricciones(std::vector<ContactoSinRestricciones>& contactos, const std::string& nombreContacto, const std::string& mensaje);
void mostrarMensajesSinRestricciones(const std::vector<ContactoSinRestricciones>& contactos);

#endif // CONTACTOS_SIN_RESTRICCIONES_H
