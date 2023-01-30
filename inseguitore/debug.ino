void print_limits(){
    Serial.print("state1: ");Serial.println(state1);
    Serial.print("state2: ");Serial.println(state2);
}

void stampa_val_ser(){
    //Serial.println("u_sx     u_dx     d_sx     d_dx");
    Serial.print(u_sx);Serial.print("     ");
    Serial.print(u_dx);Serial.print("     ");
    Serial.print(d_sx);Serial.print("     ");
    Serial.print(d_dx);Serial.println("\n");
}