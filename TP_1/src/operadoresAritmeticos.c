/*
 * operadoresAritmeticos.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Luciano Miralles
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000
#define LARGO 1000

static int get_Float(float* pResultado);
static int myGetsFloat(char* cadena, int longitud);
static int esNumericaFloat(char* cadena);
/// validacion float
static int get_Char(char* cadena, int longitud);
static int myGetsChar(char* cadena, int longitud);
static int esChar(char* cadena);
///validacion char


/*
brief Devuelve en fomra de puntero una variable int por direccion de memoria
param se carga un mensaje
param se carga un mensaje de error
param un maximo
param un minimo
return devuelve 0 EXITO y 1 si Error
*/

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
    char bufferFloat[LEN];

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

/*
brief Carga un variable con el puntero y se pasa la variable con la direccion de memoria
param se pasa el largo
param mensaje
param mensaje de error
param caracter maximo
param caracter minimo
return 0 EXTIO y 1 si error
*/
int get_EntradaChar(char* pResultado, int longitud, char* mensaje, char* mensajeError, char maximo, char minimo, int intentos)
{
    int retorno = 1;
    char bufferChar[LARGO];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo> minimo && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            if(get_Char(bufferChar, sizeof(bufferChar)) == 0 && bufferChar[0] >= minimo && bufferChar[0] <= maximo)
            {
                strncpy(pResultado, bufferChar, longitud);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                intentos --;
            }

        }while(intentos > 0);
    }
    return retorno;
}


static int get_Char(char* cadena, int longitud)
{
    int retorno = 1;
    char bufferChar[LARGO];
    if(cadena != NULL && longitud > 0)
    {
        if(myGetsChar(bufferChar, LARGO) == 0 && esChar(bufferChar))
        {
            strncpy(cadena, bufferChar, longitud);
            retorno = 0;
        }

    }
    return retorno;
}

static int myGetsChar(char* cadena, int longitud)
{
    int retorno = 1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)- 1] == '\n')
            {
                cadena[strlen(cadena) - 1] = '\0';
            }
        retorno = 0;
    }
    return retorno;
}

static int esChar(char* cadena)
{
    int i = 0;
	int retorno = 1;

	if(cadena != NULL)
	{
		for(i=0; cadena[i] != '\0' ; i++)
		{
			if((cadena[0] <'a' || cadena[0] >'z' || cadena[0] == '\0') ||
                (i >= 1 && (cadena[i] >= 0 || cadena[i] <= 127)))
			{
				retorno = 0;
				break;
			}
	    }
	}
	return retorno;
}

/*
brief Recibe el operador 1 y 2 mas la letra de la operacion y devuelve la operacion por return
*/

float oAritmeticos(float num1, float num2, char operador)
{
    float resultado;

    switch(operador)
    {
        case 'a':
            resultado = num1 + num2;
            break;
        case 'b':
            resultado = num1 - num2;
            break;
        case 'c':
            resultado = num1 * num2;
            break;
        case 'd':
            if(num2 != 0)
            {
                resultado = num1 / num2;
            }
            else
            {
                resultado = 0.0;
            }
            break;
    }

    return resultado;
}

float oFactorial(float num, char operador)
{
    float resultado;
    float j;
    float barrera;
    barrera = num;
    switch(operador)
    {
        case 'e':
            if(num == 0 || num == 1)
            {
                resultado = 1;
                break;
            }
            for(int i = 0; i < barrera - 1;i++)
            {
                if(i == 0)
                {
                    j = num * (num - 1);
                    resultado = j;
                    num --;
                }
                else
                {
                    num --;
                    resultado = resultado * num;
                }
            }
            break;
    }
    return resultado;
}



