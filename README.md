Arduino Etch-A-Sketch Project
=============================

Project Overview
----------------

This project uses an Arduino, two rotary encoders, and a TFT display to create a modern twist on the classic Etch-A-Sketch toy. By rotating the encoders, you can control the drawing cursor on the screen to create various shapes and designs. Additionally, this setup allows for color cycling, screen clearing, and displaying a hidden image as a fun "secret" feature.

Components
----------

-   **Arduino Board** (e.g., Uno, Mega)
-   **TFT Display** with SD card reader
-   **SD Card** (formatted and containing `arduino.bmp` image)
-   **Two Rotary Encoders** with push buttons
-   **Connecting Wires**

Pin Configuration
-----------------

| Component | Arduino Pin | Description |
| --- | --- | --- |
| SD Card (CS) | 4 | SD card chip select |
| TFT Display (CS) | 10 | Screen chip select |
| TFT Display (DC) | 9 | Data/Command pin |
| TFT Display (RST) | 8 | Reset pin |
| Encoder 1 (CLK) | 16 | Horizontal control |
| Encoder 1 (DT) | 15 | Horizontal control |
| Encoder 1 (SW) | 14 | Clear screen |
| Encoder 2 (CLK) | 7 | Vertical control |
| Encoder 2 (DT) | 6 | Vertical control |
| Encoder 2 (SW) | 5 | Change color |

Features
--------

-   **Cursor Control**: Rotate encoder 1 to control the horizontal movement and encoder 2 to control the vertical movement.
-   **Color Cycling**: Press encoder 2's button to cycle through 8 preset colors for drawing.
-   **Screen Clear**: Press encoder 1's button to clear the screen and reset the drawing canvas.
-   **Secret Image**: Simultaneously press both encoders to display an image (`arduino.bmp`) loaded from the SD card.

Getting Started
---------------

1.  **Wiring**: Connect the components to the Arduino according to the pin configuration.
2.  **SD Card Setup**: Place an image named `arduino.bmp` on the SD card, ensuring it's compatible with the TFT library.
3.  **Upload Code**: Upload the provided code to the Arduino.
4.  **Run the Sketch**: Power the Arduino, and use the rotary encoders to start drawing on the screen.

Code Explanation
----------------

-   **Setup**: Initializes the TFT display, loads the image from the SD card, and sets up encoder pins.
-   **Loop**: Continuously reads encoder states to move the cursor. If an encoder button is pressed, it triggers color cycling or clears the screen. Pressing both buttons simultaneously displays the secret image.

Troubleshooting
---------------

-   **SD Card Issues**: If the SD card fails to initialize, ensure it's correctly formatted, and `arduino.bmp` is present in the root directory.
-   **Display Issues**: If the display is blank or glitchy, check the wiring and TFT library compatibility.

Libraries Required
------------------

-   `TFT.h`: Provides functions for controlling the TFT display.
-   `SD.h`: Enables access to the SD card.

Future Improvements
-------------------

-   Add more color options for enhanced drawing.
-   Save drawn images to the SD card for future retrieval.
-   Add smoother cursor control by tweaking encoder sensitivity.

This fun Arduino project combines electronics and creativity, perfect for experimenting with rotary encoders and displays! Enjoy bringing your digital Etch-A-Sketch to life!
## Used Resources

https://www.arduino.cc/en/Reference/TFTLibrary

https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/

## Pins
### Left Rotary Encoder

CLK A2
DT A1
SW A0

### Right Rotary Encoder

CLK 7
DT 6
SW 5

### Display

Reset 8
D/C-LD 9
CS-SD 4
CS-LD 10
MOSI 11
SCK 13
MISO 12
