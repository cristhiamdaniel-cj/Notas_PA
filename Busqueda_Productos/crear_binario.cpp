#include "Producto.h"
#include "crear_binario.h"
#include <fstream>
#include <cstring>
#include <iostream>

void crearArchivoBinario() {
    Producto productos[4];

    std::strcpy(productos[0].NombreTienda, "Tiendas Jupiter");
    std::strcpy(productos[0].URLTienda, "www.jupiter.com");
    std::strcpy(productos[0].NombreProducto, "Parlantes tipo 1");
    std::strcpy(productos[0].FechaVigenciaPromocion, "30/03/2023");
    productos[0].Precio = 175000;

    std::strcpy(productos[1].NombreTienda, "Yelao");
    std::strcpy(productos[1].URLTienda, "yelao.com");
    std::strcpy(productos[1].NombreProducto, "Llantas marca a");
    std::strcpy(productos[1].FechaVigenciaPromocion, "13/02/2023");
    productos[1].Precio = 400000;

    std::strcpy(productos[2].NombreTienda, "Logro");
    std::strcpy(productos[2].URLTienda, "logro.com");
    std::strcpy(productos[2].NombreProducto, "Parlantes tipo 1");
    std::strcpy(productos[2].FechaVigenciaPromocion, "28/03/2023");
    productos[2].Precio = 172000;

    std::strcpy(productos[3].NombreTienda, "Llanticas.com");
    std::strcpy(productos[3].URLTienda, "www.llanticas.com");
    std::strcpy(productos[3].NombreProducto, "Llantas marca a");
    std::strcpy(productos[3].FechaVigenciaPromocion, "16/02/2023");
    productos[3].Precio = 412000;

    std::ofstream archivo("productos.dat", std::ios::binary);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo crear el archivo productos.dat" << std::endl;
        return;
    }

    archivo.write(reinterpret_cast<char*>(productos), sizeof(productos));
    archivo.close();

    std::cout << "Archivo productos.dat creado con éxito." << std::endl;
}
