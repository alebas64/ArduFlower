#define STEPS_HOMING 10
#define STEPS_REVOLUTION 2038
#include <Stepper.h>
#include <Servo.h>
int Pu_sx=A0, Pu_dx=A3, Pd_sx=A1, Pd_dx=A2; //pin arduino
//2000 non può mai uscire dall' ADC di arduino
//10bit = 0~1023
uint16_t u_sx=2000, u_dx=2000, d_sx=2000, d_dx=2000; //valore lettura
const int stepsPerRevolution = 2038;  // change this to fit the number of steps per revolution
int pos;
uint16_t stepper_position=0;
int limit1=12, limit2=13;
bool state1=false, state2=false;
Servo myServo_testa;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    myServo_testa.attach(6);
    // set the speed at 20 rpm:
    myStepper.setSpeed(15);
    pinMode(limit1,INPUT_PULLUP);
    pinMode(limit2,INPUT_PULLUP);
    // initialize the serial port:

    Serial.begin(9600);
    Serial.println("u_sx     u_dx     d_sx     d_dx");
}

void loop() {
    lettura();
    //stampa_val_ser();
    
    print_limits();
    limit_check();
    print_limits();
    Serial.println("\n");
    delay(1000);
    /*
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(2000);
  Serial.println("servo position 180");
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo_testa.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   delay(2000);
   
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(2000);
  Serial.println("servo position 0");
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myServo_testa.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  */
}

void lettura(){
    u_sx=analogRead(Pu_sx);
    u_dx=analogRead(Pu_dx);
    d_sx=analogRead(Pd_sx);
    d_dx=analogRead(Pd_dx);
}
