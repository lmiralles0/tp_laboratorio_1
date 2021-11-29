#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "get_Entrada.h"
#include "LinkedList.h"


Employee* employee_new()
{
	Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
	if(newEmployee != NULL)
	{
		newEmployee->id = 0;
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo = 0;
		strcpy(newEmployee->nombre, "  ");
	}
	return newEmployee;
}


Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee = employee_new();
	if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(!(employee_setId(newEmployee, atoi(idStr)) && employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) &&
			employee_setNombre(newEmployee, nombreStr) && employee_setSueldo(newEmployee, atoi(sueldoStr))))
		{
			free(newEmployee);
			newEmployee = NULL;
		}

	}
	return newEmployee;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int employee_Id(LinkedList* pArrayListEmployee)
{
    int retornoId = -1;
    int longitud;
    int contador = 0;
    Employee* aux = NULL;
    if(pArrayListEmployee != NULL)
    {
        longitud = ll_len(pArrayListEmployee);
        if(longitud > 0)
        {
            for( int i = 0; i < longitud; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);
                if(aux != NULL)
                {
                    if(contador == 0)
                    {
                        retornoId = aux->id;
                    }
                    else
                    {
                        if(aux->id > retornoId)
                        {
                            retornoId = aux->id;
                        }
                    }
                    contador++;
                }
            }
        }
        if(contador > 0)
        {
            retornoId++;
        }
        else
        {
           retornoId= 1;
        }
    }
    return retornoId;
}


int employee_setId(Employee* this, int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}


int employee_getId(Employee* this, int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}


int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}


int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{

	int retorno = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{

	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;

}


int employee_setSueldo(Employee* this, int sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}


int employee_getSueldo(Employee* this, int* sueldo)
{

	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}


void employee_Print(Employee* employee)
{
	printf("%d    %10s        %d     %d \n", employee->id, employee->nombre, employee->sueldo, employee->horasTrabajadas);
}


int compareEmployee(void* employee1, void* employee2)
{
	if(strcmp(((Employee*)employee1)->nombre ,((Employee*)employee2)->nombre) > 0 )
	{
		return 1;
	}
	if(strcmp(((Employee*)employee1)->nombre , ((Employee*)employee2)->nombre) < 0)
	{
		return -1;
	}
	return 0;
}


