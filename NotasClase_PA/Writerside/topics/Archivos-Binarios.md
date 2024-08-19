# Archivos en C++: Enfoque en Archivos Binarios

## 1. Introducción

Los archivos son una parte esencial de la programación en C++, permitiendo a los programas almacenar datos de manera persistente. Existen dos tipos principales de archivos: **archivos de texto** y **archivos binarios**. Mientras que los archivos de texto almacenan datos en formato legible por humanos, los archivos binarios almacenan datos en un formato más compacto y eficiente, que es directamente interpretable por la máquina.

Este documento se centra en los **archivos binarios**, cubriendo desde los conceptos básicos hasta técnicas avanzadas para manejar datos primitivos y compuestos, así como el uso de funciones de posicionamiento como `seekp` y `seekg`.

## 2. Conceptos Básicos: Archivos de Texto vs. Archivos Binarios

### 2.1 Archivos de Texto

En un archivo de texto, los datos se almacenan como una secuencia de caracteres, utilizando codificaciones como ASCII o UTF-8. Estos archivos son fáciles de leer y editar con un editor de texto simple.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream archivo("ejemplo.txt"); // Crear un archivo de texto
    archivo << "Hola, mundo!" << std::endl; // Escribir en el archivo
    archivo.close(); // Cerrar el archivo

    return 0;
}
```

### 2.2 Archivos Binarios

En un archivo binario, los datos se almacenan en su representación binaria nativa, lo que hace que los archivos sean más eficientes en términos de almacenamiento y velocidad de acceso. Sin embargo, no son legibles directamente por humanos.

```cpp
#include <iostream>
#include <fstream>

int main() {
    int numero = 12345;
    std::ofstream archivo("ejemplo.bin", std::ios::binary); // Crear un archivo binario
    archivo.write(reinterpret_cast<char*>(&numero), sizeof(numero)); // Escribir el número en formato binario
    archivo.close(); // Cerrar el archivo

    return 0;
}
```

## 3. Manipulación de Datos Primitivos en Archivos Binarios

### 3.1 Escritura de Datos Primitivos

Para escribir datos primitivos como `int`, `float`, o `char` en un archivo binario, se utiliza la función `write` del objeto `ofstream`. Es necesario convertir el puntero al tipo de dato a un puntero a `char` usando `reinterpret_cast`.

```cpp
#include <iostream>
#include <fstream>

int main() {
    int numero = 100;
    float valor = 3.14;
    char letra = 'A';

    std::ofstream archivo("datos.bin", std::ios::binary);

    archivo.write(reinterpret_cast<char*>(&numero), sizeof(numero));
    archivo.write(reinterpret_cast<char*>(&valor), sizeof(valor));
    archivo.write(reinterpret_cast<char*>(&letra), sizeof(letra));

    archivo.close();

    return 0;
}
```

### 3.2 Lectura de Datos Primitivos

Para leer datos primitivos de un archivo binario, se utiliza la función `read` del objeto `ifstream`.

```cpp
#include <iostream>
#include <fstream>

int main() {
    int numero;
    float valor;
    char letra;

    std::ifstream archivo("datos.bin", std::ios::binary);

    archivo.read(reinterpret_cast<char*>(&numero), sizeof(numero));
    archivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));
    archivo.read(reinterpret_cast<char*>(&letra), sizeof(letra));

    archivo.close();

    std::cout << "Numero: " << numero << "\nValor: " << valor << "\nLetra: " << letra << std::endl;

    return 0;
}
```

## 4. Manipulación de Datos Compuestos en Archivos Binarios

### 4.1 Estructuras y Archivos Binarios

Las estructuras (`structs`) en C++ pueden almacenarse en archivos binarios de la misma manera que los datos primitivos, siempre que no contengan apuntadores u otros elementos que dependan de la memoria dinámica.

```cpp
#include <iostream>
#include <fstream>

struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};

int main() {
    Estudiante estudiante = {"Juan Perez", 20, 89.5};

    std::ofstream archivo("estudiante.bin", std::ios::binary);
    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(estudiante));
    archivo.close();

    return 0;
}
```

### 4.2 Lectura de Estructuras desde un Archivo Binario

La lectura de estructuras desde un archivo binario sigue el mismo patrón que con datos primitivos.

```cpp
#include <iostream>
#include <fstream>

struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};

int main() {
    Estudiante estudiante;

    std::ifstream archivo("estudiante.bin", std::ios::binary);
    archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(estudiante));
    archivo.close();

    std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nCalificación: " << estudiante.calificacion << std::endl;

    return 0;
}
```

### 4.3 Consideraciones sobre Alineación y Portabilidad

Es importante tener en cuenta la alineación de los datos dentro de las estructuras, ya que diferentes compiladores o arquitecturas pueden alinear los datos de manera diferente. Para garantizar la portabilidad, es recomendable escribir y leer los campos de las estructuras individualmente o utilizar técnicas de serialización/deserialización específicas.

## 5. Operaciones Avanzadas en Archivos Binarios

### 5.1 Uso de `seekp` y `seekg` para Reposicionar el Puntero

Cuando se trabaja con archivos binarios, a menudo es necesario mover el puntero de lectura/escritura a una posición específica dentro del archivo. Esto se logra utilizando las funciones `seekp` (seek put) y `seekg` (seek get). Estas funciones permiten reposicionar el puntero en cualquier lugar del archivo, facilitando operaciones como la modificación de datos en medio del archivo o la lectura selectiva de datos.

- **`seekp(pos)`**: Mueve el puntero de escritura a la posición `pos`.
- **`seekg(pos)`**: Mueve el puntero de lectura a la posición `pos`.
- **`tellp()`**: Devuelve la posición actual del puntero de escritura.
- **`tellg()`**: Devuelve la posición actual del puntero de lectura.

#### Ejemplo: Modificación de un Valor en un Archivo Binario

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::fstream archivo("datos.bin", std::ios::in | std::ios::out | std::ios::binary);

    int nuevoValor = 200;
    archivo.seekp(sizeof(int), std::ios::beg); // Mover el puntero al segundo dato (un float en este caso)
    archivo.write(reinterpret_cast<char*>(&nuevoValor), sizeof(nuevoValor));

    archivo.close();

    return 0;
}
```

En este ejemplo, el puntero de escritura se mueve al segundo elemento en el archivo binario, y el valor de ese elemento se modifica. Esto es útil en situaciones donde solo necesitas actualizar una pequeña parte del archivo sin reescribirlo por completo.

### 5.2 Inserción de Nuevos Datos

Para insertar nuevos datos en un archivo binario, generalmente se requiere crear un nuevo archivo y copiar los datos antiguos junto con los nuevos en el orden deseado.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream archivoLectura("datos.bin", std::ios::binary);
    std::ofstream archivoEscritura("nuevo_datos.bin", std::ios::binary);

    // Leer y copiar el primer entero
    int numero;
    archivoLectura.read(reinterpret_cast<char*>(&numero), sizeof(numero));
    archivoEscritura.write(reinterpret_cast<char*>(&numero), sizeof(numero));

    // Insertar un nuevo float
    float nuevoValor = 7.89;
    archivoEscritura.write(reinterpret_cast<char*>(&nuevoValor), sizeof(nuevoValor));

    // Copiar el resto del archivo
    float valor;
    char letra;
    archivoLectura.read(reinterpret_cast<char*>(&valor), sizeof(valor));
    archivoLectura.read(reinterpret_cast<char*>(&letra), sizeof(letra));
    archivoEscritura.write(reinterpret_cast<char*>(&valor), sizeof(valor));
    archivoEscritura.write(reinterpret_cast<char*>(&letra), sizeof(letra));

    archivoLectura.close();
    archivoEscritura.close();

    return 0;
}
```

### 5.3 Uso de `seekg` para Lectura Selectiva

A veces, solo es necesario leer una parte específica de un archivo binario, lo que se puede hacer usando `seekg` para mover el puntero de lectura a la posición deseada.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream archivo("datos.bin", std::ios::binary);

    archivo.seekg(sizeof(int), std::ios::beg); // Mover el puntero al segundo

 dato

    float valor;
    archivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));

    std::cout << "Valor leído: " << valor << std::endl;

    archivo.close();

    return 0;
}
```

En este ejemplo, el puntero de lectura se mueve al segundo dato en el archivo binario, y se lee solo ese valor. Esto es útil cuando se trabaja con archivos grandes y se necesita acceder rápidamente a datos específicos sin cargar todo el archivo en memoria.

## 6. Conclusión

Los archivos binarios son una herramienta poderosa en C++ para almacenar y manipular datos de manera eficiente. Desde la escritura y lectura de datos primitivos hasta la manipulación de estructuras completas, el manejo de archivos binarios ofrece un control detallado sobre cómo se almacenan los datos. Además, las funciones de posicionamiento como `seekp` y `seekg` permiten realizar operaciones avanzadas como la modificación y la lectura selectiva de datos en archivos binarios, lo que proporciona una gran flexibilidad y eficiencia en el manejo de datos persistentes.
