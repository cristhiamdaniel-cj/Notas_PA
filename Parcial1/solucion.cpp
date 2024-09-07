// SOlucion 1, usando las restricciones

#include <iostream>
#include <fstream>
#include <cstring> // Para usar funciones como strcpy
#include <cstdlib> // Para usar malloc y free

using namespace std;

// Estructura de Pasajero
struct Pasajero {
    char nombre[50];
    char apellido[50];
    int documento;
    char nacionalidad[30];
};

// Estructura de Asiento
struct Asiento {
    int numero;
    bool ocupado;
    Pasajero* pasajero; // Pasajero dinámico, puede ser NULL si no está ocupado
};

// Estructura de Vuelo
struct Vuelo {
    char codigo[10];
    char origen[50];
    char destino[50];
    char fecha[11]; // Formato DD/MM/AAAA
    Asiento* asientos; // Arreglo dinámico de asientos
    int num_asientos;
};

// Estructura de Avión
struct Avion {
    char nombre_empresa[50];
    char codigo_avion[10];
    int num_asientos;
    Vuelo* vuelos; // Arreglo dinámico de vuelos
    int num_vuelos;
};

// Estructura de Compañía Aérea
struct Compania {
    Avion* aviones; // Arreglo dinámico de aviones
    int num_aviones;
};

// Función para agregar un avión a la compañía
void agregarAvion(Compania& compania, Avion avion) {
    // Redimensionar el arreglo de aviones
    compania.aviones = (Avion*)realloc(compania.aviones, (compania.num_aviones + 1) * sizeof(Avion));
    compania.aviones[compania.num_aviones] = avion;
    compania.num_aviones++;
}

// Función para buscar un avión por su código
Avion* buscarAvionPorCodigo(Compania& compania, const char* codigo_avion) {
    for (int i = 0; i < compania.num_aviones; i++) {
        if (strcmp(compania.aviones[i].codigo_avion, codigo_avion) == 0) {
            return &compania.aviones[i];
        }
    }
    return nullptr; // Si no se encuentra, retornar nullptr
}

// Función para agregar un vuelo a un avión
void agregarVueloAAvion(Avion& avion, Vuelo vuelo) {
    // Redimensionar el arreglo de vuelos
    avion.vuelos = (Vuelo*)realloc(avion.vuelos, (avion.num_vuelos + 1) * sizeof(Vuelo));
    avion.vuelos[avion.num_vuelos] = vuelo;
    avion.num_vuelos++;
}

// Función para leer el archivo de texto y agregar aviones y vuelos a la compañía
void leerArchivoTexto(Compania& compania, const char* nombre_archivo) {
    ifstream archivo(nombre_archivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
        return;
    }

    char linea[256];
    while (archivo.getline(linea, sizeof(linea))) {
        cout << "Línea leída: " << linea << endl;  // Depuración

        // Omitir líneas que contienen nombres de aerolíneas (como Avianca o American Airlines)
        if (strchr(linea, ':') != nullptr || strcmp(linea, "#") == 0) {
            continue; // Ignorar líneas con nombres de aerolíneas y fin de sección
        }

        if (strchr(linea, '-') != nullptr) { // Especificación de aviones
            char* token = strtok(linea, ",");
            while (token != nullptr) {
                char codigo_avion[10];
                int num_asientos;
                sscanf(token, "%[^-]-%d", codigo_avion, &num_asientos);

                Avion avion;
                strcpy(avion.codigo_avion, codigo_avion);
                avion.num_asientos = num_asientos;
                avion.num_vuelos = 0;
                avion.vuelos = nullptr;

                agregarAvion(compania, avion);
                cout << "Avión agregado: " << avion.codigo_avion << " con " << avion.num_asientos << " asientos." << endl;  // Depuración
                token = strtok(nullptr, ","); // Sigue con el siguiente avión
            }
        } else { // Especificación de vuelo
            char codigo_avion[10], codigo_vuelo[10], origen[50], destino[50], fecha[11];
            sscanf(linea, "%[^,], %[^,], %[^,], %[^,], %s", codigo_avion, codigo_vuelo, origen, destino, fecha);

            Vuelo vuelo;
            strcpy(vuelo.codigo, codigo_vuelo);
            strcpy(vuelo.origen, origen);
            strcpy(vuelo.destino, destino);
            strcpy(vuelo.fecha, fecha);
            vuelo.num_asientos = 0;
            vuelo.asientos = nullptr;

            Avion* avion = buscarAvionPorCodigo(compania, codigo_avion);
            if (avion != nullptr) {
                agregarVueloAAvion(*avion, vuelo);
                cout << "Vuelo agregado: " << vuelo.codigo << " en avión: " << avion->codigo_avion << endl;  // Depuración
            } else {
                cout << "Avión no encontrado: " << codigo_avion << endl;  // Depuración
            }
        }
    }

    archivo.close();
}


// Función para generar reporte de vuelos por ciudad de origen
void generarReporteVuelosPorOrigen(Compania& compania, const char* ciudad_origen) {
    ofstream archivo_texto("vuelosOrigen.txt");
    ofstream archivo_binario("vuelosOrigen.dat", ios::binary);

    bool encontrado = false;

    for (int i = 0; i < compania.num_aviones; i++) {
        Avion& avion = compania.aviones[i];
        for (int j = 0; j < avion.num_vuelos; j++) {
            Vuelo& vuelo = avion.vuelos[j];

            if (strcmp(vuelo.origen, ciudad_origen) == 0) {
                archivo_texto << vuelo.codigo << ", " << vuelo.origen << ", " << vuelo.destino << ", " << vuelo.fecha << endl;
                archivo_binario.write((char*)&vuelo, sizeof(Vuelo));
                encontrado = true;
                cout << "Vuelo encontrado: " << vuelo.codigo << " desde " << vuelo.origen << endl;  // Depuración
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron vuelos desde: " << ciudad_origen << endl;  // Depuración
    }

    archivo_texto.close();
    archivo_binario.close();
}

// Función para leer el archivo binario vuelosOrigen.dat
void leerArchivoBinario() {
    ifstream archivo_binario("vuelosOrigen.dat", ios::binary);
    if (!archivo_binario) {
        cerr << "Error al abrir el archivo binario: vuelosOrigen.dat" << endl;
        return;
    }

    Vuelo vuelo;
    while (archivo_binario.read((char*)&vuelo, sizeof(Vuelo))) {
        cout << "Código: " << vuelo.codigo << ", Origen: " << vuelo.origen << ", Destino: " << vuelo.destino << ", Fecha: " << vuelo.fecha << endl;
    }

    archivo_binario.close();
}

int main() {
    Compania compania;
    compania.num_aviones = 0;
    compania.aviones = nullptr;

    // Leer archivo de texto
    leerArchivoTexto(compania, "vuelos.txt");

    // Generar reporte por ciudad de origen
    generarReporteVuelosPorOrigen(compania, "Bogota");

    // Leer archivo binario vuelosOrigen.dat
    leerArchivoBinario();

    // Liberar memoria
    for (int i = 0; i < compania.num_aviones; i++) {
        free(compania.aviones[i].vuelos); // Liberar los vuelos de cada avión
    }
    free(compania.aviones); // Liberar el arreglo de aviones

    return 0;
}
