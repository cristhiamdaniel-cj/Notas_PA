**5. (30 puntos) Función de encriptación**

Una empresa requiere un programa que encripte los datos de entrada que se reciben en un archivo llamado `datos.txt`, transformando cada carácter del mensaje según la siguiente tabla:

| Original  | a  | b  | c  | d  | e  | f  | g  | h  | i  | j  | k  | l  | m  | n  | o  | p  | q  | r  | s  | t  | u  | v  | w  | x  | y  | z  |
|-----------|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| Encriptado| z  | y  | x  | w  | v  | u  | t  | s  | r  | q  | p  | o  | n  | m  | l  | k  | j  | i  | h  | g  | f  | e  | d  | c  | b  | a  |

En la primera fila de la tabla se encuentra el carácter que se lee del archivo y en la segunda fila se encuentra la conversión que debe realizar para la respectiva letra. Siendo así, la letra "a" se reemplaza por la "z", la "b" por la "y", y así sucesivamente.

Un ejemplo para demostrar la funcionalidad es:

- **Mensaje original:** `Hola como se encuentran`
- **Mensaje encriptado:** `Slox xlnl hv vmxfvmgizm`

A partir del enunciado anterior se requiere:

1. (7 puntos) Leer el archivo `datos.txt` con el mensaje original.
2. (15 puntos) Crear la función para encriptar y desencriptar un mensaje utilizando apuntadores a funciones.
3. (8 puntos) Guardar el mensaje encriptado en un archivo llamado `encriptado.txt` con el mensaje generado en el punto anterior.
