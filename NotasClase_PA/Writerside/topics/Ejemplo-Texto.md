# Ejemplo de Aplicación para Archivos de Texto en C++

## Enunciado

Desarrolla un programa en C++ que gestione una lista de tareas. El programa debe permitir al usuario agregar nuevas tareas, mostrar todas las tareas y marcar una tarea como completada. Las tareas se almacenan en un archivo de texto llamado `tareas.txt`, donde cada línea representa una tarea. Una tarea completada se marcará añadiendo la etiqueta `[COMPLETADA]` al final de la línea correspondiente en el archivo.

## Código

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Función para mostrar todas las tareas
void mostrarTareas(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de tareas para lectura." << std::endl;
        return;
    }

    std::string tarea;
    int numeroTarea = 1;
    while (std::getline(archivo, tarea)) {
        std::cout << numeroTarea << ". " << tarea << std::endl;
        numeroTarea++;
    }

    archivo.close();
}

// Función para agregar una nueva tarea
void agregarTarea(const std::string& nombreArchivo, const std::string& nuevaTarea) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de tareas para escritura." << std::endl;
        return;
    }

    archivo << nuevaTarea << std::endl;
    archivo.close();
}

// Función para marcar una tarea como completada
void completarTarea(const std::string& nombreArchivo, int numeroTarea) {
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de tareas para lectura." << std::endl;
        return;
    }

    std::ofstream archivoTemporal("temporal.txt");
    std::string tarea;
    int contador = 1;

    while (std::getline(archivoEntrada, tarea)) {
        if (contador == numeroTarea) {
            tarea += " [COMPLETADA]";
        }
        archivoTemporal << tarea << std::endl;
        contador++;
    }

    archivoEntrada.close();
    archivoTemporal.close();

    std::remove(nombreArchivo.c_str());
    std::rename("temporal.txt", nombreArchivo.c_str());
}

int main() {
    const std::string nombreArchivo = "tareas.txt";
    int opcion;

    do {
        std::cout << "1. Mostrar tareas\n2. Agregar tarea\n3. Completar tarea\n4. Salir\nElige una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea residual

        if (opcion == 1) {
            mostrarTareas(nombreArchivo);
        } else if (opcion == 2) {
            std::string nuevaTarea;
            std::cout << "Escribe la nueva tarea: ";
            std::getline(std::cin, nuevaTarea);
            agregarTarea(nombreArchivo, nuevaTarea);
        } else if (opcion == 3) {
            int numeroTarea;
            std::cout << "Número de tarea a completar: ";
            std::cin >> numeroTarea;
            completarTarea(nombreArchivo, numeroTarea);
        }

    } while (opcion != 4);

    return 0;
}
```

## Explicación Detallada del Código

### 1. Función `mostrarTareas`

```cpp
void mostrarTareas(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de tareas para lectura." << std::endl;
        return;
    }

    std::string tarea;
    int numeroTarea = 1;
    while (std::getline(archivo, tarea)) {
        std::cout << numeroTarea << ". " << tarea << std::endl;
        numeroTarea++;
    }

    archivo.close();
}
```

- **Propósito**: Esta función lee y muestra todas las tareas almacenadas en el archivo `tareas.txt`.
- **Detalles**:
    - `std::ifstream archivo(nombreArchivo);` abre el archivo en modo de solo lectura.
    - `std::getline(archivo, tarea)` lee cada línea del archivo, representando cada una como una tarea.
    - Las tareas se muestran en la consola, numeradas secuencialmente.
    - El archivo se cierra después de que todas las tareas se han leído.

### 2. Función `agregarTarea`

```cpp
void agregarTarea(const std::string& nombreArchivo, const std::string& nuevaTarea) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de tareas para escritura." << std::endl;
        return;
    }

    archivo << nuevaTarea << std::endl;
    archivo.close();
}
```

- **Propósito**: Agregar una nueva tarea al final del archivo `tareas.txt`.
- **Detalles**:
    - `std::ofstream archivo(nombreArchivo, std::ios::app);` abre el archivo en modo de adición (`append`), permitiendo que las nuevas tareas se añadan al final del archivo sin sobrescribir las existentes.
    - La tarea proporcionada se escribe en el archivo seguida de un salto de línea (`std::endl`).
    - El archivo se cierra después de la escritura.

### 3. Función `completarTarea`

```cpp
void completarTarea(const std::string& nombreArchivo, int numeroTarea) {
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de tareas para lectura." << std::endl;
        return;
    }

    std::ofstream archivoTemporal("temporal.txt");
    std::string tarea;
    int contador = 1;

    while (std::getline(archivoEntrada, tarea)) {
        if (contador == numeroTarea) {
            tarea += " [COMPLETADA]";
        }
        archivoTemporal << tarea << std::endl;
        contador++;
    }

    archivoEntrada.close();
    archivoTemporal.close();

    std::remove(nombreArchivo.c_str());
    std::rename("temporal.txt", nombreArchivo.c_str());
}
```

- **Propósito**: Marcar una tarea específica como completada, añadiendo la etiqueta `[COMPLETADA]` al final de la línea correspondiente.
- **Detalles**:
    - Se abre el archivo de tareas para lectura y se crea un archivo temporal `temporal.txt` para escribir las modificaciones.
    - Se itera sobre cada línea del archivo original. Si la línea corresponde al número de tarea especificado, se le añade la etiqueta `[COMPLETADA]`.
    - Después de procesar todas las líneas, el archivo original se elimina y el archivo temporal se renombra para reemplazar al original.
    - Este enfoque asegura que la modificación de tareas se realice de manera segura, evitando la corrupción de datos en caso de errores durante el proceso.

### 4. Función `main`

```cpp
int main() {
    const std::string nombreArchivo = "tareas.txt";
    int opcion;

    do {
        std::cout << "1. Mostrar tareas\n2. Agregar tarea\n3. Completar tarea\n4. Salir\nElige una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea residual

        if (opcion == 1) {
            mostrarTareas(nombreArchivo);
        } else if (opcion == 2) {
            std::string nuevaTarea;
            std::cout << "Escribe la nueva tarea: ";
            std::getline(std::cin, nuevaTarea);
            agregarTarea(nombreArchivo, nuevaTarea);
        } else if (opcion == 3) {
            int numeroTarea;
            std::cout << "Número de tarea a completar: ";
            std::cin >> numeroTarea;
            completarTarea(nombreArchivo, numeroTarea);
        }

    } while (opcion != 4);

    return 0;
}
```

- **Propósito**: Ofrecer un menú interactivo al usuario para realizar las operaciones de mostrar, agregar, y completar tareas.
- **Detalles**:
    - Un bucle `do-while` mantiene el programa en ejecución hasta que el usuario elige salir.
    - Dependiendo de la opción seleccionada por el usuario, se llaman las funciones correspondientes (`mostrarTareas`, `agregarTarea`, `completarTarea`).
    - Se utiliza `std::cin.ignore()` para manejar correctamente las entradas de texto después de seleccionar opciones numéricas, asegurando que no se omitan entradas debido a caracteres residuales en el buffer.

## Conclusión

Este ejemplo muestra cómo se puede utilizar C++ para gestionar de manera efectiva un archivo de texto que almacena una lista de tareas. La estructura del programa permite agregar nuevas tareas, mostrar las existentes y marcar tareas como completadas, todo ello gestionando el archivo de texto de forma segura y eficiente. Este tipo de aplicaciones es común en el desarrollo de software que requiere persistencia de datos y manejo de listas o registros.
