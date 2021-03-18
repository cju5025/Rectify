#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class RectifyAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    RectifyAudioProcessorEditor (RectifyAudioProcessor&);
    ~RectifyAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    Slider mMixSlider;
    Slider mRectifySlider;
    
    RectifyAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RectifyAudioProcessorEditor)
};
