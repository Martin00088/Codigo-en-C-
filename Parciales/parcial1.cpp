#include <stdio.h> 

const int H=3;
const int M=3;
const int N=3;

void Precarga(int tu[H][M][N],int h,int m,int n){
	if(h<H){
		if(m<M){
			if(n<N){
				tu[h][m][n]=0;
				Precarga(tu,h,m,n+1);
			}
			else Precarga(tu,h,m+1,0);
		}else Precarga(tu,h+1,0,0);
	}
	
}

int buscar (int tu[H][M][N],char mes[30]){
	if(mes=="Junio"){
		return(0);
	}
	if(mes=="Julio"){
		return(1);
	}
	if(mes=="Agosto"){
		return(2);
	}	
	
}

void Carga(int tu[H][M][N]){
	int hotel,nac,pos;
	char mes[30];
	printf("Ingrese el numero de hotel 1..3 (finalice con 0)\n");
	scanf("%d",&hotel);
	while (hotel!=0 && hotel<4 && hotel>0){
		printf("Ingrese el nombre del Mes \n");
		fflush(stdin);
		gets(mes);
		pos=buscar(tu,mes);
		if(pos!=-1){
			printf("Ingrese la nacionalidad del turista (1:Argentina, 2: Brasil, 3:Otra)\n");
			scanf("%d",&nac);
			tu[hotel-1][pos][nac-1]+=1;
		}
	printf("Ingrese el numero de hotel 1..3 (finalice con 0)\n");
	scanf("%d",&hotel);
	}
}


void Total_tur_mes(int tu[H][M][N]){
	int i,j,m,acum=0;
	for(m=0;m<H;m++){
		for (i=0;i<M;i++){	
			for (j=0;j<N;j++){	
				acum+=tu[m][i][j];
		}
	}
	printf("La cantidad total de turistas que recibio mensualmente para el hotel %d es de %d\n",m+1,acum);
	acum=0;
}
}

void Mayor_tur(int tu[H][M][N]){
	int j,i,hotel,aux,acum,max=-1;
	printf("Ingrese un numero de hotel para saber la nacionalidad de la mayor cantidad de turistas\n");
	scanf("%d",&hotel);
	for(j=0;j<N;j++){
		for(i=0;i<M;i++){
			acum+=tu[hotel-1][i][j];	
		}
		if(tu[hotel-1][i][j]>max){
			max=tu[hotel-1][i][j];
			aux=j;
		}
	}
	printf("La nacionalidad que tiene mayor cantidad de turistas es %d\n",aux+1);
}

void Cant_tur(int tu[H][M][N]){
	char mes[30];
	int i,j,acum,pos;
	printf("Ingrese un nombre de mes para saber la cantidad de turistas\n");
	fflush(stdin);
	gets(mes);
	pos=buscar(tu,mes);
		for(j=0;j<H;j++){
			for(i=0;i<N;i++){
				acum+=tu[j][pos][i];	
		}
	}
	printf("La cantidad de turistas para el mes de %s es de %d\n",mes,acum);
}

int main(){
	int turista[H][M][N],ind;

	
	Precarga(turista,0,0,0);//recursiva	
	Carga(turista);
	
	Total_tur_mes(turista);
	
	Mayor_tur(turista);
	
	Cant_tur(turista);

}
