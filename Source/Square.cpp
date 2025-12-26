#include "Square.h"

void Square::paint(juce::Graphics& g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::blue);

    g.setColour(juce::Colours::red);
    g.setFont(20.0f);
    g.drawFittedText("squr wav", getLocalBounds(), juce::Justification::centred, 1);
};

void Square::resized() {
};