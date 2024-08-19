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
