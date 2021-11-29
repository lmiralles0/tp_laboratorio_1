#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "get_Entrada.h"

/****************************************************

*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int flag = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
        printf("Menu:\n");
	    printf("\t1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	    printf("\t2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	    printf("\t3. Alta de empleado.\n");
	    printf("\t4. Modificar datos de empleado\n");
	    printf("\t5. Baja de empleado\n");
	    printf("\t6. Listar empleados\n");
	    printf("\t7. Ordenar empleados\n");
	    printf("\t8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("\t9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	    printf("\t10. Salir\n");
	    if(get_EntradaInt(&option, "Ingrese un a opcion del menu.\n", "Error al ingresar opcion.\n", 10, 1, 5) == 0)
	    {
			switch(option)
			{
				case 1:
					if(controller_loadFromText("data.txt", listaEmpleados) == 0)
					{
						printf("Carga desde texto exitosa.\n");
						flag = 1;
					}
					else
					{
						printf("Error al cargar texto.\n");
					}
					break;
				case 2:
					if(controller_loadFromBinary("data.bin", listaEmpleados) == 0 )
					{
						printf("Carga desde binario exitosa.\n");
						flag = 1;
					}
					else
					{
						printf("Error al carga binario.\n");
					}
					break;
				case 3:
					if(controller_addEmployee(listaEmpleados) == 0)
					{
						printf("Empleado creado con exito.\n");
						flag = 1;
					}
					else
					{
						printf("Error al crear empleado.\n");
					}
					break;
				case 4:
					if(flag == 1)
					{
						if(controller_editEmployee(listaEmpleados) == 0)
						{
							printf("Empleado modificado con exito.\n");
						}
						else
						{
							printf("Error al modificar empleado.\n");
						}
					}
					else
					{
						printf("No hay empleados cargados.\n");
					}
					break;
				case 5:
					if(flag == 1)
					{
						if(controller_removeEmployee(listaEmpleados) == 0)
						{
							printf("Empleado eliminado con exito.\n");
						}
						else
						{
							printf("Error al eliminar empleado.\n");
						}
					}
					else
					{
						printf("No se hay empleados cargados.\n");
					}
					break;
				case 6:
					if(flag == 1)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("No hay empleados cargados.\n");
					}
					break;
				case 7:
					if(flag == 1)
					{
						controller_sortEmployee(listaEmpleados);
					}
					else
					{
						printf("No hay empleados cargados.\n");
					}
					break;
				case 8:
					if(flag == 1)
					{
						if(controller_saveAsText("data.txt", listaEmpleados) == 0)
						{
							printf("Empleados guardados en txt.\n");
						}
						else
						{
							printf("Error al guardar empleados.\n");
						}

					}
					else
					{
						printf("No hay empleados cargados.\n");
					}
					break;
				case 9:
					if(flag == 1)
					{
						if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
						{
							printf("Empleados guardados en bin.\n");

						}
						else
						{
							printf("Error al guardar empleados.\n");
						}

					}
					else
					{
						printf("No hay empleados cargados.\n");
					}
					break;
				case 10:

					break;
			}
	    }
    }while(option != 10);
    return EXIT_SUCCESS;
}

