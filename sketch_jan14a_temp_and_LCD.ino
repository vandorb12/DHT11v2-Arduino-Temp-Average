

/*
  Temperature and humidity average sensor with LCD output

  Written by Thomas Avent

  Using the input libaries of a DHT11 v2 and the output libraries of the most common LCD driver,
  a printed average of the temperature and humidity will present itself over 30 minute averages.
 */

// Libraires to include
#include <LiquidCrystal.h> // LCD library
#include <dht.h> // DHT11 v2 library
dht DHT;

// Declare constants
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int DHT11_PIN = 9; // Pin 9 is used for DHT11 v2

// C to F function for temperature conversion
int tempF(int tempC)
{
  int output = (tempC * 1.8) + 32;
  return output;
}

// DHT11 doesn't like to make fast reads on sensor data. A delay of 1.25 seconds tends to keep it from erring out.
void readTemp()
{
  DHT.read11(DHT11_PIN); // DHT11 library function to read the temperature and humidity into memory
  delay(1250);
}

void setup() 
 {
    // Prepare serial communications
    Serial.begin(9600);
    // setup the LCD's number of columns and rows
    lcd.begin(16,2);
    // Print a welcome message to the LCD and to serial
//    lcd.print("Hello, World!");
//    Serial.println("Hello, World!");
//    // Delay 5 seconds before clearing LCD
//    delay(5000);
//    lcd.clear(); // Clears LCD
//    delay(500);
    //lcd.setCursor(0,0); // Implied after lcd.clear(), but handy to have.
    
     
 }

void loop() 
  {
    // put your main code here, to run repeatedly:
    readTemp();
    lcd.setCursor(0,0);
    lcd.print("Current Temp:");
    lcd.setCursor(0,1); // Sets LCD cursor to column 0, line 1 (first column, line 2)
    lcd.print(tempF(DHT.temperature)); // Prints temperature in F
    Serial.print(tempF(DHT.temperature), 1);
    Serial.print("\n");
    lcd.blink();
}
