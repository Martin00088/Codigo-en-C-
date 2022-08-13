/*Ejercicio 6
El Proyecto Internacional de Código de Barras de la Vida (iBOL, del inglés 
International Barcode of Life Project) tiene 
como objetivo la obtención de las “huellas genéticas” de las especies en peligro de
 extinción. Para ello se registra toda 
la fauna y flora con el fin de constituir una base de datos global que pueda ser
 consultada por la comunidad científica 
de todo el mundo. En particular se registrará información de los países de Argentina,
 Brasil y Estados Unidos, 
conociendo de los mismos: país, continente y especies. De cada especie en peligro
 de extinción se registra: nombre, 
nombre científico, reino (animal/fauna o vegetal/flora) y cantidad de ejemplares.
Realizar un programa en C que a través de funciones óptimas permita:
a) Generar un arreglo de lista a través de punteros con los datos de las especies
 en extinción para los países indicados. 
El ingreso de información se encuentra ordenada por país. Para cada país el ingreso
 de información finaliza con el 
nombre de la especie igual a FIN. 

b) Para un nombre de país ingresado por teclado, realizar una función que devuelva
 al programa principal la cantidad 
de especies de la flora y cantidad de especies de la fauna en peligro de extinción.
 Realizar una función recursiva 
que devuelva un dato por parámetro y el otro que lo calcule la función.

c) Incrementar en 200 ejemplares la cantidad de la especie con nombre 
Petiribí (árbol) en Brasil.

d) Indicar en el programa principal cantidad de ejemplares de Petiribí
(árbol presente en Argentina y Brasil) 
considerar solamente los ejemplares de los países indicados.
Nota: Para los distintos países se registra una sola vez las distintas especies.

*/
//EJERCIO 6//ejercicio 6 Garcia Sebastian
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 3

typedef char cadena[50];

struct nodo{
        cadena nombre;
        cadena ncientifico;
        cadena reino;
        int cant;
        nodo *sig;
};

typedef struct nodo *puntero;

struct lugares{
        cadena pais;
        cadena continente;
        puntero cabeza;
};


void Carga(lugares arre[], int i){
        if(i<N){
                puntero nuevo, anterior, p;
                cadena especie;
                printf("Ingresar pais\n");
                fflush(stdin);
                gets(arre[i].pais);
                printf("Ingresar continente\n");
                fflush(stdin);
                gets(arre[i].continente);
                printf("------------------------\n");
                printf("Ingresar especie, finzalizar con FIN\n");
                fflush(stdin);
                gets(especie);
                while(stricmp(especie,"FIN")!=0){
                        nuevo=(puntero)malloc(sizeof(nodo));
                        if(nuevo==NULL){
                                printf("No hay memoria\n");
                        }
                        else{
                                strcpy(nuevo->nombre,especie);
                                printf("Ingresar nombre cientifico\n");
                                fflush(stdin);
                                gets(nuevo->ncientifico);
                                
                                printf("Ingresar reino\n");
                                fflush(stdin);
                                gets(nuevo->reino);
                                
                                printf("Ingresar cantidad de ejemplares\n");
                                scanf("%d", &nuevo->cant);
                                nuevo->sig=NULL;
                                if(arre[i].cabeza==NULL){
                                        arre[i].cabeza=nuevo;
                                }
                                else{
                                        p=arre[i].cabeza;
                                        while(p!=NULL){
                                                anterior=p;
                                                p=p->sig;        
                                        }
                                        
                                anterior->sig=nuevo;                
                                }
                                printf("------------------------\n");
                                printf("Ingresar especie, finzalizar con FIN\n");
                                fflush(stdin);
                                gets(especie);
                                p=arre[i].cabeza;
                                        while(p!=NULL){
                                        if(stricmp(p->nombre,especie)==0){
                                                        printf("Especie ya ingresada, ingresar otra especie\n");
                                                        fflush(stdin);
                                                        gets(especie);
                                                        p=arre[i].cabeza;
                                        }
                                        else
                                        p=p->sig;
                                        }
                        }        
                }
                Carga(arre,i+1);
        }
        return;
}

int cual(lugares arre[],cadena bus){
        int i=0;
        while((i<N)&&(stricmp(arre[i].pais,bus)!=0)){
                i=i+1;
        }
        if(i<N)
                return(i);
        else
                return(-1);
}


int Buscar(lugares arre[],int &flora){
        cadena bus;
        puntero p;
        int acumA=0,i;
        printf("Ingrear pais a buscar\n");
        fflush(stdin);
        gets(bus);
        i=cual(arre,bus);
        if(i==-1)
        printf("No se encontro el pais\n");
        else{
        
                p=arre[i].cabeza;
                while(p!=NULL){
                        if((stricmp(p->reino,"Animal")==0)){
                                acumA=acumA+p->cant;
                        }
                        else{
                        flora=flora+p->cant;        
                        }
                        p=p->sig;
                }
        }
        return(acumA);
}

void cambiar(lugares arre[]){
        cadena nom,pa;
        puntero p;
        int i,nue,k=0;
        printf("\nIngresar pais del cambio\n");
        fflush(stdin);
        gets(pa);
        i=cual(arre,pa);
        if(i==-1)
        printf("Pais no encontrado\n");
        else{
                printf("Ingresar especie a cambiar cantidad de ejemplares\n");
                fflush(stdin);
                gets(nom);
                printf("Ingrese nueva cantidad\n");
                scanf("%d", &nue);
                p=arre[i].cabeza;
                while(p!=NULL){
                        if(stricmp(p->nombre,nom)==0){
                                p->cant=nue;
                                k=1;
                                p=NULL;
                        }
                        else
                        p=p->sig;
                }
                if(k=0)
                printf("Especie no encontrada\n");
        }
        return;
}

int indicar(lugares arre[], cadena es){
        int acum=0,i;
        cadena B={"Brasil"}, A={"Argentina"};
        
        i=cual(arre,B);
        puntero p=arre[i].cabeza;
        while(p!=NULL){
                if(stricmp(p->nombre,es)==0){
                        acum=acum+p->cant;
                }
                p=p->sig;
        }
        i=cual(arre,A);
        puntero a;
        p=arre[i].cabeza;
        while(p!=NULL){
                if(stricmp(p->nombre,es)==0){
                        acum=acum+p->cant;
                }
                p=p->sig;
        }
        return(acum);
}

void Mostrar(lugares arre[]){
        puntero p;
        for(int i=0;i<N;i++){
                p=arre[i].cabeza;
                printf("------------------------------------------\n");
                printf("Pais: %s\n",arre[i].pais);
                printf("Continente: %s\n", arre[i].continente);
                printf("Especies: \n");
                while(p!=NULL){
                        printf("Especie: %s\n",p->nombre);
                        printf("Nombre cientifico: %s\n", p->ncientifico);
                        printf("Reino: %s\n", p->reino);
                        printf("Cantidad de ejemplares: %d\n", p->cant);
                        
                        p=p->sig;
                }
                printf("------------------------------------------\n");
        }
}

int main(){
        int cantAnimal, cantFlora=0;
        lugares arre[N];
        cadena es;
        for(int i=0; i<N;i++){
                arre[i].cabeza=NULL;
        }
        /*printf("Ingresar cantidad de lugares: ");
        scanf("%d", &cantl);
        arre=(lugares)malloc(cantl*sizeof(lugares));*/
        Carga(arre,0);
        Mostrar(arre);
        cantAnimal=Buscar(arre,cantFlora);
        printf("\nCantidad de animales: %d", cantAnimal);
        printf("\nCantidad de flroa: %d", cantFlora);
        cambiar(arre);
        Mostrar(arre);
        printf("Especie a indicar cantidad de ejemplares\n");
        fflush(stdin);
        gets(es);
        printf("Cantidad de ejemplares en Brasil y Argentina: %d",indicar(arre,es));
}


/*
Argentina
America
Perro
Canino
Animal
50
Cocodrilo
Reptil
Animal
68
Petiribi
Arboleaus
Planta
89
FIN
Brasil
America
Mono
Makako
animal
50
Petiribi
Arboleaus
Planta
1
FIN
Estados Unidos
America
Oso
Mamifero
animal
80
Roble
arboleade
planta
5
FIN
Argentina
Brasil
Petiribi
200
Petiribi


*/
