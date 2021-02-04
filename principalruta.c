

#include <stdio.h>
#include <stdlib.h>
#include "ruta.h"

int main(){
			
	int a,b,filcol,nodos,adya,r,r2=0,aux=0;
    int matriz [TAM][TAM]; 
    int grafo [TAM][2];
	
	#include <stdio.h>
#include <stdlib.h>
#include "ruta.h"

int main(){
			
	int a,b,filcol,nodos,adya,r,r2=0,aux=0;
    int matriz [TAM][TAM]; 
    int grafo [TAM][2];
	
	insertar0(matriz,filcol);	//rellenar 0
	printf("\n----------Cuantas adyacencias hay?----------\n");
	scanf("%d", &adya);
	introducir_adya(grafo,matriz,adya); 
	imprimir(matriz,filcol);   
	  
	while(r2==0){//inicio while 
	printf("\n-----------Que ruta desea buscar?-----------\n");
	printf("Punto A: ");
	scanf("%d", &a);
	printf("Punto B: ");
	scanf("%d", &b);
	
	r=buscar(grafo,matriz,a,b,filcol,aux);
	if (r==1){
		printf("\n------->SI hay ruta");
	}
	else {
		printf("\n------->NO hay ruta");
	}
	printf("\n\nPara buscar otra ruta oprima 0\nSi desea salir oprima 1:\n\a");
	scanf("%d", &r2);
	}	//fin while 
	printf("\n\n============Ok Vuelva pronto uwu============\a");
	
return 0;
}
