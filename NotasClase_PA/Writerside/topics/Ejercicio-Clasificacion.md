# Ejemplo de Aplicación: Implementación Básica del Algoritmo k-NN en C++

## Enunciado del Problema

Se desea implementar el algoritmo de k-Nearest Neighbors (k-NN) para clasificar un conjunto de puntos en el espacio 2D. Dado un conjunto de puntos etiquetados, el algoritmo debe predecir la clase de un nuevo punto en función de las clases de sus `k` vecinos más cercanos. 

Utilizaremos:
- **Estructuras (`structs`)** para representar puntos y clasificaciones.
- **Arreglos Dinámicos** para manejar un número variable de puntos.
- **Apuntadores** para acceder y manipular dinámicamente la memoria.

## Código Completo

```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // Necesario para std::sort

// Estructura para almacenar un punto en el espacio 2D con su etiqueta
struct Punto {
    double x;
    double y;
    int etiqueta; // 0 o 1
};

// Función para calcular la distancia euclidiana entre dos puntos
double calcularDistancia(const Punto* p1, const Punto* p2) {
    return std::sqrt(std::pow(p1->x - p2->x, 2) + std::pow(p1->y - p2->y, 2));
}

// Función para encontrar los k vecinos más cercanos
int kNN(Punto* puntos, int n, Punto* nuevo, int k) {
    std::vector<std::pair<double, int>> distancias; // Vector para almacenar distancias y etiquetas

    for (int i = 0; i < n; ++i) {
        double dist = calcularDistancia(&puntos[i], nuevo);
        distancias.push_back(std::make_pair(dist, puntos[i].etiqueta));
    }

    // Ordenar el vector de distancias
    std::sort(distancias.begin(), distancias.end());

    // Contar las etiquetas de los k vecinos más cercanos
    int contador0 = 0, contador1 = 0;
    for (int i = 0; i < k; ++i) {
        if (distancias[i].second == 0) {
            contador0++;
        } else {
            contador1++;
        }
    }

    // Retornar la clase más común entre los vecinos
    return (contador0 > contador1) ? 0 : 1;
}

int main() {
    int n;
    std::cout << "Ingrese el número de puntos de entrenamiento: ";
    std::cin >> n;

    Punto* puntos = new Punto[n]; // Memoria dinámica para puntos de entrenamiento

    std::cout << "Ingrese los valores de x, y y la etiqueta (0 o 1) para cada punto:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Punto " << i + 1 << ":\n";
        std::cout << "x: ";
        std::cin >> puntos[i].x;
        std::cout << "y: ";
        std::cin >> puntos[i].y;
        std::cout << "etiqueta (0 o 1): ";
        std::cin >> puntos[i].etiqueta;
    }

    Punto nuevo;
    std::cout << "Ingrese las coordenadas del nuevo punto a clasificar:\n";
    std::cout << "x: ";
    std::cin >> nuevo.x;
    std::cout << "y: ";
    std::cin >> nuevo.y;

    int k;
    std::cout << "Ingrese el valor de k: ";
    std::cin >> k;

    int etiquetaPredicha = kNN(puntos, n, &nuevo, k);
    std::cout << "La clase predicha para el nuevo punto es: " << etiquetaPredicha << std::endl;

    delete[] puntos; // Liberar la memoria dinámica

    return 0;
}
```

## Explicación del Código

### 1. Estructura `Punto`

```cpp
struct Punto {
    double x;
    double y;
    int etiqueta; // 0 o 1
};
```

- **Punto**: Esta estructura representa un punto en el espacio 2D con una coordenada `x`, una coordenada `y`, y una etiqueta que indica la clase del punto (0 o 1).

### 2. Función para Calcular la Distancia Euclidiana

```cpp
double calcularDistancia(const Punto* p1, const Punto* p2) {
    return std::sqrt(std::pow(p1->x - p2->x, 2) + std::pow(p1->y - p2->y, 2));
}
```

- **calcularDistancia**: Esta función toma dos apuntadores a `Punto` y calcula la distancia euclidiana entre ellos.

### 3. Función `kNN` para Clasificación

```cpp
int kNN(Punto* puntos, int n, Punto* nuevo, int k) {
    std::vector<std::pair<double, int>> distancias; // Vector para almacenar distancias y etiquetas

    for (int i = 0; i < n; ++i) {
        double dist = calcularDistancia(&puntos[i], nuevo);
        distancias.push_back(std::make_pair(dist, puntos[i].etiqueta));
    }

    // Ordenar el vector de distancias
    std::sort(distancias.begin(), distancias.end());

    // Contar las etiquetas de los k vecinos más cercanos
    int contador0 = 0, contador1 = 0;
    for (int i = 0; i < k; ++i) {
        if (distancias[i].second == 0) {
            contador0++;
        } else {
            contador1++;
        }
    }

    // Retornar la clase más común entre los vecinos
    return (contador0 > contador1) ? 0 : 1;
}
```

- **kNN**: Esta función implementa el algoritmo k-NN. Toma un arreglo dinámico de puntos, el número de puntos, un apuntador al nuevo punto a clasificar, y el valor de `k`. Calcula las distancias entre el nuevo punto y los puntos de entrenamiento, ordena estas distancias, y determina la clase más común entre los `k` vecinos más cercanos.

### 4. Función Principal `main`

```cpp
int main() {
    int n;
    std::cout << "Ingrese el número de puntos de entrenamiento: ";
    std::cin >> n;

    Punto* puntos = new Punto[n]; // Memoria dinámica para puntos de entrenamiento

    std::cout << "Ingrese los valores de x, y y la etiqueta (0 o 1) para cada punto:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Punto " << i + 1 << ":\n";
        std::cout << "x: ";
        std::cin >> puntos[i].x;
        std::cout << "y: ";
        std::cin >> puntos[i].y;
        std::cout << "etiqueta (0 o 1): ";
        std::cin >> puntos[i].etiqueta;
    }

    Punto nuevo;
    std::cout << "Ingrese las coordenadas del nuevo punto a clasificar:\n";
    std::cout << "x: ";
    std::cin >> nuevo.x;
    std::cout << "y: ";
    std::cin >> nuevo.y;

    int k;
    std::cout << "Ingrese el valor de k: ";
    std::cin >> k;

    int etiquetaPredicha = kNN(puntos, n, &nuevo, k);
    std::cout << "La clase predicha para el nuevo punto es: " << etiquetaPredicha << std::endl;

    delete[] puntos; // Liberar la memoria dinámica

    return 0;
}
```

- **Entrada de Datos**: El usuario ingresa los puntos de entrenamiento, incluyendo sus coordenadas y etiquetas, que se almacenan en un arreglo dinámico de `Punto`.
- **Clasificación**: Se clasifica un nuevo punto usando el algoritmo k-NN, y se muestra la clase predicha.
- **Gestión de Memoria**: Se usa `new` para asignar memoria dinámica para los puntos de entrenamiento y `delete[]` para liberar esa memoria al final del programa.

## Conclusión

Este ejercicio demuestra cómo se pueden combinar estructuras (`structs`), arreglos dinámicos, apuntadores y memoria dinámica en C++ para implementar un algoritmo básico de Machine Learning como k-NN. El uso de estructuras permite organizar los datos de manera clara, mientras que los arreglos y apuntadores proporcionan la flexibilidad necesaria para manejar un número variable de datos en tiempo de ejecución. Este tipo de implementación es un ejemplo práctico de cómo los conceptos básicos de C++ pueden aplicarse en la resolución de problemas complejos.
