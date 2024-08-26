#include <iostream>
#include "contactos_sin_restricciones.h"
#include "contactos_con_restricciones.h"

int main() {
    // Parte sin restricciones
    std::vector<ContactoSinRestricciones> contactosSinRestricciones;
    agregarMensajeSinRestricciones(contactosSinRestricciones, "Pedro Perez", "Hola Pedro, ¿cómo sigues?");
    agregarMensajeSinRestricciones(contactosSinRestricciones, "Pedro Perez", "¿Nos vemos para almorzar?");
    agregarMensajeSinRestricciones(contactosSinRestricciones, "Juliana Lopez", "Hola Juliana, ¿cómo estás?");
    agregarMensajeSinRestricciones(contactosSinRestricciones, "Juliana Lopez", "¿Tienes listo el trabajo?");
    agregarMensajeSinRestricciones(contactosSinRestricciones, "Juliana Lopez", "Recuerda que es para hoy a las 9am");

    std::cout << "Mensajes sin restricciones:" << std::endl;
    mostrarMensajesSinRestricciones(contactosSinRestricciones);

    // Parte con restricciones
    ContactoConRestricciones* contactosConRestricciones = nullptr;
    int numContactos = 0;
    agregarMensajeConRestricciones(contactosConRestricciones, numContactos, "Pedro Perez", "Hola Pedro, ¿cómo sigues?");
    agregarMensajeConRestricciones(contactosConRestricciones, numContactos, "Pedro Perez", "¿Nos vemos para almorzar?");
    agregarMensajeConRestricciones(contactosConRestricciones, numContactos, "Juliana Lopez", "Hola Juliana, ¿cómo estás?");
    agregarMensajeConRestricciones(contactosConRestricciones, numContactos, "Juliana Lopez", "¿Tienes listo el trabajo?");
    agregarMensajeConRestricciones(contactosConRestricciones, numContactos, "Juliana Lopez", "Recuerda que es para hoy a las 9am");

    std::cout << "\nMensajes con restricciones:" << std::endl;
    mostrarMensajesConRestricciones(contactosConRestricciones, numContactos);

    liberarMemoriaContactos(contactosConRestricciones, numContactos);

    return 0;
}
