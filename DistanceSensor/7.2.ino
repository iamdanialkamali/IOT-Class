#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define TRIG_PIN (9)
#define ECHO_PIN (8)
long duration, distanceCm, distanceIn;
#include <Wire.h>
#include <SPI.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
    Serial.begin(9600);
    display.begin();
    display.setContrast(50);
    display.setRotation(2);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.

  display.display(); // show splashscreen
  display.clearDisplay();   
  // put your setup code here, to run once:
 
}

void loop() {
  delay(200);
  display.clearDisplay();   // clears the screen and buffer
  // put your main code here, to run repeatedly:
 // yek pulse 2us ebteda mifrestim ke motmaen 
 //bashim az pak shodan pulse haye ghabli
 //pulse 10us ham marboot be tozihat mode1 hastesh . ke balatar tozih dadam
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN,HIGH);

  
 
  // tabdil maghadir be inch va Cm baraye namayesh
  distanceCm = duration / 29.1 / 2 ;
  distanceIn = duration / 74 / 2;
  // khoruji tabe pulsin bayad * sorat moj dar hava beshe ke 340 m/s hastesh
  // va chon moj ersal va daryaft mishe meghdar 2 barabare meghdar vaghea
    // mishe!! pas bayad taghsim bar 2 ham beshe ke in meghdar
    // da vahed cm/mm barabar 29.1 be dast miad. 
  Serial.println(F("HELLO"));

  if (distanceCm <= 0){
    Serial.println("Out of range");
  }
  else {
    
    Serial.println(distanceCm);
    display.print("DISTANCE: \t"); 
    display.print(distanceCm);
    display.display(); 
 // show distance 
}

}
