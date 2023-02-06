//calcolo della posizione del sole
//i movimenti dei motori vengono fatti qui
void calculate_movement(){
    if (u_sx > u_dx) {
        stepper_movement(STEPS_RPM_SLOW,10,10);
    }
    if (d_sx > d_dx) {
        stepper_movement(STEPS_RPM_SLOW,10,10);
    }
    if (u_sx < u_dx) {
        stepper_movement(STEPS_RPM_SLOW,10,-10);
    }
    if (d_sx < d_dx) {
        stepper_movement(STEPS_RPM_SLOW,10,-10);
    }
    if (u_sx > d_sx) {
        servo_movement_relative2(3,4);
    }
    if (u_dx > d_dx) {
        servo_movement_relative2(3,4);
    }
    if (u_sx < d_sx) {
        servo_movement_relative2(-3,4);
    }
    if (u_dx < d_dx) {
        servo_movement_relative2(-3,4);
    }
}