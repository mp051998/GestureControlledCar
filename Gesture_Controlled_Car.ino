const int xpin = A3;
const int ypin = A2;
const int zpin = A1;
const int trigPin = A4;
const int echoPin = A5;
int sensorPin = A0;
int ledPin = 13;

int sensorValue=0;

// connect motor controller pins to Arduino digital pins
// MOTOR A
int enA = 10; //to control speed
int motorPin1 = 9;
int motorPin2 = 8;
// MOTOR B
int enB = 5; //to control speed
int motorPin3 = 7;
int motorPin4 = 6;



long duration;
int distance;


void stoper() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);  
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

void back()
{   // BACKWARD
  Serial.print("backward");
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  //xxxxx analogWrite(enA, 200);  // set speed to 200 out of possible range 0~255
  // turn on motor B
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  //xxxxx analogWrite(enB, 200); // set speed to 200 out of possible range 0~255
  delay(250); 
} 

void left()
{  // TURN
  Serial.print("left");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
//  analogWrite(enA, 200); // set speed to 200 out of possible range 0~255
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH); 
//  analogWrite(enB, 200); // set speed to 200 out of possible range 0~255
  delay(250); 
}

void forward()
{  // FORWARD
  Serial.print("forward");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW); 
//  analogWrite(enA, 200); // set speed to 200 out of possible range 0~255 
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
//  analogWrite(enB, 200); // set speed to 200 out of possible range 0~255 
  delay(250);
}

void right()
{  // TURN OTHER WAY
  Serial.print("right");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH); 
//  analogWrite(enA, 200); // set speed to 200 out of possible range 0~255    
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW); 
//  analogWrite(enA, 200); // set speed to 200 out of possible range 0~255 
  delay(250);
} 

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(ledPin,OUTPUT);
 pinMode(11,OUTPUT);


// pinMode(enA, OUTPUT);
// pinMode(enB, OUTPUT);
 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);
 pinMode(motorPin3, OUTPUT);
 pinMode(motorPin4, OUTPUT);

 stoper();
}

void loop() {
 unsigned int AnalogValue;
 unsigned int XpinValue;
 unsigned int YpinValue;
 AnalogValue = analogRead(A0);
 XpinValue = analogRead(xpin);
 YpinValue = analogRead(ypin);

 analogWrite(enA, 255);
 analogWrite(enB, 255);
 
 Serial.print(AnalogValue);
 Serial.print("\t");
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 duration=pulseIn(echoPin,HIGH);
 distance=duration*0.034/2;
 Serial.print("Distance:");
 Serial.print(distance);
 Serial.print("\t");
 Serial.print(XpinValue);
 Serial.print("\t");
 Serial.print(YpinValue);
 Serial.print("\t");
 Serial.println();
 delay(100);

 if (AnalogValue<1000)
 {
    digitalWrite(ledPin, LOW);
    delay(1000);    
 }
 else
 {
    digitalWrite(ledPin, HIGH);
    delay(1000);    
 }

 
 if(XpinValue>410)
 {
    forward();
 }
 else if(XpinValue<360)
 {
    back();
 }
 else
 {
    if(YpinValue>410)
    {
        left();
    }
    else if(YpinValue<360)
    {
        right();
    }
    else
    {
      stoper();
    }
 }

 
}

