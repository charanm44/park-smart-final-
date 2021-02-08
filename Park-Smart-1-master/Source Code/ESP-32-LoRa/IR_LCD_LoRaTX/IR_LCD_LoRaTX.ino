#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <LiquidCrystal_I2C.h>
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, 16, 2);  
int irSenRead1 =15;
int irSenRead2 =4;
int isObstacle1 = HIGH;
int isObstacle2 = HIGH;

//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define BAND 915E6

//OLED pins
#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//packet counter
int counter = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void setup() {

  //reset OLED display via software
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  //initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever

  }
   lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  pinMode(irSenRead1 ,INPUT);
    pinMode(irSenRead2 ,INPUT);
   Serial.begin(115200);
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LORA SENDER ");
  display.display();
  
  //initialize Serial Monitor

  
  Serial.println("LoRa Sender Test");

  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Initializing OK!");
  display.setCursor(0,10);
  display.print("LoRa Initializing OK!");
  display.display();
  delay(2000);
}

void loop() {
   


  counter++;
    isObstacle1 = digitalRead(irSenRead1); // // Read IR sensor output
   Serial.println(digitalRead(irSenRead1)); // // print the output

     isObstacle2 = digitalRead(irSenRead2); // // Read IR sensor output
   Serial.println(digitalRead(irSenRead2)); // // print the output

  // // isObstacle ==low there is obstacle infront of sensor
  // // using serial monitor we can see this output
  
  if (isObstacle1 == LOW) {
    lcd.setCursor(0, 0);
    Serial.println("OBSTACLE1");
    Serial.println("P1: Occupied");
    lcd.print("P1: Occupied");
      delay(1000);
  // clears the display to print new message
  lcd.clear();
  }
  else
  {
    lcd.setCursor(0, 0);
    Serial.println("NO");
        lcd.print("P1: Available");
         Serial.println("P1: Available");
      delay(1000);
  // clears the display to print new message
  lcd.clear();
  }
   Serial.print("Sending packet: ");
  LoRa.beginPacket();
  LoRa.print(isObstacle1);
  LoRa.print("a");
  LoRa.print(counter);
  LoRa.endPacket();
  
    if (isObstacle2 == LOW) {
      lcd.setCursor(0,1);
    Serial.println("OBSTACLE2");
     Serial.println("P2: Occupied");
    lcd.print("P2: Occupied");
          delay(1000);
  // clears the display to print new message
  lcd.clear();
  }
  else
  {
    lcd.setCursor(0, 1);
    Serial.println("NO");
    Serial.println("P2: Available");
            lcd.print("P2: Available");
      delay(1000);
  // clears the display to print new message
  lcd.clear();
  }  
   Serial.print("Sending packet: ");
  LoRa.beginPacket();
  LoRa.print(isObstacle2);
  LoRa.print("b");
  LoRa.print(counter);
  LoRa.endPacket();
    Serial.print("Sending packet: ");
  Serial.println(counter);

  //Send LoRa packet to receiver

  
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("LORA SENDER");
  display.setCursor(0,20);
  display.setTextSize(1);
  display.print("LoRa packet sent.");
  display.setCursor(0,30);
  display.print("Counter:");
  display.setCursor(50,30);
  display.print(counter);      
  display.display();
         


  
  delay(10000);
}
