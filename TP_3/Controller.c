#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "get_Entrada.h"
#include "Controller.h"


static int buscarEmpleado(LinkedList* pArrayListEmployee, int id);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "r");
	if(f != NULL)
	{
		if(parser_EmployeeFromText(f, pArrayListEmployee) == 0)
		{
			retorno = 0;
		}
		fclose(f);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "rb");
	if(f != NULL)
	{
		if(parser_EmployeeFromBinary(f, pArrayListEmployee) == 0)
		{
			retorno = 0;
		}
		fclose(f);
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int id;
	Employee* aux = NULL;
	if(pArrayListEmployee != NULL)
	{
		aux = employee_new();
		if(aux != NULL)
		{
			id = employee_Id(pArrayListEmployee);
			if((get_EntradaTexto(aux->nombre, 130, "Ingrese nombre del empleado.\n", "Error al ingresar nombre.\n", 4) == 0) &&
			  (get_EntradaInt(&aux->horasTrabajadas, "Ingrese las horas trabajadas por el empleado.\n", "Error en el ingreso.\n", 400, 5, 3) == 0) &&
			  (get_EntradaInt(&aux->sueldo, "Ingrese sueldo del empleado.\n", "Error al ingresar sueldo.\n", 100000, 500, 5) == 0)&& id != -1)

			{
				aux->id = id;
				ll_add(pArrayListEmployee, (Employee*)aux);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int opcion;
	int indice;
	int idAux;
	Employee* aux = NULL;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(get_EntradaInt(&idAux, "Ingrese el N° de Id del empleado a modificar.\n", "Error al ingresar numero Id.\n", 1000000, 1, 5) == 0)
		{
			indice = buscarEmpleado(pArrayListEmployee, idAux);
			if(indice > -1)
			{
				aux = ((Employee*) (ll_get(pArrayListEmployee, indice)));
				printf("Modificar empleado: \n");
				printf("1) Nombre.\n");
				printf("2) Horas trabajadas.\n");
				printf("3) Sueldo.\n");
				if(get_EntradaInt(&opcion, "Ingrese la opcion a modificar.\n", "Error al ingresar opcion.\n", 3, 1, 5) == 0)
				{
					switch(opcion)
					{
					case 1:
						if(get_EntradaTexto(aux->nombre,  128, "Ingrese el nuevo nombre.\n", "Error al ingresar nombre.\n", 5) == 0)
						{
							printf("Nombre modificado con exito.\n");
						}
						break;
					case 2:
						if(get_EntradaInt(&aux->horasTrabajadas,"Ingrese la cantidad de horas de trabajo a modificar.\n", "Error al ingresar horas.\n", 216, 8, 5) == 0)
						{
							printf("Horas modificadas con exito.\n");
						}
						break;
					case 3:
						if(get_EntradaInt(&aux->sueldo, "Ingrese sueldo a modificar.\n", "Error al ingresar sueldo.\n", 900000, 50000, 5) == 0)
						{
							printf("Sueldo moficardo con exito.\n");
						}
						break;
					}
					ll_set(pArrayListEmployee, indice, (Employee*) aux);
					retorno = 0;
				}

			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int idAux;
	int indice;
	Employee* aux = NULL;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(get_EntradaInt(&idAux,  "Ingrese el Id del empleado a eliminar: \n", "Error al ingresar empleado.\n", 10000000, 1, 5) == 0)
		{
			indice = buscarEmpleado(pArrayListEmployee, idAux);
			if(indice > -1)
			{
				aux = (Employee*) ll_get(pArrayListEmployee, indice);
				employee_delete(aux);
				ll_remove(pArrayListEmployee, indice);
				retorno = 0;
			}
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int tam = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			employee_Print((Employee*) ll_get(pArrayListEmployee, i));
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int opcion;
	if(pArrayListEmployee != NULL)
	{
		if(get_EntradaInt(&opcion, "Ingrese 0 para ordenar de manera ascendente o 1 para ordenar de manera descendete: \n", "Error al ingresar orden.\n", 1, 0, 5) == 0)
		{
			ll_sort(pArrayListEmployee, compareEmployee, opcion);
		}


	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "w");
	int tam = ll_len(pArrayListEmployee);
	Employee* aux = NULL;
	int cant;
	if(f != NULL && pArrayListEmployee != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			cant = fprintf(f, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
			if(cant < 4)
			{
				break;
			}
		}
		retorno = 0;

	}
	fclose(f);
    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "wb");
	int tam = ll_len(pArrayListEmployee);
	int cant;
	if(f != NULL && pArrayListEmployee != NULL)
	{
		for(int i = 0; i < tam; i ++)
		{
			cant = fwrite((Employee*) ll_get(pArrayListEmployee, i), sizeof(Employee), 1, f);
			if(cant !=  1)
			{
				break;
			}
		}
		retorno = 0;
	}
	fclose(f);
	return retorno;
}


static int buscarEmpleado(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int longitud;
    Employee* aux = NULL;

    if(pArrayListEmployee != NULL && id > 0)
    {
        longitud = ll_len(pArrayListEmployee);
        if(longitud > 0)
        {
            for(int i = 0; i < longitud; i++)
            {
                aux = ll_get(pArrayListEmployee, i);
                if(aux != NULL && aux->id == id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}
