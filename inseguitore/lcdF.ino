//contiene le funzioni per stampare sul display i vari dati
void lcdPrint(){
    lcd.setCursor(0,0);
    lcd.print("Sun Pw:");
    lcd.print(irraggiamento(),2);
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print(temperature,2);
    lcd.print(" H:");
    lcd.print(humidity,2);
}