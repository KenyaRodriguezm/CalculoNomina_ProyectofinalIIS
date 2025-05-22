# CalculoNomina_ProyectofinalIIS

Proyectofinal

Este proyecto es un **sistema de cálculo de nómina** desarrollado en lenguaje C, diseñado para gestionar la información de empleados y calcular automáticamente su salario en función de las horas trabajadas y la tarifa por hora correspondiente a su puesto.

Entre las principales funcionalidades se incluyen:

* Registro de nuevos empleados.
* Cálculo automático de la nómina al ingresar los datos.
* Edición y eliminación de empleados por ID.
* Listado general de empleados y filtro por salario menor a \$1000.
* Almacenamiento persistente de datos en un archivo de texto (`empleados.txt`).

### Mejoras implementadas

El código ha sido optimizado con las siguientes mejoras:

* Se eliminó el uso de **variables globales**, utilizando únicamente variables locales para un mejor control de memoria.
* Se integró el manejo de **memoria dinámica** mediante `malloc` y `realloc` para una gestión flexible y eficiente de los registros.
* El **menú principal** fue encapsulado en una única función para facilitar su mantenimiento y legibilidad.
* Se reservaron los nombres mediante corchetes (`[]`) y funciones específicas, garantizando el uso correcto de la memoria para cadenas de texto.

Este sistema está diseñado para ser práctico, escalable y seguir buenas prácticas en el desarrollo de software en C, ideal para proyectos escolares o implementación en pequeños entornos administrativos.

Creado Por Kenya Mendieta Rodriguez 
Jessica Medellin Madagleno 
Alondra Jacqueline Magaña Cabrera
