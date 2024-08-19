# Ejemplo Combinado: Uso de `std::string` y Apuntadores Dinámicos en C++

A continuación se presenta un ejemplo en el que se manejan cadenas de caracteres utilizando tanto `std::string` como apuntadores dinámicos (`char*`). El ejemplo realiza la misma operación: invertir una cadena de caracteres y comparar la cadena original con su versión invertida para determinar si es un palíndromo.

## Código

```cpp
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

// Versión con std::string
bool esPalindromoString(const std::string& cadena) {
    std::string invertida = cadena;
    std::reverse(invertida.begin(), invertida.end()); // Invertir la cadena
    return cadena == invertida;
}

// Versión con apuntadores dinámicos
bool esPalindromoChar(const char* cadena) {
    int longitud = std::strlen(cadena);
    char* invertida = new char[longitud + 1]; // +1 para el carácter nulo

    // Invertir la cadena
    for (int i = 0; i < longitud; ++i) {
        invertida[i] = cadena[longitud - 1 - i];
    }
    invertida[longitud] = '\0'; // Terminar la cadena con el carácter nulo

    bool resultado = std::strcmp(cadena, invertida) == 0;

    delete[] invertida; // Liberar memoria
    return resultado;
}

int main() {
    std::string cadenaString;
    char cadenaChar[100];

    std::cout << "Ingrese una cadena (para std::string y char*): ";
    std::getline(std::cin, cadenaString); // Leer cadena en std::string

    std::strcpy(cadenaChar, cadenaString.c_str()); // Copiar la cadena a char*

    // Verificación usando std::string
    if (esPalindromoString(cadenaString)) {
        std::cout << "[std::string] La cadena es un palíndromo." << std::endl;
    } else {
        std::cout << "[std::string] La cadena no es un palíndromo." << std::endl;
    }

    // Verificación usando apuntadores dinámicos
    if (esPalindromoChar(cadenaChar)) {
        std::cout << "[char*] La cadena es un palíndromo." << std::endl;
    } else {
        std::cout << "[char*] La cadena no es un palíndromo." << std::endl;
    }

    return 0;
}
```

## Explicación del Código

1. **Función `esPalindromoString`**:
    - Utiliza `std::string` para manejar la cadena.
    - Invierte la cadena utilizando `std::reverse` de la STL.
    - Compara la cadena original con la invertida para determinar si es un palíndromo.

2. **Función `esPalindromoChar`**:
    - Utiliza apuntadores dinámicos (`char*`) para manejar la cadena.
    - Invierte la cadena manualmente en un nuevo arreglo de caracteres.
    - Compara la cadena original con la invertida utilizando `std::strcmp`.

3. **Función Principal `main`**:
    - Se solicita al usuario que ingrese una cadena de caracteres.
    - La cadena se maneja tanto como `std::string` como `char*`.
    - Se llama a ambas versiones de la función para verificar si la cadena es un palíndromo.
    - Se imprime el resultado para cada versión.

## Resultado Esperado

Al ejecutar este programa, obtendrás dos resultados para la misma operación: uno utilizando `std::string` y otro utilizando apuntadores dinámicos. Ambos enfoques deben arrojar el mismo resultado sobre si la cadena es un palíndromo o no, pero con diferentes métodos de implementación.

## Comparación

Este ejemplo muestra cómo se puede lograr la misma funcionalidad con ambos enfoques. Usar `std::string` simplifica el manejo de cadenas al abstraer la gestión de memoria y proporcionar métodos fáciles de usar. Por otro lado, utilizar apuntadores dinámicos (`char*`) da un control más directo sobre la memoria, pero requiere una gestión más cuidadosa y detallada.
