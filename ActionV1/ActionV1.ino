#include <DynamixelSerial.h>
#include <Wire.h>
//#include <ZSharpIR.h>


#define temps_rotate_90 650
#define vitesse_rotation 50
#define pin_STOP_capteur 3
#define pin_STOP_time 2
#define pin_GO 9
#define pin_Camp_Jaune 7
#define pin_Camp_Violet 8
#define ADD_Carte_Capteur 5

#define ir A2
#define model 20150
//ZSharpIR sharp(ir, 25, 93, model);
int dis = 0;


char camp = 'a';
volatile boolean stop_capteur = 0;
volatile boolean stop_time = 0;
boolean GO = 0;
boolean couleur_camp = 0;
int i = 0;
boolean homologuation_active = 0;
boolean step_homologuation = 0;

void setup()
{
  Wire.begin();
  Dynamixel.begin(1000000, 4);
  pinMode(13, OUTPUT);
  pinMode (ir, INPUT);
  pinMode(pin_GO, INPUT);
  pinMode(pin_STOP_time, INPUT);
  pinMode(pin_STOP_capteur, INPUT);
  pinMode(pin_Camp_Jaune, INPUT);
  pinMode(pin_Camp_Violet, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), interruption_capteur, RISING);
  attachInterrupt(digitalPinToInterrupt(2), interruption_time, RISING);
}

void loop()
{
  attendre_signal_de_depart();

  determination_du_camp();


  while (stop_time == 0)
  {

    if (couleur_camp == 1)
    {
      realisation_parcours_violet();
    }

    else if (couleur_camp == 0)
    {
      homologuation_dynamique();
      /*
        choix_capteur_actif(1,1,1);
        etape_calibrer_bloc();
        courbure_v3();
        delay(10000);
        fin_de_match();*/
    }
    fin_de_match();
  }
  fin_de_match();
}

/*

  void receiveEvent(int howMany)
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    camp = c;
    if (camp='s'){stoper();}
  }
*/
