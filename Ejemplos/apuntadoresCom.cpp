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