#include <LiquidCrystal.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define RS 2
#define EN 3
#define DB4 4
#define DB5 5
#define DB6 6
#define DB7 7
RF24 radio(9, 10); //setar CE e CSN do nrf
const byte address[6] = "00001"; //endereço de transmissão para parear com o recebedor do sinal
//definicao dos pinos do arduino

int CONTADOR = 0;

const int PRESSAO = A0; 
const int PRESSAOPADRAO;
float VALORPRESSAO = 0;
float MEDIAPRESSAO = 0;
int NUMEROLEITURAS = 0;
int PRESSAONOVA;

//bool RODADIANTEIRA = 1;

int led = 8;
//criacao das variaveis

LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

void setup() {
  Serial.begin(9600);             //iniciar serial com baud rate de 9600

  pinMode(led, OUTPUT)            //setar led como output
  
  pinMode(buzzer, OUTPUT);        //setar pino do buzzer
   
  lcd.begin(16,2);                //iniciar lcd
  lcd.setCursor(1,0);             //setar onde comeca a escrita
  lcd.print("Formula Tesla")      //escrever no lcd
  lcd.setCursor(7,1);             //setar onde comeca a escrita
  lcd.print("UFMG")               //escrever no lcd
  delay(4000);                    //tempo que vai ficar escrito no lcd
  lcd.clear();                    //limpar lcd
  lcd.setCursor(0,0);             //setar onde comeca a escrita
  lcd.print("Numero de voltas")   //escrever no lcd
  lcd.setCursor(0,1);             //setar onde comeca a escrita
  lcd.print(CONTADOR);            //escrever no lcd
  
  radio.begin();
  radio.openWritingPipe(00001);   //setar endereço de comunicação entre os modulos
  radio.setPALevel(RF24_PA_MIN);  //setar amplificacao do sinal
  radio.stopListening();          //setar como transmissor
  
  for(NUMEROLEITURAS = 1; NUMEROLEITURAS < 10; NUMEROLEITURAS++){
   PRESSAONOVA = analogRead(A0)
   MEDIAPRESSAO = (MEDIAPRESSAO + PRESSAONOVA)/NUMEROLEITURAS 
  } //estabelecer uma media da pressao para o desvio desta acionar o if do loop
}

void loop() {
  VALORPRESSAO = analogRead(A0);                    //pegar valor da pressao medida pelo sensor
  PRESSAOPADRAO = MEDIAPRESSAO
  if(VALORPRESSAO <= PRESSAOPADRAO - 1 || VALOR PRESSAO >= PRESSAOPADRAO + 1){
        //RODADIANTEIRA = !RODADIANTEIRA;             //inverter valor de RODADIANTEIRA
        CONTADOR++;                                 //aumentar contador
        tone(buzzer, 1000);                         //acionar buzzer
        digitalWrite(led, HIGH)                     //acionar led
        lcd.clear();                                //limpar lcd
        lcd.setCursor(0,0);                         //setar onde comeca a escrita
        lcd.print("Numero de Voltas");              //escrever no lcd
        lcd.setCursor(0,1);                         //setar onde comeca a escrita
        lcd.print(CONTADOR);                        //printar numero de voltas
        radio.write(&CONTADOR, sizeof(CONTADOR));   //transmitir numero de voltas via NRF
        delay(1000);                                //tempo do buzzer e do led acionados
        noTone(buzzer);                             //buzzer desativado
        digitalWrite(led, LOW);                     //led desativado
        delay(4000);                                //tempo estimado da roda passando pelo sensor para que o loop nao rode mais uma vez na mesma ativacao
    }
   
}
