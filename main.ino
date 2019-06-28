#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int p=0;           // a maximum of eight servo objects can be created
int q=0;
int i=0;
int c=0;
const int E1=12;
const int E2=11;
const int E3=10;
int  a=0;
int sensorValue;
int GasSensorPin = 0; 
const int pingPin = 7; 
const int echoPin = 6;
int pos = 0;    // variable to store the servo position
void setup() 
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(E2,OUTPUT);
  pinMode(E3,OUTPUT);
  pinMode(E1,OUTPUT);
  myservo.write(180); 
}
void loop() 
{
  int  s1=digitalRead(E1);
  int  s2=digitalRead(E2);
  int  s3=digitalRead(E3);
  //initital switch off
  if(a==0)
  {
    myservo.write(180);             
    a++;
  }
   
  if(s1==HIGH)  //switch 1
  {
    Serial.println("BUTTON 1 ACTICATED: SYSTEM ON!");
    if(pos<=90)
    {
      for(; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);
      }
    }
    else
    {
      for(; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);
      }
    }

  }
  if(s2==HIGH)   //switch 2
  {
    Serial.println("BUTTON 2 ACTIVATED: SYSTEM TURNING OFF!");
    for(; pos <=180; pos += 1)  // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    c=0;
  }
  c--;
  if(s3==HIGH)   //switch 3
  {
      Serial.println("BUTTON 3 ACTICATED: TIMER ON!");
      Serial.println("HIGHHHH!!! + 10 sec. ");
      if(c>0)
        c+=12;
      else
        c=12;
      if(pos<=90)
      {
        for(; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
      else
      {
        for(; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
  }
  if(c==1)
  {
    Serial.println("TIME'S UP: OFF SIRE!!");
    for(; pos <=180; pos += 1)  // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
    //motor
  if(Serial.available()>0)
  {
    char i=Serial.read();
    if(i=='0'||i=='o') //off
    {
      for(; pos <=180; pos += 1) 
      {
        myservo.write(pos);             
        delay(15);                      
      }
    }
    else if (i=='1'||i=='h')//high
    {
      if(pos<=90)
      {
        for(; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
      else
      {
        for(; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
    }

    else if (i=='2'||i=='m')//med
    {
      if(pos<=45)
      {
        for(; pos<45; pos+=1)     // goes from 180 degrees to 0 degrees
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
      else
      {
        for(; pos>45; pos-=1)     // goes from 180 degrees to 0 degrees
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
    }
    else if (i=='3'||i=='l')//low
    {
      for(; pos>=1; pos-=1)     
    {
      myservo.write(pos);             
      delay(15);
    }
    }
  }
  

  //ultrasonic 
  
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print("Distance = ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if(cm>=20)
   p++;
  else
   p=0;

// gas
  sensorValue = analogRead(GasSensorPin);       // read analog input pin 0
  Serial.print("Gas Sensor Index:");
  Serial.println(sensorValue, DEC); 
  delay(1000); 
  if(pos!=180)
  {
    if(sensorValue>=50&&sensorValue<=350)
      Serial.println("PASS: NO GAS LEAKAGE DETECTED");
    else
    {
       q++;
       Serial.println("Gas Leakage Detected.");
    }
      
    if(q>=6)
    {
      Serial.println("Switching Off Main Supply since Prominent gas leakage has been detected");
      if(pos=180)
        Serial.println("All valves are already closed. Please check your surroundings for further misccalculations");
      q=0;
      for(; pos <=180; pos += 1)  
      {                                
        myservo.write(pos);              
        delay(15);                      
      }
    }
  }
    
  


  if(p>=10)                  //ultrasonic condition off
  {
    if(pos<170)
    {
    Serial.println("SWITCHING OFF SINCE NO VESSEL HAS BEEN PLACED :(");
    if(pos>=170)
    {
      Serial.println("Detected: System was already in OFF Mode.");
    }
    delay(3000);
    p=0;
    if(pos!=180)
    {
      for(; pos <=180; pos += 1)  // goes from 0 degrees to 180 degrees
      {                                  // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
  }
  if(pos>=170)
    {
      Serial.println("Detected: System is in OFF Mode.");
      p=0;
      
    }
  
}
  
}



long microsecondsToCentimeters(long microseconds) 
{
   return microseconds / 29 / 2;
}


//This project was created by Niran N in PC://Felirox by an open source platform Arduino IDE 1.8.7 
//The program being viewed has it's Copyright Accreditation for Niran N and in no cirmcumstances can this program be 
//used for mass replication without the consent of the creator. However, it can be used for any individual'd personal
//Non-Organisational work. Contact the owner of this project for any other further clarifications.
