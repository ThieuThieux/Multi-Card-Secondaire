#include <Wire.h>
#include <NewPing.h>

//Serial
#define BAUD 9600

//I2C
#define ADD 9

//US
#define SONAR_NUM     6 // Number or sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 40 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).
#define DISTANCETOSTOP 30 // Distance à partir de laquelle on met le pin stop à 1

// I/O
#define trig0 2  // 
#define echo0 3
#define trig1 4
#define echo1 5
#define trig2 6
#define echo2 7
#define trig3 8
#define echo3 9
#define trig4 10
#define echo4 11
#define STOP 12
#define duree_interruption 1
#define duree_rearmement 1

#define distance_obstacle 45

NewPing US_A(trig0, echo0, MAX_DISTANCE);
NewPing US_B(trig2, echo2, MAX_DISTANCE);
NewPing US_C(trig3, echo3, MAX_DISTANCE);
NewPing US_D(trig4, echo4, MAX_DISTANCE);
NewPing US_E(trig1, echo1, MAX_DISTANCE);

int camp = 2;
int strategie = 0;
char mot = 'z';

boolean a = LOW;
boolean b = LOW;
boolean c = LOW;
boolean d = LOW;
boolean e = LOW;

void setup() {
  Wire.begin(5);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(12,OUTPUT);
  pinMode(trig0, INPUT);
  pinMode(echo0, INPUT);
  pinMode(trig1, INPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, INPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, INPUT);
  pinMode(echo3, INPUT);
  pinMode(trig4, INPUT);
  pinMode(echo4, INPUT);
}

void loop() {
if(a==1){if(US_A.ping_cm() < distance_obstacle && US_A.ping_cm() >10 ){Stopall(HIGH); delay(duree_interruption); Stopall(LOW); delay(duree_rearmement); }}else{Stopall(LOW );}
//if(b){if(US_B.ping_cm() < distance_obstacle && US_B.ping_cm() >10 ){Stopall(HIGH);delay(100); Stopall(LOW);}}else{Stopall(LOW );}
if(c==1){if(US_C.ping_cm() < distance_obstacle && US_C.ping_cm() >10 ){Stopall(HIGH);delay(duree_interruption); Stopall(LOW);delay(duree_rearmement);}}else{Stopall(LOW );}
//if(d){if(US_D.ping_cm() < distance_obstacle && US_D.ping_cm() >10 ){Stopall(HIGH);delay(100); Stopall(LOW);}}else{Stopall(LOW );}
if(e==1){if(US_E.ping_cm() < distance_obstacle && US_E.ping_cm() >10 ){Stopall(HIGH);delay(duree_interruption); Stopall(LOW);delay(duree_rearmement);}}else{Stopall(LOW );}
digitalWrite(12,LOW);
}


void receiveEvent(int howMany)
{
  while (1 < Wire.available()) // loop through all but the last
  {
    mot = Wire.read(); // receive byte as a character
  }

  if(mot=='a'){a=Wire.read();} 
//  else if(mot=='b'){ b = Wire.read();}
  else if(mot=='c'){ c = Wire.read();}
//  else if(mot=='d'){ d = Wire.read();}
  else if(mot=='e'){ e = Wire.read();}
  else {mot='z';}
}

void Stopall(bool stopstate)
{
    if(stopstate)
  {
    pinMode(STOP,OUTPUT);        
    digitalWrite(STOP,HIGH);
  }
  else
  {
    digitalWrite(STOP,LOW);  
    pinMode(STOP,INPUT);        
  }
}




