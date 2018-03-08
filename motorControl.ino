//pins
int trigger;
int echo;
int motor1;
int motor2;

 //values that are used for the ultrasonic sensor
long duration;
int distance;
float intensity;

void setup() {
  //pin values for buttons, rgb LED and ultrasonic sensor
  trigger = 4;
  echo = 7;
  motor1 = 3;
  motor2 = 6;

  //echo pin set to input to take in data from the 
  //ultrasonic sensor
  pinMode(echo, INPUT);
  //trigger set to output to let ultrasonic sensor know when
  //a distance value is wanted
  pinMode(trigger, OUTPUT);
  //pins for led are set to output so the arduino can provide power to light it
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  
  //initial values for colors so that they arent garbage values
  Serial.begin(9600);
}

void loop() {
/*****************
 * This section of code is to determine the distance that a person or object
 * is to the cube
 */
//sets the trigger low state so it does not activate the ultrasonic sensor
digitalWrite(trigger, LOW);
//delays for 2 microseconds
delayMicroseconds(2);
// sets the trigger on HIGH state for 10 micro seconds
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
//sets the trigger on low state
digitalWrite(trigger, LOW);
// Reads the pulse sent back ny the echo pin
//the pulse width is the amount of time the sound wave traveled from the 
//sensor to the object and back to the sensor.
duration = pulseIn(echo, HIGH);
// Calculating the distance between the object and sensor
//takes duration of flight and divides by 2 since we want one way, not round trip.
//then multiplies by the speed of sound in cm per microsecond
distance= duration*0.034/2;

//this is to scale the values on the sensor so that high values
//will give a distance of 100 which is used by the intensity calculation
if(distance > 100)
{
  distance = 100;
}
//this takes the distance and makes it so that there is an intensity value
//that is larger, the closer the object is to the sensor
intensity = float(distance) /25;
intensity = 1-intensity;
//if the intensity ends up being negative, set it to 0
if(intensity<0)
{
  intensity =0;
}
//sets the motor speed depending on how close the person is
//requires 1 motor input to be set to ground
Serial.println(intensity);
analogWrite(motor1,0);
analogWrite(motor2, intensity*255);

}

