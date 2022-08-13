#include <stdio.h>
#include <string.h>

typedef char string[30];
struct empleados{
	string nom_empleado,nom_empresa;
	int DNI,CUIT;
	float suel_neto;
};
void Cargar(FILE *archi){
	empleados em;
	
	printf("Ingrese el nombre del empleado (Finalice con FIN)\n");
	fflush(stdin);
	gets(em.nom_empleado);
	while(strcmp(em.nom_empleado,"FIN")!=0){
	printf("Ingrese el nombre de la empresa\n");
	fflush(stdin);
	gets(em.nom_empresa);
	printf("Ingrese el DNI \n");
	scanf("%d",&em.DNI);
	printf("Ingrese el CUIT \n");
	scanf("%d",&em.CUIT);
	printf("Ingrese el sueldo neto\n");
	scanf("%f",&em.suel_neto);
	fwrite(&em,sizeof(em),1,archi);	
	
	printf("Ingrese el nombre del empleado (Finalice con FIN)\n");
	fflush(stdin);
	gets(em.nom_empleado);
	}
	
}

void Listado(FILE *archi,string nombre){
	empleados em;
	rewind(archi);
	fread(&em,sizeof(em),1,archi)!=0;
	printf("DNI           Nombre        Sueldo\n");
	while(!feof(archi)){
		if(strcmp(em.nom_empresa,nombre)==0){
			printf("%d           %s           %f\n",em.DNI,em.nom_empleado,em.suel_neto);
		}
	fread(&em,sizeof(em),1,archi);
	}
}



void Listar(){
	FILE *archi;
	empleados e;
	string empre;
	float total=0;
	
		if((archi=fopen("EMPLEADOS.dat","r"))==NULL){
		printf("No se ha podido abrir el archivo\n");
	}			
	else{
	rewind(archi);
	fread(&e,sizeof(e),1,archi)!=0;
	printf("******************* LISTADO DE LIQUIDACION *********************\n");
	strcpy(empre,e.nom_empresa);
	while(!feof(archi)){
	printf("Lista de empleados de %s\n",e.nom_empresa);
    Listado(archi,e.nom_empresa);
    printf("Total pagado por %s es de %f\n",e.nom_empresa,total);
	printf("------------------------------------------------\n");
	
	int b=1;
	while(strcmp(empre,e.nom_empresa)==0&& !feof(archi)){
		b+=1;
		fread(&e,sizeof(e),1,archi);
	}
	fread(&e,sizeof(e),b,archi);
	}
	}
	}
	


int main(){
	FILE *archi;
	
	if((archi=fopen("EMPLEADOS.dat","w"))==NULL){
		printf("No se ha podido abrir el archivo\n");
	}	
	else{
		Cargar(archi);
		fclose(archi);
		Listar();
}
}
/*
martin
tele
23
1
900
pablo
tele
1232
23
800
kapo
zaper
200
2
500
FIN
*/