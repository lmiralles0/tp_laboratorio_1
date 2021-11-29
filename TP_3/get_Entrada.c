/*
 * get_Entrada.c
 *
 *  Created on: 16 nov. 2021
 *      Author: Luciano Miralles
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_Entrada.h"
#define LARGO 50


static int get_Int(int* pResultado);
static int esNumericaInt(char* cadena);
static int myGetsInt(char* cadena, int longitud);
//
static int get_String(char *cadena, int longitud);
static int esString(char* cadena, int longitud);
static int myGetsTexto(char* cadena, int longitud);
//
static int get_Float(float* pResultado);
static int myGetsFloat(char* cadena, int longitud);
static int esNumericaFloat(char* cadena);


int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos)
{
    int retorno = -1;
    int bufferInt;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && intentos >= 0)
    {

        do
        {
            printf("%s", mensaje);

            if(get_Int(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                intentos --;
            }
        }while(intentos >= 0);
    }
    return retorno;
}

static int get_Int(int* pResultado)
{
    int retorno = -1;
    char bufferInt[LARGO];

    if(myGetsInt(bufferInt,sizeof(bufferInt)) == 0 && esNumericaInt(bufferInt))
    {
        *pResultado = atoi(bufferInt);
        retorno = 0;
    }
    return retorno;
}

static int esNumericaInt(char* cadena)
{
    int i = 0;
    int retorno = 1;

    if(cadena != NULL && strlen(cadena)>0)
    {
        for(i=0; cadena[i] != '\0' ; i++)
        {
            if(i ==0 && (cadena[i] == '-' || cadena [i] == '+'))
            {
                continue;
            }
            if(cadena[i] > '9' || cadena[i] < '0')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

static int myGetsInt(char* cadena, int longitud)
{
    int retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)//fgets saca la informacion del fflush porque al limpiar la consola es un archivo
    {
        fflush(stdin);//me limpia la consola
        if(cadena[0] != '\n')
        {
            if(cadena[strlen(cadena)-1] == '\n')
            {
                cadena[strlen(cadena)-1] = '\0';
            }
        }
        retorno = 0;
    }
    return retorno;
}


int get_EntradaTexto(char* pResultado, int longitud, char* mensaje, char* mensajeError, int intentos)
{
    int retorno = -1;
    char bufferString[LARGO];

    if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            if(get_String(bufferString, LARGO) == 0)
            {
                strncpy(pResultado, bufferString, longitud);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                intentos --;
            }
        }
        while(intentos >= 0);
    }
    return retorno;
}

static int get_String(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[LARGO];
    if(cadena != NULL && longitud > 0)
    {
        if(myGetsTexto(bufferString, LARGO) == 0 && esString(bufferString, LARGO) && strnlen(bufferString,sizeof(bufferString)) < longitud)
        {
            strncpy(cadena, bufferString, longitud);
            retorno = 0;
        }
    }
    return retorno;
}

static int myGetsTexto(char* cadena, int longitud)
{
    int retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
        fflush(stdin);
        retorno = 1;
        if(cadena[0] != '\n')
        {
            if(cadena[strlen(cadena)-1] == '\n')
            {
                cadena[strlen(cadena)-1] = '\0';
            }
        }
        retorno = 0;
    }
    return retorno;
}

static int esString(char* cadena, int longitud)
{
    int i = 0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0; cadena[i] != '\0' ; i++)
        {
            if(((cadena[i] <'a' || cadena[i] >'z') && (cadena[i] < 'A' || cadena[i] >'Z')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError, float maximo , float minimo ,int intentos)
{
    int retorno = 1;
    float bufferFloat;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            if(get_Float(&bufferFloat)==0 && bufferFloat <= maximo && bufferFloat >= minimo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                intentos --;
            }
        }while(intentos >= 0);
    }
    return retorno;
}

static int get_Float(float* pResultado)
{
    int retorno = 1;
    char bufferFloat[LARGO];

    if(myGetsFloat(bufferFloat, sizeof(bufferFloat))== 0 && esNumericaFloat(bufferFloat))
    {
        *pResultado = atof(bufferFloat);
        retorno = 0;
    }
    return retorno;
}

static int myGetsFloat(char* cadena, int longitud)
{
    int retorno = -1;

    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin)== cadena)
    {
        fflush(stdin);
        if(cadena[0] != '\n')
        {
            if(cadena[strlen(cadena)- 1] == '\n')
            {
                cadena[strlen(cadena) - 1] = '\0';
            }
        }
         retorno = 0;
    }
    return retorno;
}

static int esNumericaFloat(char* cadena)
{
    int i = 0;
    int retorno = 1;
    int contadorPunto = 0;
    if(cadena != NULL && strlen(cadena)>0)
    {
        for(i=0;cadena[i] != '\0'; i++)
        {
            if((i==0 && (cadena[i] == '-' || cadena[i] == '+')) || (cadena[i] >= '0' && cadena[i] <= '9'))
            {
                continue;
            }
            if(cadena[i] == '.' && contadorPunto == 0)
            {
                contadorPunto ++;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
