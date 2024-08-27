### Enunciado del Ejercicio:

**2. (70%) Tensión Arterial**

Suponga que se dispone de un archivo texto llamado “medidas.txt” el cual contiene por cada línea, las medidas de tensión arterial de determinados pacientes, los cuales tienen un dispositivo que toma esta medida en diferentes horas del día para ser informadas al médico.

Por cada línea se dispone del número de cédula del paciente, luego un punto y coma y luego todas las medidas reportadas para cada paciente por los dispositivos, cada una de ellas separadas por “,”. El número de medidas para cada paciente puede variar.

La medida está dada por dos números separados por guion, por ejemplo, 120-80, que indica la presión sistólica y diastólica respectivamente. Un ejemplo de este archivo es:

```
101356789;120-80,119-78,123-82,124-79,128-85
101010;130-87,141-89,135-87,138-92
52899659;145-92,142-95,151-87,148-92,152-89,141-94,138-88
```

**a) (40%)** Desarrolle una función que utilice el archivo anterior y que retorne un arreglo dinámico de “structs” que en cada posición almacene la información de cada paciente: Número de cédula, medida en donde se encuentre la más alta de la presión sistólica y medida en donde se encuentre la más alta de la presión diastólica. Por ejemplo, para el archivo anterior, para la cédula 101010 en el arreglo se retornaría: `101010 141-89 138-92`.

**b) (30%)** Desarrolle una función que reciba como parámetro el arreglo generado en el punto anterior y que almacene la información en un archivo binario llamado “Pacientes.dat”. Cada registro de este archivo contiene el número de cédula del paciente, la medida con la mayor presión sistólica, la medida con la menor presión diastólica y una cadena de texto que contiene el siguiente texto:

- **ADVERTENCIA:** si la presión sistólica es mayor de 140 o la diastólica es mayor de 95.
- **SEGUIMIENTO:** si la presión sistólica está en el rango de 130 a 140 o la diastólica está en el rango 90-95.
- En caso de no cumplirse con ninguno de los criterios anteriores, la cadena queda vacía.

Para el ejemplo anterior, para la cédula 101010 la cadena diría **ADVERTENCIA** ya que existe el valor de 141.

**Nota:** No se puede usar el tipo de dato string, los arreglos deben ser recorridos con apuntadores (sin subíndices) y deben manejarse con memoria dinámica donde sea necesario.

**Tiempo máximo:** 2 horas.