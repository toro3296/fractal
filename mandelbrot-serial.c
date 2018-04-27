#include "global.h"


int mandel(float c_re, float c_im, int count){
    float z_re = c_re, z_im = c_im;
    int i;
    for (i = 0; i < count; ++i) {

        if (z_re * z_re + z_im * z_im > 4.f)
            break;

        float new_re = z_re*z_re - z_im*z_im;
        float new_im = 2.f * z_re * z_im;
        z_re = c_re + new_re;
        z_im = c_im + new_im;
    }

    return i;
}

//
// MandelbrotSerial --
//
// Compute an image visualizing the mandelbrot set.  The resulting
// array contains the number of iterations required before the complex
// number corresponding to a pixel could be rejected from the set.
//
// * x0, y0, x1, y1 describe the complex coordinates mapping
//   into the image viewport.
// * width, height describe the size of the output image
// * startRow, totalRows describe how much of the image to compute
void mandelbrotSerial(
    float x0,//-2
    float y0,//-1
    float x1,//1
    float y1,//1
    int width,//1200
    int height,//800
    int startRow,//0
    int totalRows,//800
    int maxIterations,//256
    int output[]) {
		
    float dx = (x1 - x0) / width;//0,0025
    float dy = (y1 - y0) / height;//0,0025

    int endRow = startRow + totalRows;//800

    for (int j = startRow; j < endRow; j++) {
        for (int i = 0; i < width; ++i) {
            float x = x0 + i * dx;
            float y = y0 + j * dy;

            int index = (j * width + i);
            output[index] = mandel(x, y, maxIterations);
        }
    }
}
