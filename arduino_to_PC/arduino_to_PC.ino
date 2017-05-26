// This program shown how to control arduino from PC Via Bluetooth
// Connect ...
// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
//Written By Mohannad Rawashdeh
//for http://www.genotronex.com/

// you will need arduino 1.0.1 or higher to run this sketch

#include <SoftwareSerial.h>// import the serial library
#include <SimpleDHT.h>

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
long previousMillis = 0;        // will store last time LED was updated
int pinDHT11 = 2;
SimpleDHT11 dht11;

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)
int ledState = LOW;             // ledState used to set the LED
long Counter=0; // counter will increase every 1 second
int i =0;


void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  //Genotronex.println("Bluetooth On please wait....");
  pinMode(ledpin,OUTPUT);
}

void loop() {

  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};

  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    //Serial.print("Read DHT11 failed");
    return;
  }
  
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;  
     Counter+=1;
  
    //Genotronex.print((int)temperature);
    //Genotronex.print("*C ");
    Genotronex.print("19");
    Genotronex.print("#");
    
    

    delay(2000);
  
    // if the LED is off turn it on and vice-versa:
//    if (ledState == LOW)
//      ledState = HIGH;
//    else
//      ledState = LOW;
//
//    // set the LED with the ledState of the variable:
//    digitalWrite(ledpin, ledState);
  }
}
