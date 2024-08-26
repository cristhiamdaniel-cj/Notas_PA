#include "sin_restricciones.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

// No es necesario definir EsMayor aquí ya que está incluido desde con_restricciones.h

// Implementación de la función BuscarProductosSinRestricciones
std::vector<ProductoSinRestriccion> BuscarProductosSinRestricciones(const char* FechaBuscar, const char* Nombre) {
    std::ifstream archivo("productos.dat", std::ios::binary);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo productos.dat" << std::endl;
        return {};
    }

    std::vector<ProductoSinRestriccion> productos;
    Producto producto;

    while (archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto))) {
        if (strstr(producto.NombreProducto, Nombre) != nullptr && EsMayor(producto.FechaVigenciaPromocion, FechaBuscar)) {
            ProductoSinRestriccion p;
            std::memcpy(&p, &producto, sizeof(Producto));
            productos.push_back(p);
        }
    }

    archivo.close();
    return productos;
}

// Implementación de la función OrdenarYGuardarProductos para ProductoSinRestriccion
void OrdenarYGuardarProductos(const std::vector<ProductoSinRestriccion>& productos, const std::string& nombreArchivo) {
    auto productosOrdenados = productos;
    std::sort(productosOrdenados.begin(), productosOrdenados.end(), [](const ProductoSinRestriccion& a, const ProductoSinRestriccion& b) {
        return a.Precio < b.Precio;
    });

    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
        return;
    }

    for (size_t i = 0; i < std::min<size_t>(5, productosOrdenados.size()); i++) {
        archivo << productosOrdenados[i].NombreTienda << "," << productosOrdenados[i].URLTienda << "," << productosOrdenados[i].NombreProducto << ","
                << productosOrdenados[i].FechaVigenciaPromocion << "," << productosOrdenados[i].Precio << "\n";
    }

    archivo.close();
    std::cout << "Resultados sin restricciones guardados en " << nombreArchivo << std::endl;
}
