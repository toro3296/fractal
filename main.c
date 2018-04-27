#include "global.h"

#include "check_args.h"
#include "mandelbrot-serial.h"
#include "ppm.h"
#include "crono.h"

/*=============VARIABLES GLOBALES=============*/



/*
*  Función para comparar el cómputo realizado por
*  el código serial y el código multiThread
*
*  Entrada:
*      gold         : matriz con datos obtenidos mediante código serial
*      result       : matriz con datos obtenidos mediante código multiThread
*      width, height: dimensiones de la matriz
*
*  Salida:
*      0 : Hay discrepancia entre las matrices
*      1 : Las matrices son iguales
*/
uint8_t verificar_resultado(int *gold, int *result, int width, int height) {

    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (gold[i * width + j] != result[i * width + j]) {
                printf ("Error en: [%d][%d], Valor Serial : %d, Valor  multiThread: %d\n",
                            i, j, gold[i * width + j], result[i * width + j]);
                return 0;
            }
        }
    }
    return 1;
}

/*
*  Función para realizar un "zoom"
*  en el plano de mandelbrot.
*
*  Entrada:
*      x0,x1,y0,y1   : coordenadas mínimas y máximas del
*                      plano de mandelbrot
*      scale         : número float en el rango [0,1]
*      shiftX, shiftY: número float para mover el plano
*/
void
scaleAndShift(float *x0, float *x1, float *y0, float *y1,
              float scale,
              float shiftX, float shiftY) {

    *x0 *= scale;
    *x1 *= scale;
    *y0 *= scale;
    *y1 *= scale;
    *x0 += shiftX;
    *x1 += shiftX;
    *y0 += shiftY;
    *y1 += shiftY;

}

/*
*   Función pricipal de los threads
*/
void* thread_main(void* param){
	uint32_t th_id;

	th_id  = (intptr_t)param;

	printf("Thread ID: %i\n", th_id);

	pthread_exit(NULL);
}


int main(int argc, char** argv) {
	struct timeval startTime, endTime;
	long deltaTime;

	const unsigned int width = 1200;
    const unsigned int height = 800;
    const int maxIterations = args.NITERACIONES;

    float x0 = -2;
    float x1 = 1;
    float y0 = -1;
    float y1 = 1;

	int* output_serial;

	check_args(argc,argv);


	/* ---EJEMPLO DE ZOOM---*/
	if (args.ZOOM_LEVEL == 2) {
		float scaleValue = .15f;
	    float shiftX = -.986f;
	    float shiftY = .30f;
	    scaleAndShift(&x0, &x1, &y0, &y1, scaleValue, shiftX, shiftY);
	}
	if (args.ZOOM_LEVEL > 2) {
		printf("Nivel de zoom no implementado. Asumiendo ZOOM_LEVEL=1\n");
	}


	output_serial = calloc(width*height, sizeof(int));

	gettimeofday(&startTime, NULL);
	mandelbrotSerial(x0, y0, x1, y1, width, height, 0, height, maxIterations, output_serial);
  	gettimeofday(&endTime, NULL);

  	deltaTime = delta_time(startTime, endTime);

	printf("Conjunto Mandelbrot calculado en %lu[us]\n", deltaTime);

	writePPMImage(output_serial, width, height, args.FILE_OUT, maxIterations);
	printf("Imagen guardada en %s\n", args.FILE_OUT);
	printf("Plano calculado:\nx0:%.3f\nx1:%.3f\ny0:%.3f\ny1:%.3f\n",
		x0, x1, y0, y1);



	free(output_serial);
	return(EXIT_SUCCESS);
}
