//
//  main.cpp
//  MayerFFT
//
//  Created by Andrew Robertson on 10/03/2015.
//  Copyright (c) 2015 Andrew Robertson. All rights reserved.
//

#include <iostream>

#include "Mayer_FFT.c"

void rearranger(const int n, float* buffer) {
    float real[n/2+1];
    float imag[n/2+1];
    for (int i = 0; i <= n/2; i++)
        real[i] = buffer[i];
    for (int i = 1; i < n/2; i++)
        imag[i] = -1*buffer[n-i];
    imag[n/2+1] = 0.f;
    imag[0] = 0.f;
    for (int i = 0; i <= n/2; i++)
        printf("fft[%i]: %f + %f j\n", i, real[i], imag[i]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Simple FFT example using Ron Mayer library\n";
    const int n = 8;
    float buffer[n] = {8,4,8,2,1,3,0};
    
    float real[n];
    float imag[n];
    for (int i = 0; i < n; i++) {
        imag[i] = 0;
        real[i] = buffer[i];
    }
    
    for (int i = 0; i < n; i++)
        printf("buffer [%i] : %f\n", i, buffer[i]);
    
    mayer_realfft(n, &buffer[0]);
    
    printf("\nafter\n");
    
    for (int i = 0; i < n; i++)
        printf("buffer [%i] : %f\n", i, buffer[i]);
    
    printf("\na weird way to arrange the data, let's process that... \n");
    
    rearranger(n, &buffer[0]);
    
    mayer_fft(n, &real[0], &imag[0]);//complex fft
    
    printf("\ncomplex fft call\n");
    for (int i = 0; i < n; i++)
        printf("real[%i] %f : %f\n", i, real[i], imag[i]);

    
    return 0;
}
