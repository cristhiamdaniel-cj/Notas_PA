#ifndef CON_RESTRICCIONES_H
#define CON_RESTRICCIONES_H

#include "Producto.h"
#include <string>

bool EsMayor(const char* fecha1, const char* fecha2);

Producto* BuscarProductos(const char* FechaBuscar, const char* Nombre, int& cantidad);

void OrdenarYGuardarProductos(Producto* productos, int cantidad, const std::string& nombreArchivo);

#endif // CON_RESTRICCIONES_H
