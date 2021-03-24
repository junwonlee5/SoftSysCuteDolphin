#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 10
#define PI 3.14159265

float* convolve(float x[], float h[], int xlen, int hlen) {
  //float x[] = {1, 1, 1};
  //float h[] = {1, 1, 1};
  //int xlen = sizeof(x)/sizeof(x[0]);
  //int hlen = sizeof(h)/sizeof(h[0]);
  int ylen;
  ylen = xlen + hlen - 1;
  float *y = malloc(ylen);
  int i,j, k, l, m;
  y[0] = x[0]*h[0];
  for (i=1;i < ylen; i++) {
    //y[i] = 0;
    if (i > xlen-1) {
      k = xlen-1;
      m = i-(xlen-1);
      if (m > hlen-1) {
        m = hlen;
      }
    }
    else {
      k = i;
      m = 0;
    }
    if (i < hlen-1){
      l = i;
    }
    else {
      l = hlen-1;

    }
    printf("%d \n", k);
    printf("%d \n", m);
    for (j=m;j<l+1; j++) {
      y[i] += x[k-j]*h[j];

    }

  }
  return y;

}

float DFT(float data[]){
   int m, n;
   //float data[N];
   float real[N], imag[N];
   float out[2][N];
   for (m=0; m < N; m++) {
     real[m] = 0;
     for (n = 0; n <N; n++);
      real[m] += data[m] * cos(2*PI*n*m);
      imag[m] -= data[m] * sin(2*PI*n*m);
   }

}

int main() {
  float x[] = {1, 1, 1};
  float h[] = {1, 1, 1};
  int xlen = sizeof(x)/sizeof(x[0]);
  int hlen = sizeof(h)/sizeof(h[0]);
  float *y = convolve(x, h, xlen, hlen);
  //int ylen = sizeof(&y);
  int i;
  for (i = 0; i <5; i++) {
    printf("%f \n", y[i]);
  }
}
