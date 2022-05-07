#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <PWMServo.h> 
PWMServo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
#define pin_GO A0
#define pin_parasol 9
#define pin_stop_time A2
boolean GO = 0;
int temps=90;
int i = 0;
int pos = 0;



void setup()
{
  myservo.attach(pin_parasol);
  parasol_ferme();
	lcd.begin();
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
	lcd.backlight();
	lcd.print("Pret pour depart");

   pinMode(pin_GO,INPUT);
   pinMode(A2, OUTPUT);
   digitalWrite(A2,LOW);
   pinMode(12, OUTPUT);
   digitalWrite(12,LOW);
}

void loop()

{
  attendre_signal_de_depart();

  
  if(temps>0){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("TEMPS : ");
  lcd.print(temps);
  lcd.setCursor(0,1);
  lcd.print("en cours");
  delay(1000);
  temps--;}
  
  else{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("fin du temps");
  lcd.setCursor(0,1);
  lcd.print("reglementaire");
 Stop_Time(HIGH);
 parasol_ouvert();
 parasol_ouvert();
 parasol_ouvert();
 delay(2000);
 fin_de_match();
  }
  
}


void fin_de_match(){
    for(i=0;i<10000;i++){delay(5000);}
    for(i=0;i<10000;i++){delay(5000);}
    for(i=0;i<10000;i++){delay(5000);}
}

void attendre_signal_de_depart(){
  while(GO == 0){delay(500); if(digitalRead(pin_GO)==0){GO=1;}}
}

void parasol_ferme(){
  myservo.write(0);
}

void parasol_ouvert(){
  myservo.write(90);
}


void Stop_Time(bool stopstate)
{
    if(stopstate)
  {
    pinMode(pin_stop_time,OUTPUT);        
    digitalWrite(pin_stop_time,HIGH);     
  }
  else
  {
    pinMode(pin_stop_time,INPUT);        
    digitalWrite(pin_stop_time,LOW);     
  }
  
}

