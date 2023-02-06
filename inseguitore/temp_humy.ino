//contiene le funzioni per poter leggere i dati dalla sonda di temperatura e di umidità

void dht_read(){/*
    if(millis()-last_millis<DHT_DELAY)
        return;
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    if(isnan(temperature))
        temperature = 999;
    if(isnan(humidity))
        humidity = 999;*/

    dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
        //Serial.println(F("Error reading temperature!"));
        temperature = 999;
    }else{
        temperature = event.temperature;
        
    }
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
        //Serial.println(F("Error reading humidity!"));
        humidity = 999;
    }else{
        humidity = event.relative_humidity;
        
    }
    last_millis=millis();
}