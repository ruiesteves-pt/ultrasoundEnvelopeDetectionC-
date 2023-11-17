#include "ultrasoundEnvelope.h"

using namespace std;

// Manual FFT function
vector<complex<double>> manualFFT(const vector<double>& data) {
    complex<double> i(0, 1.0);

    double nSamples = data.size();
    vector<complex<double>> fftData(nSamples, 0);

    for (double k = 0; k < nSamples; ++k) {
        for (double n = 0; n < nSamples; ++n) {
            fftData[k] += data[n] * exp(-complex<double>(0.0, 1.0) * 2.0 * M_PI * k * n / nSamples);
        }
    }

    return fftData;
}


// Manual IFFT function
vector<complex<double>> manualIFFT(const vector<complex<double>>& data) {
    complex<double> i(0, 1.0);
    double nSamples = data.size();
    vector<complex<double>> ifftData(nSamples, 0);

    for (double n = 0; n < nSamples; ++n) {
        for (double k = 0; k < nSamples; ++k) {
            ifftData[n] += (1.0 / nSamples) * data[k] * exp(i * 2.0 * M_PI * k * n / nSamples);
        }
    }

    return ifftData;
}

vector<double> ultrasoundEnvelope(vector<double> data) {
    double nSamples = data.size();
     
    // FFT step
    vector<complex<double>> fftData = manualFFT(data);

    // Removing negative frequencies
    vector<double> freqPos(nSamples - 2);
    vector<double> freqNeg(nSamples - 2);

    for (int k = 2; k < nSamples; ++k) {
        if (k <= nSamples / 2) {
            freqPos[k - 2] = k;
        }
        else {
            freqNeg[k - 2] = k;
        }
    }

    for (int i = 0; i < freqPos.size(); ++i) {
        fftData[freqPos[i]] = 2.0 * fftData[freqPos[i]];
    }

    for (int i = 0; i < freqNeg.size(); ++i) {
        fftData[freqNeg[i]] = 0.0;
    }

    // IFFT step
    vector<complex<double>> hilbertMan = manualIFFT(fftData);

    // Take the absolute value
    vector<double> envelope(nSamples);
    for (int n = 0; n < nSamples; ++n) {
        envelope[n] = abs(hilbertMan[n]);
    }

    return envelope;

}