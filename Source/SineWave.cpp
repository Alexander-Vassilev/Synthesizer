#include "SineWave.h"
#include <numbers>

void SineWave::prepare(const double sampleRate, const int numChannels) {
	currentSampleRate = static_cast<float>(sampleRate);
	smoothedFreq.reset(sampleRate, 0.1f);
	smoothedFreq.setCurrentAndTargetValue(getFrequency());
};

void SineWave::process(float* output, int numSamples) {
	float doublePi = 2.0f * std::numbers::pi_v<float>;

	for (int sample = 0; sample < numSamples; sample++) {
		output[sample] = 0;
		float frequency = smoothedFreq.getNextValue();
		float phaseInc = doublePi * frequency / currentSampleRate;
		
		for (int n = 1; n <= numHarmonics; n++) {
			float currFrequency = n * frequency;

			if (true || (currFrequency <= 20000)) {
				float seriesCoefficient = (1.0f / static_cast<float>(n));
				output[sample] += seriesCoefficient * amplitude * std::sinf(n * phase);
			} else {
				break;
			}
		}

		phase += phaseInc;
	}
};