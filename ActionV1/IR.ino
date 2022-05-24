/*void mesureIR(){
  
  unsigned long pepe1=millis(); 
 // distanceIr=sharp.distanceIr();  
  delay(20);  
 // Serial.print("Mean distanceIr: ");
 // Serial.println(distanceIr);
}



void suivre_IR(){
  mesureIR();
  if(distanceIr>23){  Dynamixel.turn(1,RIGTH,30);
  Dynamixel.turn(3,LEFT,30);}
  else if(distanceIr==23){Dynamixel.turn(1,RIGTH,0);
  Dynamixel.turn(3,LEFT,0);}
  else if(distanceIr<23){Dynamixel.turn(3,RIGTH,30);
  Dynamixel.turn(1,LEFT,30);}
}
*/