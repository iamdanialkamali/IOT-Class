
#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE); 
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  // init done
  display.begin();
  dht.begin();
  display.setRotation(2);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.
  display.setContrast(50);
  display.clearDisplay();   // clears the screen and buffer
  
  
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  float h = dht.readHumidity();
  Serial.print(h);
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);

  float hic = dht.computeHeatIndex(t, h, false);

  display.print("Humidity: \n ");
  display.print(h);
  display.print(" %");
  display.print("\n");
  display.print( "Temperature: ");
  display.print("\n");
  display.print(t);
  display.print("°C ");
  display.print("\n");
  display.print(f);
  display.print("°C ");
  display.print("\n");
 
  display.display();
  display.clearDisplay();   // clears the screen and buffer
}
