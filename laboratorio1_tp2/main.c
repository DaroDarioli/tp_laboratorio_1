#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libreria.h"

/*Tecnicatura en Programación, UTN FRA
  Laboratorio I
  TP 2 Olinuck Darío Esteban*/

#define Q 20

int main()
{
   persona arrayP[Q];
   persona arrayAuxiliar;

   char auxNombre[50];
   char auxE[50];
   char auxD[50];
   int auxDNI,auxEdad,i;
   int hasta18=0,de19a35=0,mayorDe35=0, mayor;


   int flag=0;

   int indicarLugarLibre;
   int indicarResultadoBusqueda;

   int opcion=0;
   inicializar(arrayP,Q,0);

   while(opcion != 6)
   {
       printf("\n -- ABM de Usuarios -- \n");
       opcion=getInt("\n1. Alta \n2. Baja \n3. Modificar \n4. Listar \n5. Imprimir grafico \n6. Salir\n");
       switch(opcion)
       {
            case 1:
                system("cls");
                indicarLugarLibre=buscar(arrayP,Q,0);
                if(indicarLugarLibre == -1)
                {
                    printf("\n No quedan mas lugares libres!!\n");
                    break;
                }
                printf("\n - Alta - \n");
                if(!getStringLetras("Ingrese nombre: ",auxNombre))
                {
                    printf("El nombre debe estar compuesto solo por letras.");
                    break;
                }

                if(!getStringNumeros("\nIngrese edad: \n",auxE))
                {
                    printf("La edad debe estar compuesta solo por numeros");
                    break;
                }

                auxEdad=atoi(auxE);
                if(!validaRango(auxEdad,0,120))
                {
                    printf("La edad se encuentra fuera de rango.\n");
                    break;
                }

                if(!getStringNumeros("\nIngrese DNI: \n",auxD))
                {
                    printf("El DNI deber ser solo numeros: ");
                    break;
                }


                auxDNI=atoi(auxD);
                if(!validaRango(auxDNI,12000000,99999999))
                {
                    printf("El DNI ingresado se encuentra fuera de rango.\n");
                    break;
                }


                if(buscarPorDNI(arrayP,Q,auxDNI)!= -1)
                {
                    printf("\n El DNI ya existe. \n");
                    break;
                }

                strcpy(arrayP[indicarLugarLibre].nombre,auxNombre);
                arrayP[indicarLugarLibre].dni=auxDNI;
                arrayP[indicarLugarLibre].edad=auxEdad;
                arrayP[indicarLugarLibre].estado= 1;
                flag=1;

                if(arrayP[indicarLugarLibre].edad < 18)
                {
                      hasta18++;
                }

                else if(arrayP[indicarLugarLibre].edad >= 18 && arrayP[indicarLugarLibre].edad < 35)
                {
                      de19a35++;
                }

                else if(arrayP[indicarLugarLibre].edad >= 35)
                {
                      mayorDe35++;
                }


                system("cls");
                break;
            case 2:
                system("cls");
                if(buscar(arrayP,Q,1)== -1)
                {
                    printf("\nPrimero debe ingrear usuarios!!\n");
                    break;
                }

                if(!getStringNumeros("Ingrese el DNI de usario a dar de baja: ",auxD))
                {
                    printf("El DNI deber poseer solo numeros: ");
                    break;
                }

                auxDNI=atoi(auxD);
                if(!validaRango(auxDNI,12000000,99999999))
                {
                    printf("El DNI ingresado se encuentra fuera de rango.\n");
                    break;
                }

                indicarResultadoBusqueda=buscarPorDNI(arrayP,Q,auxDNI);

                if(indicarResultadoBusqueda == -1)
                {
                    printf("No se encuentra ese Usuario!\n");
                    break;
                }
                printf("\nSe ha eliminado el usuario DNI: %d Nombre: %s\n", arrayP[indicarResultadoBusqueda].dni, arrayP[indicarResultadoBusqueda].nombre);
                if(arrayP[indicarLugarLibre].edad < 18)
                {
                      hasta18--;
                }

                else if(arrayP[indicarLugarLibre].edad >= 18 && arrayP[indicarLugarLibre].edad < 35)
                {
                      de19a35--;
                }

                else if(arrayP[indicarLugarLibre].edad >= 35)
                {
                      mayorDe35--;
                }
                arrayP[indicarResultadoBusqueda].estado=0;
                break;

            case 3:
                system("cls");
                if(buscar(arrayP,Q,1)== -1)
                {
                    printf("\nPrimero debe ingrear usuarios!!\n");
                    break;
                }

                if(!getStringNumeros("Ingrese el DNI del usuario a modificar: ",auxD))
                {
                    printf("El DNI deber poseer solo numeros: ");
                    break;
                }

                auxDNI=atoi(auxD);
                if(!validaRango(auxDNI,12000000,99999999))
                {
                    printf("El DNI ingresado se encuentra fuera de rango.\n");
                    break;
                }


                indicarResultadoBusqueda=buscarPorDNI(arrayP,Q,auxDNI);
                if(indicarResultadoBusqueda == -1)
                {
                    printf("No se encuentra ese DNI!\n");
                    break;
                }

                if(!getStringLetras("Ingrese nombre: ",auxNombre))
                {
                    printf("El nombre debe estar compuesto solo por letras.");
                    break;
                }

                if(!getStringNumeros("\nIngrese edad: \n",auxE))
                {
                    printf("La edad debe estar compuesta solo por numeros");
                    break;
                }

                auxEdad=atoi(auxE);
                if(!validaRango(auxEdad,0,120))
                {
                    printf("La edad se encuentra fuera de rango.\n");
                    break;
                }


                if(!getStringNumeros("\nIngrese nuevo DNI: \n",auxD))
                {
                    printf("El DNI deber ser solo numeros: ");
                    break;
                }

                auxDNI=atoi(auxD);
                if(!validaRango(auxDNI,12000000,99999999))
                {
                    printf("El DNI ingresado se encuentra fuera de rango.\n");
                    break;
                }

                strcpy(arrayP[indicarResultadoBusqueda].nombre,auxNombre);
                arrayP[indicarResultadoBusqueda].edad=auxEdad;
                arrayP[indicarResultadoBusqueda].dni=atoi(auxD);
                break;
            case 4:
                system("cls");
                if(buscar(arrayP,Q,1)== -1)
                {
                    printf("\nPrimero debe ingrear usuarios!!\n");
                    break;
                }

                printf("\n - Listado Alfabetico- \n\n");
                int j;

                for(i=0;i<Q -1; i++)
                {
                    for(j=i;j<Q;j++)
                    {
                        if(arrayP[i].estado != 0)
                        {
                            if(stricmp(arrayP[i].nombre,arrayP[j].nombre)>0)
                            {
                                    arrayAuxiliar=arrayP[i];
                                    arrayP[i]=arrayP[j];
                                    arrayP[j]=arrayAuxiliar;
                            }
                        }
                    }

                }

                for(i=0;i<Q; i++)
                {
                    if(arrayP[i].estado == 1)
                    {
                        printf("Nombre: %s  DNI: %d\n",arrayP[i].nombre,arrayP[i].dni);
                    }
                }

                break;
            case 5:
                system("cls");
                if(buscar(arrayP,Q,1)== -1)
                {
                    printf("\nPrimero debe ingrear usuarios!!\n");
                    break;
                }

                if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
                {
                    mayor = hasta18;
                }

                else if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
                {
                    mayor = de19a35;
                }

                else
                {
                    mayor = mayorDe35;
                }


                for(i=mayor; i>0; i--){
                    if(i<10){
                        printf("%02d|",i);
                    }
                    else
                        printf("%02d|",i);

                    if(i<= hasta18){
                        printf("*");
                    }
                    if(i<= de19a35){
                        flag=1;
                        printf("\t*");
                    }
                    if(i<= mayorDe35){
                if(flag==0)
                    printf("\t\t*");
                if(flag==1)
                    printf("\t*");

                    }
                    printf("\n");
                }
                printf("--+-----------------");
                printf("\n  |<18\t19-35\t>35");
                printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
                printf("\n\n");






                break;
        }
   }

    return 0;
}
