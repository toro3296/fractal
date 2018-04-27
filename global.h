#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include <sys/types.h>

struct args_t{
	uint32_t ZOOM_LEVEL;
	char*    FILE_OUT;
	uint32_t NTHREADS;
	uint32_t NITERACIONES;
} args;


#endif
