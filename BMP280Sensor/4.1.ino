

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

//Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  display.begin();
    display.setContrast(50);
    display.setRotation(2);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.

  display.display(); // show splashscreen
  display.clearDisplay();
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
    display.clearDisplay(); 
    
    display.print("Temperature = \n");
    display.print(bmp.readTemperature());
    display.print(" *C");

    display.print("Pressure = \n");
    display.print(bmp.readPressure());
    display.print(" Pa");

    display.print("Approx altitude = \n");
    display.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    display.print(" m");

   display.display();

    delay(2000);
}
