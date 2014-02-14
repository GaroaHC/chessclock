#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tempo = 60;
int minutos = 4;
int segundos = 59;
char comando;
 
byte r0[8] = {
  B00000, 
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
}; // 0 / 5
byte r1[8] = {
  B10000, 
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
}; // 1 / 5
byte r2[8] = {
  B11000, 
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
}; // 2 / 5 
byte r3[8] = {
  B11100, 
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
}; // 3 / 5
byte r4[8] = {
  B11110, 
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
}; // 4 / 5
byte r5[8] = {
  B11111, 
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
}; // 5 / 5

void draw_bargraph(byte percent) {
  byte i, cp, cl;
 
  lcd.setCursor(0, 0);
  lcd.print(tempo);
  lcd.print("s faltando..."); 
  //TODO
  //lcd.print(minutos);
  //lcd.print(":");
  //lcd.print(segundos);
  //lcd.print("s");
  
  lcd.setCursor(0, 1);
 
  percent = map(percent, 39, 100, 0, 80);
 
  cp = percent / 5;
  cl = percent % 5;
 
  for(i = 0; i < cp; ++i)
    lcd.write(5);
 
  lcd.write(cl);
 
  for(i = 0; i < 16 - (cp + (cl ? 1 : 0)); ++i)
    lcd.write((uint8_t)0);
}
 
void setup(){
  lcd.createChar(0, r0);
  lcd.createChar(1, r1);
  lcd.createChar(2, r2);
  lcd.createChar(3, r3);
  lcd.createChar(4, r4);
  lcd.createChar(5, r5);

  lcd.begin(16, 2); 
  lcd.clear();
  
  Serial.begin(9600);

  draw_bargraph(0);
}

int blinkfim = 1;

void loop(){
  comando = Serial.read();
  static byte percent = 100;
 
  byte changed = true;
  
  if(tempo >= 0){
    percent--;
    if(changed) {
      draw_bargraph(percent);    
      delay(100);
    }
    tempo--;
  }else{
    lcd.setCursor(0, 0);
    if(blinkfim == 1){
      blinkfim = 0;
      lcd.print("acabou o tempo!");
    }else{
      blinkfim = 1;
      lcd.clear();
    }
    if(comando == 'x'){
      tempo = 60;
      percent = 100;
    }
  }
  delay(200);
}
