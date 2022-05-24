void determination_du_camp(){
  if(digitalRead(PIN_CAMP_JAUNE)==1){couleur_camp=0;}
  else{couleur_camp=1;}
}

void attendre_signal_de_depart(){
  while(go == 0){delay(1000); if(digitalRead(PIN_GO)==0){go=1;}}
}



void clignoter(){
  for(i=0;i<200;i++){digitalWrite(LED_BUILTIN,HIGH);delay(500);digitalWrite(13,LOW);delay(500);}
}


void fin_de_match(){
    stoper();
    for(i=0;i<10000;i++){delay(5000);}
    for(i=0;i<10000;i++){delay(5000);}
    for(i=0;i<10000;i++){delay(5000);}
}



void interruption_capteur() {

    if(homologuationActive==1){
      stoper();
      delay(1000);
    }
  
    else if(homologuationActive==0){
    stoper();
    isStopCapteur=true;
    }
}


void interruption_time() {
    stoper();
    isStopTime=true;
}
