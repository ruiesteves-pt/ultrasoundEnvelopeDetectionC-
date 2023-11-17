#pragma once

#include <vector>
#include <complex>

// Constant for Pi, if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// This function performs envelope detection on beamformed ultrasound RF data.
// Parameters:
// - data: A vector of doubles representing the input signal.
// The function follows this sequence:
//		1. FFT via discrete Fourier transform (DFT)
//		2. Removing the negative frequencies
//		3. Inverse FFT via inverse discrete Fourier transform (IDFT)
//		4. Absolute value of the obtained signal
// Returns:
// - A vector of doubles representing the envelope of the input signal.

std::vector<double> ultrasoundEnvelope(const std::vector<double>& data);
