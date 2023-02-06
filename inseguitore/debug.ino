//funzioni debug stampa su seriale

void stampa_val_ser(){
    //Serial.println("u_sx     u_dx     d_sx     d_dx");
    Serial.print(u_sx);Serial.print("     ");
    Serial.print(u_dx);Serial.print("     ");
    Serial.print(d_sx);Serial.print("     ");
    Serial.print(d_dx);Serial.print("     ");
    Serial.print(servo_position);Serial.println("\n");
}