//declare global variables
int voltagePin;
int reading;
int ledPin;
int state;
int brightness;
boolean increaseBrightness;
boolean stateChange;

void setup() {
  //initialize variables
  state = 0;
  ledPin = 3;
  voltagePin = 5;
  reading = 0;
  increaseBrightness = true;
  stateChange = false;
}

void loop() {
  stateChange = false;
  //gets a reading for what the voltage is from the bend sensor
  reading = analogRead(voltagePin);
  //this section of code determines which state to be in depending
  //on the voltage reading
  //if the reading is less than 850 then we are in state 0
  if(reading < 850)
  {
    state = 0;
  }
  //if the reading is between 850 and 950 then we are in state 1
  else if(reading>850 && reading<950){
    //this sets the stateCHange variable to true so that we only 
    //preform the action in this state once while in the state
    if(state != 1)
    {
      stateChange = true;
    }
    state = 1;
  }
  //otherwise we must be in state 2
  else{
    state = 2;
  }

//this next section of code determines what to do depending on the state we are in
    if(state == 0)
  {
    //when in state 0, turn the led on with a specific brightness
    analogWrite(3, brightness);
    //wait for 5ms
    delay(5);
    //increases the brightness till it gets to 255
    if(increaseBrightness == true)
    {
      if(brightness == 255)
      {
        //sets boolean to no longer increase brightness
        increaseBrightness = false;
      }
      else
      {
        //increment the brightness value
        brightness++;
      }
    }
    else
    {
      //decrease the brightness till it reaches 0
      if(brightness == 0)
      {
        increaseBrightness = true;
      }
      else
      {
        //decrements the brightness
        brightness --;
      }
    }
  }
  //preformed only if coming from a different state into state 1
  else if(state = 1 && stateChange == true)
  {
    //blinks the light 3 times
    for(int i=0; i<3; i++)
    {
      analogWrite(3,255);
      delay(200);
      analogWrite(3, 0);
      delay(200);
    }
  }
  //sets the brightness lower if in state 2
  else if(state == 2)
  {
    analogWrite(3, 100);
  }

}
