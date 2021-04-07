#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <complex.h>
#include "wav.h"

#define N 100000
#define PI 3.14159265

float* convolve(float x[], float h[], int xlen, int hlen, int * ylens) {
  //float x[] = {1, 1, 1};
  //float h[] = {1, 1, 1};
  //int xlen = sizeof(x)/sizeof(x[0]);
  //int hlen = sizeof(h)/sizeof(h[0]);
  int ylen;
  ylen = xlen + hlen - 1;
  float *y = malloc(ylen);
  int i,j, k;
  float yval;
  for (i=0;i < ylen; i++) {
    k = i;
    yval = 0.00;
    for (j = 0; j <xlen; j++) {
      if (k >=0)  {
        if (k < hlen) {
        yval += h[k]*x[j];
        }
      }
      k = k-1;
      y[i] = yval;
    }
  }
  (*ylens) = ylen;
  return y;

}

int create_csv(char *filename, float a[],int m){

  printf("\n Creating %s.csv file",filename);
  int p;
  filename=strcat(filename,".csv");
  FILE *fp=fopen(filename,"w");
  //fprintf(fp,"Output");

  for(p=0;p<m;p++){
    //fprintf(fp,"\n%d",p+1);
    fprintf(fp,"%f \n",a[p]);
    }

  fclose(fp);
  printf("\n %sfile created \n",filename);
  return 0;
}

float complex *DFT(float complex data[], int dlen){

   int n, k;
   //float data[N];
   int i, j;
   float real, imag;
   //float complex *output = malloc(dlen);
   float complex *output = (float complex*)malloc(sizeof(float complex*) * dlen);
   for (n=0; n < dlen; n++) {
     real = 0;
     imag = 0;
     for (k = 0; k < dlen; k++) {
      real += creal(data[k] * (cos(2*PI*n*k/dlen) -I * sin(2*PI*n*k/dlen)));
      imag -= cimag(data[k] * (cos(2*PI*n*k/dlen) -I * sin(2*PI*n*k/dlen)));
    }
    float complex z = CMPLX(real, imag);
    output[n] = z;
   }
   /*
   for (i = 0; i <dlen; i++) {
     printf("%f %f\n", real[i], imag[i]);
   }
   */
   return output;
}

void _fft(float complex buf[], float complex out[], int n, int step)
{
  int i;
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);

		for (i = 0; i < n; i += 2 * step) {
			float complex t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}

float complex* fft(float complex buf[], int n)
{
  int i;
  int j;
	float complex *out = (float complex*)malloc(sizeof(float complex*) * n);
	for (i = 0; i < n; i++) {
    out[i] = buf[i];
  }
	_fft(buf, out, n, 1);
  for (j = 0; j < n; j++) {
    out[i] = buf[i];
  }
  return out;
}


void show(const char * s, float complex buf[]) {
	printf("%s", s);
	for (int i = 0; i < 8; i++)
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else
			printf("(%g, %g) ", creal(buf[i]), cimag(buf[i]));
}



float* choose_channel(float** x, int len, int side) {
  //float x[] = {1, 1, 1};
  //float h[] = {1, 1, 1};
  //int xlen = sizeof(x)/sizeof(x[0]);
  //int hlen = sizeof(h)/sizeof(h[0]);
  int i;
  //float y[len];

  float *y = (float *)malloc(sizeof(float *) * len);
  for (i=0;i <len;i++) {
    if (side == 0) {
      y[i] = x[i][0];
    }
    else {
      y[i] = x[i][1];
    }
  }
  return y;

}

float* choose_complex(float** x, int len, int side) {
  //float x[] = {1, 1, 1};
  //float h[] = {1, 1, 1};
  //int xlen = sizeof(x)/sizeof(x[0]);
  //int hlen = sizeof(h)/sizeof(h[0]);
  int i;
  //float y[len];

  float *y = (float *)malloc(sizeof(float *) * len);
  for (i=0;i <len;i++) {
    if (side == 0) {
      y[i] = x[i][0];
    }
    else {
      y[i] = x[i][1];
    }
  }
  return y;

}
