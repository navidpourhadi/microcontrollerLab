void setup() {
Serial.begin(9600);
pinMode (2, OUTPUT);
pinMode (4, OUTPUT);
pinMode (A0, INPUT);
pinMode (A2, INPUT);
pinMode (A4, INPUT);
pinMode (A5, INPUT);
 
}

void loop() {
//  delay(10);
  int s1 = analogRead(A2);
  int s2 = analogRead(A0);
  int s3 = analogRead(A4);
  int s4 = analogRead(A5);
  
//  Serial.print(analogRead(A5));
  //Serial.print(s1);
  //Serial.print(" -- ");
  //Serial.print(s2);
  //Serial.println("  ");

//
  if ( ((s1>=600) && (s4>=600)) && ((s2>=600) && (s3>=600))) {
    forward();
  }
  else if ( (s1<=600) && (s2<=600) ) {
    stop();
  }
  else if ( ((s1<=600) || (s4<=600)) && ((s2>=600) && (s3>=600)) ) {
    right();
  }
  
  else if ( ((s1>=600) && (s4>=600)) && ((s2<=600) || (s3<=600)) ) {
    left();
  }
  else{
    forward();
  }
}

//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//} 

void stop()
{

digitalWrite(2, LOW);
digitalWrite(4, LOW);
Serial.println("Stop");
}

void left()
{
digitalWrite(2, HIGH);
digitalWrite(4, LOW);
Serial.println(" Rotate Left");
}
void right()
{
digitalWrite(2, LOW);
digitalWrite(4, HIGH);
Serial.println(" Rotate Right");
}
void forward()
{
digitalWrite(2, HIGH);
digitalWrite(4, HIGH);
Serial.println("Forward");
}
