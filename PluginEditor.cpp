#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), 
      processorRef (p),
      gainAttachment (p.apvts, "gain", gainSlider)
{
    gainSlider.setSliderStyle (juce::Slider::LinearVertical);
    gainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    gainSlider.setTextValueSuffix ("dB");
    addAndMakeVisible (gainSlider);
    
    
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds (getLocalBounds().reduced (20));
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
