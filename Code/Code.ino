const int buttonPin = 2;
const int servoPin  = 10;
const int servoPin2 = 11;
int buttonState = 0;


void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
  }


void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    for (int pos = 0; pos < 256; pos++)  {			//Flap opens
        analogWrite(servoPin2, pos);
        delay(20);
    }
     
    byte x = random(1,5);												// random case gets chosen, in any case finger comes out of the box
    
    switch(x)  {
      case 1: fast(); break;
      case 2: slow(); break;
      case 3: staccato(); break;
      case 4: funny(); break;
    } 

    for (int pos = 255; pos >= 0; pos--)  { 		// flap closes
       analogWrite(servoPin2, pos);              
       delay(30);
    }
  } 
}

void fast() {
   analogWrite(servoPin,95);             
   delay(400);

   analogWrite(servoPin,245);
   delay(400);
    
   analogWrite(servoPin,95);
   delay(400);
   }
 
void slow() {
   int speed = (30);                 
   for(int i = 95; i < 246; i++) {
     analogWrite(servoPin,i);
     delay(speed);
   }

   delay(1000);

   for(int i = 245; i > 94; i--) {
     analogWrite(servoPin,i);
     delay(speed);
   }
   }

void staccato() {
  analogWrite(servoPin,95);
  delay(1000);

  analogWrite(servoPin,135);
  delay(1000);

  analogWrite(servoPin,175);
  delay(1000);

  analogWrite(servoPin,215);
  delay(1000);

  analogWrite(servoPin,245);
  delay(1500);

  analogWrite(servoPin,95);
  }

void funny()  {
  analogWrite(servoPin,95);
  delay(400);
  analogWrite(servoPin,135);
  delay(1500);
  analogWrite(servoPin,95);
  delay(400);

  analogWrite(servoPin,175);
  delay(1500);
  analogWrite(servoPin,135);
  delay(400);
  analogWrite(servoPin,215);
  delay(1500);

  analogWrite(servoPin,175);
  delay(400);
  analogWrite(servoPin,245);
  delay(1500);

  analogWrite(servoPin,95);
  }
