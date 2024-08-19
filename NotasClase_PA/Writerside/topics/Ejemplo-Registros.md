# Gestión Avanzada de Estudiantes en C++ Usando `structs`

## Enunciado del Problema

Se requiere desarrollar un sistema para gestionar estudiantes en una universidad. Este sistema debe permitir almacenar información sobre los estudiantes, como nombre, edad, fecha de ingreso y calificaciones. Además, el sistema debe manejar tanto listas de estudiantes de tamaño fijo como listas dinámicas que pueden cambiar en tiempo de ejecución.

El sistema debe implementar lo siguiente:

1. Definir estructuras (`structs`) para almacenar la información básica de los estudiantes.
2. Utilizar estas estructuras tanto en memoria estática (listas de tamaño fijo) como en memoria dinámica (listas de tamaño variable).
3. Incluir funciones que permitan agregar y mostrar la información de los estudiantes utilizando punteros y el operador `->`.

## Código del Sistema de Gestión de Estudiantes

```cpp
#include <iostream>
#include <string>
#include <vector>

// Estructura para almacenar la fecha de ingreso de un estudiante
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Estructura para almacenar la información del estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    Fecha fechaIngreso;
    std::vector<int> notas; // Uso dinámico para almacenar notas
};

// Función para mostrar la información de un estudiante mediante puntero
void mostrarEstudiante(const Estudiante* estudiante) {
    std::cout << "Nombre: " << estudiante->nombre << std::endl;
    std::cout << "Edad: " << estudiante->edad << std::endl;
    std::cout << "Fecha de Ingreso: " << estudiante->fechaIngreso.dia << "/"
              << estudiante->fechaIngreso.mes << "/"
              << estudiante->fechaIngreso.anio << std::endl;
    std::cout << "Notas: ";
    for (int nota : estudiante->notas) {
        std::cout << nota << " ";
    }
    std::cout << std::endl;
}

// Función para agregar una nota a un estudiante mediante puntero
void agregarNota(Estudiante* estudiante, int nota) {
    estudiante->notas.push_back(nota); // Acceso dinámico a las notas usando `->`
}

// Función para crear un estudiante y retornar un puntero
Estudiante* crearEstudiante(std::string nombre, int edad, Fecha fechaIngreso) {
    Estudiante* nuevoEstudiante = new Estudiante; // Memoria dinámica para el estudiante
    nuevoEstudiante->nombre = nombre;
    nuevoEstudiante->edad = edad;
    nuevoEstudiante->fechaIngreso = fechaIngreso;
    return nuevoEstudiante; // Retorna un puntero al estudiante
}

int main() {
    // Uso Estático de `struct`
    const int NUM_ESTUDIANTES = 3;
    Estudiante estudiantesEstaticos[NUM_ESTUDIANTES] = {
        {"Juan Perez", 20, {1, 8, 2021}, {85, 90}},
        {"Maria Lopez", 22, {15, 1, 2020}, {78, 88, 92}},
        {"Carlos Ruiz", 19, {10, 7, 2022}, {91, 85, 89}}
    };

    std::cout << "Información de Estudiantes (Estático):" << std::endl;
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        mostrarEstudiante(&estudiantesEstaticos[i]); // Pasamos el puntero
        std::cout << "-------------------" << std::endl;
    }

    // Uso Dinámico de `struct` con Punteros
    std::vector<Estudiante*> estudiantesDinamicos;

    estudiantesDinamicos.push_back(crearEstudiante("Ana Torres", 21, {5, 3, 2021}));
    estudiantesDinamicos.push_back(crearEstudiante("Luis Martinez", 23, {12, 9, 2019}));

    agregarNota(estudiantesDinamicos[0], 95); // Agregar nota usando puntero
    agregarNota(estudiantesDinamicos[1], 88);
    agregarNota(estudiantesDinamicos[1], 82);

    std::cout << "\nInformación de Estudiantes (Dinámico con Punteros):" << std::endl;
    for (Estudiante* estudiante : estudiantesDinamicos) {
        mostrarEstudiante(estudiante); // Pasamos el puntero
        std::cout << "-------------------" << std::endl;
    }

    // Liberar la memoria dinámica
    for (Estudiante* estudiante : estudiantesDinamicos) {
        delete estudiante; // Liberamos la memoria asignada dinámicamente
    }

    return 0;
}
```

## Explicación del Código

### Definición de `structs`

```cpp
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Estudiante {
    std::string nombre;
    int edad;
    Fecha fechaIngreso;
    std::vector<int> notas; // Uso dinámico para almacenar notas
};
```

- **Fecha**: Esta `struct` almacena la información de la fecha de ingreso del estudiante, utilizando tres enteros: día, mes y año.
- **Estudiante**: Esta `struct` almacena la información de un estudiante, incluyendo su nombre, edad, fecha de ingreso (usando la `struct` `Fecha`), y un `vector<int>` para almacenar las notas del estudiante de manera dinámica.

### Mostrar Información de un Estudiante

```cpp
void mostrarEstudiante(const Estudiante* estudiante) {
    std::cout << "Nombre: " << estudiante->nombre << std::endl;
    std::cout << "Edad: " << estudiante->edad << std::endl;
    std::cout << "Fecha de Ingreso: " << estudiante->fechaIngreso.dia << "/"
              << estudiante->fechaIngreso.mes << "/"
              << estudiante->fechaIngreso.anio << std::endl;
    std::cout << "Notas: ";
    for (int nota : estudiante->notas) {
        std::cout << nota << " ";
    }
    std::cout << std::endl;
}
```

- **Función `mostrarEstudiante`**: Esta función toma un puntero a una `struct` `Estudiante` y muestra la información del estudiante en la consola. Se utiliza el operador `->` para acceder a los miembros de la `struct` a través del puntero.

### Agregar Nota a un Estudiante

```cpp
void agregarNota(Estudiante* estudiante, int nota) {
    estudiante->notas.push_back(nota); // Acceso dinámico a las notas usando `->`
}
```

- **Función `agregarNota`**: Permite agregar una nota a un estudiante específico utilizando un puntero a la `struct` `Estudiante`. Se accede a la lista de notas de manera dinámica utilizando `push_back` en el `vector`.

### Crear un Estudiante (Memoria Dinámica)

```cpp
Estudiante* crearEstudiante(std::string nombre, int edad, Fecha fechaIngreso) {
    Estudiante* nuevoEstudiante = new Estudiante; // Memoria dinámica para el estudiante
    nuevoEstudiante->nombre = nombre;
    nuevoEstudiante->edad = edad;
    nuevoEstudiante->fechaIngreso = fechaIngreso;
    return nuevoEstudiante; // Retorna un puntero al estudiante
}
```

- **Función `crearEstudiante`**: Esta función asigna memoria dinámica para un nuevo estudiante usando `new`. La función inicializa los miembros del estudiante y devuelve un puntero a la `struct` creada.

### Uso Estático de `struct`

```cpp
const int NUM_ESTUDIANTES = 3;
Estudiante estudiantesEstaticos[NUM_ESTUDIANTES] = {
    {"Juan Perez", 20, {1, 8, 2021}, {85, 90}},
    {"Maria Lopez", 22, {15, 1, 2020}, {78, 88, 92}},
    {"Carlos Ruiz", 19, {10, 7, 2022}, {91, 85, 89}}
};
```

- **Arreglo Estático de `structs`**: Aquí se define un arreglo de `structs` de tamaño fijo (3) para almacenar información sobre los estudiantes. La memoria para este arreglo se asigna de manera estática en el stack.

### Uso Dinámico de `struct` con Punteros

```cpp
std::vector<Estudiante*> estudiantesDinamicos;

estudiantesDinamicos.push_back(crearEstudiante("Ana Torres", 21, {5, 3, 2021}));
estudiantesDinamicos.push_back(crearEstudiante("Luis Martinez", 23, {12, 9, 2019}));
```

- **Lista Dinámica de `structs`**: Se utiliza un `vector` de punteros a `structs` para manejar dinámicamente la lista de estudiantes. Esto permite que la lista crezca o disminuya en tiempo de ejecución.

### Liberación de Memoria Dinámica

```cpp
for (Estudiante* estudiante : estudiantesDinamicos) {
    delete estudiante; // Liberamos la memoria asignada dinámicamente
}
```

- **Liberación de Memoria**: Es importante liberar la memoria asignada dinámicamente con `delete` para evitar fugas de memoria. Esto se hace recorriendo todos los pun

teros en el vector y llamando a `delete` para cada uno.

## Conclusión: Importancia de las `structs` en C++

Las `structs` en C++ son una herramienta poderosa para agrupar datos relacionados bajo un solo nombre, lo que facilita el manejo de datos complejos. Además, el uso combinado de `structs` con punteros y memoria dinámica permite una mayor flexibilidad en la gestión de datos, permitiendo a los desarrolladores crear estructuras que pueden adaptarse a diferentes necesidades en tiempo de ejecución.
