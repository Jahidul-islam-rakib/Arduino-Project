int trigpin=A5;
int echopin=A4;
int distance=0;
float duration;

int  Distance()
{
digitalWrite(trigpin,LOW);
 delay(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin,LOW);

 duration= pulseIn(echopin,HIGH);

 distance = duration *0.034;
 return distance ;

}

void setup()
{
	// initialize the LCD
  Serial.begin(9600);

  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(5, OUTPUT);  // use on-board LED

   delay(400);


}

void loop()
{

  distance=Distance();
   

 Serial.println(distance);



    if( distance > 7 && distance <= 14)
  {
    digitalWrite(5,0);///pump off 

  }

  else if(distance > 14 ) 
  {
    digitalWrite(5,1); ///[pump on]

    check :
      distance=Distance();

      if( distance >7 )
      {
        delay(200); 
        Serial.println(distance);
        goto check ;
      }
      else
      {
//         delay(200);
        Serial.println(distance);
        digitalWrite(5,0) ;
      }
   /*      
            for(;Distance()>=7;)
                 {
                   Serial.println(distance);
                 }

    digitalWrite(5,0);///pump off  
    */          
  }


 delay(200);
}






