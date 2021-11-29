/*
 * arrayEmployees.h
 *
 *  Created on: 16 may. 2021
 *      Author: Luciano Miralles
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define LONG_NAME 51


typedef struct
{
    int id;
    char name[LONG_NAME];
    char lastName[LONG_NAME];
    float salary;
    int sector;
    int isEmpty;
} Employee;


int initEmployees(Employee* list, int longitud);
int addEmployees(Employee* list, int longitud, int* pId, char* pName, char* pLastName, float vSalary, int vSector);
int findEmployees(Employee* list, int longitud, int auxId);
int removeEmployee(Employee* list, int longitud, int posicion);
int sortEmployess(Employee* list, int longitud);
int printEmployees(Employee* list, int longitud);


#endif /* ARRAYEMPLOYEES_H_ */
