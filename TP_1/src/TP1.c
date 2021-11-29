/*
 ============================================================================
 Name        : TP1.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operadoresAritmeticos.h"
#define WEIGHT 2


int main()
{
	setbuf(stdout, NULL);

    float operador_A = 0;
    float operador_B = 0;
    int flagOperadores = 0;
    int contadorOperadoresA = 0;
    int contadorOperadoresB = 0;
    float operadorMenuNumerico;
    char operadorMenuLetra[WEIGHT];
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactorialA;
    float resultadoFactorialB;
    int flagImprimoSuma = 0;
    int flagImprimoResta = 0;
    int flagImprimoMultiplicacion = 0;
    int flagImprimoDivision = 0;
    int flagImprimoFactorialA = 0;
    int flagImprimoFactorialB = 0;

    do
    {
        printf("Calculadora 1G.\n\n");
        if(flagOperadores == 0)
        {
            printf("1. Ingresar 1er operando \n");
            printf("2. Ingresar 2do operando \n");
        }
        else if(flagOperadores == 1)
        {
            printf("1. Ingresar 1er operando (A = %.2f)\n", operador_A);
            printf("2. Ingresar 2do operando \n");
        }
        else if(flagOperadores == 2)
        {
            printf("1. Ingresar 1er operando \n");
            printf("2. Ingresar 2do operando (B = %.2f)\n", operador_B);
        }
        else if(contadorOperadoresA > 0 && contadorOperadoresB > 0)
        {
            printf("1. Ingresar 1er operando (A = %.2f)\n", operador_A);
            printf("2. Ingresar 2do operando (B = %.2f)\n", operador_B);
        }
        printf("3. Calculo de operaciones\n"
               "4. Informar resultados\n"
               "5. Salir\n");
        get_EntradaFloat(&operadorMenuNumerico,"\n\nIngrese un numero del menu: \n", "Error no es un numero valido.\n", 5, 1, 3);
        system("cls");

        switch((int)operadorMenuNumerico)
        {
        case 1:
            if(get_EntradaFloat(&operador_A,"\n\nIngrese un numero A: \n", "Error no es un numero valido.\n", 999999999, -999999999, 3) == 0)
            {
                flagOperadores = 1;
                contadorOperadoresA ++;
                flagImprimoFactorialA = 0;
                flagImprimoSuma = 0;
                flagImprimoResta = 0;
                flagImprimoMultiplicacion = 0;
                flagImprimoDivision = 0;

                if(contadorOperadoresA > 0 && contadorOperadoresB > 0)
                {
                    flagOperadores = 3;
                }
            }
            system("cls");
            break;
        case 2:
            if(get_EntradaFloat(&operador_B,"\n\nIngrese un numero B: \n", "Error no es un numero valido.\n", 999999999, -999999999, 3) == 0)
            {
                flagOperadores = 2;
                contadorOperadoresB ++;
                flagImprimoFactorialB = 0;
                flagImprimoSuma = 0;
                flagImprimoResta = 0;
                flagImprimoMultiplicacion = 0;
                flagImprimoDivision = 0;

                if(contadorOperadoresB > 0 && contadorOperadoresA > 0)
                {
                    flagOperadores = 3;
                }
            }
            system("cls");
            break;
        case 3:
            do
            {
                if(contadorOperadoresA > 0 && contadorOperadoresB == 0)
                {
                    printf("e) Calcular el factorial (A!)\n"
                           "f) ATRAS.\n");
                    get_EntradaChar(operadorMenuLetra, WEIGHT, "Ingrese una letra del menu para realizar una operacion.\n", "Error al seleccionar una operacion del menu.\n", 'f', 'a',5);
                }
                if(contadorOperadoresB > 0 && contadorOperadoresA == 0)
                {
                    printf("e) Calcular el factorial de (B!)\n"
                           "f) ATRAS.\n");
                    get_EntradaChar(operadorMenuLetra, WEIGHT, "Ingrese una letra del menu para realizar una operacion.\n", "Error al seleccionar una operacion del menu.\n", 'f', 'a',5);
                }
                if(contadorOperadoresA > 0 && contadorOperadoresB > 0)
                {
                    printf("a) Calcular la suma (A+B)\n"
                           "b) Calcular la resta (A-B)\n"
                           "c) Calcular la multiplicacion (A*B)\n"
                           "d) Calcular la division (A/B)\n"
                           "e) Calcular el factorial (A!) y/o de (B!)\n"
                           "f) ATRAS.\n");
                    get_EntradaChar(operadorMenuLetra, WEIGHT, "Ingrese una letra del menu para realizar una operacion.\n", "Error al seleccionar una operacion del menu.\n", 'f', 'a',5);
                }
                else if(contadorOperadoresA == 0 && contadorOperadoresB == 0)
                {
                    printf("No hay operaciones para seleccionar porque no hay numeros cargados.\n");
                    printf("Ingrese numeros.\n");
                    system("pause");
                    break;
                }
            }
            while(operadorMenuLetra[0] < 'a' || operadorMenuLetra[0] > 'f');

            if(operadorMenuLetra [0] == 'a' && contadorOperadoresA > 0 && contadorOperadoresB > 0)
            {
                resultadoSuma = oAritmeticos(operador_A, operador_B, operadorMenuLetra[0]);
                flagImprimoSuma = 1;
            }
            if(operadorMenuLetra[0] == 'b' && contadorOperadoresA > 0 && contadorOperadoresB > 0)
            {
                resultadoResta = oAritmeticos(operador_A, operador_B, operadorMenuLetra[0]);
                flagImprimoResta = 1;
            }
            if(operadorMenuLetra[0] == 'c' && contadorOperadoresA > 0 && contadorOperadoresB > 0)
            {
                resultadoMultiplicacion = oAritmeticos(operador_A, operador_B, operadorMenuLetra[0]);
                flagImprimoMultiplicacion = 1;
            }
            if(operadorMenuLetra[0] == 'd' && contadorOperadoresA > 0 && contadorOperadoresB > 0)
            {
                resultadoDivision = oAritmeticos(operador_A, operador_B, operadorMenuLetra[0]);
                flagImprimoDivision = 1;
            }
            if(operadorMenuLetra[0] == 'e' && contadorOperadoresA > 0 && contadorOperadoresB > 0)
            {
                resultadoFactorialA = oFactorial(operador_A, operadorMenuLetra[0]);
                resultadoFactorialB = oFactorial(operador_B, operadorMenuLetra[0]);
                flagImprimoFactorialA = 1;
                flagImprimoFactorialB = 1;
            }
            if(operadorMenuLetra[0] == 'e' && contadorOperadoresA > 0 && contadorOperadoresB == 0)
            {
                resultadoFactorialA = oFactorial(operador_A, operadorMenuLetra[0]);
                flagImprimoFactorialA = 1;
            }
            if(operadorMenuLetra[0] == 'e' && contadorOperadoresB > 0 && contadorOperadoresA == 0)
            {
                resultadoFactorialB = oFactorial(operador_A, operadorMenuLetra[0]);
                flagImprimoFactorialB = 1;
            }
            system("cls");
            break;
        case 4:
            if(contadorOperadoresA > 0 && contadorOperadoresB == 0 && flagImprimoFactorialA == 1)
            {
                printf("e) El factorial de A es: %.2f\n", resultadoFactorialA);
            }
            if(contadorOperadoresB > 0 && contadorOperadoresA == 0 && flagImprimoFactorialB == 1)
            {
                printf("El factorial de B es: %.2f\n", resultadoFactorialB);
            }
            if(contadorOperadoresA > 0 && contadorOperadoresB > 0 && flagImprimoSuma == 1)
            {
                printf("a) El resultado de A+B es: %.2f\n\n", resultadoSuma);
            }
            if(contadorOperadoresA > 0 && contadorOperadoresB > 0 && flagImprimoResta == 1)
            {
                printf("b) El resultado de A-B es: %.2f\n\n", resultadoResta);
            }
            if(contadorOperadoresA > 0 && contadorOperadoresB > 0 && flagImprimoMultiplicacion == 1)
            {
                printf("c) El resultado de A*B es: %.2f\n\n", resultadoMultiplicacion);
            }
            if(contadorOperadoresA > 0 && contadorOperadoresB > 0 && flagImprimoDivision == 1)
            {
                if(operador_B != 0.00)
                {
                    printf("d) El resultado de A/B es: %.2f\n\n", resultadoDivision);
                }
                else
                {
                    printf("No es posible dividir por cero\n\n");
                }
            }
            if(contadorOperadoresA > 0 && contadorOperadoresB > 0 && flagImprimoFactorialA == 1 && flagImprimoFactorialB == 1)
            {
                printf("e) El factorial de A es: %.2f y El factorial de B es: %.2f\n\n", resultadoFactorialA, resultadoFactorialB );
            }
            if(flagImprimoSuma == 1 || flagImprimoResta == 1 || flagImprimoMultiplicacion == 1 || flagImprimoDivision == 1 ||
                    flagImprimoFactorialA == 1 || flagImprimoFactorialB == 1)
            {
                system("pause");
                system("cls");
            }
            if(flagImprimoSuma == 0 && flagImprimoResta == 0 && flagImprimoMultiplicacion == 0 && flagImprimoDivision == 0 &&
                flagImprimoFactorialA == 0 && flagImprimoFactorialB == 0)
            {
                printf("No hay resultados para mostrar\n");
                printf("Ingrese numeros.\n\n");
                system("pause");
                system("cls");
            }
            break;
        }
    }
    while(operadorMenuNumerico != 5);

    return EXIT_SUCCESS;
}
