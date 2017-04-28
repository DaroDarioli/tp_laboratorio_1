#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libreria.h"

/*Tecnicatura en Programación, UTN FRA
  Laboratorio I
  TP 2 Olinuck Darío Esteban*/

/** \brief Inicializa todos los elementos del array en un mismo valor
 * \param El array de elementos a ser inicializado
 * \param La cantidad de elementos del array
 * \param El valor en el que se va a inicializar los elementos
 *
 */

void inicializar(persona arrayP[], int cant,int valor)
{
    int i;
    for(i=0;i<cant;i++)
    {
        arrayP[i].estado=valor;

    }
}

/** \brief Busca un elemento dentro del array
 * \param El array a ser recorrido en la busqueda
 * \param La cantidad de elementos del array
 * \param El valor que el usuario está buscando
 * \return La posición del elemento que se busca dentro del array o -1 en caso de no encontrarlo
 *
 */

int buscar(persona arrayP[], int cant, int valor)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayP[i].estado==valor)
        {
            return i;
        }
    }
    return -1;
}

/** \brief Busca una persona dentro del array por DNI
 * \param El array a ser recorrido en la busqueda
 * \param La cantidad de elementos del array
 * \param El DNI que el usuario está buscando
 * \return La posición del elemento que se busca dentro del array o -1 en caso de no encontrarlo
 *
 */

int buscarPorDNI(persona arrayP[], int cant, int valor)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayP[i].estado==1 && arrayP[i].dni==valor)
		{
			return i;
		}

    }
    return -1;
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

/** \brief Solicita un vector de caracteres
 * \param mensaje es el mensaje a imprir por pantalla
 * \param input es donde será guardado el mensaje
 *
 */


void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/** \brief Solicita un vector de numeros enteros
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
