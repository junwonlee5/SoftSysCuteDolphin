#include <stdlib.h>
#include <stdio.h>

float* convolve(float x[], float h[]) {
  size_t xlen = sizeof(x);
  size_t hlen = sizeof(h);
  int ylen;

  ylen = xlen + hlen - 1;
  float *y = malloc(ylen+1);

  int i,j;
  int k;
  for (i=0;i < ylen; i++) {
    y[i] = 0;

    for (j=0;j<hlen; j++) {
      y[i] += x[i-j]*h[j];

    }

  }

  return y;

}

float* fourier_transform(float x[]) {

}

int main() {
  float x[] = {1, 1, 1};
  float h[] = {1, 1, 1};
  float *y = convolve(x, h);
  int ylen = sizeof(y);
  int i;
  for (i = 0; i < ylen; i++) {
    printf("%f \n", y[i]);
  }
}
