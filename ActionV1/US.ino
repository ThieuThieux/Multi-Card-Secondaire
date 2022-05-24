
void choix_capteur_actif(bool e,bool c, bool a){              // disposition en forme de T :    capteur E = = = = = = = capteur A
                                                                       //                                      \\                 //
                                                                       //                                       \\               //
                                                                       //                                            capteur C
  Wire.beginTransmission(ADD_CARTE_CAPTEUR);                           //
  Wire.write("a");     
  Wire.write(a);                  
  Wire.endTransmission(); 
  
  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("c");     
  Wire.write(c);                  
  Wire.endTransmission();  

  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("e");     
  Wire.write(e);                  
  Wire.endTransmission(); 
}







void choix_capteur_actif_old(bool a,bool b,bool c , bool d , bool e){

  Wire.begin();
  
  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("a");     
  Wire.write(a);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("b");     
  Wire.write(b);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("c");     
  Wire.write(c);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("d");     
  Wire.write(d);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_CARTE_CAPTEUR);
  Wire.write("e");     
  Wire.write(e);                  
  Wire.endTransmission(); 
}
