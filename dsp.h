#include <complex.h>

float* convolve(float x[], float h[], int xlen, int hlen, int * ylens);
int create_csv(char *filename, float a[],int m);
float complex *DFT(float data[], int dlen);
float* choose_channel(float** x, int len, int side);
void fft(float complex buf[], int n);
float complex* _fft(float complex buf[], float complex out[], int n, int step);
void show(const char * s, float complex buf[]);
