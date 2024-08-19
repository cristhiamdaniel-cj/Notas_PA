# Ejemplo Avanzado de Apuntadores Complejos en C++

## Enunciado del Problema

Implementaremos un sistema de gestión de empleados con las siguientes características avanzadas:
- **Múltiples tipos de tareas**: Los empleados pueden realizar diferentes tareas que se asignan dinámicamente.
- **Apuntadores a funciones miembro**: Se utilizan para asignar y ejecutar diferentes tareas.
- **Combinación de `std::unique_ptr` y `std::shared_ptr`** para demostrar la gestión avanzada de memoria en C++.

El sistema debe permitir agregar empleados, asignarles tareas específicas, y ejecutar esas tareas de manera flexible.

## Código Completo

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Clase base para todos los empleados
class Empleado {
public:
    virtual void realizarTarea() const = 0; // Función virtual pura
    virtual void tareaEspecifica1() const = 0;
    virtual void tareaEspecifica2() const = 0;
    virtual ~Empleado() {}
};

// Clase para empleados desarrolladores
class Desarrollador : public Empleado {
public:
    void realizarTarea() const override {
        std::cout << "El desarrollador está escribiendo código." << std::endl;
    }
    
    void tareaEspecifica1() const override {
        std::cout << "El desarrollador está depurando código." << std::endl;
    }
    
    void tareaEspecifica2() const override {
        std::cout << "El desarrollador está participando en una revisión de código." << std::endl;
    }
};

// Clase para empleados de recursos humanos
class RecursosHumanos : public Empleado {
public:
    void realizarTarea() const override {
        std::cout << "Recursos Humanos está gestionando el personal." << std::endl;
    }
    
    void tareaEspecifica1() const override {
        std::cout << "Recursos Humanos está organizando una entrevista." << std::endl;
    }
    
    void tareaEspecifica2() const override {
        std::cout << "Recursos Humanos está evaluando el desempeño del personal." << std::endl;
    }
};

// Clase para gestionar empleados
class GestorEmpleados {
public:
    void agregarEmpleado(std::shared_ptr<Empleado> empleado) {
        empleados.push_back(empleado);
    }

    void asignarTareas() const {
        for (const auto& empleado : empleados) {
            empleado->realizarTarea();
            (empleado.get()->*ptrTareaEspecifica1)();
            (empleado.get()->*ptrTareaEspecifica2)();
        }
    }

    void setTareas(void (Empleado::*tarea1)() const, void (Empleado::*tarea2)() const) {
        ptrTareaEspecifica1 = tarea1;
        ptrTareaEspecifica2 = tarea2;
    }

private:
    std::vector<std::shared_ptr<Empleado>> empleados; // Uso de std::shared_ptr
    void (Empleado::*ptrTareaEspecifica1)() const; // Apuntador a función miembro
    void (Empleado::*ptrTareaEspecifica2)() const; // Apuntador a función miembro
};

int main() {
    GestorEmpleados gestor;

    // Creación de empleados usando std::make_shared
    auto desarrollador = std::make_shared<Desarrollador>();
    auto recursosHumanos = std::make_shared<RecursosHumanos>();

    // Agregar empleados al gestor
    gestor.agregarEmpleado(desarrollador);
    gestor.agregarEmpleado(recursosHumanos);

    // Asignar tareas específicas
    gestor.setTareas(&Empleado::tareaEspecifica1, &Empleado::tareaEspecifica2);

    // Asignar tareas a todos los empleados
    gestor.asignarTareas();

    return 0;
}
```

## Explicación del Código

### 1. Clase Base `Empleado` con Apuntadores a Múltiples Funciones Miembro

```cpp
class Empleado {
public:
    virtual void realizarTarea() const = 0; // Función virtual pura
    virtual void tareaEspecifica1() const = 0;
    virtual void tareaEspecifica2() const = 0;
    virtual ~Empleado() {}
};
```

- **Empleado**: La clase base define funciones virtuales puras para `realizarTarea` y dos tareas específicas (`tareaEspecifica1` y `tareaEspecifica2`), que las clases derivadas deben implementar.

### 2. Clases Derivadas `Desarrollador` y `RecursosHumanos`

```cpp
class Desarrollador : public Empleado {
public:
    void realizarTarea() const override {
        std::cout << "El desarrollador está escribiendo código." << std::endl;
    }
    
    void tareaEspecifica1() const override {
        std::cout << "El desarrollador está depurando código." << std::endl;
    }
    
    void tareaEspecifica2() const override {
        std::cout << "El desarrollador está participando en una revisión de código." << std::endl;
    }
};

class RecursosHumanos : public Empleado {
public:
    void realizarTarea() const override {
        std::cout << "Recursos Humanos está gestionando el personal." << std::endl;
    }
    
    void tareaEspecifica1() const override {
        std::cout << "Recursos Humanos está organizando una entrevista." << std::endl;
    }
    
    void tareaEspecifica2() const override {
        std::cout << "Recursos Humanos está evaluando el desempeño del personal." << std::endl;
    }
};
```

- **Desarrollador** y **RecursosHumanos**: Implementan las tareas específicas que corresponden a cada tipo de empleado.

### 3. Clase `GestorEmpleados` con Apuntadores a Funciones Miembro

```cpp
class GestorEmpleados {
public:
    void agregarEmpleado(std::shared_ptr<Empleado> empleado) {
        empleados.push_back(empleado);
    }

    void asignarTareas() const {
        for (const auto& empleado : empleados) {
            empleado->realizarTarea();
            (empleado.get()->*ptrTareaEspecifica1)();
            (empleado.get()->*ptrTareaEspecifica2)();
        }
    }

    void setTareas(void (Empleado::*tarea1)() const, void (Empleado::*tarea2)() const) {
        ptrTareaEspecifica1 = tarea1;
        ptrTareaEspecifica2 = tarea2;
    }

private:
    std::vector<std::shared_ptr<Empleado>> empleados; // Uso de std::shared_ptr
    void (Empleado::*ptrTareaEspecifica1)() const; // Apuntador a función miembro
    void (Empleado::*ptrTareaEspecifica2)() const; // Apuntador a función miembro
};
```

- **GestorEmpleados**: Esta clase ahora maneja apuntadores a funciones miembro (`ptrTareaEspecifica1` y `ptrTareaEspecifica2`). Estos apuntadores se utilizan para asignar dinámicamente diferentes tareas a los empleados.

### 4. Función Principal `main`

```cpp
int main() {
    GestorEmpleados gestor;

    // Creación de empleados usando std::make_shared
    auto desarrollador = std::make_shared<Desarrollador>();
    auto recursosHumanos = std::make_shared<RecursosHumanos>();

    // Agregar empleados al gestor
    gestor.agregarEmpleado(desarrollador);
    gestor.agregarEmpleado(recursosHumanos);

    // Asignar tareas específicas
    gestor.setTareas(&Empleado::tareaEspecifica1, &Empleado::tareaEspecifica2);

    // Asignar tareas a todos los empleados
    gestor.asignarTareas();

    return 0;
}
```

- **Asignación Dinámica de Tareas**: Se asignan dos tareas específicas a todos los empleados usando apuntadores a funciones miembro. Las tareas se ejecutan dinámicamente para cada empleado.

## Ejecución del Código

Al ejecutar el código, deberías obtener una salida similar a esta:

```plaintext
El desarrollador está escribiendo código.
El desarrollador está depurando código.
El desarrollador está participando en una revisión de código.
Recursos Humanos está gestionando el personal.
Recursos Humanos está organizando una entrevista.
Recursos Humanos está evaluando el desempeño del personal.
```

Este ejemplo demuestra un uso más avanzado de apuntadores en C++, incluyendo la asignación dinámica de tareas a través de apuntadores a funciones miembro, y el manejo de la memoria con `std::shared_ptr`. Es un ejemplo representativo de cómo se pueden utilizar estos conceptos en aplicaciones complejas en el mundo real.
