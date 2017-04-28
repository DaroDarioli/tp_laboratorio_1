#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*Laboratorio - TP 1 - Olinuck Dario */


int main()
{
    char seguir='s';
    int opcion=0;
    float x, y;
    int flag1=0, flag2=0;

    do
    {
        printf("\n--- Calculadora en C ---\n\n");

        if(flag1==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando A= %.2f\n",x);
        }

        if(flag2==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando B= %.2f\n",y);

        }
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("1- Ingresar 1er operando: ");
                scanf("%f",&x);
                flag1=1;
                system("cls");
                break;
            case 2:
                printf("2- Ingresar 2do operando: ");
                scanf("%f",&y);
                flag2=1;
                system("cls");
                break;
            case 3:
                suma(x,y);
                break;
            case 4:
                resta(x,y);
                break;
            case 5:
                if(flag1== 0 || flag2 == 0)
                {
                    printf("\nCalculo no valido.\n");
                }
                else
                {
                    division(x,y);
                }
                break;
            case 6:
                if(flag1== 0 || flag2 == 0)
                {
                    printf("\nCalculo no valido.\n");
                }
                else
                {
                    multiplicacion(x,y);
                }
                break;
            case 7:
                printf("\n\nEl resultado del factoreo de %.2f es: %.2f\n\n",x,(factorial(x)));
                break;
            case 8:
                if(flag1== 0 || flag2 == 0)
                {
                    printf("\nCalculo no valido.\n");
                }
                else
                {
                    suma(x,y);
                    resta(x,y);
                    division(x,y);
                    multiplicacion(x,y);
                    printf("\n\nEl resultado del factoreo de %.2f es: %.2f\n\n",x,(factorial(x)));
                }
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("Por favor ingresar opcion valida.");
                break;
        }

    }while(seguir=='s');

    return 0;
}
