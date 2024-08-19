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