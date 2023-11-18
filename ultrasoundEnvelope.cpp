#include "ultrasoundEnvelope.h"
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

// Manual FFT function
vector<complex<double>> manualFFT(const vector<double>& data) {
    size_t nSamples = data.size();
    vector<complex<double>> fftData(nSamples, 0);
    double twoPiOverN = 2.0 * M_PI / nSamples;

    for (size_t k = 0; k < nSamples; ++k) {
        for (size_t n = 0; n < nSamples; ++n) {
            double angle = twoPiOverN * k * n;
            fftData[k] += data[n] * exp(complex<double>(0.0, -angle));
        }
    }

    return fftData;
}

// Manual IFFT function
vector<complex<double>> manualIFFT(const vector<complex<double>>& data) {
    size_t nSamples = data.size();
    vector<complex<double>> ifftData(nSamples, 0);
    double twoPiOverN = 2.0 * M_PI / nSamples;

    for (size_t n = 0; n < nSamples; ++n) {
        for (size_t k = 0; k < nSamples; ++k) {
            double angle = twoPiOverN * k * n;
            ifftData[n] += (1.0 / nSamples) * data[k] * exp(complex<double>(0.0, angle));
        }
    }

    return ifftData;
}

vector<double> ultrasoundEnvelope(const vector<double>& data) {
    size_t nSamples = data.size();
     
    // FFT step
    vector<complex<double>> fftData = manualFFT(data);

    // Removing negative frequencies
    for (size_t k = nSamples / 2; k < nSamples; ++k) {
        fftData[k] = 0.0;
    }

    // IFFT step
    vector<complex<double>> hilbertMan = manualIFFT(fftData);

    // Take the absolute value
    vector<double> envelope(nSamples);
    for (size_t n = 0; n < nSamples; ++n) {
        envelope[n] = abs(hilbertMan[n]);
    }

    return envelope;
}
