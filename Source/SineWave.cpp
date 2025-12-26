#include "SineWave.h"

void SineWave::prepare(const double sampleRate, const int numChannels) {
	currentSampleRate = static_cast<float>(sampleRate);
	timeIncrement = 1.0f / sampleRate;
	currentTime.resize(numChannels, 0.0);
};

void SineWave::process(juce::AudioBuffer<float>& buffer) {
	if (currentTime.size() != buffer.getNumChannels()) {
		return;
	}

	int numHarmonics = 60;

	for (int channel = 0; channel < buffer.getNumChannels(); channel++) {
		auto* output = buffer.getWritePointer(channel);

		for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
			output[sample] = 0;
			
			for (int n = 1; n < numHarmonics; n++) {
				output[sample] += (1.0f / static_cast<float>(n)) * amplitude * std::sinf(juce::MathConstants<float>::twoPi * n * frequency * currentTime[channel]);
			}

			//output[sample] += amplitude * std::sinf(juce::MathConstants<float>::twoPi * frequency * currentTime[channel]);
			currentTime[channel] += timeIncrement;
		}
	}
};