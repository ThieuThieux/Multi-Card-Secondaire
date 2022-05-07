
void choix_capteur_actif(boolean e,boolean c, boolean a){              // disposition en forme de T :    capteur E = = = = = = = capteur A
                                                                       //                                      \\                 //
                                                                       //                                       \\               //
                                                                       //                                            capteur C
  Wire.beginTransmission(ADD_Carte_Capteur);                           //
  Wire.write("a");     
  Wire.write(a);                  
  Wire.endTransmission(); 
  
  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("c");     
  Wire.write(c);                  
  Wire.endTransmission();  

  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("e");     
  Wire.write(e);                  
  Wire.endTransmission(); 
}







void choix_capteur_actif_old(boolean a,boolean b,boolean c , boolean d , boolean e){

  Wire.begin();
  
  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("a");     
  Wire.write(a);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("b");     
  Wire.write(b);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("c");     
  Wire.write(c);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("d");     
  Wire.write(d);                  
  Wire.endTransmission(); 

  Wire.beginTransmission(ADD_Carte_Capteur);
  Wire.write("e");     
  Wire.write(e);                  
  Wire.endTransmission(); 
}
