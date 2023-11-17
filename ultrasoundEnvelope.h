#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// This function performs envelope detection on beamformed ultrasound RF data.
// It follows the sequence:
//		1. FFT via discrete Fourier transform (DFT)
//		2. Removing the negative frequencies
//		3. Inverse FFT via inverse discrete Fourier transform (IDFT)
//		4. Absolute value of obtained signal

vector<double> ultrasoundEnvelope(vector<double> data);
