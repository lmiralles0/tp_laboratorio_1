/*
 * arrayEmployees.c
 *
 *  Created on: 16 may. 2021
 *      Author: Luciano Miralles
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecasEntradas.h"
#include "arrayEmployees.h"
#define LONG_NAME 51




/**
*\ brief inicializa el arrays
*\ param array Puntero Arrayz de empleados a ser actualizado
*\ param longitud limite de longitud del arrays de empleados
*\ return Retorna 0 x EXITO o -1 ERROR por longgitud invalida o NULL al puntero
**/

int initEmployees(Employee* list, int longitud)
{
    int retorno = -1;
    if(list != NULL && longitud > 0)
    {
        retorno = 0;
        for(int i = 0; i < longitud; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;
}
/**
*\ brief carga el arrays con datos que se le pide al usuario
*\ param longitud limite de longitud del arryas de empleados
*\ param id (numero unico para la carga que se realiza)
*\ param name
*\ param lastName
*\ param salary
*\ param sector
*\ return Retorna 0 x EXITO o -1 ERROR por longgitud invalida o NULL al puntero
**/
int addEmployees(Employee* list, int longitud, int* pId, char* pName, char* pLastName, float vSalary, int vSector)
{
    int retorno = -1;
    if(list != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id = *pId;
                strcpy(list[i].name, pName);
                strcpy(list[i].lastName, pLastName);
                list[i].salary = vSalary;
                list[i].sector = vSector;
                list[i].isEmpty = 0;
                (*pId)++;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
*\ brief encuentra un empleado del arrays por el N° de ID
*\ param longitud limite de longfitud del arrays de empleados
*\ param id numero de id del empleado
*\ return Retorna indice del empleado buscado x EXITO o -1 por ERROR
**/
int findEmployees(Employee* list, int longitud, int auxId)
{
	int indice = -1;
	if(list != NULL && longitud > 0)
	{
		for(int i = 0; i < longitud; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == auxId)
			{
     			indice = i;
     			break;
			}
	    }
     }
    return indice;
}
/**
*\brief Elimina un Employee por el Id (pone isEmpty en 1)
* \param list Employee*
* \param longitud limite de longitud del arrays
* \param pide el id a modificar por valor
* \return Retorna 1 x Error o 0 x EXITO
**/
int removeEmployee(Employee* list, int longitud, int posicion)
{
    int retorno = 1;
    if(list != NULL && longitud > 0)
    {
        if(list[posicion].isEmpty == 0)
        {
            retorno = 0;
            list[posicion].isEmpty = 1;
        }
    }
    return retorno;
}
/** \brief Ordena los elementos in el array de empleados, el argumento order indica si se hace de manera
     ascendete o descendentee the argument
* \param list Employee*
* \param len longitud
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/

int sortEmployess(Employee* list, int longitud)
{
    Employee buffer;
    if(list != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud-1; i++)
        {
            for(int j = i + 1; j < longitud; j++)
            {
                if((list[i].isEmpty == 0 && list[j].isEmpty == 0) &&
                   (strncmp(list[i].name, list[j].name, LONG_NAME) > 0 ||
                  ((strncmp(list[i].name, list[j].name, LONG_NAME) == 0) && (list[i].sector > list[j].sector))))
                {
                    buffer = list[i];
                    list[i] = list[j];
                    list[j] = buffer;
                }
            }
        }
    }
    return 0;
}

/** \brief impreme el contenido del arrays de empleados
* \param list Employee*
* \param longitud
* \return int
**/
int printEmployees(Employee* list,int longitud)
{
    if(list != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("Apellido: %s|  Nombre: %s|  Sector: %d|  Id: %d|  Sueldo: $%0.2f|  .\n", list[i].lastName, list[i].name, list[i].sector, list[i].id, list[i].salary);
            }
        }
    }
    return EXIT_SUCCESS;
}
