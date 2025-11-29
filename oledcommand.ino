#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// we will define the screen dimensions here
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// declaring the connection for SDD1306 display with I2C
#define OLED_RESET -1  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT. &Wire, OLED_RESET);

void setup() {
    Serial.begin(115200); //will begin serial
    delay(500);

    Wire.begin(8, 9); // we are using gpio 8 for SDA and gpio 9 for SCL

    // initilizing display at the I2C address 0x3C
    if(!display.begin(SDD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        while (true) {
            // hanging (dont proceed)
        }
    }

    display.clearDisplay

    // == setting up text properties ==
    display.setTextSize(2);
    display.setTextColor(SDD1306_WHITE);
    display.setCursor(0, 0);

    // == print message ==
    display.println("Hello");
    display.setCursor(0,20); 
    display.println("World");
    
    display.display();
}

void loop() {


}
