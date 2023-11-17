# Ultrasound Envelope Detection

## Description

This repository contains a C++ implementation for ultrasound envelope detection. The program is designed to process beamformed ultrasound RF data, applying a sequence of FFT (Fast Fourier Transform), removal of negative frequencies, IFFT (Inverse Fast Fourier Transform), and calculating the absolute value of the obtained signal.

## Installation

To use this program, first clone the repository and navigate to the project directory:

```bash
git clone https://github.com/yourusername/ultrasound-envelope-detection.git
cd ultrasound-envelope-detection
```

Ensure you have a C++ compiler installed that supports C++11 or later.
Usage

The main functionality is provided through the ultrasoundEnvelope function. Include the header ultrasoundEnvelope.h in your project and link the corresponding source file.

Here's a basic example of how to use the function:

```
#include "ultrasoundEnvelope.h"

int main() {
    std::vector<double> inputSignal = {/* ...input data... */};
    std::vector<double> envelope = ultrasoundEnvelope(inputSignal);
    
    // Use envelope data as needed
    return 0;
}
```

## Contributing

Contributions to enhance the functionality, improve efficiency, or fix bugs are highly welcome. Please feel free to fork the repository and submit pull requests.
License

This project is licensed under the MIT License - see the LICENSE.md file for details.

## Contact Information

For any queries or further discussion related to this project, please reach out to me at ruiesteves97@gmail.com.
