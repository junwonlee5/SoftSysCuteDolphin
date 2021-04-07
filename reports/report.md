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

## Things I Need to Get started
I need to know if there are any preexisting DSP libraries available. I will find them through googling.

## What I worked on So Far

### Convolution function
One of my two lower bound goals was to create a convolution function that took two float arrays x[] and h[] and outputted another array y[] that was equivalent to the convolution of x and h, or x * h. The function convolve takes 5 inputs total: float x[], float h[], int xlen, int hlen, and int ylen. The main assumption is that both arrays start at index of 0. If users want to show that data starts a little off from 0, they will have to pad the first part of data with 0’s.  The mathematical definition of discrete convolution is (add formula here). The illustration below shows how the formula works.



### DTFT Function
The other lower bound goal was to create a DTFT function that took a float array x[] and outputted 2 * (length of float array) array,where one row consisted of real components of the DTFT and the other consisted of the imaginary component. The mathematical definition of DTFT is (add formula here). This was relatively a straight forward operation, where you implement the equation in this code snippet.

One thing that made me curious was how slow it was compared to the FFT function, which is more commonly used and faster than the traditional DTFT function. I used the standard FFT function already available in C and ran the optimization test.  

### Saving Array in CSV FILE
I made a create_csv file function that took an array as input and saved an elements inside the array in the csv file.



## What to Do Next

### 1. Revise functions so that they take arrays/filenames as arguments
So far, both of the functions have input arrays defined inside the argument rather than taking them as arguments. I will revise the functions so that instead of having pre-defined arrays in the function, it will have arrays as input. This will enable me to further expand on this by letting the function take filename input instead of array input.
**Definition of Done:** Functions will take arrays or files as arguments and use these arguments to return the functions & respective outputs.

### 2. Function saves array in a file.
The function will save the outputs in a file that users can use to either edit or plot the results.
**Definition of Done:** In the main(), while the functions print output arrays, they will also create csv (?) files that contain outputs of those files.

### 3. Use these functions with audio files
I will use these functions with actual audio files. I will create new audio files with convolution and analyze different frequencies in audio files using DTFT. For convolution, this could be the classic QEA problem where we use the clapping sound from a room to model how a music file would sound like in different rooms.
**Definition of Done:** The functions will take audio files as input and save the output array as audio file as well as csv file.

### 4. Optimize functions
I will figure out runtime of each function and see if there is any room for me to optimize function performance.
**Definition of Done:** The easiest way to test this is to plot runtime of original and modified functions with respect to size of array and compare runtime results.

**Trello:** https://trello.com/b/obZ4Vb82/digital-signal-processing
**Github:** https://github.com/junwonlee5/SoftSysCuteDolphin
