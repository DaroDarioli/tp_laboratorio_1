/*Laboratorio I
  TP 3
  Olinuck Dario Esteban
*/


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}s_Pelicula;



int menu();
void peliculas_inicializar(s_Pelicula *peliculas,int cant,int valor);
int peliculas_buscarLugarLibre(s_Pelicula *peliculas,int cant,int valor);
int peliculas_buscar(s_Pelicula *peliculas,int cant,char valor[]);
int peliculas_baja(s_Pelicula *peliculas,int cant);
int peliculas_modificar(s_Pelicula *peliculas,int cant);
int peliculas_alta(s_Pelicula *peliculas,int cant);

int peliculas_guardarBIN(s_Pelicula*peli);
int peliculas_generarHTML(s_Pelicula *peliculas,int cant);



