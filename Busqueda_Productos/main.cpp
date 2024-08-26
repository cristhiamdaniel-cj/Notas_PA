#include <iostream>
#include <fstream>
#include "con_restricciones.h"
#include "sin_restricciones.h"
#include "crear_binario.h"

int main() {
    // Crear archivo binario con productos
    crearArchivoBinario();

    // Mostrar contenido del archivo binario
    std::ifstream archivo("productos.dat", std::ios::binary);
    if (archivo.is_open()) {
        Producto producto;
        std::cout << "Contenido del archivo productos.dat:" << std::endl;
        while (archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto))) {
            std::cout << "NombreTienda: " << producto.NombreTienda << std::endl;
            std::cout << "URLTienda: " << producto.URLTienda << std::endl;
            std::cout << "NombreProducto: " << producto.NombreProducto << std::endl;
            std::cout << "FechaVigenciaPromocion: " << producto.FechaVigenciaPromocion << std::endl;
            std::cout << "Precio: " << producto.Precio << std::endl;
            std::cout << "---------------------------------" << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo productos.dat para lectura." << std::endl;
    }

    // Pruebas con restricciones
    int cantidadConRestricciones = 0;
    Producto* productosConRestricciones = BuscarProductos("25/03/2023", "Parlantes", cantidadConRestricciones);
    OrdenarYGuardarProductos(productosConRestricciones, cantidadConRestricciones, "Mejores_con.txt");
    delete[] productosConRestricciones;  // Liberar memoria dinámica

    // Pruebas sin restricciones
    std::vector<ProductoSinRestriccion> productosSinRestricciones = BuscarProductosSinRestricciones("25/03/2023", "Parlantes");
    OrdenarYGuardarProductos(productosSinRestricciones, "Mejores_sin.txt");

    return 0;
}
