# Ejemplo Completo: Operaciones en un Archivo Binario en C++

Este ejemplo cubre todas las operaciones fundamentales que se pueden realizar en un archivo binario en C++, incluyendo escritura, lectura, modificación, y lectura selectiva. Se utiliza una estructura `Estudiante` para representar los datos que se almacenan y manipulan en el archivo.

## Estructura del Código

### 1. Definición de la Estructura `Estudiante`

```cpp
struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};
```

- **`nombre[50]`**: Un arreglo de caracteres para almacenar el nombre del estudiante.
- **`edad`**: Un entero para almacenar la edad del estudiante.
- **`calificacion`**: Un valor flotante para almacenar la calificación del estudiante.

Esta estructura será utilizada para almacenar y recuperar datos en el archivo binario.

### 2. Función `escribirArchivoBinario`

```cpp
void escribirArchivoBinario(const char* nombreArchivo) {
    Estudiante estudiantes[3] = {
        {"Juan Perez", 20, 89.5},
        {"Maria Lopez", 22, 92.0},
        {"Carlos Ruiz", 19, 78.4}
    };

    std::ofstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        archivo.write(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
    }

    archivo.close();
}
```

- **Propósito**: Esta función crea un archivo binario y escribe en él un array de estructuras `Estudiante`.
- **Detalles**:
    - Se define un array de tres estudiantes con datos de ejemplo.
    - Se abre un archivo binario utilizando `std::ofstream`.
    - Se utiliza un bucle para escribir cada estructura en el archivo con la función `write`.
    - `reinterpret_cast<char*>` convierte el puntero de la estructura a un puntero de tipo `char*`, necesario para escribir en el archivo binario.
    - Se cierra el archivo después de la escritura.

### 3. Función `leerArchivoBinario`

```cpp
void leerArchivoBinario(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
        return;
    }

    Estudiante estudiante;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nCalificación: " << estudiante.calificacion << std::endl;
        std::cout << "-------------------" << std::endl;
    }

    archivo.close();
}
```

- **Propósito**: Leer el contenido de un archivo binario y mostrar la información almacenada.
- **Detalles**:
    - Abre el archivo binario utilizando `std::ifstream`.
    - Usa un bucle `while` para leer cada registro (estructura `Estudiante`) del archivo hasta el final.
    - La función `read` se utiliza para leer los datos binarios del archivo y almacenarlos en la variable `estudiante`.
    - Muestra la información de cada estudiante en la consola.
    - Se cierra el archivo después de la lectura.

### 4. Función `modificarArchivoBinario`

```cpp
void modificarArchivoBinario(const char* nombreArchivo) {
    std::fstream archivo(nombreArchivo, std::ios::in | std::ios::out | std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para modificación." << std::endl;
        return;
    }

    // Modificar la calificación del segundo estudiante (índice 1)
    archivo.seekp(sizeof(Estudiante) + offsetof(Estudiante, calificacion), std::ios::beg);
    float nuevaCalificacion = 95.0;
    archivo.write(reinterpret_cast<char*>(&nuevaCalificacion), sizeof(nuevaCalificacion));

    archivo.close();
}
```

- **Propósito**: Modificar un valor específico dentro del archivo binario sin reescribir todo el archivo.
- **Detalles**:
    - Abre el archivo binario en modo lectura/escritura utilizando `std::fstream`.
    - `seekp` mueve el puntero de escritura al campo `calificacion` del segundo estudiante en el archivo.
    - La nueva calificación (95.0) se escribe en la ubicación especificada utilizando `write`.
    - El archivo se cierra después de la modificación.

### 5. Función `lecturaSelectiva`

```cpp
void lecturaSelectiva(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para lectura selectiva." << std::endl;
        return;
    }

    // Leer solo el segundo estudiante (índice 1)
    archivo.seekg(sizeof(Estudiante), std::ios::beg);

    Estudiante estudiante;
    archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));

    std::cout << "Lectura selectiva - Segundo Estudiante:" << std::endl;
    std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nCalificación: " << estudiante.calificacion << std::endl;

    archivo.close();
}
```

- **Propósito**: Leer un registro específico del archivo binario sin cargar todo el archivo en memoria.
- **Detalles**:
    - Abre el archivo binario utilizando `std::ifstream`.
    - `seekg` mueve el puntero de lectura al inicio del segundo registro en el archivo.
    - Lee y muestra solo la información del segundo estudiante utilizando `read`.
    - Se cierra el archivo después de la lectura selectiva.

### 6. Función `main`

```cpp
int main() {
    const char* nombreArchivo = "estudiantes.bin";

    // 1. Escritura en archivo binario
    escribirArchivoBinario(nombreArchivo);

    // 2. Lectura del archivo binario
    std::cout << "Contenido original del archivo binario:" << std::endl;
    leerArchivoBinario(nombreArchivo);

    // 3. Modificación del archivo binario
    modificarArchivoBinario(nombreArchivo);

    // 4. Lectura después de la modificación
    std::cout << "Contenido del archivo binario después de la modificación:" << std::endl;
    leerArchivoBinario(nombreArchivo);

    // 5. Lectura selectiva
    lecturaSelectiva(nombreArchivo);

    return 0;
}
```

- **Propósito**: Coordinar la ejecución de todas las funciones para realizar las operaciones en el archivo binario.
- **Detalles**:
    - Se llama a `escribirArchivoBinario` para crear y escribir los datos en el archivo binario.
    - Luego, se llama a `leerArchivoBinario` para leer y mostrar el contenido original del archivo.
    - Se llama a `modificarArchivoBinario` para modificar la calificación del segundo estudiante.
    - `leerArchivoBinario` se llama nuevamente para mostrar el contenido del archivo después de la modificación.
    - Finalmente, se llama a `lecturaSelectiva` para mostrar solo el segundo estudiante.

## Conclusión

Este ejemplo demuestra cómo manejar un archivo binario completo en C++, desde la creación y escritura inicial, hasta la lectura, modificación, y lectura selectiva. Estas operaciones son fundamentales para trabajar eficientemente con archivos binarios, especialmente en aplicaciones que requieren la manipulación de grandes volúmenes de datos o registros estructurados.
