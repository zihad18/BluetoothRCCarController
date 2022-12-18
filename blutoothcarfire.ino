#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

AF_DCMotor fl(1,MOTOR12_1KHZ);
AF_DCMotor fr(2,MOTOR12_1KHZ);
AF_DCMotor bl(3,MOTOR34_1KHZ);
AF_DCMotor br(4,MOTOR34_1KHZ);
char command;
const int flamePin = 9;
//int t=0;
int Flame = HIGH;
void setup() 
{
  //Set initial speed of the motor & stop
 
  bluetoothSerial.begin(9600);
  pinMode(flamePin, INPUT);
 // motor.run(RELEASE);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  
 if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    //Stop(); //initialize with motors stoped
    forward();
    if(Flame== LOW){
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }}
    else{
      Stop();
    }
  } 
  

   
}
void forward(){
   //Forward
    fl.setSpeed(255);
  bl.setSpeed(255);
  fr.setSpeed(255);
  br.setSpeed(255);
  fl.run(BACKWARD);
  bl.run(BACKWARD);
  fr.run(FORWARD);
  br.run(FORWARD);
  //delay(3000);
 // t=1;
 
  }
  void back(){
   //Forward
    fl.setSpeed(255);
  bl.setSpeed(255);
  fr.setSpeed(255);
  br.setSpeed(255);
  fl.run(FORWARD);
  bl.run(FORWARD);
  fr.run(BACKWARD);
  br.run(BACKWARD);
  //delay(3000);
 // t=1;
 
  }
 void Stop()
 { fl.setSpeed(0);
  bl.setSpeed(0);
  fr.setSpeed(0);
  br.setSpeed(0);
  fl.run(RELEASE);
  bl.run(RELEASE);
  fr.run(RELEASE);
  br.run(RELEASE);
 }
 void right()
 {
   fl.setSpeed(255);
  bl.setSpeed(255);
  fr.setSpeed(255);
  br.setSpeed(255);
  fl.run(BACKWARD);
  fr.run(FORWARD);
  bl.run(FORWARD);
  br.run(BACKWARD);
 }
 void left()
 { fl.setSpeed(255);
  bl.setSpeed(255);
  fr.setSpeed(255);
  br.setSpeed(255);
  fl.run(FORWARD);
  fr.run(BACKWARD);
  bl.run(BACKWARD);
  br.run(FORWARD);
 }
  
