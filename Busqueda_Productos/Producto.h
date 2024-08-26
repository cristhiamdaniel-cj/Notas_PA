#ifndef PRODUCTO_H
#define PRODUCTO_H

struct Producto {
    char NombreTienda[100];
    char URLTienda[200];
    char NombreProducto[300];
    char FechaVigenciaPromocion[10]; // Formato dd/mm/yyyy
    double Precio;
};

#endif // PRODUCTO_H
