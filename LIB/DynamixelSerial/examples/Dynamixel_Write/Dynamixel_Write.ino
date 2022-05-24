#include <DynamixelSerial.h>

void setup(){
Dynamixel.begin(1000000,2);  // Inicialize the servo at 1Mbps and Pin Control 2
delay(1000);
}

void loop(){

  Dynamixel.move(255,random(200,800));  // Move the Servo radomly from 200 to 800
  delay(1000);
  Dynamixel.moveSpeed(255,random(200,800),random(200,800));
  delay(2000);
  Dynamixel.setEndless(255,ON);
  Dynamixel.turn(255,RIGTH,1000);
  delay(3000);
  Dynamixel.turn(255,LEFT,1000);
  delay(3000);
  Dynamixel.setEndless(255,OFF);
  Dynamixel.ledStatus(255,ON);
  Dynamixel.moveRW(255,512);
  delay(1000);
  Dynamixel.action();
  Dynamixel.ledStatus(255,OFF);
 
delay(1000);

}
