#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Tecnicatura en Programación, UTN FRA
  Laboratorio I
  TP 2 Olinuck Darío Esteban*/


typedef struct{
    char nombre[50];
    int dni;
    int edad;
    int estado;

}persona;

void inicializar(persona arrayP[], int cant, int valor);
int buscar(persona arrayP[], int cant, int valor);
int buscarPorDNI(persona arrayP[], int cant, int valor);
int validaRango(int value, int limMin, int limMax);

int valida_letras(char vect[]);
int valida_numeros(char vect[]);

int getInt(char msg[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
