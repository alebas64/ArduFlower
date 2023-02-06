//funzioni di movimento del servo
void servo_enable(){
    myServo_testa.attach(SERVO_PIN);
    servo_reset();
}

void servo_movement_absolute(uint8_t position, uint8_t delay_per_degree){
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

void servo_movement_relative(int8_t movement, uint8_t delay_per_degree){
    if(movement<0&&servo_position==0){
        return;
    }
    if(movement>0&&servo_position==180){
        return;
    }
    uint8_t limit;
    if(movement>0){
        limit = (servo_position+movement)>=180 ? 180 : servo_position+movement;
        Serial.print("Limit1:");Serial.println(limit);
        for(i=servo_position;i<limit;i++){
            myServo_testa.write(i);
            delay(delay_per_degree);
        }
        servo_position = i;
    }else{
        limit = (servo_position-movement)<=0 ? 0 : servo_position-movement;
        Serial.print("Limit2:");Serial.println(limit);
        for(i=servo_position;i>limit;i--){
            myServo_testa.write(i);
            delay(delay_per_degree);
        }
        servo_position = i;
    }
}

void servo_movement_relative2(int8_t movement, uint8_t delay_per_degree){
    servo_position+=movement;
    if(servo_position<0){
        servo_position=0;
        myServo_testa.write(servo_position);
        return;
    }
    if(servo_position>180){
        servo_position=180;
        myServo_testa.write(servo_position);
        return;
    }
    myServo_testa.write(servo_position);
}

void servo_reset(){
    myServo_testa.write(90);
    delay(200);
    myServo_testa.write(90);
    delay(200);
    myServo_testa.write(90);
    delay(200);
}