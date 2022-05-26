#include <NewPing.h>
#include <Servo.h>
Servo motor;
#define TRIGGER_PIN 7
#define LED_TRIG 5
#define LED_ECHO 4
#define ECHO_PIN 6
#define MAX_DISTANCE 200
#define GREEN 11
#define RED 10

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
NewPing led_sonar(LED_TRIG, LED_ECHO, MAX_DISTANCE); 

 
void setup() {
   pinMode(GREEN, OUTPUT);
   pinMode(RED, OUTPUT);
   Serial.begin(9600);
   motor.attach(9);
   motor.write(130);
}
 
void loop() {
   delay(50);
   digitalWrite(LED_TRIG, HIGH);
   
   unsigned int distance = sonar.ping_cm();
   unsigned int led_distance = led_sonar.ping_cm();
   Serial.print("distance");
   Serial.println(distance);
   Serial.print("led");
   Serial.println(led_distance);
   
   if( distance < 10 && distance !=0){
    motor.write(30);
    delay(2000);
    motor.write(130);
    }
   else
   {
    motor.write(130);
   }

    if(led_distance < 5) {
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,LOW);
    } else {
        digitalWrite(GREEN,HIGH);
        digitalWrite(RED, LOW);
    }
}






//#include <NewPing.h>
//#include <Servo.h>
//Servo motor;
//#define TRIGGER_PIN 7
//
//#define ECHO_PIN 6
//
//#define MAX_DISTANCE 200
//
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//
//void setup() {
//motor.attach(9);
//Serial.begin(9600);
//
//}
//
//void loop() {
//delay(50);
//
//
//unsigned int uS = sonar.ping();
//
//pinMode(ECHO_PIN,OUTPUT);
//
//digitalWrite(ECHO_PIN,LOW);
//
//pinMode(ECHO_PIN,INPUT);
//
//
//digitalWrite(TRIGGER_PIN,LOW);
//delayMicroseconds(2);
//digitalWrite(TRIGGER_PIN,HIGH);
//delayMicroseconds(2);
//digitalWrite(TRIGGER_PIN,HIGH);
//
//
//int mesafe = uS / US_ROUNDTRIP_CM;
//Serial.println(mesafe);
//
//
//if( mesafe < 10) {
//  motor.write(90);
//  delay(3000);
//  motor.write(0);
//}
//
//
//
//
//}














/* #include <Servo.h>

Servo motor;

#define echo 6
#define trig 7

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  motor.attach(9);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);

  float zaman = pulseIn(echo, HIGH);
  float cm = zaman/58.2;
  
  delay(200);
  
  Serial.println(cm);
  
  if(cm<10) {
    motor.write(90);
    delay(3000);
    motor.write(0);
  }  

} */
