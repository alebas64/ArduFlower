#include "costants.h"
#include <Stepper.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

const int Pu_sx=A0, Pu_dx=A1, Pd_sx=A2, Pd_dx=A3; //pin arduino
//2000 non può mai uscire dall' ADC di arduino
//10bit = 0~1023
int16_t u_sx=2000, u_dx=2000, d_sx=2000, d_dx=2000; //valore lettura fotoresistori
uint8_t i;
int8_t servo_position=90;
float temperature,humidity;

Servo myServo_testa;
Stepper myStepper(STEPS_REVOLUTION, IN1, IN3, IN2, IN4);
//DHT dht(DHT_PIN,DHT_TYPE);
DHT_Unified dht(DHT_PIN,DHT_TYPE);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

uint32_t last_millis;
sensor_t sensor;
sensors_event_t event;

void setup() {
    Serial.begin(9600);
    stepper_enable();
    servo_enable();
    letturaAnalogici();
    lcd.begin(16,2);
    //myServo_testa.write(30);
    last_millis=millis();
}

void loop() {
    letturaAnalogici();
    dht_read();
    stampa_val_ser();
    calculate_movement();
    lcdPrint();
    delay(LOOP_DELAY);
}
