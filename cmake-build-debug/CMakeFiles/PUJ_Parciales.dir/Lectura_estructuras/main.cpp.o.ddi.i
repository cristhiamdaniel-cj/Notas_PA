# 0 "/home/usuario/CLionProjects/PUJ-Parciales/Lectura_estructuras/main.cpp"
# 1 "/home/usuario/CLionProjects/PUJ-Parciales/cmake-build-debug//"
# 0 "<interno>"
# 0 "<línea-de-órdenes>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<línea-de-órdenes>" 2
# 1 "/home/usuario/CLionProjects/PUJ-Parciales/Lectura_estructuras/main.cpp"

# 1 "/home/usuario/CLionProjects/PUJ-Parciales/Lectura_estructuras/lectura_archivos.h" 1




struct Estudiante {
    int identificacion;
    char nombre[50];
    char tipo_examen[12];
    float nota;
};


void crearArchivoBinario(const char* archivoSalida);
void procesarArchivo(const char* archivoEntrada);
# 3 "/home/usuario/CLionProjects/PUJ-Parciales/Lectura_estructuras/main.cpp" 2

int main() {

    crearArchivoBinario("notas.dat");


    procesarArchivo("notas.dat");

    return 0;
}
