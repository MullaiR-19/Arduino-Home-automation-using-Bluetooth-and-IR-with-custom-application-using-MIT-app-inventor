#include <dht.h>
#include<IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>

#define dht_apin A0

const int PulseWire = A1;
int thres = 490;
int PulseSensorON = 12;

PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

dht DHT11;

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte Heartchar[] = {
  B00000,  B01010,  B10101,  B10001,  B10001,  B01010,  B00100,  B00000
};
byte manchar[] = {
  B01110,  B01110,  B00100,  B01110,  B10101,  B00100,  B01010,  B01010
};
byte smilechar[] = {
  B00000,  B00000,  B01010,  B00000,  B00100,  B10001,  B01110,  B00000
};

#define relay1  10
#define relay2  9
#define relay3  8
#define relay4  7
#define relay5  6
#define relay6  5
#define relay7  4
#define relay8  3

int RECV_PIN = 2; // the pin where you connect the output pin of TSOP
int itsRELAYon[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //initialize array of realy
/* the initial state of LEDs is OFF (zero)
  the first zero must remain zero but you can
  change the others to 1's if you want a certain
  led to light when the board is powered */
#define code1  20655 // code received from button 1
#define code2  55335 // code received from button 2
#define code3  63495 // code received from button 3
#define code4  12495 // code received from button 4
#define code5  45135 // code received from button 9
#define code6  28815 // code received from button 6
#define code7  255 // code received from button 7
#define code8  61455 // code received from button 8
#define code9  39015 // code received from button 9
#define code10  57375 // code received from button 0
#define code11  8415 // code received from button EQ
#define codered 18615  // code received from button power

IRrecv irrecv(RECV_PIN); //setting IR rx pin
decode_results results; //moving IR decoded value to results

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  Serial.println("Initializing...");
  delay(2000);

  irrecv.enableIRIn();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Setup Starting");
  Serial.println("Setup Starting");
  delay(300);
  Serial.println("IR and Bluetooth Enabled");
  delay(2000);
  lcd.clear();

  pulseSensor.analogInput(PulseWire);
  pinMode(PulseSensorON, OUTPUT);
  pulseSensor.begin();  //activating pulse sensor
  pulseSensor.setThreshold(thres);

  pinMode(RECV_PIN, INPUT); //setting up IR sensor TSOP as INPUT

  pinMode(relay1, OUTPUT); //relay condition as out put
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  delay(100);
  lcd.createChar(0, Heartchar); // creating custom charactor 1
  lcd.createChar(1, manchar);   // creating custom charactor 2
  lcd.createChar(2, smilechar);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Welcome....");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("Device Active-OK");
  delay(2000);
  lcd.clear();
  delay(500);
  lcd.noBacklight();
  Serial.println("Yaali, At your Service.");
  Serial.print("WELCOME!");
  delay(300);

}

void loop() {

  if (irrecv.decode(&results) ) {
    unsigned int value0 = results.value;

    switch (value0) {

      case code1:
        if (itsRELAYon[1] == 1) {       // if first led is on then
          digitalWrite(relay1, LOW);   // turn it off when button is pressed
          itsRELAYon[1] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay1, HIGH); // turn it on when the button is pressed
          itsRELAYon[1] = 1;          // and set its state as on
        }
        break;

      case code2:
        if (itsRELAYon[2] == 1) {
          digitalWrite(relay2, LOW);
          itsRELAYon[2] = 0;
        } else {
          digitalWrite(relay2, HIGH);
          itsRELAYon[2] = 1;
        }
        break;

      case code3:
        if (itsRELAYon[3] == 1) {
          digitalWrite(relay3, LOW);
          itsRELAYon[3] = 0;
        } else {
          digitalWrite(relay3, HIGH);
          itsRELAYon[3] = 1;
        }
        break;

      case code4:
        if (itsRELAYon[4] == 1) {       // if first led is on then
          digitalWrite(relay4, LOW);   // turn it off when button is pressed
          itsRELAYon[4] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay4, HIGH); // turn it on when the button is pressed
          itsRELAYon[4] = 1;          // and set its state as on
        }
        break;

      case code5:
        if (itsRELAYon[5] == 1) {
          digitalWrite(relay5, LOW);
          itsRELAYon[5] = 0;
        } else {
          digitalWrite(relay5, HIGH);
          itsRELAYon[5] = 1;
        }
        break;

      case code6:
        if (itsRELAYon[6] == 1) {
          digitalWrite(relay6, LOW);
          itsRELAYon[6] = 0;
        } else {
          digitalWrite(relay6, HIGH);
          itsRELAYon[6] = 1;
        }
        break;

      case code7:
        if (itsRELAYon[7] == 1) {       // if first led is on then
          digitalWrite(relay7, LOW);   // turn it off when button is pressed
          itsRELAYon[7] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay7, HIGH); // turn it on when the button is pressed
          itsRELAYon[7] = 1;          // and set its state as on
        }
        break;

      case code8:
        if (itsRELAYon[8] == 1) {       // if first led is on then
          digitalWrite(relay8, LOW);   // turn it off when button is pressed
          itsRELAYon[8] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay8, HIGH); // turn it on when the button is pressed
          itsRELAYon[8] = 1;          // and set its state as on
        }
        break;

      case code9:
        Serial.println("Test Signal Done!!!");
        break;

      case code10:
        DHT11.read11(dht_apin);
        lcd.backlight();
        delay(2000);
        Serial.print("Temperature = ");
        Serial.print(DHT11.temperature);
        Serial.println("°Celsius  ");
        Serial.print("Current humidity = ");
        Serial.print(DHT11.humidity);
        Serial.print(" %  ");

        lcd.setCursor(0, 1);
        lcd.print("humidity: ");
        lcd.setCursor(10, 1);
        lcd.print(DHT11.humidity);
        lcd.setCursor(15, 1);
        lcd.print(" %  ");
        lcd.setCursor(0, 0);
        lcd.print("temp: ");
        lcd.setCursor(6, 0);
        lcd.print(DHT11.temperature);
        lcd.setCursor(10, 0);
        lcd.print("C'");
        lcd.setCursor(13, 0);
        lcd.write(byte(2));
        delay(7000);
        lcd.noBacklight();
        lcd.clear();
        break;

      case code11:
        int myBPM = 0;     //setting beat initialy 0
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("Place Finger...");
        lcd.setCursor(15, 0);
        lcd.write(byte(2));
        delay(2000);
        digitalWrite(PulseSensorON, HIGH); // powring the pulse sensor
        delay(2000);  // delay to set threshold in sensors comparator
        do {
          myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
          pulseSensor.sawStartOfBeat();            // Constantly test to see if "a beat happened".
        } while (myBPM > 90 || myBPM < 70);
        Serial.println("♥ HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
        Serial.print("BPM: ");
        Serial.println(myBPM);                        // Print the value inside of myBPM.
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.write(byte(0));
        lcd.setCursor(2, 0);
        lcd.print("A HeartBeat!");
        lcd.setCursor(0, 1);
        lcd.print("BPM:");
        lcd.setCursor(5, 1);
        lcd.print(myBPM);
        lcd.setCursor(10, 1);
        lcd.write(byte(1));
        lcd.setCursor(11, 1);
        lcd.write(byte(1));
        lcd.setCursor(12, 1);
        lcd.write(byte(1));
        lcd.setCursor(13, 1);
        lcd.write(byte(0));
        delay(7000);
        lcd.clear();
        lcd.noBacklight();
        digitalWrite(PulseSensorON, LOW);
        break;

      case codered:
        if (itsRELAYon[8] == 1) {       // if first led is on then
          digitalWrite(relay1, LOW);
          digitalWrite(relay2, LOW);
          digitalWrite(relay3, LOW);
          digitalWrite(relay4, LOW);
          digitalWrite(relay5, LOW);
          digitalWrite(relay6, LOW);
          digitalWrite(relay7, LOW);
          digitalWrite(relay8, LOW);
          itsRELAYon[8] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay1, HIGH);
          digitalWrite(relay2, HIGH);
          digitalWrite(relay3, HIGH);
          digitalWrite(relay4, HIGH);
          digitalWrite(relay5, HIGH);
          digitalWrite(relay6, HIGH);
          digitalWrite(relay7, HIGH);
          digitalWrite(relay8, HIGH);
          itsRELAYon[8] = 1;          // and set its state as on
        }
        break;
    }
    //Serial.println(value0); // you can comment this line
    value0 = "";
    irrecv.resume();
  }

  if (Serial.available() > 0) {

    char value1 = Serial.read();

    switch (value1) {

      case 'z':
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        digitalWrite(relay5, HIGH);
        digitalWrite(relay6, HIGH);
        digitalWrite(relay7, HIGH);
        break;

      case 'x':
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        digitalWrite(relay5, HIGH);
        digitalWrite(relay6, HIGH);
        digitalWrite(relay7, HIGH);
        digitalWrite(relay8, HIGH);
        break;

      case 'a':
        if (itsRELAYon[1] == 1) {       // if first led is on then
          digitalWrite(relay1, LOW);   // turn it off when button is pressed
          itsRELAYon[1] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay1, HIGH); // turn it on when the button is pressed
          itsRELAYon[1] = 1;          // and set its state as on
        }
        break;

      case 'b':
        if (itsRELAYon[2] == 1) {
          digitalWrite(relay2, LOW);
          itsRELAYon[2] = 0;
        } else {
          digitalWrite(relay2, HIGH);
          itsRELAYon[2] = 1;
        }
        break;

      case 'c':
        if (itsRELAYon[3] == 1) {
          digitalWrite(relay3, LOW);
          itsRELAYon[3] = 0;
        } else {
          digitalWrite(relay3, HIGH);
          itsRELAYon[3] = 1;
        }
        break;

      case 'd':
        if (itsRELAYon[4] == 1) {       // if first led is on then
          digitalWrite(relay4, LOW);   // turn it off when button is pressed
          itsRELAYon[4] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay4, HIGH); // turn it on when the button is pressed
          itsRELAYon[4] = 1;          // and set its state as on
        }
        break;

      case 'e':
        if (itsRELAYon[5] == 1) {
          digitalWrite(relay5, LOW);
          itsRELAYon[5] = 0;
        } else {
          digitalWrite(relay5, HIGH);
          itsRELAYon[5] = 1;
        }
        break;

      case 'f':
        if (itsRELAYon[6] == 1) {
          digitalWrite(relay6, LOW);
          itsRELAYon[6] = 0;
        } else {
          digitalWrite(relay6, HIGH);
          itsRELAYon[6] = 1;
        }
        break;

      case 'g':
        if (itsRELAYon[7] == 1) {       // if first led is on then
          digitalWrite(relay7, LOW);   // turn it off when button is pressed
          itsRELAYon[7] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay7, HIGH); // turn it on when the button is pressed
          itsRELAYon[7] = 1;          // and set its state as on
        }
        break;

      case 'h':
        if (itsRELAYon[8] == 1) {       // if first led is on then
          digitalWrite(relay8, LOW);   // turn it off when button is pressed
          itsRELAYon[8] = 0;           // and set its state as off
        } else {                      // else if first led is off
          digitalWrite(relay8, HIGH); // turn it on when the button is pressed
          itsRELAYon[8] = 1;          // and set its state as on
        }
        break;

      case 'i':
        DHT11.read11(dht_apin);
        lcd.backlight();
        delay(2000);
        Serial.print("Temperature is ");
        Serial.print(DHT11.temperature);
        Serial.println("° Celsius  ");
        Serial.print("Current humidity is ");
        Serial.print(DHT11.humidity);
        Serial.println("%  ");


        lcd.setCursor(0, 1);
        lcd.print("humidity:");
        lcd.setCursor(10, 1);
        lcd.print(DHT11.humidity);
        lcd.setCursor(15, 1);
        lcd.print("%  ");
        lcd.setCursor(0, 0);
        lcd.print("temp: ");
        lcd.setCursor(6, 0);
        lcd.print(DHT11.temperature);
        lcd.setCursor(10, 0);
        lcd.print("C'");
        lcd.setCursor(13, 0);
        lcd.write(byte(2));
        delay(8000);
        lcd.noBacklight();
        lcd.clear();
        break;

      case 'j':
        int myBPM = 0;     //setting beat initialy 0
        lcd.backlight();
        Serial.println("Place Finger...");
        lcd.setCursor(0, 0);
        lcd.print("Place Finger...");
        lcd.setCursor(15, 0);
        lcd.write(byte(2));
        delay(2000);
        digitalWrite(PulseSensorON, HIGH); // powring the pulse sensor
        delay(2000);  // delay to set threshold in sensors comparator
        do {
          myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
          pulseSensor.sawStartOfBeat();            // Constantly test to see if "a beat happened".
        } while (myBPM > 89 || myBPM < 70);
        //Serial.println("♥ A HeartBeat Happened ! ♥"); // If test is "true", print a message "a heartbeat happened".
        Serial.println(" A HeartBeat Happened !"); // If test is "true", print a message "a heartbeat happened".
        Serial.print("BPM is: ");
        Serial.print(myBPM);                        // Print the value inside of myBPM.
        //Serial.println("  ☺");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.write(byte(0));
        lcd.setCursor(2, 0);
        lcd.print("A HeartBeat!");
        lcd.setCursor(0, 1);
        lcd.print("BPM: ");
        lcd.setCursor(5, 1);
        lcd.print(myBPM);
        lcd.setCursor(10, 1);
        lcd.write(byte(1));
        lcd.setCursor(11, 1);
        lcd.write(byte(1));
        lcd.setCursor(12, 1);
        lcd.write(byte(1));
        lcd.setCursor(13, 1);
        lcd.write(byte(0));
        delay(8000);
        lcd.clear();
        lcd.noBacklight();
        digitalWrite(PulseSensorON, LOW);
        break;

    }
    //Serial.println(value1); // you can comment this line
    value1 = "";
  }
}
