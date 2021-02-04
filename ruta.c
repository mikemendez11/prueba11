
#include "ruta.h"


void insertar0(int m[][TAM],int fc){
	int i,j;
	for (i=0;i<fc;i++){
		for (j=0;j<fc;j++){
			m[i][j]=0;
		}
    } 
}

void imprimir(int m[][TAM],int fc){
	int i,j;
	printf("\n|x\\y|\t"); 
   for (j=0;j<fc;j++){  
   	    printf("%d\t",j+1);
	}
   printf("\n-----");
   for (j=0;j<fc;j++){  
		printf("--------");
		}
	printf("\n");	
   for (i=0;i<fc;i++){
        printf("| %d |\t",i+1);  	
		for (j=0;j<fc;j++){  
			printf("%d\t",m[i][j]);
			if(j == fc-1){
				printf("\n");
			}
		}
    }
}

void introducir_adya(int g[][2],int m[][TAM],int f){
	int i,x,y;
	for(i=0;i<f;i++){	
	printf("\n__--Introduce las coordenadas de la adyacencia %d--__\n",i+1);
	printf("Introduce x: ");
	scanf("%d", &x);
	printf("Introduce y: ");
	scanf("%d", &y);
	m [x-1][y-1]=1;
	g [i][0]=x;
	g [i][1]=y;
}
}


int buscar(int g[][2],int m[][TAM],int a,int b,int fc,int ax){
	int i,j,d;
	if (m[a-1][b-1]!=1){
		for (i=0;i<fc+1;i++){
			if (g[i][0]==a){
				d=g[i][1];
				return buscar(g,m,d,b,fc,ax);
			}
			
		}
		
	}
	else {
		ax=1;
		return ax;
	}
	
	}
