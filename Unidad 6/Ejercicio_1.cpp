/*
Ejercicio 1
Codificar un programa en C que permita leer un archivo de caracteres cualesquiera e indique cu�l de las cinco vocales
del abecedario tiene mayor frecuencia. Realice un men� de opciones que permita leer:
a) Archivo de caracteres con extensi�n. cpp
b) Archivo de caracteres con extensi�n. dat
c) Archivo de caracteres con extensi�n. txt
*/
#include <stdio.h>

void Generar(int vocales[5],FILE *archivo){
    char aux='a';
        printf("\n-----TEXTO----\n");
        while (aux != EOF){
        aux = fgetc(archivo);
        printf("%c",aux);
        if (aux=='a') vocales[0]++;
            else if(aux=='e') vocales[1]++;
                else if(aux=='i') vocales[2]++;
                    else if(aux=='o') vocales[3]++;
                        else if(aux=='u') vocales[4]++;
    }
    printf("\n-----FIN TEXTO----\n");
}


void maximo(int vocales[5]){
    int max=0,i,indice;
    char voca[5]={'a','e','i','o','u'};
    for(i=0;i<5;i++){
        if(max<vocales[i]){
            max=vocales[i];
            indice=i;
        }

    }
    printf("\nLa vocal '%c' tuvo la mayor frecuencia con %d veces\n",voca[indice],max);
}


int main (){
    FILE *archivo=NULL;
    int opcion, vocales[5]={0,0,0,0,0};
    do{
        printf("\n1- Leer archivo txt\n");
        printf("2- Leer archivo cpp\n");
        printf("3- Leer archivo dat\n");
        printf("4- Vocal con mas frecuencia\n");
        printf("5- Total vocales\n");
        printf("6- Fin\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{
                archivo=fopen("vocales.txt","r");
                if(archivo==NULL){
                    printf("\nError\n");
                }else{
                Generar(vocales,archivo);
                }
                break;
            }
            case 2:{
                archivo=fopen("vocales.cpp","r");
                if(archivo==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                Generar(vocales,archivo);
                }
                break;
            }
            case 3:{
                archivo=fopen("vocales.dat","r");
                if(archivo==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                Generar(vocales,archivo);
                }
                break;
            }
            case 4:{
                if(archivo==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                maximo(vocales);}
                break;
            }
            case 5:{
                if(archivo==NULL){
                    printf("\nNo se ha podido abrir el fichero\n");
                }else{
                printf("\nCantidad de vocales A: %i ", vocales[0]);
                printf("\nCantidad de vocales E: %i ", vocales[1]);
                printf("\nCantidad de vocales I: %i ", vocales[2]);
                printf("\nCantidad de vocales O: %i ", vocales[3]);
                printf("\nCantidad de vocales U: %i \n", vocales[4]);}
                break;
            }
        } 

    }while(opcion!=6);
fclose(archivo);
return 0;
}

