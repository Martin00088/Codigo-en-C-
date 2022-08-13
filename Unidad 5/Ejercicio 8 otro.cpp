#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct nodo{
    char nomb[30];
    float prom;
    int anio;
    struct nodo *sig;
};

typedef struct{
    char nombre[30];
    int cant;
    struct nodo *ins;
}datos;

typedef struct nodo *inscriptos;


void Crear(datos &f);
void Insertar2(inscriptos &xp, char *nbre);
void Listar(datos f[], int N);
void Listar2(inscriptos xp);
void Ordenar (inscriptos &xp);
void Lista_Ordenada(datos f[], int N);
void Menos_Inscriptos(datos f[],int N);
void Cantidad(inscriptos xp,int &cont);
void Lista_Recursiva(datos f[],int i,int N);


int main(){
datos *facultad;
char nbre[30];
int i,N;

    printf("\n Ingrese cantidad de facultades:");
    scanf("%d",&N);
    fflush(stdin);
    facultad=(datos *)malloc(sizeof(datos)*N);

    for(i=0;i<N;i++){
        
        printf("\n Ingrese nombre de facultad:");
        gets(facultad[i].nombre);
        Crear(facultad[i]);
        facultad[i].cant=0;
        printf("\n Ingrese nombre del alumno (FIN para terminar):");
        gets(nbre);

            while(strcmp(nbre,"FIN")!=0){
               
               Insertar2(facultad[i].ins,nbre);
               facultad[i].cant++;
               printf("\n cantidad:%d",facultad[i].cant);
               printf("\n Ingrese nombre del alumno (FIN para terminar):");
               gets(nbre);
            }
    }
    printf("\n");
    Listar(facultad,N);
    printf("\n");
    Lista_Ordenada(facultad,N);
    printf("\n");
    Menos_Inscriptos(facultad,N);
    printf("\n");
    Lista_Recursiva(facultad,0,N);
    free(facultad);
    return 0;
}
void Crear(datos &f){

    f.ins=NULL;
}

void Insertar2(inscriptos &xp, char nbre[]){ 

inscriptos p, nuevo, anterior;
nuevo =(inscriptos)malloc(sizeof(struct nodo));
/*********************************/
    strcpy(nuevo->nomb,nbre);
    printf("\n Ingrese promedio:");
    scanf("%f",&nuevo->prom);
    fflush(stdin);
    printf("\n Ingrese anio de cursado:");
    scanf("%d",&nuevo->anio);
    fflush(stdin);
/*********************************/
nuevo->sig = NULL;
    
    if(xp==NULL) // controla si la lista está vacía
        xp=nuevo;
        
        else{ 
            
            p=xp;
            
                while(p!=NULL){ 
                    
                    anterior=p;
                    p=p->sig;
                }
            
            anterior->sig=nuevo;
        }
    return;
}

void Listar(datos f[], int N){

int i;
inscriptos xp;

    for(i=0;i<N;i++){

        printf("\n Datos del inscripto en la facultad %s",f[i].nombre);
        printf("\n Inscriptos:");
        xp=f[i].ins;

            while(xp!=NULL){

                printf("\n Nombre:%s--Promedio:%2.2f--Cursa:%d anio",xp->nomb,xp->prom,xp->anio);
                xp=xp->sig;
            }
        printf("\n");
    }
}
void Listar2(inscriptos xp){

            while(xp!=NULL){

                printf("\n Nombre:%s--Promedio:%2.2f--Cursa:%d anio",xp->nomb,xp->prom,xp->anio);
                xp=xp->sig;
            }
}
void Ordenar (inscriptos &xp){

inscriptos k=NULL,cota=NULL,p;
char aux[30];
float aux2;
int aux3;


    while (k!=xp){

        k=xp;
        p=xp;
       
        while (p->sig!=cota){
                
            if (p->prom<p->sig->prom){
                
                strcpy(aux,p->sig->nomb);
                strcpy(p->sig->nomb,p->nomb);
                strcpy(p->nomb,aux);
                aux2=p->sig->prom;
                p->sig->prom=p->prom;
                p->prom=aux2;
                aux3=p->sig->anio;
                p->sig->anio=p->anio;
                p->anio=aux3;

                k=p;
                
            }
      
        p=p->sig;        
        }
       
        cota=k->sig;
        
    }
    
    
}
void Lista_Ordenada(datos f[], int N){

int i,posi;
char nbre[30];

    printf("\n Ingrese facultad a ordenar:");
    gets(nbre);

        for(i=0;i<N;i++){

            if(strcmp(f[i].nombre,nbre)==0){
                Ordenar(f[i].ins);
                posi=i;
            }
        }
   Listar2(f[posi].ins);
}
void Menos_Inscriptos(datos f[], int N){

int i,menor=f[0].cant,posi=0;
    
        for(i=1;i<N;i++){

            if(menor>f[i].cant){

                menor=f[i].cant;
                posi=i;
            }
        }

        printf("\n La facultad con menos inscriptos es %s con una cantidad de %d",f[posi].nombre,f[posi].cant);
}
void Cantidad(inscriptos xp,int &cont){

    if(xp!=NULL){

        if((xp->prom>=7) && (xp->anio>=2)){

            cont++;
            Cantidad(xp=xp->sig,cont);    
        
        }
    }

}
void Lista_Recursiva(datos f[],int i, int N){

int c=0;

    if(i<N){

        Cantidad(f[i].ins,c);
        printf("\n Cant. alumnos con prom >= 7 y que cursan de segundo en adelante en %s:%d",f[i].nombre,c);
        Lista_Recursiva(f,i+1,N);    
    }
    else{

        return;
    }
}
