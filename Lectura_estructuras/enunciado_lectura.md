**6. (40 puntos) Lectura de estructuras**

Suponga que los resultados de presentación de exámenes están grabados en un archivo binario con tipo llamado «notas.dat» que contiene para cada persona: No. de identificación, nombre de la persona, tipo de examen (INICIAL o SUPLETORIO) y la nota obtenida con un decimal, como se muestra en el siguiente ejemplo:

| Identificación | Nombre          | Tipo de examen | Nota |
|----------------|-----------------|----------------|------|
| 111111         | Roberto Muñoz    | INICIAL        | 3,5  |
| 222222         | María Benavidez  | SUPLETORIO     | 2,8  |
| 333333         | Yamile Zapata    | INICIAL        | 4,6  |

Desarrolle una función que cree dos archivos de texto llamados "inicial.txt" y "supletorio.txt". Cada tipo de archivo debe contener: El tipo de examen, el nombre y la nota obtenida por todos los estudiantes presentados, el número de exámenes presentados, y la nota promedio de los exámenes. Un ejemplo de este archivo es:

**INICIAL**

Roberto Muñoz 3,5  
Yamile Zapata 4,6  
No. de exámenes: 2  
Promedio: 4,05

**Nota:** Los arreglos deben generarse con memoria dinámica y deben recorrerse con apuntadores (sin índice).
