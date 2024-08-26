#include "con_restricciones.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>

// Implementación de la función EsMayor
bool EsMayor(const char* fecha1, const char* fecha2) {
    int dia1, mes1, año1;
    int dia2, mes2, año2;

    sscanf(fecha1, "%d/%d/%d", &dia1, &mes1, &año1);
    sscanf(fecha2, "%d/%d/%d", &dia2, &mes2, &año2);

    if (año1 > año2) return true;
    if (año1 < año2) return false;
    if (mes1 > mes2) return true;
    if (mes1 < mes2) return false;
    return dia1 > dia2;
}

// Implementación de la función BuscarProductos
Producto* BuscarProductos(const char* FechaBuscar, const char* Nombre, int& cantidad) {
    std::ifstream archivo("productos.dat", std::ios::binary);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo productos.dat" << std::endl;
        return nullptr;
    }

    Producto* productos = new Producto[100];
    cantidad = 0;

    Producto producto;
    while (archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto))) {
        if (strstr(producto.NombreProducto, Nombre) != nullptr && EsMayor(producto.FechaVigenciaPromocion, FechaBuscar)) {
            productos[cantidad] = producto;
            cantidad++;
        }
    }

    archivo.close();
    return productos;
}

// Implementación de la función OrdenarYGuardarProductos
void OrdenarYGuardarProductos(Producto* productos, int cantidad, const std::string& nombreArchivo) {
    std::sort(productos, productos + cantidad, [](const Producto& a, const Producto& b) {
        return a.Precio < b.Precio;
    });

    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
        return;
    }

    for (int i = 0; i < std::min(5, cantidad); i++) {
        archivo << productos[i].NombreTienda << "," << productos[i].URLTienda << "," << productos[i].NombreProducto << ","
                << productos[i].FechaVigenciaPromocion << "," << productos[i].Precio << "\n";
    }

    archivo.close();
    std::cout << "Resultados con restricciones guardados en " << nombreArchivo << std::endl;
}
