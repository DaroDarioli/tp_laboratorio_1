#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "libreria.h"

/*Laboratorio I
  TP 3
  Olinuck Dario Esteban
*/

#define Q 5

int main()
{
    s_Pelicula peliculas[Q];
    peliculas_inicializar(peliculas,Q,0);

    int opcion=0;

    while(opcion !=6)
    {
        opcion=menu();
        switch(opcion)
        {
        case 1:
            if(peliculas_alta(peliculas,Q)==1)
            {
                printf("\nSe ingreso la pelicula.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nNo se pudo ingresar la pelicula.\n");
            }
            break;
        case 2:
            if(peliculas_baja(peliculas,Q)==1)
            {
                printf("\nSe elimino la pelicula.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nNo se pudo eliminar la pelicula.\n");
            }
            break;
        case 3:
            if(peliculas_modificar(peliculas,Q)==1)
            {
                printf("\nSe modifico pelicula.\n");
                system("pause");
                system("cls");

            }
            else
            {
                printf("\nNo se puedo modificar pelicula.\n");

            }
            break;
        case 4:
            if(peliculas_guardarBIN(peliculas)==1)
            {
                printf("\nSe genero archivo binario.\n");
                system("pause");
                system("cls");

            }
            else
            {
                printf("\nNo se puedo generar archivo binario.\n");
            }
            break;
        case 5:
            if(peliculas_generarHTML(peliculas,Q)==1)
            {
                printf("Se genero pagina web.");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nNo se pudo generar pagina web.\n");
            }
            break;
        case 6:
            opcion = 6;
            break;
        default:
            printf("Opcion invalida.");
            break;
        }
    }
    return 0;
}
