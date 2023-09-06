- COLORE BACKGROUND DELLA APP

#endif
    // Globals

colore background app:

    g.fillAll (juce::Colours::white);



- COLORE SFUMATURE DEI BOX

/** 
         * Fill the uiBox bounds with a grey color, different shades depending on its order.
         * Write the uiBox name if it needs to.
         */
        void paint(juce::Graphics& g) override
        {
            // Fill the box background in gray shades
            g.setColour(juce::Colours::grey .withAlpha(0.15f)); // 0.05, used until 2023-08-5, is not readable on the Mac
          

- COLORE BACKGROUND NUMERICO
  
  /**
           * Method in charge of drawing the Numerical Display VU-meter, dB or not.
           *
           * \param   g       JUCE graphics context, used to draw components or images.
           * \param   width   Width of the Numerical Display.
           * \param   height  Height of the Numerical Display.
           * \param   level   Current level of the VU-meter.
           */
          void drawNumDisplay(juce::Graphics& g, int width, int height)
          {
              // Centering it
              int x = (getWidth()-width) / 2;
              int y = (getHeight()-height) / 2;
  
          // Draw box.
          g.setColour(juce::Colours::black);
          g.fillRect(x, y, width, height);
          g.setColour(juce::Colours::black);
          g.fillRect(x+1, y+1, width-2, height-2);
        

- COLORE NOME DEGLI SLIDER

/** Draw the name of a vertical or circular slider. */
        virtual void paint(juce::Graphics& g) override
        {
            if (fType == VSlider || fType == Knob) {
                g.setColour(juce::Colours::white);



/** Display the name of the Menu */
        virtual void paint(juce::Graphics& g) override
        {
            g.setColour(juce::Colours::white);



// VUMeter Background
            g.setColour(juce::Colours::lightgrey);
            g.fillRect(x, y, (float)width, (float)height);
            g.setColour(juce::Colours::black);
