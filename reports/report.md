# Digital Signal Processing in C

## Team Members
Junwon Lee

## Goals

The goal of this project is to create functions in C that are necessary for signal processing, such as convolution and DTFT (Discrete Time Fourier Transform).

The lower bound goal is to create a convolution function and DTFT function. Ideally, the convolution function would take input signal and system function as inputs. The function would convolve these two inputs and return the output signal that can be saved as a new audio file. The DTFT function would take the input signal and output the DTFT of the signal.

If I am successful in achieving this goal, my stretch goal is to apply the functions I use for audio signal processing projects, such as pitch detection or convolution.

## Learning Goals

### Becoming Familiar with writing C code
I am not comfortable writing C code. I hope that by writing these basic signal processing functions I hope to improve my C code writing experience.

### Learning connection between writing C code and signal processing.
I am familiar with and very interested in studying signal processing, and I am very curious about how similar the mathematical concepts in signal processing are relevant to writing efficient code for signal processing functions. For example, I could learn how C can make the calculations more efficient.  

## What I Have Accomplished

### Convolution function
One of my two lower bound goals was to create a convolution function that took two float arrays x[] and h[] and outputted another array y[] that was equivalent to the convolution of x and h, or x * h. In convolution, h[k] is reflected across k axis. Then, we shift the flipped h[k] by m, which we express as h[m-k]. For every shift, we see if x[k] overlaps with h[m-k]. For each overlap, we multiply the overlapping values and sum them up to get the convolution of two arrays x and h, or y[m] where m is the number of shifts. The function convolve takes 5 inputs total: float x[], float h[], int xlen, int hlen, and int ylen.
(For more info about convolution, please look at the resources posted below.)

```C
float* convolve(float x[], float h[], int xlen, int hlen, int * ylens)
```

The main challenge of making convolution function was making sure that the function doesn't operate on index beyond range. This was solved by having limits such that the function knows where arrays x and h end and therefore terminate checking overlaps. The code snippet below demonstrates this logic.

```C
for (i=0;i < ylen; i++) { // for loop occurs until the max shift happens
  k = i;
  yval = 0.00;
  for (j = 0; j <xlen; j++) {
    if (k >=0)  {
      if (k < hlen) { // k must be from 0 to (length of h - 1)
      yval += h[k]*x[j];  // add values to y[i] for every overlap
      }
    }
    k = k-1;
  }
  y[i] = yval; // output y[i]
}

```

I also had annoying experiences in C where I could not calculate the length of the input float arrays x[] and h[] in the function. I had to make Another annoying experience for me was that for some reason in C the function had to return a pointer to the float instead of returning a float.

To prove that the function was working properly, I inputted two arrays x = {1 1 1} and h = {0 0 1 0 0} and checked the output. Ideally it should output {0 0 1 1 1 0 0}. I ran the function and verified that it matched what I expected.



### DTFT Function
The other lower bound goal was to create a DTFT function that took a float array x[] and outputted float complex array, where the row consisted of float complex elements. This was relatively a straight forward operation, where you implement the equation in this code snippet.
(For more info about DTFT, please look at the resources posted below.)
```C
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
```

One thing that made me curious was how slow it was compared to the FFT function, which is more commonly used and faster than the traditional DFT function. I used the standard FFT function already available in C and ran the optimization test.  Figure below shows the runtime of DTFT function vs. input array. Looking at the code, I predicted it would operate in O(n^2) time.

![alt text](https://github.com/junwonlee5/SoftSysCuteDolphin/blob/main/reports/images/Runtime%20of%20DTFT%20function%20vs%20Input%20Array%20Size.png "DTFT Runtime vs. Array Size")

We can see that the runtime grows significantly especially when the input array size goes beyond 15000. I compared this horrible performance with the FFT function already available.  Figure below shows the runtime of FFT function vs. input array.
![alt text](https://github.com/junwonlee5/SoftSysCuteDolphin/blob/main/reports/images/Runtime%20of%20FFT%20function%20vs%20Input%20Array%20Size.png "FFT Runtime vs. Array Size")

Looking at this, I can immediately see that the runtime is much shorter than DTFT's runtime. However, one thing I noticed was that when the array size went beyond 15000 I got memory error.

This made me conclude that although FFT runs much faster than DTFT, DTFT can handle larger array sizes despite the high runtime.

### Saving Array in CSV FILE
I made a create_csv file function that took an array as input and saved an elements inside the array in the csv file.
```C
void create_csv(char *filename, float a[],int m){

  int p;
  filename=strcat(filename,".csv");
  FILE *fp=fopen(filename,"w");

  for(p=0;p<m;p++){
    fprintf(fp,"%f \n",a[p]);
    }

  fclose(fp);
  printf("\nfile created\n");

}
```
### Working with audio files.

I found a snippet of code that parsed WAV files and collected data from it. I modified the code so that the code not only parsed the audio file but also saved audio data in 2D array, where each column represented audio data from each channel (ex) left side & right side of earphones).

I had to write separate function choose_channel so that I can only use 1 channel audio data.
```C
float* choose_channel(float** x, int len, int side) {
  int i;
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
```
I applied my convolution function to audio processing by doing a standard QEA/ESA assignment problem where I tried to simulate sound of cow mooing in my room. I defined my clapping sound, which is close to impulse response, as array h and mooing sound as array x. Theoretically, when I convolve these two arrays it should simulate mooing sound in my room. The audio file was generated with preexisting library make_wav.h & make_wav.c, but unforunately it doesn't sound as good as I thought it would.

```C
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
```

I also succeeded in saving audio file data into csv file using create_csv function.  

I tried to plot DTFT of a sound file with known frequency, but unfortunately I could not get it because I could not make the function save complex numbers in the csv file.

### Header files

I was writing all functions in single file, and it became a hassle to scroll down over and over again. I decided to make header files so that files and functions are more organized. wav.h contains read_wav(), make_wav.h contains write_wav(), dsp.h contains convolve(), create_csv(), DFT(), FFT(), and choose_channel() functions.

### Reflection
I am somewhat satisfied with the progress I made on this project, mainly because I managed to reach the desired MVP. Also, I am happy with how much I feel more comfortable working with C after this project. Through extensive uses of pointers, arrays, and other tools, I feel more comfortable finding errors in my own code. Unfortunately I did not get to save DTFT of audio files in csv file. I also did not get a chance to optimize any of the functions. If I continued working on this project, I would look into ways to save the complex numbers in DTFT in csv file and optimize the functions so that I could either reduce the runtime or allocate more memory to save more data.

### Resources used

**Original code that parses wav file:** http://truelogic.org/wordpress/2015/09/04/parsing-a-wav-file-in-c/ (This was later modified to save the audio data in an array)

**Code that saves audio data into wav file:** https://karplus4arduino.wordpress.com/2011/10/08/making-wav-files-from-c-programs/ (This was used to hear audio data generated from convolution function)

**FFT algorithm:** https://rosettacode.org/wiki/Fast_Fourier_transform#C (This code was used to compare its performance with my DTFT function's performance)

**Convolution Review:** http://www.songho.ca/dsp/convolution/convolution.html (to review convolution)

**DTFT Review:**https://en.wikipedia.org/wiki/Discrete-time_Fourier_transform (to review DTFT)

**External Libraries Used:** complex.h (to output complex numbers for DTFT), wav.h (to parse wav files)




### Links
**Trello:** https://trello.com/b/obZ4Vb82/digital-signal-processing
**Github:** https://github.com/junwonlee5/SoftSysCuteDolphin
