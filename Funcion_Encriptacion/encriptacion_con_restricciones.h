#ifndef ENCRIPTACION_CON_RESTRICCIONES_H
#define ENCRIPTACION_CON_RESTRICCIONES_H

// Funciones para encriptar y desencriptar con restricciones
char encriptarConRestriccion(char c);
char desencriptarConRestriccion(char c);
void procesarMensaje(const char* input, char* output, char (*func)(char));

#endif // ENCRIPTACION_CON_RESTRICCIONES_H
