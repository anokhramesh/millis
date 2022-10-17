#include <LiquidCrystal.h>


const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4; //LCD pins Connection 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //LCD pins initiallization
int m0=0; //varialbe for indication of button pressed or not
int delay_sec=60; // variable store OFF delay time (set for 1 minute)
unsigned long current_time=0; //variable that will store current value of millis()function 
unsigned long previous_time=0; // variable that will store previous value of millis() function
int sec=0; //variable that will count seconds  
int current_state=0; //variable store current button State
int previous_state=0; //variable store previous button State
void setup() {
  lcd.begin(16,2);
  pinMode(3,INPUT_PULLUP); //timer and output reset button  
  pinMode(12,OUTPUT); 


}
 
void loop() {
 
current_time=millis();  
current_state=digitalRead(3);

if (current_state!=previous_state)
{
  if(current_state==LOW)
  {m0=0;
  digitalWrite(12,HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BUTTON PRESSED");
   lcd.setCursor(0,1);
    lcd.print("LIGHT ON");
  }
  if (current_state==HIGH)
  {m0=1;
  sec=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BUTTON RELEASED"); //msg will print on display when button pressed
  }
  previous_state=current_state;
  }
  if(m0==1)
  {
    if((current_time-previous_time)>=1000)
    {
      sec++;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("BUTTON RELEASED"); //msg will print on display when button released
      lcd.setCursor(0,1);
      lcd.print("DELAY SEC: ");//msg will print on display when button released
      lcd.print(sec);// Seconds value will print on display when button released
      previous_time=current_time;
     if (sec>=delay_sec)
     {
      m0=0;
         lcd.clear();
      digitalWrite(12,LOW);
        lcd.setCursor(0,0);
      lcd.print("DELAY COMPLETED");//msg will display at the end of delay 
        lcd.setCursor(0,1);
        lcd.print("LIGHT OFF"); //msg will display at the end of delay 
      delay(1000); //msg for ending delay time 
      lcd.clear();
       lcd.setCursor(0,0);   
lcd.print("TIMER STATUS:OFF"); //msg will display when timer off
lcd.setCursor(0,1);
lcd.print("SET DELAY: "); //msg will display when timer off
lcd.print(delay_sec); //delay time in seconds will print on display when timer off
      
      }
      }
    }
}
