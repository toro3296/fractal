#ifndef _MANDELBROT_SERIAL_H_
#define _MANDELBROT_SERIAL_H_

void mandelbrotSerial(
    float x0, float y0, float x1, float y1,
    int width, int height,
    int startRow, int numRows,
    int maxIterations,
    int output[]);
	
#endif
