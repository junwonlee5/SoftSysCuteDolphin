#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include "wav.h"
#include "dsp.h"
#include "make_wav.h"
#include <time.h>
#include <complex.h>

float * create_random_array(int count) {
   int i;
   float * a = (float *)malloc(sizeof(float *) * count);
   for (i=0;i <count;i++) {
      a[i] = rand();
   }
   return a;

}

float complex * create_random_array_comp(int count) {
   int i;
   float complex * a = (float complex*)malloc(sizeof(float complex*) * count);
   for (i=0;i <count;i++) {
     a[i] = CMPLX(rand(), rand());
   }
   return a;

}
int main() {
 /*
  char str[100] = "moo.wav";
  float **read;
  int frequency;
  int read_len;
  int side = 0;
  read = read_wav(str, &frequency, &read_len);
  float *m = choose_channel(read, read_len, side);
  char str1[100] = "voice020.wav";
  float **read1;
  int frequency1;
  int read_len1;
  int side1 = 0;
  read1 = read_wav(str1, &frequency1, &read_len1);
  float *n = choose_channel(read1, read_len1, side1);
  int ylen;
  float *y = convolve(m, n, read_len, read_len1, &ylen);
  int k;
  int p[ylen];
  for (k = 0; k < ylen;k++) {
    p[k] = round(y[k]* 32768);
  }
  char str2[100] = "moomod.wav";
  write_wav(str2, ylen, p, 44100);
  // Calculate the time taken by fun()
*/

  float x[] = {1,0,0,0,0};
  float h[] = {1,1};
  int xlen = sizeof(x)/sizeof(x[0]);
  int hlen = sizeof(h)/sizeof(h[0]);
  int ylen;
  float *y = convolve(x, h, xlen, hlen, &ylen);
  int i;
  for (i = 0; i <ylen;i++){
    printf("%f \n", y[i]);
  }
/*
  int count = 12000;
  float *a = create_random_array(count);
  clock_t t;
  t = clock();
  DFT(a, count);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("fun() took %f seconds to execute \n", time_taken);
  return 0;
  */
}
  //0.541259765625000
