
#include "simplex3.h"

void insertar0(float m[][TAM],int f, int c){
	int i,j;
	for (i=0;i<f;i++){
		for (j=0;j<c;j++){
			m[i][j]=0;
		}
    } 
    m [f-1][0]=1; 
}

void imprimir(float m[][TAM],int f, int c){
	int i,j;
   for (i=0;i<f;i++){
		for (j=0;j<c;j++){
			printf(" %f ",m[i][j]);
			if(j == c-1){
				printf("\n");
			}
		}
    }
}

void introducir_funcion(float m[][TAM],int f){
	float zx1,zx2;
	printf("\n------Intruce la funcion a maximizar (Z)------\n");

	printf("Introduce la variable x1: ");
	scanf("%f", &zx1);
	zx1=zx1*-1;
	m [f-1][1]=zx1;
		
	printf("Introduce la variable x2: ");
	scanf("%f", &zx2);
	zx2=zx2*-1;
	m [f-1][2]=zx2;
}

void introducir_restriccion(float m[][TAM],int c,int r){
	printf("\n------Introduce las %d funciones de restriccion------\n",r);
	int i;
	for(i=0;i<r;i++){
		printf("\nIntroduce x1 de la restriccion %d: ",i+1);
		scanf("%f", &m[i][1]);
		
	    printf("Introduce x2 de la restriccion %d: ",i+1);
	    scanf("%f", &m[i][2]);
		
	    printf("Introduce el resultado de la restriccion %d: ",i+1);
	    scanf("%f", &m[i][c-1]);		
		
		m[i][i+3]=1;
	} 
}

int menorC(float m[][TAM],int f,int c){
   float mC=m[f-1][0];
   int noColumna,i;
	for(i= 0; i<c-1; i++){
		if(m[f-1][i] < mC){
			mC = m[f-1][i];
			noColumna=i;
		}			
	}
	return (noColumna);
}

int menorF(float m[][TAM],int f,int c,int noColumna){
	float mF=m[0][c-1];
	int noFila,i;
	float matriz2[f][1];
	
	for(i=0;i<f-2;i++){
		matriz2[i][0]= m[i][c-1]/m[i][noColumna];
		if (matriz2[i][0]<mF){
			mF=matriz2[i][0];
			noFila=i;
		}
	}
	return(noFila);
}

void dividirentreP(float m[][TAM],int c, int noFila,int piv){
    	int i;
    	for(i=0;i<c;i++){
    		m[noFila][i]=m[noFila][i]/piv;
	}
}

void filanueva(float m[][TAM],int noFila,int noColumna,int c,int f){
	int i,j;
	for (i=0;i<noFila;i++){
    	float k=m[i][noColumna];
		for (j=0;j<c;j++){
			m[i][j]=m[i][j]-(k*m[noFila][j]);
			}
	}

    for (i=noFila+1;i<f;i++){
    	float k=m[i][noColumna];
		for (j=0;j<c;j++){
			m[i][j]=m[i][j]-(k*m[noFila][j]);
			}
	}	
}
