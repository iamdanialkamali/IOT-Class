/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMEP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

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
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.println();
    delay(2000);
    
//    long duration, distanceCm, distanceIn;
//   // yek pulse 2us ebteda mifrestim ke motmaen 
//   //bashim az pak shodan pulse haye ghabli
//   //pulse 10us ham marboot be tozihat mode1 hastesh . ke balatar tozih dadam
//   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
//    digitalWrite(TRIG_PIN, LOW);
//    delayMicroseconds(2);
//    digitalWrite(TRIG_PIN, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(TRIG_PIN, LOW);
//    duration = pulseIn(ECHO_PIN,HIGH);
//   
//    // tabdil maghadir be inch va Cm baraye namayesh
//    distanceCm = duration / 29.1 / 2 ;
//    distanceIn = duration / 74 / 2;
//    // khoruji tabe pulsin bayad * sorat moj dar hava beshe ke 340 m/s hastesh
//    // va chon moj ersal va daryaft mishe meghdar 2 barabare meghdar vaghea
//    // mishe!! pas bayad taghsim bar 2 ham beshe ke in meghdar
//    // da vahed cm/mm barabar 29.1 be dast miad. 
//   
//    if (distanceCm <= 0){
//      Serial.println("Out of range");
//    }
//    else {
//   // show distance 
}
}
