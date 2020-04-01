/*-------------------------------------------
 * Countdown with SSD1306
 * Credits: Diogo Vilhena
 * https://github.com/VilhenaChen
 *-------------------------------------------
 */
 
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED SSD1306
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//DHT11
#define dhtpin 2 //Data Pin where sensor is connect
#define dhttype DHT11
DHT dht(dhtpin, dhttype);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x64
  display.fillScreen(0);
  display.display();
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(45,0);
  display.print("Temp");
  display.setTextSize(2);
  display.setCursor(32,10);
  display.print(temp,1);
  display.print("C");
  display.setTextSize(1);
  display.setCursor(45,32);
  display.print("Hum");
  display.setTextSize(2);
  display.setCursor(32,45);
  display.print(hum);
  display.print("%");
  display.display();
  
}
