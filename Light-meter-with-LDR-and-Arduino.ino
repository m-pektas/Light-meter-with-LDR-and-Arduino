/*  
    Hello there.
    In this project I read the value from the LDR light sensor and printed 
    it on the Celcius screen and set the levels according to the standards
    I set up to turn on the LEDs that express the levels.
    I hope that will be useful.
    Good work..
*/

int TempLevel (int);                                  //Fonksiyon prototype
void Just_Low_Led_ON();
void Just_Mid_Led_ON();
void Just_High_Led_ON();
void All_Led_ON();


int READ_LIGHT_PIN = A1;                              //Set LDR pin
int LIGHT_HIGH_LED_PIN = 7;                           //Set Leds
int LIGHT_MID_LED_PIN = 6;
int LIGHT_LOW_LED_PIN = 5;

void setup() {
  Serial.begin(9600);                                 

  pinMode(LIGHT_HIGH_LED_PIN,OUTPUT);                 //Leds set outpin
  pinMode(LIGHT_MID_LED_PIN,OUTPUT);
  pinMode(LIGHT_LOW_LED_PIN,OUTPUT);
}


void loop() {

  int lightVal = analogRead(READ_LIGHT_PIN);          //Read data from LDR pin
  Serial.print("Light : ");                             
  Serial.println(lightVal);                           //Print data

  int level = LightLevel(lightVal);                   //get light level       
  LightLeds(level);                                   //leds on
  
  delay(1500);                                        //wait 1.5 second
}


int LightLevel (int light){                           //light level specified

     if(light<=15)
     {
        return 0;
     }
     else if(light>15 && light<=35)
     {
        return 1;
     }
     else if(light>35 && light<85)
     {
        return 2;
     }
     else{
        return 3;
     }
}

void LightLeds(int level)                            //leds on
{
    switch(level){
    case 0 :{ 
              Just_Low_Led_ON();
              break;
            }
    case 1 :{
              Just_Mid_Led_ON();
              break;
             }
    case 2 :{ 
              Just_High_Led_ON();
              break;
            }
    default : {
              All_Led_ON(); 
        }
  }
}
  
  void Just_Low_Led_ON()                                //just low led on
  {
        digitalWrite(LIGHT_LOW_LED_PIN,HIGH);
        digitalWrite(LIGHT_MID_LED_PIN,LOW);
        digitalWrite(LIGHT_HIGH_LED_PIN,LOW);
  }
  
  void Just_Mid_Led_ON()                                //just mid led on
  {
       digitalWrite(LIGHT_MID_LED_PIN,HIGH); 
       digitalWrite(LIGHT_LOW_LED_PIN,LOW);
       digitalWrite(LIGHT_HIGH_LED_PIN,LOW);
               
  }
  
  void Just_High_Led_ON()                               //just high led on
  {
       digitalWrite(LIGHT_HIGH_LED_PIN,HIGH);
       digitalWrite(LIGHT_LOW_LED_PIN,LOW);
       digitalWrite(LIGHT_MID_LED_PIN,LOW);
  }

  
  void All_Led_ON()                                     //all leds on
  {
      digitalWrite(LIGHT_LOW_LED_PIN,HIGH); 
      digitalWrite(LIGHT_MID_LED_PIN,HIGH); 
      digitalWrite(LIGHT_HIGH_LED_PIN,HIGH); 
  }

}

