#include <LiquidCrystal.h>

#define RS 2
#define EN 3
#define DB4 4
#define DB5 5
#define DB6 6
#define DB7 7

int VOLTA = A0;
int LEITURAVOLTAS = 0;

int CONTADOR = 0;

const float ADC_mV = 4.8828125;   // Converter Arduino ADC value para voltagem em mV
const float SensorOffset = 200;   // valor em mV do datasheet
const float sensitivity = 4.413;  // valor em mV/mmH2O do datasheet
//const float mmH2O_mcH2O = 10;     // Converter mmH2O para cmH2O
const float mmH2O_kPa = 0.00981   // Converter mmH2O para kPa

LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

void setup() {
  Serial.begin(9600);
  int sensorValue = analogRead(A0);
  
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Formula Tesla")
  lcd.setCursor(0,1);
  lcd.print("UFMG")

  delay(4000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Numero de voltas")
  lcd.setCursor(0,1);
  lcd.print(contador);
  

}

void loop() {
  float sensorValue = ((analogRead(A0) * ADC_mV - SensorOffset) / sensitivity * mmH2O_kPa;
    if{ sensorValue != 




}
