#include <iostream>
#include <fstream>
#include "encriptacion_con_restricciones.h"
#include "encriptacion_sin_restricciones.h"

int main() {
    // Crear archivo datos.txt con un mensaje de ejemplo
    std::ofstream archivoDatos("datos.txt");
    if (!archivoDatos) {
        std::cerr << "Error al crear el archivo datos.txt" << std::endl;
        return 1;
    }
    archivoDatos << "Hola como se encuentran";
    archivoDatos.close();

    // Leer el archivo datos.txt usando std::string (sin restricciones)
    std::ifstream archivoEntradaSinRestriccion("datos.txt");
    if (!archivoEntradaSinRestriccion) {
        std::cerr << "Error al abrir el archivo datos.txt" << std::endl;
        return 1;
    }

    std::string mensajeSinRestriccion;
    std::getline(archivoEntradaSinRestriccion, mensajeSinRestriccion);
    archivoEntradaSinRestriccion.close();

    // Encriptar el mensaje (sin restricciones)
    std::string mensajeEncriptadoSinRestriccion = encriptarMensaje(mensajeSinRestriccion);

    // Guardar el mensaje encriptado en encriptado_sin.txt
    std::ofstream archivoSalidaSinRestriccion("encriptado_sin.txt");
    if (!archivoSalidaSinRestriccion) {
        std::cerr << "Error al abrir el archivo encriptado_sin.txt" << std::endl;
        return 1;
    }
    archivoSalidaSinRestriccion << mensajeEncriptadoSinRestriccion;
    archivoSalidaSinRestriccion.close();

    // Mostrar los resultados (sin restricciones)
    std::cout << "Mensaje original (sin restricciones): " << mensajeSinRestriccion << std::endl;
    std::cout << "Mensaje encriptado (sin restricciones): " << mensajeEncriptadoSinRestriccion << std::endl;

    // Leer el archivo datos.txt usando char[] (con restricciones)
    std::ifstream archivoEntradaConRestriccion("datos.txt");
    if (!archivoEntradaConRestriccion) {
        std::cerr << "Error al abrir el archivo datos.txt" << std::endl;
        return 1;
    }

    char mensajeConRestriccion[256];
    archivoEntradaConRestriccion.getline(mensajeConRestriccion, 256);
    archivoEntradaConRestriccion.close();

    // Encriptar el mensaje (con restricciones)
    char mensajeEncriptadoConRestriccion[256];
    procesarMensaje(mensajeConRestriccion, mensajeEncriptadoConRestriccion, encriptarConRestriccion);

    // Guardar el mensaje encriptado en encriptado_con.txt
    std::ofstream archivoSalidaConRestriccion("encriptado_con.txt");
    if (!archivoSalidaConRestriccion) {
        std::cerr << "Error al abrir el archivo encriptado_con.txt" << std::endl;
        return 1;
    }
    archivoSalidaConRestriccion << mensajeEncriptadoConRestriccion;
    archivoSalidaConRestriccion.close();

    // Mostrar los resultados (con restricciones)
    std::cout << "Mensaje original (con restricciones): " << mensajeConRestriccion << std::endl;
    std::cout << "Mensaje encriptado (con restricciones): " << mensajeEncriptadoConRestriccion << std::endl;

    return 0;
}
