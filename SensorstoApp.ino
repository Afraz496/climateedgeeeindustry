#include <SoftwareSerial.h>// import the serial library
#include <SoftWire.h>
#include <HIH61xx.h>
#include <AsyncDelay.h>
#include <OneWire.h>
#include <DallasTemperature.h>

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off

int inByte = 0;

HIH61xx hih;
AsyncDelay samplingInterval;

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);


void setup() {
  Genotronex.begin(9600);
  hih.initialise(A4, A5);
  samplingInterval.start(3000, AsyncDelay::MILLIS);
  sensors.begin();
}

bool printed = true;
void loop() {
if (Genotronex.available() > 0) {

inByte = Genotronex.read();

}

if (samplingInterval.isExpired() && !hih.isSampling()) {
    hih.start();
    printed = false;
    samplingInterval.repeat();
    //Serial.println("Sampling started");
    }

  hih.process();
  
if(inByte==49){

  //Put print commands here
  //printR() -> Rainfall depth (mm)
  printE(sensors.getTempCByIndex(0)); //-> Earth temp
  //printD() -> Raindrop Size (mm)
  if (hih.isFinished() && !printed) {
    printA(hih.getAmbientTemp() / 100.0); //-> Air Temperature
    printH(hih.getRelHumidity() / 100.0); //-> Humidity
  }
delay(2000);

}

}

void printA(float value) {
    Genotronex.write('A');
    Genotronex.println(value);
}

void printR(float value) {
    Genotronex.write('R');
    Genotronex.println(value);
}

void printE(float value) {
    Genotronex.write('E');
    Genotronex.println(value);
}

void printH(float value) {
    Genotronex.write('H');
    Genotronex.println(value);
}

void printS(float value) {
    Genotronex.write('S');
    Genotronex.println(value);
}
