/*
 * bibliotecasEntradas.h
 *
 *  Created on: 16 may. 2021
 *      Author: Luciano Miralles
 */

#ifndef BIBLIOTECASENTRADAS_H_
#define BIBLIOTECASENTRADAS_H_

int get_Texto(char* pResultado, int longitud, char* mensaje, char* mensajeError, int intentos);
//
int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos);
//
int get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError,float maximo,float minimo, int intentos);
//

int menu(char *pCadena);

#endif /* BIBLIOTECASENTRADAS_H_ */
