#include <SPI.h>
#include <LightSensor.h>
int LightPin = A2;
int LightThres = 3;
char Light[6];

LightSensor LS(LightPin,LightThres);

void setup() {
  LS.begin();
}

void loop() {
  LS.Light_To_Lux();
  Serial.print("Lux :");
  Serial.println(LS.Value());
  delay(1000);
}
