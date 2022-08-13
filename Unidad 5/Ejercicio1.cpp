/*Ejercicio 1
Escribir un programa dados 2 vectores de N componentes enteras permita:
a) Calcular el producto escalar (Realizar un subprograma de carga que sea reusable y 
que permita ingresar por 
teclado el tama�o de los arreglos).
b) Generar una nueva estructura con los valores impares contenidos en uno de los
 arreglos (realizar un subprograma 
que solicite memoria para la nueva estructura y la devuelva cargada).
c) Realizar el mapa de memoria con el siguiente lote de prueba, espec�ficamente
 al momento de la carga de un 
vector, creaci�n y carga de la nueva estructura.
vector a={1, 2, 3} 
vector b={4, 5, 6}, 
Nota
El producto escalar es una operaci�n donde al multiplicar dos vectores se obtiene un escalar.
A = (ax,ay), E = (ex,ey) => A � E = ax � ex + ay � ey*/
#include <stdio.h>
#include <malloc.h>


void carga(int *n, int N,int i)
{
if (N>i)
{
printf ("Ingrese el numero %d del vector\n",i+1);
scanf("%d",&n[i]);
carga(n,N,i+1);
}
}
int prodescalar(int *vec1,int *vec2,int N,int i){
	if(i<N){
	return vec1[i]*vec2[i]+ prodescalar(vec1,vec2,N,i+1);
	}
	else return 0;
}

int cuentaimp(int *vec1,int N,int i){
	if(i<N){
		if(vec1[i]%1==0){
		return  1+cuentaimp(vec1,N,i+1);
		}
		else return cuentaimp(vec1,N,i+1);
	}
	else return 0;
}

void cargasubvector(int *vec1,int *subvector,int N,int i,int j){
	subvector=(int*)malloc(comp*sizeof(int));
	if(i<N){
		if(vec1[i]%2!=0){
			subvector[j]=vec1[i];
			cargasubvector(vec1,subvector,N,i+1,j+1);			
		}
		else cargasubvector(vec1,subvector,N,i+1,j);			
		}
}

void mostrar(int *subvector,int N,int i){
	if(i<N){
		printf("%d",subvector[i]);
		mostrar(subvector,N,i+1);
	}
}

int main(){
int *vec1, *vec2,*subvector, comp, cont;
printf("ingrese la cantidad de componentes");
scanf("%d",&comp);
vec1=(int*)malloc(comp*sizeof(int));
vec2=(int*)malloc(comp*sizeof(int));
carga(vec1,comp,0);
carga(vec2,comp,0);

printf("%d",prodescalar(vec1,vec2,comp,0));//recursivo
cont=cuentaimp(vec1,comp,0);

cargasubvector(vec1,subvector,comp,0,0);//recursivo
mostrar(subvector,cont,0);//recursivo
}
