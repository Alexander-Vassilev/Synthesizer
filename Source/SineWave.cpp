#include "SineWave.h"
#include <numbers>

void SineWave::prepare(const double sampleRate, const int numChannels) {
	currentSampleRate = static_cast<float>(sampleRate);
	timeIncrement = 1.0f / sampleRate;
};

void SineWave::process(float* output, int numSamples) {
	for (int sample = 0; sample < numSamples; sample++) {
		output[sample] = 0;
			
		for (int n = 1; n <= numHarmonics; n++) {
			float currFrequency = 2.0f * std::numbers::pi_v<float> * n * frequency;

			if (true || (currFrequency <= 20000)) {
				output[sample] += (1.0f / static_cast<float>(n)) * amplitude * std::sinf(currFrequency * currentTime);
			}
			else {
				break;
			}
		}

		//output[sample] += amplitude * std::sinf(juce::MathConstants<float>::twoPi * frequency * currentTime[channel]);
		currentTime += timeIncrement;
	}
};