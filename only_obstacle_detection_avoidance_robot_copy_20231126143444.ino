
#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB
#define near A5

//*****************//


void setup()
 {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);

  pinMode(near, INPUT);
}

void loop()
 {
   int s6 = analogRead(near);//distnace sensor value

    if(s6 > 500 )
     {//robot move forward direction
       analogWrite(e1, 255); 
       analogWrite(e2, 255); 
       digitalWrite(m1, HIGH);
       digitalWrite(m2, LOW);
       digitalWrite(m3, HIGH);
       digitalWrite(m4, LOW);
      }
    //obstacle detected and avoide by robot
   else
   {//robot change the path by taking turn
      analogWrite(e1, 255); 
      analogWrite(e2, 255); 
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
   
      delay(500);
   //robot move agagin on changed path
      analogWrite(e1, 255); 
      analogWrite(e2, 255); 
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);

      delay(500);
    
     }
   
  }
   