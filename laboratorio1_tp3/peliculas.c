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

/** \brief Imprime por pantalla un menu de opciones y devuelve la opcion elegida *
 * \return La opcion elegida
 *
 */

int menu()
{
    int opcion;
    printf("\n** Cine Club ** \n\n");
    printf("1. Agregar pelicula\n");
    printf("2. Borrar pelicula\n");
    printf("3. Modificar pelicula\n");
    printf("4. Generar archivo Binario\n");
    printf("5. Generar web\n");
    printf("6. Salir\n");
    scanf("%d",&opcion);

    return opcion;
}


/** \brief Realiza el alta de un elemento del array peliculas
 * \param el array de peliculas
 * \param la cantidad de elementos del mismo
 * \return 1 si la tarea se concluyo, caso contrario 0
 *
 */

int peliculas_alta(s_Pelicula *peliculas,int cant)
{
    char auxGeneroStr[25],auxDuracionStr[10],auxPuntajeStr[10];

    int indice;

    indice=peliculas_buscarLugarLibre(peliculas,cant,0);

    if(indice==-1)
    {
        printf("No hay lugares.\n");
    }
    else
    {
        getString("Ingrese titulo: ",peliculas[indice].titulo);

        while(!getStringLetras("Ingrese genero: ",auxGeneroStr))
        {
            printf("Solo letras por favor!\n");
        }

        while(!getStringNumeros("Ingrese duracion: ",auxDuracionStr))
        {
            printf("Solo numeros por favor!\n");
        }

        getString("Ingrese sinopsis: ",peliculas[indice].descripcion);

        while(!getStringNumeros("Ingrese el puntaje: ",auxPuntajeStr))
        {
            printf("Solo numeros por favor!\n");
        }

        getString("Ingrese direccion URL: ",peliculas[indice].linkImagen);

        strncpy(peliculas[indice].genero,auxGeneroStr,100);
        peliculas[indice].puntaje=atoi(auxPuntajeStr);
        peliculas[indice].duracion=atoi(auxDuracionStr);
        peliculas[indice].estado=1;
        return 1;
    }
    return 0;

}

/** \brief Realiza la baja logica de un elemento del array peliculas
 * \param el array peliculas
 * \param la cantidad de elementos que posee el array
 * \return 1 si la tarea se realizo, caso contrario 0
 *
 */

int peliculas_baja(s_Pelicula *peliculas,int cant)
{
    int indice,indiceTest;

    char auxTituloStr[25];

    indiceTest=peliculas_buscarLugarLibre(peliculas,cant,1);

    if(indiceTest == -1)
    {
        printf("Para esta opcion debe ingresar peliculas primero\n");
    }
    else
    {
        while(!getStringLetras("Ingrese el titulo de la pelicula: ",auxTituloStr))
        {
            printf("El titulo debe estar en letras!!\n");
        }

        indice=peliculas_buscar(peliculas,cant,auxTituloStr);

        if(indice == -1)
        {
            printf("La pelicula no existe.\n");
        }
        else
        {
            peliculas[indice].estado=0;
            printf("\nSe elimino la pelicula: %s",peliculas[indice].titulo);
            return 1;
        }
    }
    return 0;
}


/** \brief Realiza la modificacion de una pelicula
 * \param El array de peliculas
 * \param La cantidad de elementos que posee el array
 * \return 1 si se realizo la tarea, caso contrario 0
 *
 */

int peliculas_modificar(s_Pelicula *peliculas,int cant)
{
    int indice,indiceTest;

    char auxTituloStr[25],auxGeneroStr[25],auxDuracionStr[10],auxPuntajeStr[10];

    indiceTest=peliculas_buscarLugarLibre(peliculas,cant,1);

    if(indiceTest == -1)
    {
        printf("Para esta opcion debe ingresar peliculas primero\n");
    }
    else
    {
        while(!getStringLetras("Ingrese el titulo de la pelicula a modificar: ",auxTituloStr))
        {
            printf("El titulo debe estar en letras!!\n");
        }

        indice=peliculas_buscar(peliculas,cant,auxTituloStr);

        if(indice == -1)
        {
            printf("La pelicula no existe.\n");
        }
        else
        {
            getString("Ingrese titulo: ",peliculas[indice].titulo);

            while(!getStringLetras("Ingrese genero: ",auxGeneroStr))
            {
                printf("Solo letras por favor!\n");
            }

            while(!getStringNumeros("Ingrese duracion: ",auxDuracionStr))
            {
                printf("Solo numeros por favor!\n");
            }

            getString("Ingrese sinopsis: ",peliculas[indice].descripcion);

            while(!getStringNumeros("Ingrese el puntaje: ",auxPuntajeStr))
            {
                printf("Solo numeros por favor!\n");
            }

            getString("Ingrese direccion URL: ",peliculas[indice].linkImagen);

            strncpy(peliculas[indice].genero,auxGeneroStr,100);
            peliculas[indice].puntaje=atoi(auxPuntajeStr);
            peliculas[indice].duracion=atoi(auxDuracionStr);

            return 1;
        }
    }
    return 0;
}


/** \brief Genera un archivo html
 * \param El array de peliculas
 * \param la cantidad de elementos del array
 */


int peliculas_generarHTML(s_Pelicula *peliculas,int cant)
{
    int i;

    FILE *parch;

    parch=fopen("Cineclub.html","w");
    if(parch != NULL)
    {
        fprintf(parch,"<!DOCTYPE html><html>");
        for(i=0; i<cant; i++)
        {

            if(peliculas[i].estado == 1)
            {
                fprintf(parch,"<body bgcolor=rgb(116,116,116)><h1>Titulo: %s </h1>\n\n<h2>Genero: %s</h2>\n\n<h3>Puntaje: %d </h3>\n\n<p>Sinopsis: %s \n\n\n\n</p><img src=%s style='width:304px;height:228px;'>",peliculas[i].titulo,peliculas[i].genero,peliculas[i].puntaje,peliculas[i].descripcion,peliculas[i].linkImagen);

            }
        }
        fprintf(parch,"</body></html>");
        fclose(parch);
        return 1;

    }


    return 0;

}


/** \brief Genera un archivo binario
 * \param El array de peliculas
 * \param la cantidad de elementos del array
 */

int peliculas_guardarBIN(s_Pelicula*peli)
{
    FILE* fp;
    fp=fopen("bin.dat","ab+");
    if(fp==NULL)
    {
        printf("Error al abrir archivo.");
    }
    else
    {
        fwrite(peli,sizeof(s_Pelicula),1,fp);
        fclose(fp);
        return 1;

    }

    return 0;
}

/** \brief Buscar peliculas por titulo
 * \param el array de peliculas
 * \param la cantidad de elementos del array
 * \param el titulo de la pelicula a buscar
 * \return La posicion de la pelicula en el array si la encuentra, caso contrario -1
 *
 */

int peliculas_buscar(s_Pelicula *peliculas,int cant,char valor[])
{
    int i;

    for(i=0; i<cant; i++)
    {
        if((peliculas[i].estado==1) && (strcmp(peliculas[i].titulo,valor)==0))
        {
            return i;
        }
    }
    return -1;
}


/** \brief Busca un lugar libre en el array de peliculas
 * \param El array de peliculas
 * \param La cantidad de elementos del array
 * \param Un valor que indica que el lugar se encuentra vacio
 * \return La posicion del lugar libre si existe, caso contario -1
 *
 */

int peliculas_buscarLugarLibre(s_Pelicula *peliculas,int cant,int valor)
{
    int i;

    for(i=0; i<cant; i++)
    {
        if(peliculas[i].estado==valor)
        {
            return i;
        }
    }

    return -1;

}

/** \brief Inicializa todos los elementos del array en un mismo valor
 * \param El array de peliculas
 * \param la cantidad de elementos del array
 * \param el valor en el que los elementos seran inicializados
 *
 */


void peliculas_inicializar(s_Pelicula *peliculas,int cant,int valor)
{
    int i;

    for(i=0; i<cant; i++)
    {
        peliculas[i].estado=valor;
    }
}

