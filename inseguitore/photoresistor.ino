//lettura valori dei fotoresistori
void readSUN(){
    update_values();
    letturaAnalogici();
}

void letturaAnalogici(){
    nu_sx=analogRead(Pu_sx);
    nu_dx=analogRead(Pu_dx);
    nd_sx=analogRead(Pd_sx);
    nd_dx=analogRead(Pd_dx);
}

void update_values(){
    ou_sx=nu_sx;
    ou_dx=nu_dx;
    od_sx=nd_sx;
    od_dx=nd_dx;
}