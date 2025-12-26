#pragma once

#ifndef SINE_H
#define SINE_H

#include <juce_audio_basics/juce_audio_basics.h>

class SineWave {
public:
	void prepare(double sampleRate, int numChannels);
	void process(float* output, int numSamples);
	float getAmplitude() const { return amplitude; }
	float getFrequency() const { return frequency; }
	void setAmplitude(const float newAmplitude) { amplitude = newAmplitude; }
	void setFrequency(const float newFrequency) { frequency = newFrequency; }
	void setNumHarmonics(const float newNumHarmonics) { numHarmonics = newNumHarmonics; }

private:
	float amplitude = 0.05f;
	float frequency = 50.0f;
	float phase = 0.0f;
	float numHarmonics = 6;
	float currentSampleRate = 0.0f;
	float timeIncrement = 0.0f;
	float currentTime;
};

#endif SINE_H