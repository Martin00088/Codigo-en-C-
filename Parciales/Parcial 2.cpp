#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef char cadena[30];

struct nodo{
	int num_r,edad,cod;
	cadena nombre;
	char sex;
	struct nodo *sig;
};

typedef struct nodo *puntero;

struct arreglo{
	cadena nombre ;
	int cantV,cantM;
};

void Crear (puntero &nodo){
	nodo=NULL;
}
void Insertar (puntero &xp){
	int car;
	puntero nuevo;
	printf("Ingrese el numero de carrera(finalice con 0)\n");
	scanf("%d",&car);
	
	while(car!=0 && car<4 && car>0){
		
	
		nuevo=(puntero)malloc(sizeof(struct nodo));
		printf("Ingrese el numero de registro \n");
		scanf("%d",&nuevo->num_r);
		printf("Ingrese el nombre \n");
		fflush(stdin);
		gets(nuevo->nombre);
		printf("Ingrese el sexo (M-V)\n");
		fflush(stdin);
		scanf("%c",&nuevo->sex);
		printf("Ingrese la edad\n");
		scanf("%d",&nuevo->edad);
		
		nuevo->cod=car;
		nuevo->sig=xp;
		xp=nuevo;
		
	printf("Ingrese el numero de carrera(finalice con 0)\n");
	scanf("%d",&car);
	}
}

int Tot_cant(puntero xp,int &cantidad){
	if(xp==NULL){
		return 0;
	}
	else{
		if(xp->edad>30){
			cantidad+=1;
			return 1 + Tot_cant(xp->sig,cantidad);
		}
		else return 1 + Tot_cant(xp->sig,cantidad);
		
	}
	
}

void Cambiar (puntero &xp,cadena nom,int nuevo){
	puntero aux,p;
	p=xp;
	
	while (p!=NULL && strcmp(p->nombre,nom)!=0){
		aux=p;
		p=p->sig;
	}
	if(aux!=NULL){
		aux->cod=nuevo;
		xp=aux;
	}
	else{
		printf("El nombre ingresado no esta en la lista \n");
	}
}

int Buscar (puntero xp){
	if(xp->cod==1){
		return 0;
	}else{
		if(xp->cod==2){
			return 1;
			
		}else return 2 ;
	}
}

void Genera (puntero xp,arreglo arr[3]){
	int pos;
	for(int i=0;i<3;i++){
		arr[i].cantV=0;
		arr[i].cantM=0;
		printf("Ingrese el nombre de la carrera %d:",i+1);
		fflush(stdin);
		gets(arr[i].nombre);
	}
	while(xp!=NULL){
		pos=Buscar(xp);
		if(xp->sex=='V'){
			arr[pos].cantV+=1;
		}else 	arr[pos].cantM+=1;
		xp=xp->sig;
	}
}

void Mostrar (arreglo a[3]){
	for(int i=0;i<3;i++){
		printf("%s\n",a[i].nombre);
		printf("%d\n",a[i].cantV);
		printf("%d\n",a[i].cantM);
	}
}

int main(){
	puntero nodo;
	int cant=0,carrera;
	cadena nombre;
	arreglo arr[3];
	
	
	Crear(nodo);
	Insertar (nodo);	
	Tot_cant(nodo,cant);
	
	printf("Ingrese un nombre de alumno para cambiar\n");
	fflush(stdin);
	gets(nombre);
	printf("Ingrese la nueva carrera\n");
	scanf("%d",&carrera);
	Cambiar(nodo,nombre,carrera);
	
	Genera(nodo,arr);
	Mostrar(arr);
	
}
