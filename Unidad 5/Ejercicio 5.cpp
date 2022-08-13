/*Ejercicio 5
Realizar un programa que mediante funciones recursivas permita:
a) Generar una lista enlazada de números enteros positivos, ordenada en forma ascendente. Validar la entrada.
b) Escribir un mensaje indicando si el número del último nodo de la lista es par. */

#include <stdio.h>
#include <malloc.h>

struct nodo{
	int numero;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &lista){
	lista=NULL;	
}

void insertar(puntero &cz){
	puntero xnue,anterior,aux;
	int xdato;
	
	printf("Ingrese un numero entero positivo finalice con 0\n");
	scanf("%d",&xdato);
	
	if (xdato!=0){
	
	if(xdato>0){
		xnue=(puntero)malloc(sizeof(struct nodo));
		xnue->numero=xdato;
		if(cz==NULL){
			cz=xnue;
			xnue->sig=NULL;
		}
		else{
			if(cz->numero>xdato){
				cz=xnue;
				
			}
			else{
				aux=cz->sig;
				anterior=cz;
				while((aux!=NULL)&&(aux->numero < xnue->numero)){
					anterior=aux;
					aux=aux->sig;
				}
				anterior ->sig=xnue;
				xnue->sig=aux;
			}
		}
	}
	else printf("El numero ingresado es incorrecto\n");
	insertar(cz);
}
}

void indica(puntero cz)
{
	if(cz!=NULL){
		if(cz->sig!=NULL){
			cz=cz->sig;
			indica(cz);
		}
		else {
		if(((cz->numero)%2)==0){
			printf("El ultimo numero de la lista si es PAR\n");
		}
		else printf("El ultimo numero de la lista no es PAR\n");		
	}	
}
}
/*
void par(puntero ca){
if(ca==NULL){
return;
}
	else{	
	if(ca->sig == NULL){
	if(ca->nro % 2 == 0){
	printf("El ultimo nodo es par\n");
}else{
printf("El ultimo nodo no es par\n");
}
}
	par(ca->sig);
}
}*/
void mostrar(puntero cz){
	if(cz!=NULL){
		printf("%d\n",cz->numero);
		cz=cz->sig;
		mostrar(cz);
	}
}

int main(){
	
	puntero list,nuevo;
	int dato;
	
	crear(list);
	insertar(list);
	indica(list);
	mostrar(list);	
	
	
}


/*// Ejercicio 5
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
}*/
