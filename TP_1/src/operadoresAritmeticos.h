/*
 * operadoresAritmeticos.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Luciano Miralles
 */

#ifndef OPERADORESARITMETICOS_H_
#define OPERADORESARITMETICOS_H_

int get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError, float maximo, float minimo, int intentos);
int get_EntradaChar(char* pResultado, int longitud, char* mensaje, char* mensajeError, char maximo, char minimo, int intentos);
float oAritmeticos(float num1, float num2, char operador);
float oFactorial(float num, char operador);

#endif /* OPERADORESARITMETICOS_H_ */
