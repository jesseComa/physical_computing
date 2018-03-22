//This is the code for my phone fortune teller

#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// sets up values for the lcd as well as input pins
int lcd_key     = 0;
int adc_key_in  = 0;
int mic_pin = 1;
int timing = 0;
int reading = 0;

//function for actuall giving the fortune
void tellFortune(int reading)
{
  //clears the lcd screen
  lcd.clear();
  //sets cursor to the start of the first line
  lcd.setCursor(0,0);
  int selection;
  //takes the modulous of the sound level reading
  //this allows a breakdown of 4 different fortunes
  //the result will be relatively random becuase of the difficulty
  //of controlling ones own volume to such a precise degree
  selection = reading%4;
  switch(selection)
  {
    case 0:
    //prints you will get an A
      lcd.print("You will get an");
      lcd.setCursor(0,1);
      lcd.print("A");
      break;
    
    case 1:
    //prints you will get a B
      lcd.print("You will get a");
      lcd.setCursor(0,1);
      lcd.print("B");
      break;
    
    case 2: 
    //prints you will get a C
      lcd.print("You will get a");
      lcd.setCursor(0,1);
      lcd.print("C");
      break;
    
    case 3:
    //prints you will get a D
      lcd.print("You will get a");
      lcd.setCursor(0,1);
      lcd.print("D");
      break;
  }
}

void setup()
{
 //sets cursor to first line
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 //prints on first line ask for your
 lcd.print("Ask for your");
 //moves cursor to second line
 lcd.setCursor(0,1);
 //prints on second line fortune!
 lcd.print("fortune!");
}

void loop()
{
  //gather up 10 readings from the microphone
  for(int i=0; i<10; i++)
  {
    reading += analogRead(1);
    delay(10);
  }
  //result of this division gives average over 100ms
  reading=reading/10;
  //if the reading is loud enough (someone speaking directly into mic)
  if(reading>250)
  {
    //tell the persons fortune based on the loudness of what they said
    tellFortune(reading);
    //run forever
    while(true)
    {}
  }
  //resets the reading
  reading=0;
}



