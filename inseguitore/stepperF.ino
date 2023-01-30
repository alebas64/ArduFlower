void stepperHoming(){
    int8_t direction = 1;
    bool finded = false;
    uint16_t steps_done=0;
    while(!finded){
        for(uint8_t i=0;i<STEPS_REVOLUTION;i<STEPS_REVOLUTION/2){
            myStepper.step(STEPS_HOMING*direction);
            steps_done+=STEPS_HOMING;
            delay(50);
            limit_check();
            if(!state1){
                //raggiunto limite 1
                finded = true;
                myStepper.step(STEPS_HOMING*direction/-4);
                i=STEPS_REVOLUTION;
            }
        }
        direction*=-1;
    }
}

void limit_check(){
    state1 = digitalRead(limit1);
    state2 = digitalRead(limit2);
}