/*
PINOUT:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
*/
/* Include the standard Arduino SPI library */
#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 10
#define RESET_DIO 9

// define led pins
#define RED_LED 2
#define GREEN_LED 3

/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 


void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.println("Setup Complete:");
}

void loop()
{
  /* Has a card been detected? */
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    Serial.println("Card detected:");
    String serial_number = String(RC522.serNum[0],DEC) + String(RC522.serNum[1],DEC) + String(RC522.serNum[2],DEC) + String(RC522.serNum[3],DEC) + String(RC522.serNum[4],DEC);
    Serial.println(serial_number);
    Serial.println();
  }
  delay(1000);
}
