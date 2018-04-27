#ifndef _CRONO_H_
#define _CRONO_H_

/*
*  Para medir, incluya el siguiente trozo de código:

  	gettimeofday(&startTime, NULL);
  	//BLOQUE A MEDIR
  	gettimeofday(&endTime, NULL);
  	deltaTime = delta_time(startTime, endTime);

*  Las variables 'startTime', 'endTime' y 'deltaTime' deben
*  estar previamente definidas de la siguiente forma:

    struct timeval startTime, endTime;
    long deltaTime;

*  Usted puede utilizar otras de ser necesario
*  (pueden ser globales o locales, según su diseño)
*/

long delta_time(struct timeval startTime, struct timeval endTime);


#endif
