#include <Arduino.h>
/**************************************************************************
 * 
 * ESP8266 NodeMCU with Nokia 5110 LCD (84x48 Pixel) and LM35 analog
 *   temperature sensor.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 *
 *************************************************************************/


#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_PCD8544.h>  // include Adafruit PCD8544 (Nokia 5110) library

// Nokia 5110 LCD module connections (CLK, DIN, D/C, CS, RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(18, 23, 4, 15, 2);

void setup(void)
{
  // initialize the display
  display.begin();

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);

  display.clearDisplay();   // clear the screen and buffer
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(6, 0);
  display.print("TEMPERATURE=");
  display.setTextSize(2);
  display.display();
}

int tKelvin, tCelsius, tFahrenheit;
// main loop
void loop()
{
  // read analog voltage and convert it to tenths °C ( = millivolts)
  tCelsius = analogRead(25);// * 3300/1024;
  tKelvin  = tCelsius + 2732;            // convert tenths °C to tenths Kelvin

  // print temperature in degree Celsius
  display.setCursor(0, 13);
  if (tCelsius >= 1000)    // if temperature >= 100.0 °C
    display.printf("%03u.%1u C", tCelsius / 10, tCelsius % 10);
  else                     // otherwise ( temperature < 100 °C)
    display.printf(" %02u.%1u C", tCelsius / 10, tCelsius % 10);

  // print temperature in Kelvin
  display.setCursor(0, 34);
  display.printf("%03u.%1u K", tKelvin / 10, tKelvin % 10);

  // print degree symbol ( ° )
  display.drawCircle(66, 15, 2, BLACK);

  // now update the screen
  display.display();

  delay(1000);  // wait a second
}

// end of code.
