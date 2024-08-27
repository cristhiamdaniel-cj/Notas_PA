#include <iostream>
#include <fstream>
#include "crear_archivos.h"

void crearArchivoMedidas() {
    std::ofstream archivo("medidas.txt");
    if (archivo.is_open()) {
        archivo << "101356789;120-80,119-78,123-82,124-79,128-85\n";
        archivo << "101010;130-87,141-89,135-87,138-92\n";
        archivo << "52899659;145-92,142-95,151-87,148-92,152-89,141-94,138-88\n";
        archivo.close();
        std::cout << "Archivo medidas.txt creado exitosamente." << std::endl;
    } else {
        std::cerr << "No se pudo crear el archivo medidas.txt." << std::endl;
    }
}
