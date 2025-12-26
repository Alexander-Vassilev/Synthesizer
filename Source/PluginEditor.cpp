#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), numHarmonicsSliderAttachment(processorRef.getState(), "numHarmonics", numHarmonicsSlider)
{
    juce::ignoreUnused (processorRef);

    addAndMakeVisible(numHarmonicsSlider);
    numHarmonicsSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    numHarmonicsSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 30, 30);
    //numHarmonicsSlider.setRange(0, 100, 1);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(600, 400);

    playButton.setHelpText("play audio");
    playButton.setButtonText("Playing");
    playButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);

    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);

    playButton.onClick = [this]() {
        const bool isPlaying = playButton.getToggleState();
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");
    };

    addAndMakeVisible(playButton);
    addAndMakeVisible(harmonicsLabel);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    //g.fillAll(juce::Colours::green);

    g.setColour (juce::Colours::white);
    g.setFont (150.0f);
    //g.drawFittedText ("sin wav", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    //square.setBounds(100, 100, 200, 200);
    numHarmonicsSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 100, 100, 200);
    playButton.setBounds(getWidth() / 2 - 35, getHeight() / 2 + 120, 70, 30);
    harmonicsLabel.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 210, 100, 200);
}
