//EJERCIO 6
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 3

typedef char cad [20];

struct nodo{
        cad pais;
        cad n;
        cad nom_c;
        cad reino;
        int cant;
        struct nodo *sig;
};  
typedef struct nodo *puntero;

void Cerear (puntero x[N], int i){
        if (i<N){
                x[i]=NULL;
                Cerear(x, i+1);
        }
}

void insertar(puntero &x, cad p){
  int t;
  char d[20];
  puntero nuevo;
  nuevo->pais==p;
          fflush(stdin);
    printf("Ingrese el nombre de la especie (Termine con la palabra Fin) \n");
    fgets(d,20,stdin);
    while(strcmp(d,"Fin\n")!=0 && strcmp(d,"fin\n")!=0 && strcmp(d,"FIN\n")!=0){
    nuevo=(puntero) malloc(sizeof(struct nodo));
    nuevo->n==d;
    nuevo->sig=x;
    x=nuevo;
    fflush(stdin);
    printf("Ingrese el nombre cientifico del animal  \n");
    fgets(d,20,stdin);
    nuevo->nom_c==d;
    nuevo->sig=x;
    x=nuevo;
    fflush(stdin);
    printf("Ingrese el reino al que pertenece \n");
    fgets(d,20,stdin);
    nuevo->reino==d;
    nuevo->sig=x;
    x=nuevo;
    printf("Ingrese la cantidad \n");
    scanf("%d", &t);
    nuevo->reino==d;
    nuevo->sig=x;
    x=nuevo;
    fflush(stdin);
    printf("Ingrese el nombre de la especie (Termine con la palabra Fin) \n");
    fgets(d,20,stdin);
        }
return;
}

int Busca (cad n, cad p[N]){
  int i;
  while (i<N && strcmp(n, p[i])==0){
  i++;
  }
  return i;         
}

int recorre (puntero &x, int z, int &y){
     if(x==NULL){
             return z;
         }
         else {
                 if(strcmp(x->reino,"fauna")==0){
                         z++;
                 } else if (strcmp(x->reino,"flora")==0){
                 y++;
                 }
                 x=x->sig;
                 return recorre(x, z, y);
         }
}

void aumento (puntero &x) {
          if (x==NULL){
    return;
        }
     else {
          if(strcmp(x->nom_c, "Petiribi")==0){
       x->cant+=200;
     return;
   }
  }
  return;
}

int mostrar (puntero &x) {
         if(x==NULL){
        return 0;
    }
   else        if (strcmp(x->nom_c, "Petiribi")==0){
            x->sig;
          return (x->cant);
     }
}

int main(){
        puntero Cabeza[N];
        int i=0, cantE=0, cantF=0, pos, T, acum=0;
        cad nomp;
        Cerear (Cabeza, i);
        cad p[N]={"Argentina\n", "Brasil\n", "Estados Unidos\n"};
        for (int x=0;x<N;x++){        
        printf("El pais a cargar es %s\n", p[x]);
        insertar(Cabeza[x], p[x]);
    }
    fflush(stdin);
    printf("Ingrese el pais a buscar \n");
    fgets(nomp,20,stdin);
    pos = Busca(nomp, p);
    T = recorre (Cabeza[pos],  cantE, cantF);
    printf("La cantidad de fauna del pais es %d\n", T);
    printf("La cantidad de flora del pais es %d\n", cantF);
    aumento(Cabeza[1]);
       for(int a=0;a<2;a++){ 
     acum += mostrar(Cabeza[a]);
  }
  printf("La cantidad de Petiribi entre Arg. y Bra. es %d\n", acum);
}

Ramiro Elizondo Ejercicio 6
#include <stdio.h>
#include <malloc.h>
#include <string.h>

const char paises[3][20]={"Argentina","Brasil","Estado Unidos"};

struct Extincion{
        char pais[20];
        char nombre[20];
        char nom_cientifico[20];
        char reino[20];
        int cantidad;
};
struct nodo{
        Extincion dato;
        struct nodo *sig;
};
typedef struct nodo *puntero;


void Carga(puntero &cabeza){
        char n[20];
        printf("  Ingrese nombre de la especie: ");
        scanf("%s",&n);
        
        if(stricmp(n,"Fin")==0){
                return;        
        } 
        
        cabeza=(puntero)malloc(sizeof(struct nodo));
        strcpy(cabeza->dato.nombre,n);
        
        printf("\tIngrese el nombre cientifico: ");
        scanf("%s",&cabeza->dato.nom_cientifico);
        
        printf("\tIngrese el reino: ");
        scanf("%s",&cabeza->dato.reino);
        
        printf("\tIngrese cantidad de ejemplares vivos: ");
        scanf("%d",&cabeza->dato.cantidad);
        
        cabeza->sig=NULL;

        Carga(cabeza->sig);
}
int IndexPais(char pais[20]){
        int i;
        for(i=0;i<3;i++){
                if(stricmp(pais,paises[i])==0){
                        return i;
                }
        }
        return -1;
}

int Cantidad(puntero nodo,int &contFauna,int contFlora){
        if(nodo!=NULL){
                if(stricmp(nodo->dato.reino,"Fauna")==0){
                        contFauna++;
                }else if(stricmp(nodo->dato.reino,"Flora")==0){
                        contFlora++;
                }
                return Cantidad(nodo->sig,contFauna,contFlora);
                                
        }else
                return contFlora;
}

void Incremento(puntero listas){
        if(listas==NULL){
                return;
        }
        if(stricmp(listas->dato.nombre,"Petiribi")==0){
                listas->dato.cantidad+=200;
                return;
        }
        Incremento(listas->sig);
}

int Indicar(puntero listas){
        if(listas==NULL){
                return 0;
        }
        if(stricmp(listas->dato.nombre,"Petiribi")==0){
                return listas->dato.cantidad;
        }
        return Indicar(listas->sig);
}

int main(){
        puntero listas[3]={NULL,NULL,NULL};
        char pais[20];
        int contFauna=0, contFlora=0,contador,total;
        for(int i=0;i<3;i++){
                printf("Pais %s\n",paises[i]);
                Carga(listas[i]);
                printf("\n");
        } 
        printf("\nIngrese pais a indicar: ");
        fflush(stdin);
        scanf("%s",&pais);
        contador=Cantidad(listas[IndexPais(pais)],contFauna,contFlora);
        printf("\nFlora en peligro de extincion: %d",contador);
        printf("\nFauna en peligro de extincion: %d\n",contFauna);
        Incremento(listas[1]);
        total=Indicar(listas[0]) + Indicar(listas[1]);
        printf("\nLa cantidad total de Petiribi es: %d",total);
}

//ejercicio 6 Garcia Sebastian
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 3

typedef char cadena[50];

typedef struct nodo *puntero;

struct nodo{
        cadena nombre;
        cadena ncientifico;
        cadena reino;
        int cant;
        nodo *sig;
};



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

// Ejercicio 5
#include <stdio.h>
#include <malloc.h>

struct nodo{
    int dato;
    nodo *sig;
};
typedef struct nodo *puntero; 

void crear(puntero &xp){
        xp=NULL;
}

void carga(puntero &xp){
    int num;
    printf ("Ingrese valor entero, de menor a mayor:\n");
    scanf("%d",&num);
    if(num>0){
        nodo*aux=(nodo*)malloc(sizeof(nodo*));
        aux->sig=xp;
        xp=aux;
        carga(xp);
    }
}

void mostrar(puntero &xp){
    if(xp!=NULL){
        printf("%d\n",xp->dato);
        mostrar(xp->sig);
    }
}

void UltNumero(puntero &xp){
    if(xp!=NULL){
        if((xp-> dato %2)== 0){
            printf("El ultimo numero ingresado, es par\n");
        }
    }
}

int main(){
        puntero cabeza;
        crear(cabeza);
    carga(cabeza);
    mostrar(cabeza);
    UltNumero(cabeza);
}
