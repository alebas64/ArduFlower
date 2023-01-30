//funzioni di movimento del servo
void servo_enable(){
    myServo_testa.attach(SERVO_PIN);
    servo_reset();
}

void servo_movement(uint8_t position, uint8_t delay_per_degree){
    if(position > servo_position){
        for (i = servo_position; i < position; i++) {
            myServo_testa.write(i);
            delay(delay_per_degree);
        }
    }else if(position < servo_position){
        for (i = position; i < servo_position; i++) {
            myServo_testa.write(i);
            delay(delay_per_degree);
        }
    }
    servo_position = position;
}

void servo_reset(){
    if(servo_position==0){
        myServo_testa.write(0);
        delay(200);
        myServo_testa.write(0);
        delay(200);
        myServo_testa.write(0);
        delay(200);
    }else{
        for (i = servo_position; i > 0; i -= 1) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            myServo_testa.write(i);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
        }
    }
    
}