/*Ejercicio 8
La UNSJ todos los años otorga becas, para lo cual se ingresa el número de facultades participantes, de las misma se 
ingresan los nombres y de cada una las inscripciones de los alumnos aspirantes a las becas de ayuda económica. Se 
ingresa, en forma ordenada por facultad, los datos de cada alumno: Nombre, promedio y año que cursa. 
Se pide, un programa que permita: 


a) Realizar un listado ordenado por promedio, de los alumnos inscriptos en una determinada facultad cuyo nombre 
se ingresa por teclado. (Mostrar nombre del alumno, promedio y año que cursa). 

b) Indicar el nombre de la facultad que tiene menos inscriptos y la cantidad de inscriptos suponer único).

c) Mostar por cada facultad la cantidad de alumnos con promedio mayor o igual a 7, que cursan de segundo año en 
adelante. Usar una función recursiva.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef char cadena[30];
struct nodo{
	cadena nombre;
	float prom;
	int ano;
	struct nodo *sig;
	
};
typedef nodo *puntero; 
struct facultad {
	cadena nom_fac;
	puntero nodo;
};

void  Carga_facu(facultad *&f,int N,int i){
	if(i<N){
		printf("Ingrese el nombre de la facultad %d\n",i+1);
		fflush(stdin);
		gets(f[i].nom_fac);
		Carga_facu(f,N,i+1);
	}
}
void Crear(facultad *&f,int N,int i){
	if(i<N){
		f[i].nodo=NULL;
	}
}
void Carga_nodo(facultad *&f,int N,int i)
{
	float prom;
	puntero nuevo,anterior,p;
	if(i<N){
		printf("Ingrese el promedio del alumno (finalice con 0)de la facultad %d\n",i+1);
		scanf("%f",&prom);
		if(prom!=0){
			nuevo=(puntero)malloc(sizeof(struct nodo));
			nuevo->prom=prom;
			printf("Ingrese el nombre de el alumno\n");
			fflush(stdin);
			gets(nuevo->nombre);
			printf("Ingrese el año en el que cursan\n");
			scanf("%d",&nuevo->ano);
			
			nuevo->sig=NULL;
			if(f[i].nodo==NULL){
				f[i].nodo=nuevo;	
				Carga_nodo(f,N,i);
			}
			else{
				nuevo->sig=f[i].nodo;
				f[i].nodo=nuevo;
				Carga_nodo(f,N,i);
			}
		}
		else{
			Carga_nodo(f,N,i+1);
		}
	}
		
}	

int Buscar(facultad *f,int i,int N,cadena facul){
	if(i<N || f[i].nom_fac != facul){
			return 1 + Buscar(f,i+1,N,facul);			
		}
		else return 0;
}
void Ordenar (puntero &xp){

puntero k=NULL,cota=NULL,p;
cadena aux;
float aux2;
int aux3;


    while (k!=xp){

        k=xp;
        p=xp;
       
        while (p->sig!=cota){
                
            if (p->prom<p->sig->prom){
                
                strcpy(aux,p->sig->nombre);
                strcpy(p->sig->nombre,p->nombre);
                strcpy(p->nombre,aux);
                aux2=p->sig->prom;
                p->sig->prom=p->prom;
                p->prom=aux2;
                aux3=p->sig->ano;
                p->sig->ano=p->ano;
                p->ano=aux3;

                k=p;
                
            }
      
        p=p->sig;        
        }
       
        cota=k->sig;
        
    }
    
    
}
void Listar(puntero xp){
	if(xp==NULL){
		printf("%s\n",xp->nombre);
		printf("%f\n",xp->prom);
		printf("%d\n",xp->ano);
		Listar(xp->sig);
	}
}

int main(){
	facultad *facu;
	int num,pos;
	cadena fac;
	
	printf("Ingrese el numero de facultades\n");
	scanf("%d",&num);
	facu=(facultad*)malloc(num*sizeof(facultad));
	//inciso 1 
	Carga_facu(facu,num,0);			
	Crear(facu,num,0);
	Carga_nodo(facu,num,0);
	printf("Ingrese un nombre de facultad \n");
	fflush(stdin);
	gets(fac);
	pos=Buscar(facu,0,num,fac);
	if(pos==num){
		printf("Facultad no encontrada\n");
	}
	else{
		Ordenar(facu[pos].nodo);
		Listar(facu[pos].nodo);
	}
	
		//inciso 2
		
}
