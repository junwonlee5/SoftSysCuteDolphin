#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include "wav.h"
#include "dsp.h"
#include <time.h>
#include <complex.h>

float complex * create_random_array(int count) {
   int i;
   float complex * a = (float complex*)malloc(sizeof(float complex*) * count);
   for (i=0;i <count;i++) {
     a[i] = CMPLX(rand(), rand());
   }
   return a;

}
int main() {
  // Calculate the time taken by fun()

  int count = 17000;
  float complex *data = create_random_array(count);

  clock_t t;
  t = clock();
  DFT(data, count);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("DFT() took %f seconds to execute \n", time_taken);

  /*
  int count = 6;
  //float complex *data[count] = {1,1,1,1,1,1};
  float complex *data = create_random_array(count);
  float complex *b = fft(data, count);
  int i;
  show("\nFFT : ", b);
  return 0;
  */
}
  //0.541259765625000
