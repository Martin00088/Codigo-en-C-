/*Ejercicio 9
La biblioteca de la facultad cuenta con una cantidad variable de libros de Programación Procedural en calidad de 
préstamo en la sala de lectura que puede modificarse. Una vez prestados los libros, de los cuales se registra el código, 
se confecciona para cada uno una lista de alumnos que están en cola de espera. Por cada alumno se guarda: nombre 
y carrera (LSI, LCC) 
Se pide realizar un programa, que a través de un menú de opciones y mediante el uso de funciones, de respuesta a las 
siguientes situaciones: 
a) Crear una lista de listas inicializadas en NULL. para almacenar la información de los libros

b) Para un código de libro solicitado, insertar un alumno a la cola de espera correspondiente. Usar una función 
recursiva. 

c) Ingresar un nuevo libro para que esté en calidad de préstamo en la biblioteca. 

d) Suponiendo devuelto un libro cuyo código se lee, realizar un préstamo al primer alumno de la lista correspondiente 
y actualizar la misma (Esto es eliminarlo de la lista) 

e) Ingresar un código de libro y una carrera, mostrar los nombres de los alumnos de dicha carrera que están en cola 
de espera. */

#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef char cadena[20];
struct alum{
	cadena nom;
	cadena carrera;
	struct alum *sig;
};
typedef struct alum *alu;
struct libro{
	int cod;
	alum *cabe;
	struct libro *sig;
};
typedef struct libro *punt;
//-------------------------//
void crear(punt &xp){
	xp=NULL;
}
void insertarL(punt &xp,punt nuevo,int n){
	printf("ingrese codigo del libro a cargar____0 (cero)para salir \n");
	scanf("%d",&n);
	if(n!=0){
		nuevo=(punt)malloc(sizeof(struct libro));
		nuevo->cod=n;
		nuevo->cabe=NULL;
		nuevo->sig=xp;
		xp=nuevo;//aculza la cabeza
		insertarL(xp,nuevo,n);
	}
}
void buscaF(alu &p,alu &ant){
	if(p!=NULL){
		ant=p;
		p=p->sig;
		buscaF(p,ant);
	}
}
void insertarAL(alu &xp,alu nuevo,alu ant,alu p,cadena nom){
	printf("ingrese nombre del alumno____'fin',para salir \n");
	fflush(stdin);
	gets(nom);
	if(stricmp(nom,"fin")!=0){
		nuevo=(alu)malloc(sizeof(alu));
		p=xp;
		if(p==NULL){ //si la lista esta vacia
			nuevo->sig=xp;
			xp=nuevo;
		}
		else{
			buscaF(p,ant);
			nuevo->sig=p;
			ant->sig=nuevo;
		}
		strcpy(nuevo->nom,nom);
		printf("ingrese nombre de la carrera (lcc,lsi,tpw)\n");
		fflush(stdin);
		gets(nuevo->carrera);
		insertarAL(xp,nuevo,ant,p,nom);
	}
}
punt buscaL(punt p,int x){
	if((p->cod!= x)&&(p!=NULL))
	p=p->sig;
	return(p);
}
void devolucion(alu &xp){
	alu p;
	p=xp;
	xp=p->sig;
	free(p);
}
void mostrar(alu p,cadena carr){
	if(p!=NULL){
		if(stricmp(p->carrera,carr)==0){
			printf("el alumno %s esta en lista de espera \n");
			
		}
		p=p->sig;
		mostrar(p,carr);
	}
}
void algo(punt &xp){
	punt p;
	int cod;
	cadena c;
	printf("ingrese codigo del libro a mostrar \n");
	scanf("%d",&cod);
	printf("ingrese nombre de la carrera a buscar \n");
	fflush(stdin);
	gets(c);
	p=buscaL(xp,cod);
	if(p==NULL)
		printf("no esta... \n");
	else mostrar(p->cabe,c);
}

main(){
	punt cabe,p,aux2;
	alu aux;
	aux=NULL;
	cadena c={"fin"};
//	struct alum *p;
	int cod;
	crear(cabe);
	insertarL(cabe,aux2,0);
	
	printf("ingrese codigo del libro para agregar al alumno \n" );
	scanf("%d",&cod);
	p=buscaL(cabe,cod);
	insertarAL(p->cabe,aux,aux,aux,c);
	
	printf("ingrese codigo del libro a devolver \n" );
	scanf("%d",&cod);
	p=buscaL(cabe,cod);
	devolucion(p->cabe);
	
	algo(cabe);
}
