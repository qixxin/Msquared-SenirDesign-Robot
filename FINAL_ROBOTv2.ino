#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


#define MOVE_FORWARD 'w'
#define MOVE_BACK 's'
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define FULL_STOP 'e'
#define OPEN 'o'
#define CLOSE 'p'

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 3;
int in1 = 6;
int in2 = 7;
// motor two
int enB = 11;
int in3 = 4;
int in4 = 5;
int pos = 0;    // variable to store the servo 

int x = 55;

void setup()
{
   Serial.begin(9600);
 
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void loop(){
  char byte = 0;
  // press q to cancel and exit
  while (byte != 'q') {
    Serial.readBytes(&byte, 1);
    //press o to open
    
    if (byte == OPEN) {
      
 myservo.attach(9);  // attaches the servo

      for (pos = 70; pos <= 180; pos += 1)
        myservo.write(pos);
        delay(1000);
        
        //myservo.write(90);
        Serial.print("Turn from 0 to 90 \n");
        byte = 0;
        
      
        
     }
     //press p to close
    if (byte == CLOSE) {
      
  myservo.attach(9);  // attaches the servo

      for (pos = 180; pos >= 70; pos -= 1)
        myservo.write(pos);
        delay(1000);
        //myservo.write(0);
      
        Serial.print("Turn from 90 to 0 \n");
        byte = 0;
          
      
    }
    
    // press w to move forward
    if (byte == MOVE_FORWARD) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, x);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, x);
      Serial.print("move forward \n");
      byte = 0;
    }
    // press s to move backward
    if (byte == MOVE_BACK) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, x);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, x);
      Serial.print("move back \n");
      byte = 0;
    }
    // press a to turn left
    if (byte == MOVE_LEFT) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, x);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, x);
    Serial.print("move left \n");
    byte = 0;
    }
    // press d to turn right
    if (byte == MOVE_RIGHT) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, x);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, x);
      Serial.print("move right \n");
      byte = 0;
    }
    // press e to default stop
    if (byte == FULL_STOP) {
     
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 0);
      Serial.print("full stop \n");
      byte = 0;
    }
     if (byte == 'o') {
      for (pos = 70; pos <= 180; pos += 1)
        myservo.write(pos);
        delay(1000);
        //myservo.write(90);
        Serial.print("Turn from 0 to 90 \n");
        byte = 0;
        
     }
    if (byte == 'p') {
      for (pos = 180; pos >= 70; pos -= 1)
        myservo.write(pos);
        delay(1000);
        //myservo.write(0);
        Serial.print("Turn from 90 to 0 \n");
        byte = 0;
     
    }
  }
  
  Serial.print("Done \n");
  Serial.end();
}
