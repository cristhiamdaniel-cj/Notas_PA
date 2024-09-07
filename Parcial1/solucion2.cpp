//
// Solucion2 usando librerìas
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring> // Para usar strcpy

using namespace std;

// Estructura de Pasajero
struct Pasajero {
    string nombre;
    string apellido;
    int documento;
    string nacionalidad;
};

// Estructura de Asiento
struct Asiento {
    int numero;
    bool ocupado;
    Pasajero* pasajero; // Pasajero dinámico, puede ser nullptr si no está ocupado
};

// Estructura de Vuelo con `char[]` en lugar de `std::string` para facilitar la serialización
struct Vuelo {
    char codigo[10];
    char origen[50];
    char destino[50];
    char fecha[11]; // Formato DD/MM/AAAA
    vector<Asiento> asientos; // Vector de asientos
};

// Estructura de Avión
struct Avion {
    string nombre_empresa;
    string codigo_avion;
    int num_asientos;
    vector<Vuelo> vuelos; // Vector de vuelos
};

// Estructura de Compañía Aérea
struct Compania {
    vector<Avion> aviones; // Vector de aviones
};

// Función para limpiar espacios en blanco alrededor de una cadena
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Función para agregar un avión a la compañía
void agregarAvion(Compania& compania, const Avion& avion) {
    compania.aviones.push_back(avion);
}

// Función para buscar un avión por su código
Avion* buscarAvionPorCodigo(Compania& compania, const string& codigo_avion) {
    for (auto& avion : compania.aviones) {
        if (avion.codigo_avion == codigo_avion) {
            return &avion;
        }
    }
    return nullptr; // Si no se encuentra, retornar nullptr
}

// Función para agregar un vuelo a un avión
void agregarVueloAAvion(Avion& avion, const Vuelo& vuelo) {
    avion.vuelos.push_back(vuelo);
}

// Función para leer el archivo de texto y agregar aviones y vuelos a la compañía
void leerArchivoTexto(Compania& compania, const string& nombre_archivo) {
    ifstream archivo(nombre_archivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << "Línea leída: " << linea << endl;  // Depuración

        // Omitir líneas que contienen nombres de aerolíneas (como Avianca o American Airlines)
        if (linea.find(':') != string::npos || linea == "#") {
            continue; // Ignorar líneas con nombres de aerolíneas y fin de sección
        }

        if (linea.find('-') != string::npos) { // Especificación de aviones
            stringstream ss(linea);
            string token;
            while (getline(ss, token, ',')) {
                string codigo_avion;
                int num_asientos;

                stringstream avion_ss(token);
                getline(avion_ss, codigo_avion, '-');
                avion_ss >> num_asientos;

                Avion avion;
                avion.codigo_avion = trim(codigo_avion); // Limpiar el código
                avion.num_asientos = num_asientos;

                agregarAvion(compania, avion);
                cout << "Avión agregado: " << avion.codigo_avion << " con " << avion.num_asientos << " asientos." << endl;
            }
        } else { // Especificación de vuelo
            stringstream ss(linea);
            string codigo_avion, codigo_vuelo, origen, destino, fecha;
            getline(ss, codigo_avion, ',');
            getline(ss, codigo_vuelo, ',');
            getline(ss, origen, ',');
            getline(ss, destino, ',');
            getline(ss, fecha, ',');

            Vuelo vuelo;
            strcpy(vuelo.codigo, trim(codigo_vuelo).c_str()); // Usar strcpy para copiar la cadena
            strcpy(vuelo.origen, trim(origen).c_str());
            strcpy(vuelo.destino, trim(destino).c_str());
            strcpy(vuelo.fecha, trim(fecha).c_str());

            Avion* avion = buscarAvionPorCodigo(compania, trim(codigo_avion));
            if (avion != nullptr) {
                agregarVueloAAvion(*avion, vuelo);
                cout << "Vuelo agregado: " << vuelo.codigo << " en avión: " << avion->codigo_avion << endl;  // Depuración
            } else {
                cout << "Avión no encontrado: " << codigo_avion << endl;
            }
        }
    }

    archivo.close();
}

// Función para generar reporte de vuelos por ciudad de origen
void generarReporteVuelosPorOrigen(Compania& compania, const string& ciudad_origen) {
    ofstream archivo_texto("vuelosOrigen.txt");
    ofstream archivo_binario("vuelosOrigen.dat", ios::binary);

    bool encontrado = false;

    for (auto& avion : compania.aviones) {
        for (auto& vuelo : avion.vuelos) {
            if (string(vuelo.origen) == ciudad_origen) {
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

    // Leer archivo de texto
    leerArchivoTexto(compania, "vuelos.txt");

    // Generar reporte por ciudad de origen
    generarReporteVuelosPorOrigen(compania, "Bogota");

    // Leer archivo binario vuelosOrigen.dat
    leerArchivoBinario();

    return 0;
}