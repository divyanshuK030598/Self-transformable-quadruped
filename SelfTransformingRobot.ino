#include <Servo.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <MPU6050.h>
#include <dht.h>
#define dht_apin 9 
dht DHT; 
MPU6050 sensor ;
const int trigPin = 6;
const int echoPin = 7;
long duration;
int distance;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int const buzzPin = 27;
SoftwareSerial mySerial(10, 11); // RX | TX
char command;
Servo FR_M1;
Servo FR_M2;
Servo FR_M3;
Servo FR_M4;
Servo FR_M5;

Servo FL_M1;
Servo FL_M2;
Servo FL_M3;
Servo FL_M4;
Servo FL_M5;

Servo BL_M1;
Servo BL_M2;
Servo BL_M3;
Servo BL_M4;
Servo BL_M5;

Servo BR_M1;
Servo BR_M2;
Servo BR_M3;
Servo BR_M4;
Servo BR_M5;
int i = 0;

void InitialPosition()
{
  FR_M1.write(140); //On seeing from top goes to 0 in anticlockwise direction
  FR_M2.write(40); // on seeing from side goes to 0 in clockwise 
  FR_M3.write(40); // on seeing from back goes to 0 in clock wise
  FR_M4.write(80); // on seeing from back goes to 0 in anti clockwise
   
  FL_M1.write(30); //on seeing from top goe to 0 anti clockwise
  FL_M2.write(135); // on seeing  from side goes to 0 in clock wise
  FL_M3.write(35); // on seeing from back goes to 0 in anti clock wise
  FL_M4.write(75); //on seeing from back goes to 0 in clockwise

  BL_M1.write(150); // on seeing from to goes to 0 in anticlockwise
  BL_M2.write(20); // on seeing from side goes to 0 in clockwise
  BL_M3.write(50); // on seeing from back goes to 0 in anticlockwise
  BL_M4.write(80); //on seeing from back goes to 0 in clockwise

  BR_M1.write(23); // on seeing from top goe to 0 in anticlockwise
  BR_M2.write(145);// on seeing from side goes to 0 in clockwise
  BR_M3.write(135); // on seeing from back goes to 0 in anticlockwise
  BR_M4.write(90); // on seeing from back goes to 0 in clockwise 
}

 void slope()
 {
  BL_M2.write(20+45-10);
         BR_M2.write(145-45);
       delay(500);
         FR_M2.write(40+45);
         FL_M2.write(135-45);
        
 }
        
void smallclimb()
{
         ItoCar();
         FR_M2.write(40+80+60);
         FL_M2.write(135-80-55);
         delay(1000);
         BL_M2.write(20+60-10);
         BR_M2.write(145-60);
         delay(1000);
         FR_M4.write(80);
         FL_M4.write(75);
         delay(500);
         FR_M2.write(40+60);
         FL_M2.write(135-60);
         delay(1000);
         BR_M5.write(180);
         BL_M5.write(0);
         delay(4000);
         BR_M5.write(90);
         BL_M5.write(90);
        for(i=0;i<=85;i++)
        {
            BL_M2.write(20+60-10+i);
            BR_M2.write(145-60-i);
        }

        delay(500);

        FR_M4.write(80+90+10);
         
         FL_M4.write(75+90);
          delay(1000);

          FR_M2.write(40+60);
         FL_M2.write(135-60);
         delay(500);
          FL_M5.write(0);
         FR_M5.write(180);
         delay(1500);
         FL_M5.write(90);
         FR_M5.write(90);
         delay(500);
         
         BL_M2.write(20+80-10);
         BR_M2.write(145-80);
           delay(500);
          FR_M2.write(40+80);
         FL_M2.write(135-80);
         BL_M2.write(20+80-10);
         BR_M2.write(145-80);
         
        
        /* BR_M5.write(90);
         BL_M5.write(90);
          delay(500);
         FR_M2.write(40+60);
         FL_M2.write(135-60);
          delay(500);
          FL_M5.write(0);
          FR_M5.write(180);
           BR_M5.write(180);
          BL_M5.write(0);
          delay(1200);*/
         
}

void down()
{
  BL_M4.write(160);
  FR_M1.write(140-100);
  delay(1000);
  FR_M2.write(40);
  delay(1000);
  FR_M3.write(50);
  delay(1000); 
  FR_M4.write(80);
  delay(1000);

  FL_M1.write(30+100);
  delay(1000);//on seeing from top goe to 0 anti clockwise
  FL_M2.write(135);
  delay(1000);// on seeing  from side goes to 0 in clock wise
  FL_M3.write(35);
  delay(1000);// on seeing from back goes to 0 in anti clock wise
  FL_M4.write(75); //on seeing from back goes to 0 in clockwise
  delay(1000);
   BL_M2.write(20+50-10);
    BR_M2.write(145-50);
   
     delay(500);
    /* FL_M4.write(75+50);
     FR_M4.write(80+50);
      delay(1000);
     FR_M1.write(140);
     FL_M1.write(30);
     delay(500);*/
     
      FL_M5.write(0);
     FR_M5.write(180);
    BR_M5.write(180);
  BL_M5.write(0);
    delay(1000);
    
    
     BR_M5.write(90);
  BL_M5.write(90);
   FL_M5.write(90);
     FR_M5.write(90);
  delay(1500);
   /* FL_M4.write(75);//uihuighjghj
     FR_M4.write(80);
    delay(500);*/
 /* FL_M1.write(30+100);
  FR_M1.write(140-100);
delay(500);*/
/*for(i=0;i<=40;i++)
{
  BL_M2.write(20+50+i-10);
  
    BR_M2.write(145-50-i);
    delay(20);}
    delay(500);*/
    
    BL_M2.write(100+45);
    delay(500);
    /*for(i=0;i<=45;i++){
    FR_M1.write(140-i);

    FL_M1.write(30+i);
 delay(25);}*/
 delay(500);
    /* FL_M4.write(75);
     FR_M4.write(80);*/
    // delay(500);
   // BL_M1.write(150+30);//mmmmmmmmmmmmmmmmmmmm
    delay(500);
    BR_M2.write(55-20);
    delay(500);
    BL_M4.write(80);
   delay(500);
    BL_M3.write(50+130);
    delay(500);
    
  BL_M1.write(150+30);
  delay(500);
   
   
     BL_M2.write(20);
     delay(500);
    BL_M3.write(50-10);
     delay(500);
    
     FR_M1.write(140+40);
 delay(500);
 FL_M1.write(30+100);
 //delay(500);
  // BR_M1.write(23-23);//ggggggggggggggg
   delay(500);
       delay(500);
     BR_M4.write(90);
     delay(500);
     BR_M3.write(135-130);
     delay(500);
     BR_M2.write(145);
     delay(500);
     BR_M1.write(23-23);
     delay(500);
     FR_M1.write(140);
      delay(500);
     BR_M3.write(135);
     delay(2000);
     //delay(500);
      InitialPosition();
     
     
    
  
  
}

void Climb()
{
  FR_M1.write(140);
  delay(100);
  FL_M1.write(30+90);
    delay(1000); 
  BL_M1.write(150-100);
    delay(1000);
  BR_M1.write(23-23);
  delay(1000);
  FR_M3.write(50+130);
  delay(1000);
  //FR_M4.write(80-80);
   //delay(1000);
   FR_M1.write(140-100);
   delay(1000);
   BL_M1.write(150+10);
   delay(1000);
   FR_M3.write(50+130-60);
   FL_M1.write(30);
   delay(1000);
   FL_M3.write(35+145);
   delay(1000);
   //FL_M4.write(75-75);
   //delay(1000); 
   FL_M1.write(30+100);
   delay(1000);
   FL_M3.write(35+145-60);
   delay(1000); 
   BL_M1.write(150);
   BR_M1.write(23);
   delay(1000); 
   BR_M3.write(135+15);
      BL_M3.write(50-15); 
    for( i=0;i<=90;i++)
      {
    
         BR_M4.write(90-i+10);
         BL_M4.write(80+i-10); 
         delay(15);
      }
      
      delay(1000);
      
      //BL_M4.write(160+20);
       BL_M2.write(20+20);
       BR_M2.write(145-20);
      FR_M3.write(50+130-90);
      FL_M3.write(35+145-90);
      delay(1000);
      BR_M5.write(180);
      BL_M5.write(0);
      delay(3000);
      BR_M5.write(90);
      BL_M5.write(90);
      delay(1000);
       BL_M1.write(150-45);
       BR_M1.write(23+45);
       delay(1000); 
       BR_M3.write(135-10);
      BL_M3.write(50); 
      delay(1000);
        BL_M4.write(80);
        BR_M4.write(90);
        /* delay(1000);
          BR_M3.write(135);
      BL_M3.write(50);*/ 
         delay(1000);
         FR_M2.write(40+120);
         FL_M2.write(135-120);
          delay(1000); 
         FR_M3.write(50+90); 
         FL_M3.write(35+90);
          delay(1000); 
          //FL_M5.write(0);
          //FR_M5.write(180);
          FR_M4.write(80+90+10);
           FL_M4.write(75+i);
         //BR_M4.write(90-90);
         delay(1000); 
         FR_M1.write(140);
         FL_M1.write(30);
         FR_M3.write(50);
         FL_M3.write(35); 
          delay(1000); 
         FR_M2.write(40+60);
         FL_M2.write(135-60);
          delay(1000); 
           FL_M5.write(0);
          FR_M5.write(180);
          delay(2000);
          FL_M5.write(90);
          FR_M5.write(90);
           delay(1000); 
          BL_M3.write(50+110);
          BR_M3.write(135-110);
          delay(1000); 
           BL_M4.write(80-40);
           BR_M4.write(90+40);
            delay(1000);
             BL_M2.write(20);
            BR_M2.write(145);
            delay(1000);
            for(i=0;i<=30;i++)
         { BL_M1.write(150+i);
          BR_M1.write(23-i);
          delay(50);}
          delay(500); 
           FL_M5.write(0);
          FR_M5.write(180);
          delay(2000);
          FL_M5.write(90);
          FR_M5.write(90);
           FR_M2.write(40+80);
         FL_M2.write(135-80);
          BL_M1.write(150); 
          BR_M1.write(23);
          delay(1000);
           BL_M2.write(20+130-10);
         BR_M2.write(145-130);
          delay(1000);
         BL_M3.write(50);
          BR_M3.write(135+10);
           delay(1000);
           BR_M4.write(90-90);
         BL_M4.write(80+90-10); 
         delay(1000);
         BL_M4.write(160+20);
         BR_M1.write(23+10);
         delay(1000);
           BL_M2.write(20+80-10);
         BR_M2.write(145-80);
         

         

   
   
  
  
}
/*
 if(ax>=102&&ax<=112&&ay>=85&&ay<=95)
 {InitialPosition();}
  if(ax<102)
   { FR_M2.write(40+30);
    FL_M2.write(135-30);
     BL_M2.write(20-10);
    BR_M2.write(145+10);
    }
    else if(ax>112)
    {
    BL_M2.write(20+30);
    BR_M2.write(145-30);
    FR_M2.write(40-10);
    FL_M2.write(135+10);
    }

    if(ay<85)
    {
    FR_M3.write(50+30);
     BR_M3.write(135-30);
      FL_M3.write(35-10);
    BL_M3.write(50-10); 
    }

    if(ay>95)
    {
    FL_M3.write(35+30);
    BL_M3.write(50+30);
     FR_M3.write(50-10);
     BR_M3.write(135+10);
    }
*/
void height()
{
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

  ax = map (ax, -17000, 17000, 0, 180) ;

   Serial.println (ax);
   runcarF();
    for(i=0;i<=20;i++)
    {
    FR_M2.write(130+2*i);
    FL_M2.write(35-2*i);
    //BL_M2.write(85-i);
    // BR_M2.write(55+i);
    delay(15);
    
    }
    if(ax>=105)
    for(i=0;i<=90;i++)
    {
     BL_M2.write(85-i);
     BR_M2.write(55+i);
     delay(15);
    }
   
}
void run()
{
  
}

void climb()
{
    BL_M2.write(110);
     BR_M2.write(45);
     
  for(i=0;i<=50;i++)
    {
    FR_M2.write(130+i);
    FL_M2.write(35-i);
    //BL_M2.write(85-i);
    // BR_M2.write(55+i);
     BL_M2.write(110-i);
     BR_M2.write(45+i); 
    delay(50);
    }
}

void walkL()
{
   for(i=0;i<=15;i++) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   delay(20);
  }
   delay(200);
    for( int i = 0; i<=15; i++) 
 {
  FR_M1.write(140-2*i); //On seeing from top goes to 0 in anticlockwise direction
  BL_M1.write(150-2*i); // on seeing from to goes to 0 in anticlockwise
  FL_M1.write(30-30+2*i); //on seeing from top goe to 0 anti clockwise
  BR_M1.write(23-23+2*i); // on seeing from top goe to 0 in anticlockwise
  
  delay(20);
 }
 
  delay(200);
  for(i=15;i>=0;i--) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   delay(20);
  }
 delay(200);

 for( int i = 0; i<=15; i++) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   delay(20);
 }
  delay(200);

  for( int i = 0; i<=15; i++) 
 {
  FL_M1.write(30-2*i); //on seeing from top goe to 0 anti clockwise
  BR_M1.write(23-2*i); // on seeing from top goe to 0 in anticlockwise
  BL_M1.write(150-30+2*i); // on seeing from to goes to 0 in anticlockwise
  FR_M1.write(140-30+2*i); //On seeing from top goes to 0 in anticlockwise direction
  delay(20);
 }
  delay(200);
 for( int i = 15; i>=0; i--) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   delay(20);
 }
 delay(200);

}




void walkR()
{
  for(i=0;i<=15;i++) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   delay(20);
  }
   delay(200);
    for( int i = 0; i<=15; i++) 
 {
  FR_M1.write(140+2*i); //On seeing from top goes to 0 in anticlockwise direction
  BL_M1.write(150+2*i); // on seeing from to goes to 0 in anticlockwise
  FL_M1.write(30+30-2*i); //on seeing from top goe to 0 anti clockwise
  BR_M1.write(23+23-2*i); // on seeing from top goe to 0 in anticlockwise
  
  delay(20);
 }
 
  delay(200);
  for(i=15;i>=0;i--) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   delay(20);
  }
 delay(200);

 for( int i = 0; i<=15; i++) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   delay(20);
 }
  delay(200);

  for( int i = 0; i<=15; i++) 
 {
  FL_M1.write(30+2*i); //on seeing from top goe to 0 anti clockwise
  BR_M1.write(23+2*i); // on seeing from top goe to 0 in anticlockwise
  BL_M1.write(150+30-2*i); // on seeing from to goes to 0 in anticlockwise
  FR_M1.write(140+30-2*i); //On seeing from top goes to 0 in anticlockwise direction
  delay(20);
 }
  delay(200);
 for( int i = 15; i>=0; i--) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   delay(20);
 }
 delay(200);

}

void walkB()
{
   for(i=0;i<=15;i++) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   FL_M2.write(135-i);
   BR_M2.write(145+i);
   delay(20);
  }
  delay(200);
  // MOTOR 2 OF FRONT RIGHT AND BACKLEFT MOVES FORWARD.
  for( int i = 0; i<=25; i++) 
 {
   FR_M2.write(40-i);
   BL_M2.write(20+i);
   delay(20);
 }
 delay(200);
// MOTOR 3 AND MOTOR 4 OF FRONT RIGHT AND BACK LEFT LEG TO THEIR ORIGINAL POSITION.
  for(i=15;i>=0;i--) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   delay(20);
  }
 delay(200);
  // Motor 3 moving in and motor 4 moves out legs lifting up from ground FOR FRONT LEFT AND BACKRIGHT LEGS. WHILE MOTOR 2 OF FR AND BACK LEFT MOVES BACK.
  for( int i = 0; i<=15; i++) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   
   FR_M2.write(40+i);
   BL_M2.write(20-i);
   delay(20);
 }
 delay(200);

 // MOTOR 2 OF FRONT LEFT AND BACK RIGHT MOVES FORWARD.
 for( int i = 0; i<25; i++) 
 {
   FL_M2.write(135+i);
   BR_M2.write(145-i);
   delay(20);
 }
 delay(200);

 // MOTOR 3 AND MOTOR 4 OF FRONT LEFT AND BACK RIGHT LEG TO THEIR ORIGINAL POSITION.

  for( int i = 15; i>=0; i--) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   delay(20);
 }
 delay(200);
}

void walk()

{  
 
 /* FR_M1.write(140+50);
      FL_M1.write(30+50);
       BL_M1.write(150+40);
       BR_M1.write(23+40);*/
  // Motor 3 moving in and motor 4 moves out legs lifting up from ground  Front Right and Back Left leg. AND MOTOR 2 OF FL AND BR MOVES BACK.
  for(i=0;i<=15;i++) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   FL_M2.write(135+i);
   BR_M2.write(145-i);
   delay(20);
  }
  delay(200);
  // MOTOR 2 OF FRONT RIGHT AND BACKLEFT MOVES FORWARD.
  for( int i = 0; i<=25; i++) 
 {
   FR_M2.write(40+i);
   BL_M2.write(20-i);
   delay(20);
 }
 delay(200);
// MOTOR 3 AND MOTOR 4 OF FRONT RIGHT AND BACK LEFT LEG TO THEIR ORIGINAL POSITION.
  for(i=15;i>=0;i--) 
 {
   FR_M3.write(50-3*i-5);
   BL_M3.write(50-3*i-5);
   FR_M4.write(80-6*i);
   BL_M4.write(80-6*i);
   delay(20);
  }
 delay(200);
  // Motor 3 moving in and motor 4 moves out legs lifting up from ground FOR FRONT LEFT AND BACKRIGHT LEGS. WHILE MOTOR 2 OF FR AND BACK LEFT MOVES BACK.
  for( int i = 0; i<=15; i++) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   
   FR_M2.write(40-i);
   BL_M2.write(20+i);
   delay(20);
 }
 delay(200);

 // MOTOR 2 OF FRONT LEFT AND BACK RIGHT MOVES FORWARD.
 for( int i = 0; i<25; i++) 
 {
   FL_M2.write(135-i);
   BR_M2.write(145+i);
   delay(20);
 }
 delay(200);

 // MOTOR 3 AND MOTOR 4 OF FRONT LEFT AND BACK RIGHT LEG TO THEIR ORIGINAL POSITION.

  for( int i = 15; i>=0; i--) 
 {
   FL_M3.write(35-3*i);
   FL_M4.write(75-5*i);
   BR_M3.write(135+3*i);
   BR_M4.write(90+6*i);
   delay(20);
 }
 delay(200);

 /* FR_M1.write(140);
      FL_M1.write(30);
       BL_M1.write(150);
       BR_M1.write(23);
 
 delay(200);*/
}

/*--------------------------***************------------------------***************************-------------------------------------------***********---------------------**********-------*/

void crawlposToCar()
{
  FR_M4.write(0);
  FL_M4.write(0);
  BL_M4.write(0);
  BR_M4.write(180);
  delay(100);
  FR_M3.write(50+45);
  FL_M3.write(35+45);
  BL_M3.write(50+45);
  BR_M3.write(135-45);  
  delay(100);
  FR_M2.write(40);
  FL_M2.write(135);
  BL_M2.write(20);
  BR_M2.write(145);
  delay(100);

  
  FR_M3.write(50+90); // on seeing from back goes to 0 in clock wise
  FR_M4.write(80); // on seeing from back goes to 0 in anti clockwise
  
   delay(100);
  FL_M3.write(35+90); // on seeing from back goes to 0 in anti clock wise
  FL_M4.write(75); //on seeing from back goes to 0 in clockwise
  delay(100);
 
  BL_M3.write(50+90); // on seeing from back goes to 0 in anticlockwise
  BL_M4.write(80); //on seeing from back goes to 0 in clockwise
  delay(100);
  
  BR_M3.write(135-90); // on seeing from back goes to 0 in anticlockwise
  BR_M4.write(90); // on seeing from back goes to 0 in clockwise 

  delay(1000);
   FR_M2.write(40+80+40);
   FL_M2.write(135-80-55);
   BL_M2.write(20+80-10+90);
   BR_M2.write(145-80-65);
   delay(1000);
   FR_M3.write(50-10);
  FL_M3.write(45);
  BL_M3.write(50-10);
  BR_M3.write(135+10); 
  delay(1000);
   
  

  FR_M4.write(80+90+10);
  BR_M4.write(90-90);
  FL_M4.write(75+90+10);
  BL_M4.write(80+90-10+20); 
  delay(1000);
  FR_M1.write(140);
FL_M1.write(30);
BL_M1.write(150); 
BR_M1.write(23);
delay(1000);


 
   FR_M2.write(40+80);
   FL_M2.write(135-80);
   BL_M2.write(20+80-10);
   BR_M2.write(145-80);

   delay(1000);
  /*FR_M1.write(140);
  FL_M1.write(30);
  BL_M1.write(150);
  BR_M1.write(23);
  delay(500);
  FR_M3.write(50);
  FL_M3.write(45);
  BL_M3.write(50);
  BR_M3.write(135);  
  delay(1000);

  FR_M4.write(80);
  FL_M4.write(75);
  BL_M4.write(80);
  BR_M4.write(90);

  delay(1000);
   FR_M2.write(40+80);
   FL_M2.write(135-80);
   BL_M2.write(20+80-10);
   BR_M2.write(145-80);

  delay(1000);

  FR_M4.write(80+90+10);
  BR_M4.write(90-90);
  FL_M4.write(75+90);
  BL_M4.write(80+90-10+20); 

  delay(1000);*/

}
void crawlpos()
{
  ItoCar();

    for(i=0;i<=45;i++)
    {
     FR_M2.write(40+80+2*i);
     FL_M2.write(135-80-2*i);
     BL_M2.write(20+80-10+2*i);
     BR_M2.write(145-80-2*i);
     delay(15);
      }
     delay(500);
  
  BR_M1.write(23+10-10);
    delay(500);
  FR_M4.write(0);
  FL_M4.write(0);
  BL_M4.write(0);
  BR_M4.write(180);
  delay(1000);
  FR_M3.write(50+45);
  FL_M3.write(45+45);
  BL_M3.write(50+45);
  BR_M3.write(135-45);  
  delay(1000);
  FR_M2.write(40);
  FL_M2.write(135);
  BL_M2.write(20);
  BR_M2.write(145);
  delay(1000);
}

void crawlR()
{
      /*FR_M1.write(140-90);
      FL_M1.write(30+90);
      BL_M1.write(150-90);
      BR_M1.write(23+90);*/
    for( i=0;i<=35;i++)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   for(i=0;i<=15;i++)
   {
      FR_M1.write(140+2*i-90);
      FL_M1.write(30+2*i+90);
      BL_M1.write(150-2*i-90);
      BR_M1.write(23-2*i+90);
      delay(15);
   }
      delay(700);
    
   for( i=35;i>=0;i--)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   
  delay(700);
  for( i=0;i<=15;i++){
      FR_M1.write(140-2*i-90);
      FL_M1.write(30-2*i+90);
      BL_M1.write(150+2*i-90);
      BR_M1.write(23+2*i+90);
      delay(15);}
   
}
void crawlL()
{
      
    for( i=0;i<=35;i++)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   for(i=0;i<=15;i++)
   {
      FR_M1.write(140-2*i-90);
      FL_M1.write(30-2*i+90);
      BL_M1.write(150+2*i-90);
      BR_M1.write(23+2*i+90);
      delay(15);
   }
      delay(700);
    
   for( i=35;i>=0;i--)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   
  delay(700);
  for( i=0;i<=15;i++){
      FR_M1.write(140+2*i-90);
      FL_M1.write(30+2*i+90);
      BL_M1.write(150-2*i-90);
      BR_M1.write(23-2*i+90);
      delay(15);}
}

void crawlStocrawlpos()
{
  FR_M4.write(0);
  FL_M4.write(0);
  BL_M4.write(0);
  BR_M4.write(180);
  delay(1000);
  FR_M3.write(50+45);
  FL_M3.write(45+45);
  BL_M3.write(50+45);
  BR_M3.write(135-45);  
  delay(1000);
  FR_M2.write(40);
  FL_M2.write(135);
  BL_M2.write(20);
  BR_M2.write(145);
  delay(1000);
}

void crawlS()
{
  FR_M3.write(50+90); // on seeing from back goes to 0 in clock wise
  FR_M4.write(80); // on seeing from back goes to 0 in anti clockwise
  
   delay(100);
  FL_M3.write(45+90); // on seeing from back goes to 0 in anti clock wise
  FL_M4.write(75); //on seeing from back goes to 0 in clockwise
delay(100);
 
  BL_M3.write(50+90); // on seeing from back goes to 0 in anticlockwise
  BL_M4.write(80); //on seeing from back goes to 0 in clockwise
delay(100);
  
  BR_M3.write(135-90); // on seeing from back goes to 0 in anticlockwise
  BR_M4.write(90); // on seeing from back goes to 0 in clockwise 
  delay(1000);
}

void crawlB()
{
   {
    
   for( i=0;i<=35;i++)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   for(i=0;i<=15;i++)
   {
      FR_M1.write(140+2*i);
      FL_M1.write(30-2*i);
      BL_M1.write(150-2*i);
      BR_M1.write(23+2*i);
      delay(15);
   }
      delay(700);
    
   for( i=35;i>=0;i--)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   
  delay(700);
  for( i=0;i<=15;i++){
      FR_M1.write(140-2*i);
      FL_M1.write(30+2*i);
      BL_M1.write(150+2*i);
      BR_M1.write(23-2*i);
      delay(15);}
   
  }
}
void crawlF()
  {
    
   for( i=0;i<=35;i++)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   for(i=0;i<=15;i++)
   {
      FR_M1.write(140-2*i);
      FL_M1.write(30+2*i);
      BL_M1.write(150+2*i);
      BR_M1.write(23-2*i);
      delay(15);
   }
      delay(700);
    
   for( i=35;i>=0;i--)
   {FR_M3.write(50+2*i+45);
   BR_M3.write(135-2*i-45);
   FL_M3.write(45+2*i+45);
   BL_M3.write(50+2*i+45); 
   delay(15);}
   
  delay(700);
  for( i=0;i<=15;i++){
      FR_M1.write(140+2*i);
      FL_M1.write(30-2*i);
      BL_M1.write(150-2*i);
      BR_M1.write(23+2*i);
      delay(15);}
   
  }
/*-----------------------**********------------------********************--------------------------------*******************--------------------********************-----------
CODE FOR CAR MODES*/
void ItoUPCar()
{
  
 for( i=0;i<=90;i++)
   {
     FR_M4.write(80-i);
     BR_M4.write(90+i);
     FL_M4.write(75+i);
     BL_M4.write(80+i-10); 
     delay(15);
   }

  delay(1000);
  for(i=0;i<=45;i++)
   {
     FL_M1.write(30+2*i);
     BL_M1.write(150-2*i-10);
     delay(15);
   }
  delay(1000);
  for(i=0;i<=45;i++)
  {
     FR_M4.write(80+2*i);
     BR_M4.write(90-2*i);
     delay(15);
  }
  delay(1000);
  for(i=0;i<=50;i++)
  {
     FR_M1.write(140-2*i);
     BR_M1.write(23+2*i);
     delay(15);
  }
  delay(1000);
  for(i=0;i<=50;i++)
  {
     FR_M1.write(40+2*i);
     FL_M1.write(120-2*i+10);
     BL_M1.write(50+2*i);
     BR_M1.write(123-2*i);
     delay(15);
  }
  delay(500);
  //BL_M4.write(160+20);
  BR_M1.write(23+10);
  delay(1000);
}

void UptoNarrowCar()
  {
     
  for( i=0;i<=90;i++)
  {
     FR_M2.write(40+i);
     FL_M2.write(135-i);
     BL_M2.write(20+i);
     BR_M2.write(145-i);
     delay(15);
  }
  delay(500);
  BL_M2.write(20+i-10);
  BL_M4.write(160+20);
   delay(1000);
    
  }
 
void ItoCar()
{ 
  for( i=0;i<=90;i++)
   {
     FR_M4.write(80-i);
     BR_M4.write(90+i);
     FL_M4.write(75+i);
     BL_M4.write(80+i-10); 
     delay(15);
   }

  delay(1000);
  for(i=0;i<=45;i++)
   {
     FL_M1.write(30+2*i);
     BL_M1.write(150-2*i-10);
     delay(15);
   }
  delay(1000);
  for(i=0;i<=45;i++)
  {
     FR_M4.write(80+2*i);
     BR_M4.write(90-2*i);
     delay(15);
  }
  delay(1000);
  for(i=0;i<=50;i++)
  {
     FR_M1.write(140-2*i);
     BR_M1.write(23+2*i);
     delay(15);
  }
  delay(1000);
  for(i=0;i<=50;i++)
  {
     FR_M1.write(40+2*i);
     FL_M1.write(120-2*i+10);
     BL_M1.write(50+2*i);
     BR_M1.write(123-2*i);
     delay(15);
  }
  delay(1000);
  for( i=0;i<=80;i++)
  {
     FR_M2.write(40+i);
     FL_M2.write(135-i);
     BL_M2.write(20+i);
     BR_M2.write(145-i);
     delay(15);
  }
   delay(500);
   BL_M2.write(20+80-10);
  BL_M4.write(160+20);
  BR_M1.write(23+10);
  delay(1000);
  }

void runcarF()
{
  FL_M5.write(0);
  FR_M5.write(180);
  BR_M5.write(180);
  BL_M5.write(0);
}

void stopcar()
{
  FL_M5.write(90);
  FR_M5.write(90);
  BR_M5.write(90);
  BL_M5.write(90);
}

void runcarB()
{
  FL_M5.write(180);
  FR_M5.write(0);
  BR_M5.write(0);
  BL_M5.write(180);
}

void runcarR()
{    
 FL_M5.write(0);
  FR_M5.write(0);
  BR_M5.write(0);
  BL_M5.write(0);
}

void runcarL()
{
  FL_M5.write(180);
  FR_M5.write(180);
  BR_M5.write(180);
  BL_M5.write(180);
}
void carToI() //
{
      BL_M4.write(160+20-20);
      delay(500);
      for( i=90;i>=0;i--)
      {
          FR_M2.write(40+i);
          FL_M2.write(135-i);
          BL_M2.write(20+i);
          BR_M2.write(145-i);
          delay(15);
      }
     delay(2000);
     InitialPosition();
}
/*-------------------******************------------------------------***********************------------------------------------*********------------------------------****************----*/
void balance()
{ 
  while(1){
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

  ax = map (ax, -17000, 17000, 0, 180) ;
  ay = map (ay, -17000, 17000, 0, 180) ;

   
     
  if(ax>=95&&ax<=120&&ay>=80&&ay<=100)
 {InitialPosition();}
 delay(100);
  if(ax<95)
   { FR_M2.write(40+30);
    FL_M2.write(135-30);
     BL_M2.write(20-10);
    BR_M2.write(145+10);
    }
     delay(100);
     if(ax>120)
    {
    BL_M2.write(20+30);
    BR_M2.write(145-30);
    FR_M2.write(40-10);
    FL_M2.write(135+10);
    }
 delay(100);
    if(ay<80)
    {
    FR_M3.write(50+30);
     BR_M3.write(135-30);
      FL_M3.write(35-10);
    BL_M3.write(50-10); 
    }
 delay(100);
    if(ay>100)
    {
    FL_M3.write(35+30);
    BL_M3.write(50+30);
     FR_M3.write(50-10);
     BR_M3.write(135+10);
    }
     delay(100);
}
}
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Wire.begin ( );
 Serial.begin(9600);
 mySerial.begin(9600 );
 lcd.begin(16, 2);
 Serial.println("You're connected via Bluetooth");

 Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( ); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 

delay (500); 

Serial.println ( "Taking Values from the sensor" );

delay (500);
pinMode(buzzPin, OUTPUT); 

  FR_M1.attach(52);
  FR_M2.attach(50);
  FR_M3.attach(48);
  FR_M4.attach(46);
  FR_M5.attach(44); //360 servo
  
  
  FL_M1.attach(53);
  FL_M2.attach(51);
  FL_M3.attach(49);
  FL_M4.attach(47);
  FL_M5.attach(45); //360 servo
  
 
  BL_M1.attach(39);
  BL_M2.attach(37);
  BL_M3.attach(35);
  BL_M4.attach(33);
  BL_M5.attach(31); // 360 servo
  
  BR_M1.attach(38);
  BR_M2.attach(36);
  BR_M3.attach(34);
  BR_M4.attach(32);
  BR_M5.attach(26); // 360 servo
  lcd.setCursor(0,0);
  lcd.print("WELCOME");
  
  //lcd.print("Transformer robot");
  InitialPosition();
  delay(2000);
  lcd.clear();
  lcd.print("I'm TRANSFORMERS!");
    
}



void loop() {

  /*sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

  ax = map (ax, -17000, 17000, 0, 180) ;

   Serial.println (ax);
   BL_M2.write(ax);
     BR_M2.write(ax);*/
  // Clears the trigPin
  DHT.read11(dht_apin);
  lcd.setCursor(5, 1);
  lcd.print(DHT.temperature);
  lcd.setCursor(7, 1);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(9, 1);
  lcd.print(" ");
  lcd.setCursor(11, 1); 
  lcd.print(DHT.humidity);
  lcd.setCursor(15, 1); 
  lcd.print("%");
  lcd.setCursor(16, 1);
   lcd.print(" ");
  delay(2000);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
Serial.println(DHT.temperature);
//lcd.clear();
lcd.setCursor(0, 1);
lcd.print("      ");
lcd.setCursor(0, 1);
lcd.print(distance);
 
   lcd.setCursor(5, 1);
  lcd.print("                              ");
  //delay(1000);
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

  ax = map (ax, -17000, 17000, 0, 180) ;
   ay = map (ay, -17000, 17000, 0, 180) ;
   az = map (az, -17000, 17000, 0, 180) ;
   Serial.println (ax);
   Serial.print("\t");
   Serial.println (ay);
   /*Serial.print("\t");
   Serial.println (az);*/

    /*if(ax>=95&&ax<=120&&ay>=80&&ay<=100)
 {InitialPosition();}
 delay(100);
  if(ax<95)
   { FR_M2.write(40+30);
    FL_M2.write(135-30);
     BL_M2.write(20-10);
    BR_M2.write(145+10);
    }
     delay(100);
     if(ax>120)
    {
    BL_M2.write(20+30);
    BR_M2.write(145-30);
    FR_M2.write(40-10);
    FL_M2.write(135+10);
    }
 delay(100);
    if(ay<80)
    {
    FR_M3.write(50+30);
     BR_M3.write(135-30);
      FL_M3.write(35-10);
    BL_M3.write(50-10); 
    }
 delay(100);
    if(ay>100)
    {
    FL_M3.write(35+30);
    BL_M3.write(50+30);
     FR_M3.write(50-10);
     BR_M3.write(135+10);
    }
     delay(100);*/

  

/*if (distance <= 10 && distance >= 0) {

// Buzz

digitalWrite(buzzPin, HIGH);
delay(2000);
digitalWrite(buzzPin, LOW);
}*/
/*delay(200);
 Climb();
 while(1){}
delay(200);*/

  
  if (mySerial.available())
   {
    command=(mySerial.read());
    if (command=='1')
    {
      lcd.setCursor(5, 1);
      //lcd.print("                              ");
      lcd.print("CAR MODE");
      ItoCar();           
      delay(500);                  
     }

    else if (command=='f')
    { if(distance>=0)
     {
      runcarF(); 
     }
   else { digitalWrite(buzzPin, HIGH);
      delay(1000);
      digitalWrite(buzzPin, LOW);}
     
      delay(200);
      
    }

    else if (command=='b')
    {
     runcarB();
      delay(200);
    }

    else if (command=='r')
    {
     runcarR();
      delay(200);
    }

    else if (command=='s')
    {
     stopcar();
      delay(200);
    }

    else if (command=='l')
    {
     runcarL();
      delay(200);
    }

     else if (command=='i')
    {
      carToI();      
      delay(500);
    }
 
    else if (command=='2')
    {
      lcd.setCursor(5, 1);
      
      if(distance>=10)
   {  lcd.print("WALKING MODE");
      walk(); 
   }
   else { digitalWrite(buzzPin, HIGH);
   lcd.print("WALKING REJECTED");
      delay(1000);
      digitalWrite(buzzPin, LOW);}
     
      delay(200);
    } 
    
    else if (command=='3')
    {
      walkR();            
      delay(500);
    }

    else if (command=='4')
    {
      walkL();            
      delay(500);
    }
     else if (command=='5')
    {
      walkB();            
      delay(500);
    }

     else if (command=='0')
    {
      InitialPosition();          
      delay(500);
    }

    else if (command=='6')
    {
     crawlpos();      
      delay(500);
    }

    
     else if (command=='w')
    { 
      lcd.setCursor(5, 1);
     // lcd.print("                              ");
    
      if(distance>=10)
        {
            lcd.print("CRAWL MODE");
            crawlF(); 
        }
      else { digitalWrite(buzzPin, HIGH);
        lcd.print("CRAWL REJECTED");
      delay(1000);
      digitalWrite(buzzPin, LOW);}
     
      delay(500);
    }

     else if (command=='x')
    {
   crawlB();      
      delay(500);
    }
     else if (command=='y')
    {
   crawlR();      
      delay(500);
    }

     else if (command=='z')
    {
   crawlL();      
      delay(500);
    }

     else if (command=='7')
    {
   crawlS();      
      delay(500);
    }
   else if (command=='8')
    {
   crawlStocrawlpos();      
      delay(500);
    }

     else if (command=='9')
    {
      crawlposToCar();        
      delay(500);
    }

    else if (command=='c')
    {
        lcd.setCursor(5, 1);
       lcd.print("CLIMBING");
   Climb();      
      delay(500);
    }

    else if (command=='u')
    {
    lcd.setCursor(5, 1);
       lcd.print("HIGHER CAR");
        ItoUPCar();     
      delay(500);
    }

    else if (command=='n')
    {
    lcd.setCursor(5, 1);
       lcd.print("MODE CAR");
       UptoNarrowCar() ;    
      delay(500);
    }

     else if (command=='g')
    {
    lcd.setCursor(5, 1);
       lcd.print("BALANCING");
       balance();     
      delay(500);
    }

     else if (command=='d')
    {
    lcd.setCursor(5, 1);
       lcd.print("DESCEND");
      down();     
      delay(500);
    }

    else if (command=='o')
    {
    lcd.setCursor(5, 1);
       lcd.print("SLOPE");
      slope();     
      delay(500);
    }
 
  }

  
}
