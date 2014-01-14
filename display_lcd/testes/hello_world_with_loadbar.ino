// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int i=0;

void hello(){
  lcd.setCursor(0,0);
  lcd.print("hello, world!");
}
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  hello();
}

void loop() {
  hello();
  //passa para a linha de baixo e corre as colunas...
  lcd.setCursor(i, 1);
  i = i + 1;
  delay(100);
  
  //simulando um progress bar
  lcd.print("#");  
  
  //16 = 0 a 15...
  if (i == 15){
    i = 0;
    // ainda nao consegui uma maneira de limpar apenas uma linha
    lcd.clear(); 
  }
}

