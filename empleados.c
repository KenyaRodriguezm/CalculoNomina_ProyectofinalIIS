#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

// Función para crear un puesto
Puesto crearPuesto(const char* nombre, double tarifa) {
    Puesto p;
    strncpy(p.nombre, nombre, 19);
    p.nombre[19] = '\0';
    p.tarifa = tarifa;
    return p;
}

// Función para agregar un nuevo empleado
void agregarEmpleado(Empleado **empleados, int *numEmpleados) {
    // Redimensionar el arreglo para agregar un nuevo empleado
    *empleados = realloc(*empleados, (*numEmpleados + 1) * sizeof(Empleado));
    if (*empleados == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    printf("\n--- Agregar Empleado ---\n");

    // Solicitar datos del empleado
    printf("Nombre: ");
    scanf(" %[^\n]", (*empleados)[*numEmpleados].nombre);

    printf("ID: ");
    scanf("%d", &(*empleados)[*numEmpleados].id);

    printf("Horas trabajadas: ");
    scanf("%d", &(*empleados)[*numEmpleados].horas_trabajadas);

    char nombrePuesto[20];
    double tarifa;
    printf("Nombre del puesto: ");
    scanf(" %[^\n]", nombrePuesto);
    printf("Tarifa por hora: ");
    scanf("%lf", &tarifa);

    // Crear y asignar el puesto
    (*empleados)[*numEmpleados].puesto = crearPuesto(nombrePuesto, tarifa);

    // Calcular salario automáticamente
    (*empleados)[*numEmpleados].salario = (*empleados)[*numEmpleados].horas_trabajadas * tarifa;

    (*numEmpleados)++;
    printf("Empleado agregado con éxito!\n");
}

// Función para listar todos los empleados
void listarEmpleados(Empleado *empleados, int numEmpleados) {
    if (numEmpleados == 0) {
        printf("\nNo hay empleados registrados.\n");
        return;
    }

    printf("\n--- Lista de Empleados (%d) ---\n", numEmpleados);
    for (int i = 0; i < numEmpleados; i++) {
        printf("\nEmpleado #%d\n", i+1);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("ID: %d\n", empleados[i].id);
        printf("Horas trabajadas: %d\n", empleados[i].horas_trabajadas);
        printf("Puesto: %s (Tarifa: %.2f)\n", empleados[i].puesto.nombre, empleados[i].puesto.tarifa);
        printf("Salario: %.2f\n", empleados[i].salario);
    }
}

// Función para buscar empleados con salario bajo
void buscarSalarioBajo(Empleado *empleados, int numEmpleados) {
    printf("\n--- Empleados con Salario < 1000 ---\n");
    int encontrados = 0;
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].salario < 1000) {
            printf("\nNombre: %s\n", empleados[i].nombre);
            printf("ID: %d\n", empleados[i].id);
            printf("Puesto: %s\n", empleados[i].puesto.nombre);
            printf("Salario: %.2f\n", empleados[i].salario);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("No se encontraron empleados con salario menor a 1000.\n");
    }
}

// Función para editar un empleado existente
void editarEmpleado(Empleado *empleados, int numEmpleados) {
    if (numEmpleados == 0) {
        printf("\nNo hay empleados para editar.\n");
        return;
    }

    int id;
    printf("\n--- Editar Empleado ---\n");
    printf("Ingrese ID del empleado a editar: ");
    scanf("%d", &id);

    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].id == id) {
            printf("\nEditando empleado ID %d\n", id);

            printf("Nuevo nombre [%s]: ", empleados[i].nombre);
            char nuevoNombre[50];
            scanf(" %[^\n]", nuevoNombre);
            if (strlen(nuevoNombre) > 0) {
                strcpy(empleados[i].nombre, nuevoNombre);
            }

            printf("Nuevas horas trabajadas [%d]: ", empleados[i].horas_trabajadas);
            int nuevasHoras;
            scanf("%d", &nuevasHoras);
            empleados[i].horas_trabajadas = nuevasHoras;

            printf("Nuevo nombre de puesto [%s]: ", empleados[i].puesto.nombre);
            char nuevoPuesto[20];
            scanf(" %[^\n]", nuevoPuesto);
            if (strlen(nuevoPuesto) > 0) {
                strcpy(empleados[i].puesto.nombre, nuevoPuesto);
            }

            printf("Nueva tarifa [%.2f]: ", empleados[i].puesto.tarifa);
            double nuevaTarifa;
            scanf("%lf", &nuevaTarifa);
            empleados[i].puesto.tarifa = nuevaTarifa;

            // Recalcular salario
            empleados[i].salario = empleados[i].horas_trabajadas * empleados[i].puesto.tarifa;

            printf("Empleado actualizado con éxito!\n");
            return;
        }
    }
    printf("No se encontró empleado con ID %d\n", id);
}

// Función para eliminar un empleado
void eliminarEmpleado(Empleado **empleados, int *numEmpleados) {
    if (*numEmpleados == 0) {
        printf("\nNo hay empleados para eliminar.\n");
        return;
    }

    int id;
    printf("\n--- Eliminar Empleado ---\n");
    printf("Ingrese ID del empleado a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *numEmpleados; i++) {
        if ((*empleados)[i].id == id) {
            // Mover los elementos restantes
            for (int j = i; j < *numEmpleados - 1; j++) {
                (*empleados)[j] = (*empleados)[j+1];
            }

            // Redimensionar el arreglo
            *empleados = realloc(*empleados, (*numEmpleados - 1) * sizeof(Empleado));
            (*numEmpleados)--;

            printf("Empleado eliminado con éxito!\n");
            return;
        }
    }
    printf("No se encontró empleado con ID %d\n", id);
}

// Función para guardar empleados en archivo
void guardarEmpleadosEnArchivo(Empleado *empleados, int numEmpleados) {
    FILE *archivo = fopen("empleados.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < numEmpleados; i++) {
        fprintf(archivo, "Nombre: %s\n", empleados[i].nombre);
        fprintf(archivo, "ID: %d\n", empleados[i].id);
        fprintf(archivo, "Horas trabajadas: %d\n", empleados[i].horas_trabajadas);
        fprintf(archivo, "Puesto: %s\n", empleados[i].puesto.nombre);
        fprintf(archivo, "Tarifa: %.2f\n", empleados[i].puesto.tarifa);
        fprintf(archivo, "Salario neto: %.2f\n\n", empleados[i].salario);
    }

    fclose(archivo);
    printf("Datos de %d empleados guardados en empleados.txt\n", numEmpleados);
}

// Función para cargar empleados desde archivo
int cargarEmpleadosDesdeArchivo(Empleado **empleados, int *numEmpleados) {
    FILE *archivo = fopen("empleados.txt", "r");
    if (archivo == NULL) {
        printf("Archivo empleados.txt no encontrado. Se creará uno nuevo.\n");
        return 0;
    }

    int contador = 0;
    char buffer[256];

    // Contar empleados en el archivo
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        if (strstr(buffer, "Nombre:") != NULL) {
            contador++;
        }
    }

    // Volver al inicio del archivo
    rewind(archivo);

    // Reservar memoria para los empleados
    *empleados = realloc(*empleados, contador * sizeof(Empleado));
    if (*empleados == NULL && contador > 0) {
        printf("Error al asignar memoria.\n");
        fclose(archivo);
        return 0;
    }

    // Leer los datos de los empleados
    *numEmpleados = 0;
    while (*numEmpleados < contador) {
        char nombre[50], puesto[20];
        int id, horas;
        double tarifa, salario;

        fscanf(archivo, "Nombre: %[^\n]\n", nombre);
        fscanf(archivo, "ID: %d\n", &id);
        fscanf(archivo, "Horas trabajadas: %d\n", &horas);
        fscanf(archivo, "Puesto: %[^\n]\n", puesto);
        fscanf(archivo, "Tarifa: %lf\n", &tarifa);
        fscanf(archivo, "Salario neto: %lf\n\n", &salario);

        // Asignar los valores al empleado
        strcpy((*empleados)[*numEmpleados].nombre, nombre);
        (*empleados)[*numEmpleados].id = id;
        (*empleados)[*numEmpleados].horas_trabajadas = horas;
        strcpy((*empleados)[*numEmpleados].puesto.nombre, puesto);
        (*empleados)[*numEmpleados].puesto.tarifa = tarifa;
        (*empleados)[*numEmpleados].salario = salario;

        (*numEmpleados)++;
    }

    fclose(archivo);
    printf("%d empleados cargados desde archivo.\n", *numEmpleados);
    return *numEmpleados;
}
