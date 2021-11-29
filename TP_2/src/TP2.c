/*
 ============================================================================
 Name        : TP2.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "bibliotecasEntradas.h"
#define LEN 1001
#define LONG_NAME 51


int main()
{
	setbuf(stdout, NULL);
    char opcion;
    int indice;
    int opcionInformes;
    int flagInitEmployees = 0;
    int flagOpcionesMenu = 0;
    Employee arraysEmpleados[LEN];
    int id = 1000;
    char aux[LONG_NAME];
    int auxiliarId;
    char name[LONG_NAME];
    char lastName[LONG_NAME];
    float salary = 0;
    int sector = 0;
    float salarioTotal;
    float salarioPromedios;
    int contadorEmpleados = 0;
    int contadorSalarioAlto = 0;



    do
    {
        if(flagInitEmployees == 0)
        {
            initEmployees(arraysEmpleados, LEN);
            flagInitEmployees = 1;
        }

        menu(&opcion);
        //system("cls");

        switch((char)opcion)
        {
        case 'a':
            if((get_Texto(name, LONG_NAME, "Ingrese nombre del empleado a cargar:\n\n", "Error al ingresar nombre.\n\n", 5) == 0) &&
               (get_Texto(lastName, LONG_NAME, "Ingrese apellido del empleado a cargar:\n\n", "Error al ingresar apellido.\n\n", 5) == 0) &&
               (get_EntradaFloat(&salary, "Ingrese salario del empleado: \n\n", "Error al ingresar sueldo.\n\n", 300000, 30000, 5) == 0) &&
               (get_EntradaInt(&sector, "Ingrese sector del empleado: \n\n", "Error al ingresar sector.\n\n", 5, 1, 5) == 0) &&
               (addEmployees(arraysEmpleados, LEN, &id, name, lastName, salary, sector) == 0))
            {
                flagOpcionesMenu = 1;
                printf("Carga exitosa.\n");
                //system("pause");
            }
            else
            {
                printf("Error en cargar empleados.\n");
                //system("pause");
            }
            system("cls");
            break;
        case 'b':
            if(flagOpcionesMenu == 1)
            {
            	printEmployees(arraysEmpleados, LEN);
                if(get_EntradaInt(&auxiliarId, "Ingrese Id del empleado a modificar:\n", "Error al ingresar Id.\n", 2000, 1000, 3) == 0)
                {
                	indice = findEmployees(arraysEmpleados, LEN, auxiliarId);
                	if(indice > -1)
                	{
                		printf("\nEmpleado selecionado es:\n");
                		printf("Nombre: %s |. Apellido: %s |. ID: %d |. Sector: %d |. Salario: %0.2f|.\n\n",arraysEmpleados[indice].name, arraysEmpleados[indice].lastName, arraysEmpleados[indice].id, arraysEmpleados[indice].sector, arraysEmpleados[indice].salary);
                		get_Texto(aux, LONG_NAME, "Que desea modificar? Nombre o Apellido: \n", "Error.\n", 3);
                	    if((strcmpi(aux,"Nombre") == 0) || (strcmpi(aux,"nombre") == 0))
                        {
                            if(get_Texto(aux, LONG_NAME, "Ingrese el nombre a modificar: \n", "Error.\n", 3) == 0)
                            {
                               strcpy(arraysEmpleados[indice].name, aux);
                               printf("Modificacion existosa.\n");
                               break;
                            }
       	                }
                		else if((strcmpi(aux,"Apellido") == 0) || (strcmpi(aux,"apellido") == 0))
                        {
                            if(get_Texto(aux, LONG_NAME, "Ingrese el apellido a modifica: \n", "Error.\n", 3)==0)
         		            {
                               strcpy(arraysEmpleados[indice].lastName, aux);
                               printf("Modificacion existosa.\n");
           	                   break;
                            }
                        }
                        else
       		            {

                            printf("\nNo ingreso una opcion valida!.\n");
                            break;
  		                }
                	}
                    //system("pause");
                    //system("cls");
                }
                else
                {
                	printf("Error al ingresar Id de Empleado a modificar.\n");
                    //system("pause");
                    //system("cls");
                }
            }
            else
            {
                printf("Primero debe cargar al menos un empleado.\n");
                //system("pause");
                //system("cls");
            }
            break;
        case 'c':
            if(flagOpcionesMenu == 1)
            {
            	printEmployees(arraysEmpleados, LEN);
                if(get_EntradaInt(&auxiliarId, "Ingrese el Id del empleado a eliminar: \n", "Error al ingresar Id.\n", 2000, 1000, 3) == 0)
                {
                	indice = findEmployees(arraysEmpleados, LEN, auxiliarId);
                	if(indice > -1)
                	{
                		printf("\nEmpleado selecionado es:\n");
                		printf("Nombre: %s. | Apellido: %s.| ID: %d | Sector: %d. | Salario: %0.2f.\n",arraysEmpleados[indice].name, arraysEmpleados[indice].lastName, arraysEmpleados[indice].id, arraysEmpleados[indice].sector, arraysEmpleados[indice].salary);
                		if(removeEmployee(arraysEmpleados, LEN, indice) == 0)
                		{
                			printf("Baja existosa\n");
                 		   //system("pause");
                           //system("cls");
                		}
                		else
                		{
                			printf("Error al dar de baja empleados.\n");
                		}
                    }
                	else
                	{
                		printf("El empleados buscado para eliminar no esta cargado.\n");
                		//system("pause");
                        //system("cls");
                	}
                }
                else
                {
                    printf("Error no existe el empleados selecccionado.\n");
                    //system("pause");
                    //system("cls");
                }
            }
            else
            {
                printf("Primero debe cargar al menos un empleado.\n");
                //system("pause");
                //system("cls");
            }
            break;
        case 'd':
            if(flagOpcionesMenu == 1)
            {
                printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n\n");
                printf("2. Total y promedio de los salarios, y cuántos empleados superan el asalario promedio.\n\n");
                get_EntradaInt(&opcionInformes, "Ingrese opcion a realizar:\n", "Error al ingresar opcion.\n", 2, 1, 3);
                switch(opcionInformes)
                {
                case 1:
                    sortEmployess(arraysEmpleados, LEN);
                    printEmployees(arraysEmpleados, LEN);
                    //system("pause");
                    //system("cls");
                    break;
                case 2:
                    for(int i = 0; i < LEN; i++)
                    {
                        if(arraysEmpleados[i].isEmpty == 0)
                        {
                            contadorEmpleados++;
                            salarioTotal += arraysEmpleados[i].salary;
                            if(arraysEmpleados[i].salary > salarioPromedios)
                            {
                                contadorSalarioAlto ++;
                            }
                        }
                    }
                    salarioPromedios = (float)salarioTotal/contadorEmpleados;
                    printf("\n\nEl total de los salarios es $%0.2f.\n", salarioTotal);
                    printf("El promedio de los salarios es de $%0.2f.\n", salarioPromedios);
                    printf("El N° de empleados que superan el promedio de los salarios es %d.\n", contadorSalarioAlto);
                    //system("pause");
                    //system("cls");
                }
                break;
            }
            else
            {
                printf("Primero debe cargar al menos un empleado.\n");
                //system("pause");
                //system("cls");
            }
            break;
        case 'e':
            break;
        default :
            printf("Opcion incorrecta.\n");
            //system("pause");
            //system("cls");
            break;
        }
    }while(opcion != 'e');


    return EXIT_SUCCESS;
}
