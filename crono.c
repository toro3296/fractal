#include "global.h"


/*============FUNCIONES MEDICION DE TIEMPO DE EJECUCIÓN========*/

/*
*  Función para calcular la diferencia de tiempo, en us
*/
long delta_time(struct timeval startTime, struct timeval endTime){
	return ((endTime.tv_sec * 1000000 + endTime.tv_usec) -
			  (startTime.tv_sec * 1000000 + startTime.tv_usec));
}

/*===========FIN FUNCIONES MEDICION DE TIEMPO DE EJECUCIÓN=========*/
