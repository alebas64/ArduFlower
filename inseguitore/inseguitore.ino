#include "costants.h"
#include <Stepper.h>
#include <Servo.h>
int Pu_sx=A0, Pu_dx=A3, Pd_sx=A1, Pd_dx=A2; //pin arduino
//2000 non può mai uscire dall' ADC di arduino
//10bit = 0~1023
uint16_t nu_sx=2000, nu_dx=2000, nd_sx=2000, nd_dx=2000; //valore nuova lettura
uint16_t ou_sx=2000, ou_dx=2000, od_sx=2000, od_dx=2000; //valore vecchia lettura
uint8_t i;
uint16_t servo_position=0;

Servo myServo_testa;
Stepper myStepper(STEPS_REVOLUTION, 8, 10, 9, 11);

void setup() {
    Serial.begin(9600);
    stepper_enable();
    servo_enable();
    letturaAnalogici();
    stepper_movement(STEPS_RPM_NORMAL,100,1); //lo faccio muovere un pò per cambiare i valori 
    readSUN();
    //Serial.println("u_sx     u_dx     d_sx     d_dx");
}

void loop() {
    readSUN();
    //stampa_val_ser();
    calculate_movement();
    readTemp();
    readHumy();
    lcdPrint();
    delay(LOOP_DELAY);
}
