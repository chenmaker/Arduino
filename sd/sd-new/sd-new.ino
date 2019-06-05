#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
   Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }// open a new file and immediately close it:新建
  Serial.println("Creating 1.txt...");
  myFile = SD.open("1.txt", FILE_WRITE);
  myFile.close();

  // Check to see if the file exists:
  if (SD.exists("1.txt")) {
    Serial.println("1.txt exists.");
  } else {
    Serial.println("1.txt doesn't exist.");
  }
  }
void loop() {
  // nothing happens after setup finishes.
}
