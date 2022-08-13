#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef char cadena[30];
struct nodo
{
 int dni;
 struct nodo * sig;
} ;
struct datos /* corresponde a cada tutorial */
{
 int numero;
 cadena titulo;
 struct nodo * ins; /* puntero a una lista de inscriptos*/
};
typedef struct nodo * inscriptos;


void main()
{
int i, n, op;
long d;
datos tutorial[fila]; /* arreglo de tutoriales */ 
printf("\n ********** Cargar de los tutoriales C\n *********");
for (i=0;i<fila;i++)
{
 tutorial[i].numero=1;
 printf("\n Ingrese nombre del tutorial %d :",i+1);
 gets(tutorial[i].titulo);
 crear(tutorial[i]);
}
printf("\n ******** MENU DE OPCIONES ***********\n");
do
{
clrscr();
printf("\n 1- Realizar una inscripción: ");
printf("\n 2- Eliminar una inscripción: ");
printf("\n 3- Mostrar Datos de un tutorial: ");
printf("\n 4- Mostrar tutoriales en los cuales se inscribió una persona : ");
printf("\n 5- Mostrar tutoriales con Datos de Inscriptos : ");
printf("\n 6- Salir del MenúRealizar una inscripción: ");
scanf("%d", &op);
switch (op)
 { case 1: { printf("\n Ingrese numero del tutorial :");
 scanf("%d", &n);
 printf("\n Ingrese DNI :");
 scanf("%d", &d);
 insertar(tutorial[n-1].ins,d);
 break;
 }
 case 2: /*** Completar ***/; break;
 case 3: /*** Completar ***/; break;
 case 4: /*** Completar ***/; break;
 case 5: listar(tutorial) ;
 }
} while (op !=6);
getche();
}

void crear (datos &d)
{
d.ins=NULL;
}
void insertar (inscriptos &xp, int DNI)
{
inscriptos nuevo;
nuevo = (inscriptos) malloc(sizeof(struct nodo));
nuevo->dni=DNI;
nuevo->sig = xp;
xp = nuevo;
return;
}
void listar(datos t[])
{ 
 int i;
 inscriptos xp;
 for(i=0; i< fila; i++)
 { 
 printf("\n **** Datos de Inscriptos en el Tutorial:%3d ****\n", i+1);
 printf("\n TITULO: "); puts(t[i].titulo);
 printf("\n INSCRIPTOS \n ");
 xp= t[i].ins;
 while (xp!= NULL)
 {
 printf("\n %d",xp->dni);
 xp = xp->sig;
 }
 }
}

