#pragma once

#include "PluginProcessor.h"
#include "Square.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;
    Square square;

    juce::TextButton playButton;
    juce::Slider numHarmonicsSlider;
    juce::Slider frequencySlider;
    juce::Label harmonicsLabel {"harmonicsLabel", "Harmonics Label"};
    juce::Label frequencyLabel {"frequencyLabel", "Frequency Label"};
    juce::AudioProcessorValueTreeState::SliderAttachment numHarmonicsSliderAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment frequencySliderAttachment;
    juce::AudioProcessorValueTreeState::ButtonAttachment playButtonAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
