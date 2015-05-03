// Samuel Lee Toepke
// samueltoepke@gmail.com
// Spring 2015
// HumidityLogger.ino: Using an Arduino clone, and a temperature/humidity sensor to log environmental data
//   to a microSD card. Utilizes DHT library from Adafruit (https://learn.adafruit.com/dht). Prints readings of
//   the system time in milliseconds, the temperature in fahrenheit and the humidity in a tab delimited file. The
//   microSD card will need pre-formatted.

#include "DHT.h"
#include <SPI.h>
#include <SD.h>

#define DHTPIN 2   
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

File myFile;     // File handle on the microSD card.
int  delay_time; // Delay between readings.

void setup() { 
  dht.begin(); // Startup the temp/humidity sensor.
  
  pinMode(4, OUTPUT);
  delay_time = 1000; // milliseconds
  
  if (!SD.begin(4)) {
    return; // Initialization failed.
  }  
  else {
     myFile = SD.open("log_file.txt", FILE_WRITE);
  
    // if the file opened, write to it:
    if (myFile) {
      myFile.print("time"); 
      myFile.print("\t");
      myFile.print("temp");
      myFile.print("\t");
      myFile.print("humidity");
      myFile.println("");
    
      myFile.close(); // close the file:
    }  
  }
}

void loop() {
  float h = dht.readHumidity();
  float f = dht.readTemperature(true); // F
  
  if (isnan(h) || isnan(f)) {
    return;
  }
  
  myFile = SD.open("log_file.txt", FILE_WRITE);
  
  // if the file opened, write to it:
  if (myFile) {
    myFile.print(millis()); // Print system time in milliseconds.
    myFile.print("\t");
    myFile.print(f);
    myFile.print("\t");
    myFile.print(h);
    myFile.println("");
    
    myFile.close(); // close the file:
  } 
  
  delay(delay_time); 
}
