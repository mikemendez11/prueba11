
#include <stdio.h>
#include <stdlib.h>
#include "simplex3.h"

int main(int argc, char *argv[]) {
	
	int i,j,filas,columnas,restric;
    float matriz [TAM][TAM]; 
	
	printf("======Metodo simplex======\n");	
	printf("Introduce el numero de restricciones hay: ");
	scanf("%d", &restric);
	
	filas=restric+1;
	columnas=4+restric;
    
	insertar0(matriz,filas,columnas);	
	introducir_funcion(matriz,filas);                 
	introducir_restriccion(matriz,columnas,restric);		      
    printf("\n__________Tabla Simplex__________\n");
    imprimir(matriz,filas,columnas); 
    int ncolumna=menorC(matriz,filas,columnas);
    int nfila=menorF(matriz,filas,columnas,ncolumna);
    int pivote= matriz[nfila][ncolumna];
    
	printf("El elemnto pivote es %d \n",pivote);
	printf("En la fila %d \n",nfila+1);
	printf("En la columna %d \n",ncolumna+1);
	
	dividirentreP(matriz,columnas,nfila,pivote);
	filanueva(matriz,nfila,ncolumna,columnas,filas);
	
	printf("\nEl resultado de la tabla:\n");
	imprimir(matriz,filas,columnas);
	
   i=0;
    while (i<ncolumna){
    	i=i+1;
	}
	if (i==1){
		j=2;
	}
	else j=1; 
	   
	printf("\nLos resultados de la funcion Z son: ");    
    printf("\n   Resultado de Z: %f",matriz[filas-1][columnas-1]);
    printf("\n   Resultado de x%d: %f",i,matriz[nfila][columnas-1]);
    printf("\n   Resultado de x%d: %d \a",j,0);
	
   
	
	return 0;
}
