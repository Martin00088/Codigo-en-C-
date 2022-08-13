/*Ejercicio 4
Un video club procesa diariamente el archivo “TITULOS.DAT”. Este archivo almacena la información para cada película:
Código de la película (de 1 a 1500), Título, Director y Cantidad de ejemplares disponibles en alquiler. El archivo no
tiene un orden particular.
Se pide realizar un programa óptimo que a través del uso de funciones genere un menú de opciones que responda a
las siguientes solicitudes:

a) Listar por cada película, el título y la cantidad de películas disponibles.

b) Dado el código de una película, mostrar el título y la cantidad de películas disponibles.

c) Para un director cuyo nombre se ingresa por teclado, listar el total de películas realizadas por el director y la
cantidad de películas con menos de 2 ejemplares disponibles.

d) Para este ítem, generar una estructura que almacene el código de película y cantidad de ejemplares disponibles
en alquiler de cada una de sus películas.

e) Utilizando esta estructura, codificar una función recursiva que devuelva al programa principal el total de películas
realizadas por el director y la cantidad de películas con menos de 2 ejemplares disponibles

Nota: Antes de resolver, realice un programa que genere el archivo “TITULOS.DAT. Para eso ingrese de manera
desordenada los títulos de las películas que están propuestas en el sitio*/


#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef char cadena[30];

struct peliculas{
	int cod_p,cant_e;
	cadena titutlo;
	cadena director;
};
struct nodo{
	cadena nom_pe,dire;
	int cod_pe,cant_ej;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void Cargar(FILE *archivo){
	int cod;
	peliculas c;
	printf("Ingrese el codigo de la pelicula a cargar (Finalice con 0)");
	scanf("%d",&c.cod_p);
	while(c.cod_p!=0 &&c.cod_p<1501&&c.cod_p>0){
        printf("Ingrese el titulo de la pelicula\n");
        fflush(stdin);
		gets(c.titutlo);
        printf("Ingrese la cantidad de ejemplares pelicula\n");
        scanf("%d",&c.cant_e);
		printf("Ingrese el director de la pelicula\n");
		fflush(stdin);
		gets(c.director);
		fwrite(&c,sizeof(c),1,archivo);
	printf("Ingrese el codigo de la pelicula a cargar (Finalice con 0)");
	scanf("%d",&c.cod_p);
	}
}
void Listar(FILE *archivo){
	peliculas c;
	rewind(archivo);
	fread(&c,sizeof(c),1,archivo)!=0;//Lectura anticipada 
	while(!feof(archivo)){
		printf("----------%s------%d------\n",c.titutlo,c.cant_e);
		fread(&c,sizeof(c),1,archivo);
	}
}
void Listar_codigo(FILE *archi,int codigo)
{
	peliculas c;
	rewind(archi);
	fread(&c,sizeof(c),1,archi)!=0;
	while(!feof(archi)){
		if(codigo==c.cod_p){
			printf("El titulo de la pelicula es %s y la cantidad de ejemplares es %d\n",c.titutlo,c.cant_e);
		}
		fread(&c,sizeof(c),1,archi);
	}
	if(codigo!=c.cod_p){
			printf("El codigo de la pelicula no se encontro\n");
		}
}

void Listar_director(FILE *archi,cadena director,puntero &cz){
	peliculas c;
	puntero nuevo;
	
	rewind(archi);
	fread(&c,sizeof(c),1,archi)!=0;
	while(!feof(archi)){
		if(strcmp(c.director,director)==0){
			nuevo=(puntero)malloc(sizeof(struct nodo));
			strcpy(nuevo->dire,c.director);
			strcpy(nuevo->nom_pe,c.titutlo);
			nuevo->cod_pe=c.cod_p;
			nuevo->cant_ej=c.cant_e;
			nuevo->sig=NULL;
			cz->sig;
}
			if(c.cant_e<2){
				
			}
		}
		fread(&c,sizeof(c),1,archi);
	}


int main(){
	
	FILE *archi;
	int codigo,opcion,Cant1,Cant2;
	cadena director;
	peliculas *d;
	puntero p;
		
	 do{
        printf("1- Listar por cada pelicula, el titulo y la cantidad de peliculas disponibles.\n");
        printf("------------------------------------\n");
        printf("2- Dado el codigo de una pelicula, mostrar el titulo y la cantidad de peliculas disponibles.\n");
        printf("------------------------------------\n");
        printf("3- Total de peliculas realizadas por el director y peliculas con menos de 2 ejemplares.\n");
        printf("------------------------------------\n");
        printf("4- El codigo de pelicula y cantidad de ejemplares disponibles en alquiler de cada una de sus peliculas.\n");
        printf("------------------------------------\n");
        printf("5- Total de peliculas realizadas por el director y la cantidad de peliculas con menos de 2 ejemplares disponibles\n");
        printf("------------------------------------\n");
		printf("6- Fin\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{
                archi=fopen("TITULOS.dat","w");//abrir el archivo en modo lectura
                if(archi==NULL){
                    printf("\nError\n");
                }else{
                Cargar(archi);
                fclose(archi);
                archi=fopen("TITULOS.dat","r");
                if(archi==NULL){
                    printf("\nError\n");
                }else{
				Listar(archi);
			    }
			    fclose(archi);
                break;
            }
            case 2:{
                archi=fopen("TITULOS.dat","r");
                if(archi==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                printf("Ingrese el codigo de una pelicula\n");
                scanf("%d",&codigo);
                Listar_codigo(archi,codigo);
                }
                break;
            }
            case 3:{
                archi=fopen("TITULOS.dat","r");
                if(archi==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                	printf("Ingrese el nombre del director\n");
                	fflush(stdin);
                	gets(director);
               	Listar_director(archi,director,p);
                }
                break;
            }
            case 4:{
                if(archi==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                //Generar(archi,d);
				}
                break;
            }
            case 5:{
                if(archi==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
				//Cant_1=Recursiva(d,Cant_2);
				}
                break;
            }
        } 

    }
	
	
	
}while(opcion!=6);
fclose(archi);
}
