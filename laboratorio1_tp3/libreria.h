#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Laboratorio I
  TP 3
  Olinuck Dario Esteban
*/

int valida_letras(char vect[]);
int valida_numeros(char vect[]);
int validaRango(int value, int limMin, int limMax);
int getValidatedInt(char mensaje[],char input[],int lowLim, int highLim);

int getInt(char msg[]);
float getFloat(char msg[]);
char getChar(char msg[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);



