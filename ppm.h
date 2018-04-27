#ifndef _PPM_H_
#define _PPM_H_

void writePPMImage(
    int* data,
    int width, int height,
    const char *filename,
    int maxIterations);

#endif
