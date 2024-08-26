### Enunciado del Ejercicio

**1. (30%) Mensajes**

Julio necesita llevar el rastro de los mensajes que envía, para eso se le ocurrió que necesita un aplicativo para almacenar en memoria (no en archivos) la siguiente información que le permite controlar los mensajes que envía: Nombre del Contacto, Número de mensajes enviados, mensajes enviados.

**En memoria, la información sería:**

- **Nombre del Contacto:** Pedro Perez, Juliana Lopez
- **Número de mensajes enviados:** 2 (Pedro Perez), 3 (Juliana Lopez)
- **Mensajes enviados:**
    - **Pedro Perez:**
        - 0: "Hola Pedro como sigues?"
        - 1: "Pedro nos vemos para almorzar?"
    - **Juliana Lopez:**
        - 0: "Hola Juliana, como estas?"
        - 1: "Juliana tienes listo el trabajo?"
        - 2: "Recuerda que es para hoy a las 9am!"

**a) (30%)** Elaborar una función que reciba como parámetros el nombre del contacto y un mensaje. Si el contacto existe, incrementar el número de mensajes enviados del contacto y adicionar el mensaje al arreglo dinámico de mensajes. Si el contacto no existe, se debe adicionar el contacto y el mensaje.

**Nota:** El arreglo de contactos y el arreglo de mensajes enviados debe ser declarado de forma dinámica y ser recorridos usando el concepto de apuntadores, no se puede utilizar subíndices.