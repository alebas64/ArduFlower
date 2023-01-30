//funzioni per movimento stepper

void stepper_enable(){
    myStepper.setSpeed(STEPS_RPM_SLOW);
}

//direction = 1, movimento orario. Antiorario se direction = -1
void stepper_movement(int speed, uint16_t steps,int8_t direction){
    switch(speed){
        case STEPS_RPM_SLOW:
            myStepper.setSpeed(STEPS_RPM_SLOW);
            myStepper.step(steps*direction);
            delay(STEPS_DELAY_SLOW*steps);
            break;
        case STEPS_RPM_NORMAL:
            myStepper.setSpeed(STEPS_RPM_NORMAL);
            myStepper.step(steps*direction);
            delay(STEPS_DELAY_NORMAL*steps);
            break;
        case STEPS_RPM_FAST:
            myStepper.setSpeed(STEPS_RPM_FAST);
            myStepper.step(steps*direction);
            delay(STEPS_DELAY_FAST*steps);
            break;
    }
}