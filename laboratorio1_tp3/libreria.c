#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "peliculas.h"
#include "libreria.h"

/*Laboratorio I
  TP 3
  Olinuck Dario Esteban
*/

/** \brief Solicita un vector de caracteres
 * \param mensaje es el mensaje a imprir por pantalla
 * \param input es donde será guardado el mensaje
 *
 */

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}


/** \brief Solicita un numero entero
 * \param msg es el mensaje a imprimir por pantalla
 * \return el numero entero ingresado
 *
 */

int getInt(char msg[])
{
    int res;
    printf("%s",msg);
    scanf("%d",&res);
    return res;
}

/** \brief Solicita un numero flotante
 * \param msg es el mensaje a imprimir por pantalla
 * \return el numero flotante ingresado
 *
 */

float getFloat(char msg[])
{
    float res;
    printf("%s",msg);
    scanf("%f",&res);
    return res;
}

/** \brief Solicita un caracter
 * \param msg es el mensaje a imprimir por pantalla
 * \return el numero caracter ingresado
 *
 */

char getChar(char msg[])
{
    char aux;
    printf("%s",msg);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/** \brief Valida si la información ingresada es vector de letras
 * \param El vector ingresado por el usuario
 * \return 1 si posee letras o espacio, caso contrario 0
 *
*/

int valida_letras(char vect[])
{
    int i=0;
    while(vect[i]!= '\0')
    {
        if((vect[i]!=' ')&&(vect[i]< 'a' || vect[i]>'z')&&(vect[i]<'A' || vect[i]>'Z'))
            return 0;
        i++;
    }
    return 1;

}

/** \brief Valida si la información ingresada es vector de numeros
 * \param El vector ingresado por el usuario
 * \return 1 si posee numeros, caso contrario 0
 *
*/

int valida_numeros(char vect[])
{
    int i=0;
    while(vect[i]!= '\0')
    {
        if(vect[i]<'0' || vect[i]>'9')
            return 0;
        i++;
    }
    return 1;
}


/** \brief Solicita un vector de caracteres y lo valida
 * \param el mensaje a ser mostrado
 * \param input es donde el carcter es guardado
 * \return 1 si se obtuvo la cadena, caso contrario 0
 *
 */

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(valida_letras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/** \brief Solicita un vector numerico y lo valida
 * \param el mensaje a ser mostrado
 * \param input es donde el carcter es guardado
 * \return 1 si se obtuvo la cadena, caso contrario 0
 *
 */

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(valida_numeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief Pide que se ingrese un valor numerico y valida que se encuentre dentro del rango
 * \param El mensaje que pide el numero
 * \param El valor ingresado
 * \param El limite inferior
 * \param El limite superior
 * \return El numero ingresado
 *
 */


int getValidatedInt(char mensaje[],char input[],int lowLim, int highLim)
{

    int auxInt;
    getString(mensaje,input);
    while(!valida_numeros(input))
    {
        printf("Ingresar solo numeros!!\n");
        getString(mensaje,input);

    }
    auxInt=atoi(input);
    if(auxInt < lowLim || auxInt > highLim)
    {
        printf("Numero fuera de rango!!\n");
        getString(mensaje,input);
    }

    return auxInt;
}

/** \brief Valida si la informacion ingresada se encuentra dentro de un rango
 * \param int value el valor ingresado
 * \param int limMin el valor más bajo permitido
 * \param in limMax el valor más alto permitido
 * \return 1 si está dentro del rango permitido, 0 caso contrario
 */


int validaRango(int value, int limMin, int limMax)
{
    if(value < limMin || value >limMax)
    {
        return 0;
    }
    return 1;
}

