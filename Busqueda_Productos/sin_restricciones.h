#ifndef SIN_RESTRICCIONES_H
#define SIN_RESTRICCIONES_H

#include "Producto.h"
#include <vector>
#include <string>
#include "con_restricciones.h" // Asegúrate de incluir este archivo para EsMayor

struct ProductoSinRestriccion {
    char NombreTienda[100];
    char URLTienda[200];
    char NombreProducto[300];
    char FechaVigenciaPromocion[10]; // Formato dd/mm/yyyy
    double Precio;
};

std::vector<ProductoSinRestriccion> BuscarProductosSinRestricciones(const char* FechaBuscar, const char* Nombre);

void OrdenarYGuardarProductos(const std::vector<ProductoSinRestriccion>& productos, const std::string& nombreArchivo);

#endif // SIN_RESTRICCIONES_H
