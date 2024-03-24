#define BLYNK_TEMPLATE_ID "TMPL3eErxY4_6"
#define BLYNK_TEMPLATE_NAME "Ventilator Project"
#define BLYNK_AUTH_TOKEN "wlk2frExaDAt2CmSSVa-IsDDo_FHDd87"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "iotdata";
char pass[] = "12345678";

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

#include "MAX30100_PulseOximeter.h"


#define REPORTING_PERIOD_MS     1000

// Global Variables
PulseOximeter pox;
String ventilatorMode;
uint32_t lastReportTimestamp = 0;
int heartRate, bloodOxygen, sensorRange;
int heartRateHighAlert, isHeartRateHigh, motionDetected;


void detectHeartBeat() {
    Serial.println("Beat!");
}

// Blynk Virtual Pin Handler
BLYNK_WRITE(V3) {
    motionDetected = param.asInt();
}

// Setup Function
void setup() {
    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   SMART VENTILATOR  ");
    lcd.setCursor(0, 1);
    lcd.print("  WITH ALERT ");
  
    // Initialize Serial Communication
    Serial.begin(115200);

    // Initialize Blynk
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

    // Configure Pin Modes
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);

    // Initialize Pulse Oximeter
    Serial.print("Initializing pulse oximeter..");
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
    pox.setIRLedCurrent(MAX30100_LED_CURR_11MA);
    pox.setOnBeatDetectedCallback(detectHeartBeat);
}

// Main Loop
void loop() {
    // Process Blynk Events
    Blynk.run();

    // Update Pulse Oximeter
    pox.update();

    // Reporting Conditions
    if (millis() - lastReportTimestamp > REPORTING_PERIOD_MS) {
        // Fetch Heart Rate and Blood Oxygen
        Serial.print("Heart rate:");
        heartRate = pox.getHeartRate();
        Serial.print(heartRate);
        Serial.print("bpm / SpO2:");
        bloodOxygen = pox.getSpO2();
        Serial.print(bloodOxygen);
        Serial.println("%");

        // Read Sensor Range
        sensorRange = analogRead(A0);
        Serial.print("Sensor range:");
        Serial.println(sensorRange);

        // Adjust Sensor Range
        if (sensorRange < 512) {
            sensorRange = map(sensorRange, 0, 512, 0, 100);
        } else {
            sensorRange = map(sensorRange, 512, 1024, 100, 200);
        }

        // Determine Ventilator Mode
        if (sensorRange < 50) {
            ventilatorMode = "LOW";
        } else if (sensorRange < 75) {
            ventilatorMode = "MID";
        } else {
            ventilatorMode = "HIGH";
        }
      
        // Display Data on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("HR = ");
        lcd.setCursor(5, 0);
        lcd.print(heartRate);
        lcd.setCursor(0, 1);
        lcd.print("SPO2 = ");
        lcd.setCursor(5, 1);
        lcd.print(bloodOxygen);
        lcd.setCursor(0, 2);
        lcd.print("VENTI SPEED = ");
        lcd.setCursor(14, 2);
        lcd.print(ventilatorMode);
        analogWrite(D5, sensorRange * 3);

        // Send Data to Blynk
        Blynk.virtualWrite(V0, heartRate);
        Blynk.virtualWrite(V1, bloodOxygen);

        // Control Ventilator
        if (ventilatorMode == "LOW") {
            if (motionDetected == 1) {
                digitalWrite(D6, HIGH);
                digitalWrite(D7, LOW);
                delay(2500);
                digitalWrite(D6, LOW);
                digitalWrite(D7, HIGH);
                delay(1500);
            }
        } else if (ventilatorMode == "MID") {
            if (motionDetected == 1) {
                digitalWrite(D6, HIGH);
                digitalWrite(D7, LOW);
                delay(2000);
                digitalWrite(D6, LOW);
                digitalWrite(D7, HIGH);
                delay(1500);
            }
        } else {
            if (motionDetected == 1) {
                digitalWrite(D6, HIGH);
                digitalWrite(D7, LOW);
                delay(1000);
                digitalWrite(D6, LOW);
                digitalWrite(D7, HIGH);
                delay(1000);
            }
        }
      
        // Heart Rate Alert
        if ((heartRate >= 110) && (isHeartRateHigh == 0)) {
            Blynk.logEvent("notify", "HEART RATE IS HIGH");
            isHeartRateHigh = 1;
        } else if ((heartRate <= 110) && (isHeartRateHigh == 1)) {
            isHeartRateHigh = 0;
        }
      
        lastReportTimestamp = millis();
    }
}
