#ifndef EMPLEADO_H
#define EMPLEADO_H

// Definición de la estructura Puesto
typedef struct {
    char nombre[20];
    double tarifa;
} Puesto;

// Definición de la estructura Empleado
typedef struct {
    char nombre[50];
    int id;
    int horas_trabajadas;
    Puesto puesto;
    double salario;
} Empleado;

// Prototipos de funciones
void agregarEmpleado(Empleado **empleados, int *numEmpleados);
void listarEmpleados(Empleado *empleados, int numEmpleados);
void buscarSalarioBajo(Empleado *empleados, int numEmpleados);
void editarEmpleado(Empleado *empleados, int numEmpleados);
void eliminarEmpleado(Empleado **empleados, int *numEmpleados);
void guardarEmpleadosEnArchivo(Empleado *empleados, int numEmpleados);
int cargarEmpleadosDesdeArchivo(Empleado **empleados, int *numEmpleados);

#endif // EMPLEADO_H
