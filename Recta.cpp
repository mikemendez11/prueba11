
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
const int ANCHO = 720, ALTO = 720;


float _A, _B, _C;
/*****************************************************************************************************************************/    
void dibujarLinea( int moverX, int moverY, int dibujarX, int dibujarY, int color, int textoX, int textoY, char *nombre ) {
    moveto   ( moverX, moverY );
    setcolor ( color );
    lineto   ( dibujarX, dibujarY );
    outtextxy( textoX, textoY, nombre );
}
/*****************************************************************************************************************************/  
void dibujarRecta ( float A, float B, float C ){
	float x, y;
	for ( x = -360; x <= 360; x += 0.01 ) {
		y = ( - C - ( A * x ) ) / B;
		putpixel( 360 + x , 360 - y , YELLOW );
	}
}
/*****************************************************************************************************************************/  
void pintarPlano ( ) {
	
	initwindow( ANCHO, ALTO );
	
	
    dibujarLinea( 0, ALTO / 2, ANCHO, ALTO / 2, WHITE, ANCHO - 20, ALTO / 2 + 10, "X" );
    dibujarLinea( ANCHO / 2, 0, ANCHO / 2, ALTO, WHITE, ANCHO / 2 + 10, 0, "Y" );
}
/*****************************************************************************************************************************/  
int main() {
	cout << " Grafica de la Recta" << endl;
    cout << " Formula Ax + By + C = 0 " << endl;
	cout << " Ingrese A: ";
	cin  >> _A;
	cout << " Ingrese B: ";
	cin  >> _B;
	cout << " Ingrese C: ";
	cin  >> _C;
	pintarPlano();
	dibujarRecta( _A, _B, _C );
	getch();
	closegraph();
}

