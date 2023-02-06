//lettura valori dei fotoresistori

void letturaAnalogici(){
    u_sx=analogRead(Pu_sx);
    u_dx=analogRead(Pu_dx);
    d_sx=analogRead(Pd_sx);
    d_dx=analogRead(Pd_dx);
}

float irraggiamento(){
    float temp = ((float)(u_sx+u_dx+d_sx+d_dx+4)/(4*1024))*1000+(int16_t)OFFSET_IRRAGGIAMENTO;
    //return (temp<=0) ? 0 : (int16_t)temp;
    return temp;
}