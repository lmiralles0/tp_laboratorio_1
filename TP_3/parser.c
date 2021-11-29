#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int cant;
	Employee* aux = NULL;
	char buffer[4][130];
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		//fscanf(pFile,"%s", buffer[0]);//lectura fantasma
		do
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(cant < 4)
			{
				break;
			}
			aux = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
			ll_add(pArrayListEmployee, (Employee*)aux);
		}while(!(feof(pFile)));
		retorno = 0;
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int cant = 1;
	Employee* aux = NULL;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do{
			aux = employee_new();
			if(aux != NULL)
			{
				cant = fread(aux, sizeof(Employee), 1, pFile);
				if(cant < 1)
				{
					break;
				}
				ll_add(pArrayListEmployee, (Employee*)aux);
			}

		}while(!(feof(pFile)));
		retorno = 0;
	}
	return retorno;
}
