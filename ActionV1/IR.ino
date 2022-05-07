void mesureIR(){
  
  unsigned long pepe1=millis(); 
 // dis=sharp.distance();  
  delay(20);  
 // Serial.print("Mean distance: ");
 // Serial.println(dis);
}



void suivre_IR(){
  mesureIR();
  if(dis>23){  Dynamixel.turn(1,RIGTH,30);
  Dynamixel.turn(3,LEFT,30);}
  else if(dis==23){Dynamixel.turn(1,RIGTH,0);
  Dynamixel.turn(3,LEFT,0);}
  else if(dis<23){Dynamixel.turn(3,RIGTH,30);
  Dynamixel.turn(1,LEFT,30);}
}
