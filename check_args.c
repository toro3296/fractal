#include "global.h"

extern char *optarg;
extern int optind, opterr, optopt;

/*
 *		Funcion que imprime en stdout el uso
 *		del programa.
 */
void print_usage(char* name){
	char opciones[] = "-z ZOOM_LEVEL -i NUMERO_ITERACIONES -t NUMERO_THREADS -f FILE_OUT [-h]\n";

	char descripcion[] = "Descripción:\n"
						 "\t-z   Nivel del zoom: 1 (normal), 2(alto)\n"
						 "\t-i	 Numero iteraciones\n"
						 "\t-t	 Numero Threads\n"
						 "\t-f   Archivo PPM de salida\n"
						 "\t-h   Muestra esta salida y termina\n";

	printf("Uso: %s %s\n%s\n", name, opciones, descripcion);
}
/* FIN print_usage()*/

void check_args(int argc , char **argv){
	int opcion;

	char *optString = "z:i:t:f:h";

	args.ZOOM_LEVEL    = 0;
	args.FILE_OUT      = NULL;

	while ((opcion = getopt (argc, argv, optString)) != -1){
		switch (opcion) {
			case 'z':
					args.ZOOM_LEVEL = atoi(optarg);
					break;
			case 'f':
					args.FILE_OUT = malloc(strlen(optarg)*sizeof(char));
					strcpy(args.FILE_OUT, optarg);
					break;
			case 't':
					args.NTHREADS = atoi(optarg);
					break;
			case 'i':
					args.NITERACIONES = atoi(optarg);
					break;
			case 'h':
			default:
					print_usage(argv[0]);
					exit(EXIT_FAILURE);
		}
	}
	printf("zoom  : %i \n",args.ZOOM_LEVEL );
	printf("archivo salida   :%s\n", args.FILE_OUT);
	printf("hilos :%i\n",args.NTHREADS );
	printf("iteraciones   :%i\n", args.NITERACIONES);
	if ( args.ZOOM_LEVEL <= 0 ||
	     args.FILE_OUT   == NULL || args.NITERACIONES <= 0 || args.NTHREADS <= 0) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}
}	

/* FIN check_args()*/
