/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RectifyAudioProcessorEditor::RectifyAudioProcessorEditor (RectifyAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (200, 175);
    
    auto& params = processor.getParameters();
    
    //mix slider
    AudioParameterFloat* mMixParameter = (AudioParameterFloat*)params.getUnchecked(0);
    
    mMixSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mMixSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 15);
    mMixSlider.setRange(mMixParameter->range.start, mMixParameter->range.end);
    mMixSlider.setValue(*mMixParameter);
    addAndMakeVisible(mMixSlider);
    
    mMixSlider.onValueChange = [this, mMixParameter] {*mMixParameter = mMixSlider.getValue(); };
    mMixSlider.onDragStart = [mMixParameter] {mMixParameter->beginChangeGesture(); };
    mMixSlider.onDragEnd = [mMixParameter] {mMixParameter->endChangeGesture(); };
    
    //rectify slider
    AudioParameterFloat* mThresholdParameter = (AudioParameterFloat*)params.getUnchecked(1);
    
    mRectifySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mRectifySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 15);
    mRectifySlider.setRange(mThresholdParameter->range.start, mThresholdParameter->range.end);
    mRectifySlider.setValue(*mThresholdParameter);
    addAndMakeVisible(mRectifySlider);
    
    mRectifySlider.onValueChange = [this, mThresholdParameter] {*mThresholdParameter = mRectifySlider.getValue(); };
    mRectifySlider.onDragStart = [mThresholdParameter] {mThresholdParameter->beginChangeGesture(); };
    mRectifySlider.onDragEnd = [mThresholdParameter] {mThresholdParameter->endChangeGesture(); };
}

RectifyAudioProcessorEditor::~RectifyAudioProcessorEditor()
{
}

//==============================================================================
void RectifyAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    
    g.drawText("Mix", ((getWidth() / 7) * 1) - (30), (getHeight() / 2) - 15, 100, 100, Justification::centred, false);
    g.drawText("Rectify", ((getWidth() / 5) * 2) + (15), (getHeight() / 2) - 15, 100, 100, Justification::centred, false);

}

void RectifyAudioProcessorEditor::resized()
{
    mMixSlider.setBounds(0, 0, 100, 100);
    mRectifySlider.setBounds(100, 0, 100, 100);
}
