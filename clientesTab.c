
#include "clientesTab.h"

void imprimir(int horas, int matriz[7][TAM]){
	int i,j;   
	printf("\n|     Clientes    | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[0][i]);
    }
    
	printf("\n|      Cajas      | ");
    for (i=0;i<horas;i++){
		printf("%d\t",matriz[1][i]);
    }
    
	printf("\n|Capacidad salidas| ");
    for (i=0;i<horas;i++){
		printf("%d\t",matriz[2][i]);
    }
    
	printf("\n| Salida clientes | ");
    for (i=0;i<horas;i++){
		printf("%d\t",matriz[3][i]);
    }
    
	printf("\n| Cola de espera  | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[4][i]);
    }
    
    printf("\n|      Input      | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[5][i]);
    }
    
	printf("\n|      Output     | ");
	for (i=0;i<horas;i++){
		printf("%d\t",matriz[6][i]);
    }
    
    printf("\n------------");
    for (i=0;i<horas;i++){
		printf("--------");
    }
}

void llenadoDatos(int horas, int horasMatriz[][2],int matriz[7][TAM]){
	int i;
	for(i=0;i<horas;i++){
		printf("\n***********Horario %d***********",(i+1));
		printf("\nIntroduzca la hora de inicio: ");
		scanf("%d", &horasMatriz[i][0]);
		
		printf("Introduzca la hora de fin: ");
		scanf("%d", &horasMatriz[i][1]);
		
		printf("Introduzca el numero de clientes: ");
		scanf("%d", &matriz[0][i]);
		
		printf("Introduzca el numero de cajas abiertas: ");
		scanf("%d", &matriz[1][i]);
	}
	printf("\n******************************\n");
}

void capacidadSalida(int rango, int capaciad, int matriz[7][TAM]){
	int i;
	for (i=0;i<rango;i++){
		matriz[2][i]=matriz[1][i]*capaciad;
    }
}

void salidaClientes(int rango, int matriz[7][TAM]){
	int i;
	if(matriz[0][0]>=matriz[2][0]){
		matriz[3][0]=matriz[2][0];
		matriz[4][0]=matriz[0][0]-matriz[2][0];
	}
	else{
		matriz[3][0]=matriz[0][0];
		matriz[4][0]=0;		
	}
	
	if(rango>1){
		for(i=1;i<rango;i++){
			if(matriz[0][i]+matriz[4][i-1]>=matriz[2][i]){
				matriz[3][i]=matriz[2][i];
		        matriz[4][i]=(matriz[0][i]+matriz[4][i-1])-matriz[2][i];
			}
			else{
				matriz[3][i]=matriz[0][i]+matriz[4][i-1];
	        	matriz[4][i]=0;	
			}
		}
	}
}

void input(int rango, int matriz[7][TAM]){
	int i;
	matriz[5][0]=matriz[0][0];
	
	if(rango>1){
		for(i=1;i<rango;i++){
			matriz[5][i]=matriz[5][i-1]+matriz[0][i];
		}
	}
}

void output(int rango, int matriz[7][TAM]){
	int i;
	matriz[6][0]=matriz[3][0];
	
	if(rango>1){
		for(i=1;i<rango;i++){
			matriz[6][i]=matriz[6][i-1]+matriz[3][i];
		}
	}
}

void recomendacion(int rango, int matriz[7][TAM],int capaciad){
	int caja=0,i,mayor=0,posicion;
	printf("\n\nNOTA: ");
	if (matriz[5][rango-1]>matriz[6][rango-1]){
		
		for (i=0;i<rango;i++){
			if(matriz[4][i]>mayor){
				mayor=matriz[4][i];
				posicion=i+1;
			}
        }
		
		if ((matriz[5][rango-1]-matriz[6][rango-1])>capaciad){
			if((matriz[5][rango-1]-matriz[6][rango-1])%capaciad==0){
				caja=(matriz[5][rango-1]-matriz[6][rango-1])/capaciad;
				printf("Usted necesita %d extras en el horario numero %d.",caja,posicion);
			}
			else{
				caja=((matriz[5][rango-1]-matriz[6][rango-1])/capaciad)+1;
				printf("Usted necesita %d extras en el horario numero %d.",caja,posicion);
			}
		}
		else{
			printf("Usted necesita una caja extra en el horario numero %d.",posicion);
	    }
	}
	else{
		printf("No necesita ninguna caja extra.");
	}
}

