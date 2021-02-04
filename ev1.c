#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define RESTRICCION 3
double funcion[MAX], restricciones[MAX+1][MAX+RESTRICCION];
double independiente[RESTRICCION];
int leeDatos(int *var) {
	int rest,c,i;
	fflush(stdin);
	
	printf("\n numero de variables: ");
	scanf("%d",var);
	
	printf("\n Recuerda que: C1.X1+C2.X2+...+Cn.Xn \n\n");
	for(c=0;c<*var;c++)
	{
		printf(" C%d: ", c+1);
		scanf("%1f",&funcion[c]);
		fflush(stdin);
	}
	
	printf("\n Numero de restricciones: ");
	scanf("%d",&rest);
	
	fflush(stdin);
	
	for(i=0;i<rest;i++)
	{
		printf("Restriccion %d\n",i+1);
		for(c=0;c<*var;c++)
		{
			printf(" C%d: ",c+1);
			scanf("%lf",&restricciones[i][c]);
			fflush(stdin);
		}
		printf("Termino independiente");
		scanf("%lf", &independiente[i]);
		fflush(stdin);
	}
	
	return rest;
}

int main(void)
{
	int rest, var, ni ;
	int i,j,k, columna, renglon, count, cuenta;
	double maximo = 0, menor, aux, mult, temp;
	rest = leeDatos(&var);
	
	
	for(i=0;i<rest;i++)
	for(j=0; j<rest; j++)
	if (i == j)
	restricciones[i][var+j]=1;
	else
	restricciones[i][var+j]=0;
	for(i=0; i<rest;i++)
	restricciones[i][var+rest] = independiente[i];
	
	for(j=0; j<var; j++)
	restricciones[rest][j] = funcion[j] * -1;
	for(j=var; j<rest+var; j++)
	restricciones[rest][j] = 0;
	
	ni=1;
	printf("\n-----------------------------------------");
	printf("\n Tabla %d",ni);
	printf("\n-----------------------------------------\n");
	ni++;
	for(i=0; i<=rest; i++) {
		for(j=0; j<rest+var; j++)
		printf(" %.2lf \t", restricciones[i][j]);
		printf("\n");
	}
	
	do
	{
		
		maximo = abs(restricciones[rest][0]);
		columna = 0;
		for(j=0; j=rest+var; j++)
		{
			if( restricciones[rest][j] < 0 )
			{
				temp = -1 * restricciones[rest][j];
				if( maximo < temp)
				{
					maximo = temp;
					columna = j;
				}
			}
			else
			continue;
		}
		
		count = 0;
		aux = 1e20;
		menor = 1e20;
		for(i=0; i<rest; i++) {
			
			if(restricciones[i][columna] > 0)
			aux = restricciones[i][rest+var] / restricciones[i][columna];
			else 
			count++;
			if( menor > aux ){
				menor = aux;
				renglon = i;
			}
		}
		if(count == rest) {
			printf("Soluci? no encontrada");
			exit(1);
		}
		printf("\n",restricciones[renglon][columna], renglon, columna);
		
		aux = restricciones[renglon][columna];
		for(j=0; j<=(rest+var); j++)
		restricciones[renglon][j] = restricciones[renglon][j] / aux;
		
		for(i=0; i<=rest; i++){
			if( i == renglon )
			continue;
			else{
				aux = restricciones[i][columna] * -1;
				for(k=0; k <= rest+var; k++){
					restricciones[i][k] = (aux * restricciones[renglon][k]) + restricciones[i][k];
					restricciones[i][k];
				}
			}
		}
		printf("\n--------------------------------------");
		printf("\n tabla %d",ni);
		printf("\n--------------------------------------\n");
		ni++;
		for(j=0; i<=rest; i++){
			for(j=0; j<=rest+var; j++)
			printf("%.2lf \t", restricciones[i][j]);
			printf("\n");
		}
		cuenta = 0;
		for(j=0;j<rest+var;j++)
		if(restricciones[rest][j] >= 0)
		cuenta++;
		if(cuenta == rest+var)
		break;
	}while(cuenta);
}
