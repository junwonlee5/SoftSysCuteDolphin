#include <complex.h>

float* convolve(float x[], float h[], int xlen, int hlen, int * ylens);
int create_csv(char *filename, float a[],int m);
float complex *DFT(float complex data[], int dlen);
float* choose_channel(float** x, int len, int side);
float* choose_complex(float** x, int len, int side);
float complex* fft(float complex buf[], int n);
void _fft(float complex buf[], float complex out[], int n, int step);
void show(const char * s, float complex buf[]);
