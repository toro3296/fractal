#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define RED   0
#define GREEN 1
#define BLUE  2

int min(int a, int b){
	return(a < b ? a: b);
}

void
writePPMImage(int* data, int width, int height, const char *filename, int maxIterations) {
	uint8_t color[3];
	FILE *fp = fopen(filename, "wb");

    // HEADER ppm
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");

    for (int i = 0; i < width*height; ++i) {

		float map;
		unsigned char result;

		map = 255.0 * pow(min(maxIterations, data[i])/256.0, 0.5);

        result = 255 - (uint8_t)map;

		color[RED]   = result;
		color[GREEN] = result;
		color[BLUE]  = result;

		fwrite(color,1,3,fp);

    }
    fclose(fp);
}
