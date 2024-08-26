# 3. (40 puntos) Busqueda de Productos

Suponga quer una aplicacion logra obtener precios comparativos de promociones de productos en tiendas de comercio electronico 
y guarda la informacion en un archivo binario con tipo llamado ```productos.dat```. Este archivo se lee con el siguiente registro:

```cpp
struct Producto{
    char NombreTienda[100];
    char URLTienda[200];
    char NombreProducto[300];
    char FechaVigenciaPromocion[10]; // Formato dd/mm/yyyy
    double Precio;
};
```

Un ejemplo de este archivo es:

```txt
Tiendas Jupiter     www.jupiter.com     Parlantes tipo 1        30/03/2023      175000
Yelao               yelao.com           Llantas marca a         13/02/2023      400000
Logro               logro.com           Parlantes tipo 1        28/03/2023      172000
Llanticas.com       www.llanticas.com   Llantas marca a         16/02/2023      412000
...                 ...                 ...                     ...             ...
```

Restricciones para todos los puntos subsecuentes: No se puede usar el tipo de datos ```string```, los arreglos deben ser dinamicos 
y recorrerse con aritmetica de punteros.

1. (5 puntos) Desarrolle una funcion que reciba como parametros dos cadenas de caracteres que cada una representa una 
fecha en formato ```dd/mm/yyyy``` y que retorne ```true``` si la primera fecha es mayor que la segunda fecha. El prototipo ded la funcion es:
```bool EsMayor(char *fecha1, char *fecha2);```
2. (15 puntos) Desarrolle una funcion que reciba como parametro una fecha en formato ```dd/mm/yyyy``` y un nombre de producto, 
y que retorne un arreglo dinamico con todos aquellos productos del archivo ```productos.dat``` cuyo nombre del producto contenga 
el nombre del producto recibido como parametro y cuya vigencia de la promocion sea mayor o igual a la fecha recibida como parametro. 
El arreglo debe retornarse con el ```return``` de la funcion.
``` struct Producto *BuscarProductos(char *FechaBuscar, char *Nombre);```
3. (20 puntos) Desarrolle una funcion que, dado el arreglo generado con la funcion anterior, lo ordene de menor a mayor 
por el precio del producto y que grabe en un archivo llamado ```Mejores.txt```, los 5 primeros productos del arreglo ordenado.
Debe grabarse toda la informacion del producto con cada campo separado por comas.