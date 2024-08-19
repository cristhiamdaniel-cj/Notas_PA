# Ejercicio Avanzado: Implementación de Regresión Lineal Usando Registros, Apuntadores y Memoria Dinámica en C++

## Enunciado del Problema

Se desea implementar un programa en C++ que realice una regresión lineal simple para predecir un valor `y` en función de un valor `x`. Para ello, se utilizarán registros (`structs`) para organizar los datos y los resultados, apuntadores para la manipulación dinámica de la memoria, y operaciones aritméticas avanzadas.

El programa debe:
1. Leer un conjunto de datos de tamaño `n` donde cada punto tiene un valor `x` y un valor `y`.
2. Calcular los coeficientes `a` y `b` de la regresión lineal usando la fórmula `y = a + b * x`.
3. Realizar la predicción para un nuevo valor `x` y mostrar el resultado.

## Código Completo

```cpp
#include <iostream>
#include <cmath>

// Estructura para almacenar los datos de un punto (x, y)
struct Punto {
    double x;
    double y;
};

// Estructura para almacenar los coeficientes de la regresión lineal
struct Coeficientes {
    double a;
    double b;
};

// Función para calcular los coeficientes de la regresión lineal
Coeficientes* calcularCoeficientes(Punto* puntos, int n) {
    double sumaX = 0, sumaY = 0, sumaXY = 0, sumaX2 = 0;

    for (int i = 0; i < n; i++) {
        sumaX += puntos[i].x;
        sumaY += puntos[i].y;
        sumaXY += puntos[i].x * puntos[i].y;
        sumaX2 += puntos[i].x * puntos[i].x;
    }

    double b = (n * sumaXY - sumaX * sumaY) / (n * sumaX2 - sumaX * sumaX);
    double a = (sumaY - b * sumaX) / n;

    Coeficientes* coef = new Coeficientes; // Memoria dinámica para los coeficientes
    coef->a = a;
    coef->b = b;

    return coef; // Retorna un puntero a los coeficientes
}

// Función para predecir el valor de y dado un valor de x
double predecirY(Coeficientes* coef, double x) {
    return coef->a + coef->b * x;
}

int main() {
    int n;
    std::cout << "Ingrese el número de puntos: ";
    std::cin >> n;

    Punto* puntos = new Punto[n]; // Memoria dinámica para los puntos

    std::cout << "Ingrese los valores de x e y:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Punto " << i + 1 << ":\n";
        std::cout << "x: ";
        std::cin >> puntos[i].x;
        std::cout << "y: ";
        std::cin >> puntos[i].y;
    }

    Coeficientes* coef = calcularCoeficientes(puntos, n); // Cálculo de los coeficientes

    std::cout << "Ecuación de la regresión lineal: y = " << coef->a << " + " << coef->b << " * x\n";

    double nuevoX;
    std::cout << "Ingrese un valor de x para predecir y: ";
    std::cin >> nuevoX;

    double prediccion = predecirY(coef, nuevoX);
    std::cout << "El valor predicho de y es: " << prediccion << std::endl;

    delete[] puntos; // Liberar memoria de los puntos
    delete coef; // Liberar memoria de los coeficientes

    return 0;
}
```

## Explicación del Código

### 1. Estructuras para Datos y Coeficientes

```cpp
struct Punto {
    double x;
    double y;
};

struct Coeficientes {
    double a;
    double b;
};
```

- **Punto**: Esta `struct` almacena los valores `x` e `y` de cada punto de datos.
- **Coeficientes**: Esta `struct` almacena los coeficientes `a` y `b` de la ecuación de regresión lineal `y = a + b * x`.

### 2. Función para Calcular los Coeficientes de la Regresión Lineal

```cpp
Coeficientes* calcularCoeficientes(Punto* puntos, int n) {
    double sumaX = 0, sumaY = 0, sumaXY = 0, sumaX2 = 0;

    for (int i = 0; i < n; i++) {
        sumaX += puntos[i].x;
        sumaY += puntos[i].y;
        sumaXY += puntos[i].x * puntos[i].y;
        sumaX2 += puntos[i].x * puntos[i].x;
    }

    double b = (n * sumaXY - sumaX * sumaY) / (n * sumaX2 - sumaX * sumaX);
    double a = (sumaY - b * sumaX) / n;

    Coeficientes* coef = new Coeficientes; // Memoria dinámica para los coeficientes
    coef->a = a;
    coef->b = b;

    return coef; // Retorna un puntero a los coeficientes
}
```

- **Entrada**: La función recibe un apuntador a un arreglo de `Punto` y un entero `n` que representa la cantidad de puntos.
- **Cálculos**: Se calculan las sumas necesarias para determinar los coeficientes `a` y `b` usando las fórmulas estándar de regresión lineal.
- **Memoria Dinámica**: Los coeficientes se almacenan en memoria dinámica usando `new`, y la función retorna un apuntador a esa memoria.

### 3. Función para Predecir el Valor de `y`

```cpp
double predecirY(Coeficientes* coef, double x) {
    return coef->a + coef->b * x;
}
```

- **Entrada**: La función recibe un apuntador a la `struct` `Coeficientes` y un valor `x`.
- **Salida**: Retorna el valor predicho de `y` utilizando la ecuación de la regresión lineal.

### 4. Función Principal `main`

```cpp
int main() {
    int n;
    std::cout << "Ingrese el número de puntos: ";
    std::cin >> n;

    Punto* puntos = new Punto[n]; // Memoria dinámica para los puntos

    std::cout << "Ingrese los valores de x e y:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Punto " << i + 1 << ":\n";
        std::cout << "x: ";
        std::cin >> puntos[i].x;
        std::cout << "y: ";
        std::cin >> puntos[i].y;
    }

    Coeficientes* coef = calcularCoeficientes(puntos, n); // Cálculo de los coeficientes

    std::cout << "Ecuación de la regresión lineal: y = " << coef->a << " + " << coef->b << " * x\n";

    double nuevoX;
    std::cout << "Ingrese un valor de x para predecir y: ";
    std::cin >> nuevoX;

    double prediccion = predecirY(coef, nuevoX);
    std::cout << "El valor predicho de y es: " << prediccion << std::endl;

    delete[] puntos; // Liberar memoria de los puntos
    delete coef; // Liberar memoria de los coeficientes

    return 0;
}
```

- **Ingreso de Datos**: El usuario ingresa el número de puntos y los valores `x` e `y` para cada punto.
- **Memoria Dinámica para los Datos**: Los puntos se almacenan en un arreglo dinámico de `Punto`.
- **Cálculo de la Regresión**: Se llaman a las funciones para calcular los coeficientes y para predecir el valor de `y` para un nuevo `x`.
- **Liberación de Memoria**: Se libera toda la memoria dinámica asignada para evitar fugas de memoria.

## Conclusión

Este ejercicio avanzado integra varios conceptos clave en C++, como el uso de registros (`structs`), apuntadores, y memoria dinámica, aplicados a un problema real de regresión lineal. La capacidad de manipular la memoria directamente permite un manejo eficiente de los recursos y una mayor flexibilidad en la implementación de algoritmos complejos. Este ejercicio es ideal para consolidar el entendimiento de cómo estos conceptos se interrelacionan y se aplican en la resolución de problemas matemáticos en programación.

 