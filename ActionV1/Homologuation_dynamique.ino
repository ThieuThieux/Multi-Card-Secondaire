void homologuation_dynamique(){
 
  homologuationActive = 1;

  choix_capteur_actif(1,1,1);

   while(1){
    
  mesureIR();
  if(distanceIr>30){  Dynamixel.turn(1,RIGTH,30);
  Dynamixel.turn(3,LEFT,30);}
  else if(distanceIr==30){Dynamixel.turn(1,RIGTH,0);
  Dynamixel.turn(3,LEFT,0);}
  else if(distanceIr<30){Dynamixel.turn(3,RIGTH,30);
  Dynamixel.turn(1,LEFT,30);}
  }

  

  
}
