#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

#define MAX_EMPLEADOS 100

// Función del menú principal
void menu() {
    Empleado *empleados = NULL;
    int numEmpleados = 0;
    int opcion;

    // Cargar empleados al iniciar
    cargarEmpleadosDesdeArchivo(&empleados, &numEmpleados);

    do {
        printf("\n---Menu de Sistema De Nominas---\n");
        printf("1. Agregar empleado\n");
        printf("2. Listar empleados\n");
        printf("3. Buscar empleados con salario < 1000\n");
        printf("4. Editar empleado\n");
        printf("5. Eliminar empleado\n");
        printf("6. Guardar en archivo\n");
        printf("7. Recuperar empleados desde archivo\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEmpleado(&empleados, &numEmpleados);
                break;
            case 2:
                listarEmpleados(empleados, numEmpleados);
                break;
            case 3:
                buscarSalarioBajo(empleados, numEmpleados);
                break;
            case 4:
                editarEmpleado(empleados, numEmpleados);
                break;
            case 5:
                eliminarEmpleado(&empleados, &numEmpleados);
                break;
            case 6:
                guardarEmpleadosEnArchivo(empleados, numEmpleados);
                break;
            case 7:
                numEmpleados = cargarEmpleadosDesdeArchivo(&empleados, &numEmpleados);
                break;
            case 0:
                guardarEmpleadosEnArchivo(empleados, numEmpleados);
                free(empleados); // Liberar memoria antes de salir
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}

