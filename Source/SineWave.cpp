#include "SineWave.h"
#include <numbers>

void SineWave::prepare(const double sampleRate, const int numChannels) {
	currentSampleRate = static_cast<float>(sampleRate);
	timeIncrement = 1.0f / sampleRate;
};

void SineWave::process(float* output, int numSamples) {
	for (int sample = 0; sample < numSamples; sample++) {
		output[sample] = 0;
			
		for (int n = 1; n < numHarmonics; n++) {
			output[sample] += (1.0f / static_cast<float>(n)) * amplitude * std::sinf(2.0f * std::numbers::pi_v<float> * n * frequency * currentTime);
		}

		//output[sample] += amplitude * std::sinf(juce::MathConstants<float>::twoPi * frequency * currentTime[channel]);
		currentTime += timeIncrement;
	}
};