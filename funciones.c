#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


/*Laboratorio - TP 1 - Olinuck Dario */

/** \brief Suma los dos números ingresados por el usuario
 * \param a como el primer número ingresado
 * \param b como el segundo número ingresado
 * \return el resultado de dicha suma
 */

 float suma(float a, float b)
{
    float total;
    total=a+b;
    return printf("\n\nEl resultado de la suma es: %.2f\n\n",total);
}

/** \brief Resta los dos números ingresados por el usuario
 * \param a como el primer número ingresado
 * \param b como el segundo número ingresado
 * \return el resultado de dicha resta
 */

float resta(float a, float b)
{
    float total;
    total=a-b;
    return printf("\n\nEl resultado de la resta es: %.2f\n\n",total);
}

/** \brief Divide los dos números ingresados por el usuario
 * \param a como dividendo
 * \param b como divisor, tiene que ser diferente de 0
 * \return el resultado de dicha multiplicación
 */

float division(float a, float b)
{
    float total;

    if(b==0)
    {
        total = printf("No se puede realizar una division por cero. Reingresar divisor valido en opcion 2.\n");
    }
    else
    {
        total=printf("\n\nEl resultado de la division es: %.2f\n\n",a/b);
    }

    return total;
}

/** \brief Multiplica los dos números ingresados por el usuario
 * \param a como el primer número ingresado
 * \param b como el segundo número ingresado
 * \return el resultado de dicha multiplicación
 */

float multiplicacion(float a, float b)
{
    float total;
    total=a*b;
    return printf("\n\nEl resultado de la multiplicacion es: %.2f\n\n",total);
}

/** \brief Realiza el factoreo del numero ingresado por el usuario
 * \param a como el numero a factorear
 * \return el resultado del factoreo
 */

float factorial(float a)
{
    float factor;

    if(a== 0 || a==1)
    {
        factor=1;
    }
    else
    {
        factor=a * factorial(a-1);
    }

    return factor;
}
