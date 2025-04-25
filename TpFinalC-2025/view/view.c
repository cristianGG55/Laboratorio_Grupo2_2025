#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/includes.h"
int leerEntero(char *msj_pant,bool clear, int minVal, int maxVal, int corteIngreso )
{
	int valor;
	while (true)
	{
		if(clear) 
		  system("cls");
		printf(msj_pant);
		fflush(stdin);
		scanf("%d",&valor);
		if(valor>=minVal && valor<=maxVal)
			return valor;
		if(valor == corteIngreso)
			return corteIngreso;		
	}
	return corteIngreso;// devuelve si no se leyo nada valor de corte
}
/// otras funciones para interaccionar con el usuario.
