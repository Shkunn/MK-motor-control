#include <SPI.h>
#include <Arduino.h>
#include <WiFi.h>
 
const char* ssid = "Teddy"; //  your network SSID (name)
const char* pass = "teddyleclercq";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

unsigned int localPort = 9000;      // local port to listen on

char packetBuffer[255]; //buffer to hold incoming packet

WiFiUDP Udp;

const int output2 = 2;

// Motor A
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

int motor2Pin1 = 25; 
int motor2Pin2 = 33; 
int enable2Pin = 32;

int motor3Pin1 = 16; 
int motor3Pin2 = 4; 
int enable3Pin = 17;

int motor4Pin1 = 18; 
int motor4Pin2 = 19; 
int enable4Pin = 5;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup() {

    //Initialize serial and wait for port to open:

    pinMode(output2, OUTPUT);
    // check for the presence of the shield:

    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Connected to wifi");

    // if you get a connection, report back via serial:

    Udp.begin(localPort);

    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);

    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);

    pinMode(motor3Pin1, OUTPUT);
    pinMode(motor3Pin2, OUTPUT);
    pinMode(enable3Pin, OUTPUT);

    pinMode(motor4Pin1, OUTPUT);
    pinMode(motor4Pin2, OUTPUT);
    pinMode(enable4Pin, OUTPUT);

    // pinMode(output27, OUTPUT);
    // Set outputs to LOW
    // digitalWrite(output2, LOW);

    // configure LED PWM functionalitites
    ledcSetup(pwmChannel, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(enable1Pin, pwmChannel);
    ledcAttachPin(enable2Pin, pwmChannel);
    ledcAttachPin(enable3Pin, pwmChannel);
    ledcAttachPin(enable4Pin, pwmChannel);

    // testing
    // Serial.print("Testing DC Motor...");
    Serial.begin(115200);
}

void loop() {

  // if there's data available, read a packet

  int packetSize = Udp.parsePacket();
  // Serial.print(packetSize);
  digitalWrite(output2, LOW);

  if (packetSize != 0) {

    Serial.print(packetSize);

    // UO
    if (packetSize == 1) {
      dutyCycle = 255;
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);
      ledcWrite(pwmChannel, dutyCycle);
      // delay(500);
      // while (dutyCycle <= 255){
      //     ledcWrite(pwmChannel, dutyCycle);   
      //     Serial.print("Forward with duty cycle: ");
      //     Serial.println(dutyCycle);
      //     dutyCycle = dutyCycle + 5;
      //     delay(500);
      //   }
      //   dutyCycle = 200;
      // digitalWrite(motor1Pin1, LOW);
      // digitalWrite(motor1Pin2, LOW);
      // digitalWrite(motor2Pin1, LOW);
      // digitalWrite(motor2Pin2, LOW);
    //   digitalWrite(output2, HIGH);
    }
    
    // DOWN
    if (packetSize == 3) {
      dutyCycle = 255;
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);
      ledcWrite(pwmChannel, dutyCycle);
      // delay(500);
      // while (dutyCycle <= 255){
      //     ledcWrite(pwmChannel, dutyCycle);   
      //     Serial.print("Forward with duty cycle: ");
      //     Serial.println(dutyCycle);
      //     dutyCycle = dutyCycle + 5;
      //     delay(500);
      // }
      // dutyCycle = 200;
      // digitalWrite(motor1Pin1, LOW);
      // digitalWrite(motor1Pin2, LOW);
      // digitalWrite(motor2Pin1, LOW);
      // digitalWrite(motor2Pin2, LOW);
    }

    // RIGHT
    if (packetSize == 2) {
      dutyCycle = 255;
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, HIGH);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, HIGH);
      ledcWrite(pwmChannel, dutyCycle);
      // delay(500);
      // while (dutyCycle <= 255){
      //     ledcWrite(pwmChannel, dutyCycle);   
      //     Serial.print("Forward with duty cycle: ");
      //     Serial.println(dutyCycle);
      //     dutyCycle = dutyCycle + 5;
      //     delay(500);
      // }
      // dutyCycle = 200;
      // digitalWrite(motor1Pin1, LOW);
      // digitalWrite(motor1Pin2, LOW);
      // digitalWrite(motor2Pin1, LOW);
      // digitalWrite(motor2Pin2, LOW);
    }

    // LEFT
    if (packetSize == 4) {
      dutyCycle = 255;
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      digitalWrite(motor3Pin1, HIGH);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, HIGH);
      digitalWrite(motor4Pin2, LOW);
      ledcWrite(pwmChannel, dutyCycle);
      // delay(500);
      // while (dutyCycle <= 255){
      //     ledcWrite(pwmChannel, dutyCycle);   
      //     Serial.print("Forward with duty cycle: ");
      //     Serial.println(dutyCycle);
      //     dutyCycle = dutyCycle + 5;
      //     delay(500);
      // }
      // dutyCycle = 200;
      // digitalWrite(motor1Pin1, LOW);
      // digitalWrite(motor1Pin2, LOW);
      // digitalWrite(motor2Pin1, LOW);
      // digitalWrite(motor2Pin2, LOW);
    }

    if (packetSize == 5) {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor3Pin1, LOW);
      digitalWrite(motor3Pin2, LOW);
      digitalWrite(motor4Pin1, LOW);
      digitalWrite(motor4Pin2, LOW);
    }
    // Serial.print("Received packet of size ");

    // Serial.println(packetSize);

    // Serial.print("From ");

    // IPAddress remoteIp = Udp.remoteIP();

    // Serial.print(remoteIp);

    // Serial.print(", port ");

    // Serial.println(Udp.remotePort());

    // read the packet into packetBufffer

    int len = Udp.read(packetBuffer, 255);

    if (len > 0) {

      packetBuffer[len] = 0;
      // Serial.print(packetBuffer);

    }

    // Serial.println("Contents:");

    // Serial.println(packetBuffer);

  }
  delay(1000);
}
