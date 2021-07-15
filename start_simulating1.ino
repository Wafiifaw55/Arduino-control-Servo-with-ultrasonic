#include<Servo.h>
int trig=8;
int echo=9;
int dt=10;
Servo servo1,servo2,servo3,servo4,servo5,servo6;


void setup() {
  
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(12);
  servo3.attach(3);
  servo4.attach(13);
  servo5.attach(4);
  servo6.attach(11);
}
int b=30,s=945,e=90,w=90,n=45,p=30;

void loop() {
  // put your main code here, to run repeatedly:


if (calc_dis()<10)
{
  for (int i=0;i<=540;i++)
  {
    servo1.write(i+b);
    servo2.write(i+s);
    servo3.write(i+e);
    servo4.write(i+w);
    servo5.write(i+n);
    servo6.write(i+p);
    delay(1);
  }
  delay(100);
  for (int i=540;i>=0;i--)
  {
    servo1.write(i);
    servo2.write(i);
    servo3.write(i);
    servo4.write(i);
    servo5.write(i);
    servo6.write(i);
    delay(1);
  }
  delay(100);
}
}

//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR

int calc_dis()
{
  int duration,distance;
  digitalWrite(trig,HIGH);
  delay(dt);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}