// FREE PINS: 2, 3, 5, 6, 7
// A0: 14, A1: 15, A2: 16...

#include <SD.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// display pins
#define sd_cs  4
#define cs   10
#define dc   9
#define rst  8

//rotary encoder 1 pins
#define CLK 16
#define DT 15
#define SW 14


//rotary encoder 2 pins
#define CLK_2 7
#define DT_2 6
#define SW_2 5

TFT TFTscreen = TFT(cs, dc, rst);

// initial position of the cursor
int xPos = TFTscreen.width() / 2;
int yPos = TFTscreen.height() / 2;

int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;

int currentStateCLK_2;
int lastStateCLK_2;
unsigned long lastButtonPress_2 = 0;

int colorCycle = 0;
int r[] = {255, 255, 0, 0, 255, 0, 255, 0}, g[] = {255, 0, 255, 0, 255, 255, 0, 0}, b[] = {255, 0, 0, 255, 0, 255, 255, 0};
int amountOfColors = 8;

boolean pressed = false;
boolean pressed_2 = false;

// this variable represents the image to be drawn on screen
PImage image;

void setup() {

  // declare inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(CLK_2,INPUT);
  pinMode(DT_2,INPUT);
  pinMode(SW_2, INPUT_PULLUP);

  Serial.begin(9600);
  
  // initialize the screen
  TFTscreen.begin();

  // make the background black
  TFTscreen.background(0, 0, 0);

  lastStateCLK = digitalRead(CLK);
  lastStateCLK_2 = digitalRead(CLK_2);

  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(sd_cs)) {
    Serial.println(F("failed!"));
    return;
  }
  Serial.println(F("OK!"));

  // now that the SD card can be access, try to load the
  // image file.
  image = TFTscreen.loadImage("arduino.bmp");
  if (!image.isValid()) {
    Serial.println(F("error while loading arduino.bmp"));
  }
}

void loop() {
  currentStateCLK = digitalRead(CLK);
  currentStateCLK_2 = digitalRead(CLK_2);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    // If the DT state is different than the CLK state then
    if (digitalRead(DT) != currentStateCLK) {
      xPos++;
    } else {
      xPos--;
    }
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  if (currentStateCLK_2 != lastStateCLK_2  && currentStateCLK_2 == 1){

    // If the DT state is different than the CLK state then
    if (digitalRead(DT_2) != currentStateCLK_2) {
      yPos--;
    } else {
      yPos++;
    }
  }

  lastStateCLK_2 = currentStateCLK_2;

  xPos = constrain(xPos, 0, 159);
  yPos = constrain(yPos, 0, 127);

  // draw the point
  TFTscreen.stroke(r[colorCycle], g[colorCycle], b[colorCycle]);
  TFTscreen.point(xPos, yPos);
  
  // read the value of the pin, and erase the screen if pressed
  if (digitalRead(SW) == LOW) {
    if (millis() - lastButtonPress > 50) {
      pressed = true;
    }
    lastButtonPress = millis();
  } else {
    pressed = false;
  }
  // read the value of the pin, and change color if pressed
  if (digitalRead(SW_2) == LOW) {
    if (millis() - lastButtonPress_2 > 50) {
     pressed_2 = true;
     colorCycle++;
      if (colorCycle >= amountOfColors) {
        colorCycle = 0; // resets color to first in list if you reach the end of the loop
      }
    }
    lastButtonPress_2 = millis();
  } else if (millis() - lastButtonPress_2 > 200) {
    pressed_2 = false;
  }

  if (pressed && pressed_2) {
    // writes secret image if both rotary encoders are pressed down
    if (image.isValid() == false) {
      return;
    }
    int x = random(TFTscreen.width() - image.width());
    int y = random(TFTscreen.height() - image.height());

    // draw the image to the screen
    if (!SD.begin(sd_cs)) {
      return;
    }
    
    image = TFTscreen.loadImage("arduino.bmp");
    if (!image.isValid()) {
      Serial.println(F("error while loading arduino.bmp"));
    }
    TFTscreen.image(image, x, y);
  } else if (pressed) {
    TFTscreen.background(0, 0, 0); // clears screen
  }

  delay(1);
}
