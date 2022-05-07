
void pivoter_g(){Dynamixel.turn(1,RIGTH,vitesse_rotation); Dynamixel.turn(3,RIGTH,vitesse_rotation);delay(temps_rotate_90); Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0);}

void pivoter_d(){Dynamixel.turn(1,LEFT,vitesse_rotation); Dynamixel.turn(3,LEFT,vitesse_rotation);delay(temps_rotate_90); Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0);}

void stoper(){ Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0);}

void Pince_default(){ Dynamixel.moveSpeed(8,512,200); Dynamixel.moveSpeed(9,508,200);}

void Pince_levee(){ Dynamixel.moveSpeed(8,530,200); delay(200); Dynamixel.moveSpeed(9,198,200);}

void Pince_baissee(){ Dynamixel.moveSpeed(9,508,200); }

void Pince_baissee_max(){ Dynamixel.moveSpeed(9,555,200); }

void Pince_Ouverture(){Dynamixel.moveSpeed(8,577,200); Dynamixel.moveSpeed(9,508,200);}

void Pince_Fermeture() {Dynamixel.moveSpeed(8,507,200); Dynamixel.moveSpeed(9,508,200);}

void Pince_Fermeture2() {Dynamixel.moveSpeed(8,400,200); Dynamixel.moveSpeed(9,508,200);}

void Pince_Fermeture_pousse_bloc() {Dynamixel.moveSpeed(8,480,200); Dynamixel.moveSpeed(9,555,200);}

void Pince_Cabane() {Dynamixel.moveSpeed(8,445,200); Dynamixel.moveSpeed(9,508,200);}

void avancer(float d)
{
  int i =0;

  float vitesseTrMin1 = (float) 470 * 50/1023;
  float vitesseTrMs1 = (float) vitesseTrMin1 / 60000;
  float TempsParcoursFloat1 = (float) (d /(2*3.14159*64*vitesseTrMs1));
  int TempsParcours1 = (int) TempsParcoursFloat1;

  float vitesseTrMin2 = (float) 470 * 200/1023;
  float vitesseTrMs2 = (float) vitesseTrMin2 / 60000;
  float calcul_correcteur = (float) 482 - (d/18);
  int correcteur = (int) calcul_correcteur;
  float TempsParcoursFloat2 = (float) (d /(2*3.14159*64*vitesseTrMs2)) - correcteur;
  int TempsParcours2 = (int) TempsParcoursFloat2;

  if(d<300){  
  Dynamixel.turn(1,RIGTH,50);
  Dynamixel.turn(3,LEFT,50);
  delay(TempsParcours1);
  Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0);  
  }

  else if(d >= 300){
  for(i=0; i<200; i=i+10){Dynamixel.turn(1,RIGTH,i); Dynamixel.turn(3,LEFT,i);delay(1);}
  Dynamixel.turn(1,RIGTH,200);
  Dynamixel.turn(3,LEFT,200);
  delay(TempsParcours2);
  for(i=200; i>9; i=i-10){Dynamixel.turn(1,RIGTH,i); Dynamixel.turn(3,LEFT,i);delay(1);}
  Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0);
  }
}

void reculer(float d)
{
  int i =0;

  float vitesseTrMin1 = (float) 470 * 50/1023;
  float vitesseTrMs1 = (float) vitesseTrMin1 / 60000;
  float TempsParcoursFloat1 = (float) (d /(2*3.14159*64*vitesseTrMs1));
  int TempsParcours1 = (int) TempsParcoursFloat1;

  float vitesseTrMin2 = (float) 470 * 200/1023;
  float vitesseTrMs2 = (float) vitesseTrMin2 / 60000;
  float calcul_correcteur = (float) 482 - (d/18);
  int correcteur = (int) calcul_correcteur;
  float TempsParcoursFloat2 = (float) (d /(2*3.14159*64*vitesseTrMs2)) - correcteur;
  int TempsParcours2 = (int) TempsParcoursFloat2;

  if(d<300){  
  Dynamixel.turn(3,RIGTH,50);
  Dynamixel.turn(1,LEFT,50);
  delay(TempsParcours1);
  Dynamixel.turn(1,RIGTH,0); Dynamixel.turn(3,LEFT,0);  
  }

  else if(d >= 300){
  for(i=0; i<200; i=i+10){Dynamixel.turn(3,RIGTH,i); Dynamixel.turn(1,LEFT,i);delay(1);}
  Dynamixel.turn(3,RIGTH,200);
  Dynamixel.turn(1,LEFT,200);
  delay(TempsParcours2);
  for(i=200; i>9; i=i-10){Dynamixel.turn(3,RIGTH,i); Dynamixel.turn(1,LEFT,i);delay(1);}
  Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0);
  }
}


void reculer_constante(float d)
{
  int i =0;

  float vitesseTrMin1 = (float) 470 * 50/1023;
  float vitesseTrMs1 = (float) vitesseTrMin1 / 60000;
  float TempsParcoursFloat1 = (float) (d /(2*3.14159*64*vitesseTrMs1));
  int TempsParcours1 = (int) TempsParcoursFloat1;
  
  Dynamixel.turn(3,RIGTH,50);
  Dynamixel.turn(1,LEFT,50);
  delay(TempsParcours1);
  Dynamixel.turn(1,RIGTH,0); Dynamixel.turn(3,LEFT,0);  
}


void courbure_v3(){
  Pince_baissee();
  Pince_Fermeture();
  delay(500);
  Dynamixel.turn(3,RIGTH,100);
  Dynamixel.turn(1,LEFT,512);
  delay(4000);
  Dynamixel.turn(1,RIGTH,512);
  Dynamixel.turn(3,LEFT,512);
  delay(2400);
  Dynamixel.turn(3,RIGTH,0); Dynamixel.turn(1,LEFT,0); 
}

void etape_calibrer_bloc(){
    
    while(dis!=23){
    suivre_IR();}
    stoper();
    Pince_Ouverture();
    avancer(250);
    Pince_Fermeture2();
    reculer(500);
    Pince_Ouverture();
    avancer(150);
    Pince_Fermeture2();
    avancer(50);
    }
