sf::Transformable (abstract base class)
|--> sf::Drawable (abstract base class)
     |--> Component (abstract base class)
          |--> AbstractButton
                |--> Button (inherits from AbstractButton)
                |--> ComboBox (inherits from AbstractButton)
                |--> ToggleButton (inherits from AbstractButton)
                |--> CheckBox (inherits from AbstractButton)
                |--> Radio (inherits from AbstractButton)
          |--> Input
          |--> Slider
          |--> ScrollArea
          |--> Panel