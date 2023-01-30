//funzioni debug stampa su seriale

void stampa_val_ser(){
    //Serial.println("u_sx     u_dx     d_sx     d_dx");
    Serial.print(nu_sx);Serial.print("     ");
    Serial.print(nu_dx);Serial.print("     ");
    Serial.print(nd_sx);Serial.print("     ");
    Serial.print(nd_dx);Serial.println("\n");
}