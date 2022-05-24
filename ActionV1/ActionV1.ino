#include <DynamixelSerial.h>
#include <Wire.h>
//#include <ZSharpIR.h>

#define TEMPS_ROTATE_90 650
#define VITESSE_ROTATION 50
#define PIN_STOP_CAPTEUR 3
#define PIN_STOP_TIME 2
#define PIN_GO 9
#define PIN_CAMP_JAUNE 7
#define PIN_CAMP_VIOLET 8
#define ADD_CARTE_CAPTEUR 5

#define DERIVATIVE 8 // Kd = DERIVATIVE/1000
#define INTEGRAL 0 // Ki = INTEGRAL*2048/1000
#define PROPORTIONAL 8 //Kp = PROPORTIONAL/8

#define IR A2
#define MODEL 20150

#define SERVO_G 3 
#define SERVO_D 1

int distanceIr = 0;
char camp;
volatile bool isStopCapteur = true;
volatile bool isStopTime = true;
bool go = 0;
bool homologuationActive = 0;
boolean couleur_camp = 0;



void setup()
{
  Serial.begin(9600);
  //Wire.begin();
  Dynamixel.begin(1000000, 4);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(PIN_GO, INPUT);
  pinMode(PIN_STOP_TIME, INPUT);
  pinMode(PIN_STOP_CAPTEUR, INPUT);
  pinMode(PIN_CAMP_JAUNE, INPUT);
  pinMode(PIN_CAMP_VIOLET, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_STOP_CAPTEUR), interruption_capteur, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_STOP_TIME), interruption_time, RISING);
  digitalWrite(LED_BUILTIN, LOW);
  Dynamixel.move(1, 0);
  Dynamixel.move(3, 0);
  delay(2000);
  Dynamixel.setmultiturn(id);
  Dynamixel.setmultiturn((char)1);
  Dynamixel.setPid(id, DERIVATIVE, INTEGRAL, PROPORTIONAL);
  Dynamixel.setPid((char)1, DERIVATIVE, INTEGRAL, PROPORTIONAL);
}

void loop()
{

  //SerialI2C.write("tot");
  //infinite_advance();

  Dynamixel.setmultiturn((char)3);
  Dynamixel.setmultiturn((char)1);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  Dynamixel.moveSpeedRW(3, 28672, 100);
  Dynamixel.moveSpeedRW(1, -28672, 100);
  delay(500);
  Dynamixel.action();
  delay(5000);
  Dynamixel.stopmultiturn((char)3);
  Dynamixel.stopmultiturn((char)1);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
 Dynamixel.moveSpeedRW(3, 4096, 100);
  Dynamixel.moveSpeedRW(1, -4096, 100);
  delay(500);
  Dynamixel.action();
  delay(5000);

  // SerialI2C.write(Dynamixel.readPosition(1));

  /*digitalWrite(LED_BUILTIN, HIGH);
    Dynamixel.move(1, 28672);
    delay(1000);
    Dynamixel.stopmultiturn(id);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    Dynamixel.move(1, 4096);
    delay(1000);
    Dynamixel.setmultiturn(id);
    delay(500);

    // Dynamixel.stopmultiturn(id);
    // delay(5000);
    //  digitalWrite(LED_BUILTIN, LOW);
    /*
    attendre_signal_de_depart();

    determination_du_camp();

    while (isStopTime)
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
        fin_de_match();
    }
    fin_de_match();
    }
    fin_de_match();*/
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
