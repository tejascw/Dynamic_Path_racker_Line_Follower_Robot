#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB
//***5 Channel IR Sensor Connection***//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define near 7

//*****************//

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(near, INPUT);
}

void loop()
 {
  //Reading Sensor Values
  int s6 = digitalRead(near);//distnace sensor value
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

 if(s6 == 1)
  {
   //forward motion of LFR on white line
   if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
   {
     analogWrite(e1, 255); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //Move little-bit right for adjesting the motion of LFR white path
   if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0))
   {
     analogWrite(e1, 255); 
     analogWrite(e2, 255); 
     digitalWrite(m1, LOW);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //Move little-bit left for adjesting the motion of LFR white path
   if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
   {
     analogWrite(e1, 255); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, LOW);
     digitalWrite(m4, LOW);
   }
   //Take left turn on White path
   if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
   {
     analogWrite(e1, 100); 
     analogWrite(e2, 255);
     digitalWrite(m1, LOW);
     digitalWrite(m2, HIGH);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //Take right turn on White path
   if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
   {
     analogWrite(e1, 255); 
     analogWrite(e2, 100); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, LOW);
     digitalWrite(m4, HIGH);
   }
   //forward moment on black line
   if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1))
   {
     analogWrite(e1, 255); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //Move little-bit right for adjesting the motion of LFR white Black path
   if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
   { 
     analogWrite(e1, 255);
     analogWrite(e2, 255);
     digitalWrite(m1, LOW);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //Move little-bit Left for adjesting the motion of LFR on Black path
   if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
   { 
     analogWrite(e1, 255);
     analogWrite(e2, 255);
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, LOW);
     digitalWrite(m4, LOW);
   }
   //Take Right turn on Black path
   if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
   {
     analogWrite(e1, 100); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
 
   //Take Left turn on black path
   if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1))
   {
     analogWrite(e1, 255); 
     analogWrite(e2, 100); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
 
   //path shift from White to Black 
   if((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 0))
   {
     analogWrite(e1, 255);
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //path shift from Black to white
   if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 1))
   { 
     analogWrite(e1, 255); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, HIGH);
     digitalWrite(m4, LOW);
   }
   //Take Next Right turn on Black path
   if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 0))
   {
     analogWrite(e1, 100); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, LOW);
     digitalWrite(m4, HIGH);
   }
    //Take Next Right turn on Black path
   if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0) && (s6 == 0))
   {
     analogWrite(e1, 100); 
     analogWrite(e2, 255); 
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m3, LOW);
     digitalWrite(m4, HIGH);
   }
  }
  
}