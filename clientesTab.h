
#ifndef __clientesTab_h
#define __clientesTab_h
#define TAM 24
#include <stdio.h>

void imprimir(int horas,int matriz[7][TAM]);

void llenadoDatos(int horas, int horasMatriz[][2],int matriz[7][TAM]);

void capacidadSalida(int rango, int capaciad, int matriz[7][TAM]);

void salidaClientes(int rango, int matriz[7][TAM]);

void input(int rango, int matriz[7][TAM]);

void output(int rango, int matriz[7][TAM]);

void recomendacion(int rango, int matriz[7][TAM],int capaciad);

#endif
