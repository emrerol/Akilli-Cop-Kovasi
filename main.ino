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

void setup()
{
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
  motor.attach(9);
  motor.write(130);
}

void loop()
{
  delay(50);
  digitalWrite(LED_TRIG, HIGH);

  unsigned int distance = sonar.ping_cm();
  unsigned int led_distance = led_sonar.ping_cm();
  Serial.print("distance");
  Serial.println(distance);
  Serial.print("led");
  Serial.println(led_distance);

  if (distance < 10 && distance != 0)
  {
    motor.write(30);
    delay(2000);
    motor.write(130);
  }
  else
  {
    motor.write(130);
  }

  if (led_distance < 5)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  else
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
}
