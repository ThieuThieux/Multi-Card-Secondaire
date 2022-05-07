void determination_du_camp(){
  if(digitalRead(pin_Camp_Vert)==1){couleur_camp=0;}
  else{couleur_camp=1;}
}

void attendre_signal_de_depart(){
  while(GO == 0){delay(1000); if(digitalRead(pin_GO)==0){GO=1;}}
}



void clignoter(){
  for(i=0;i<200;i++){digitalWrite(13,HIGH);delay(500);digitalWrite(13,LOW);delay(500);}
}


void fin_de_match(){
    stoper();
    for(i=0;i<10000;i++){delay(5000);}
    for(i=0;i<10000;i++){delay(5000);}
    for(i=0;i<10000;i++){delay(5000);}
}



void interruption_capteur() {

    if(homologuation_active==1){
      stoper();
      delay(1000);
    }
  
    else if(homologuation_active==0){
    stoper();
    stop_capteur=1;
    }
}


void interruption_time() {
    stoper();
    stop_time=1;
}
