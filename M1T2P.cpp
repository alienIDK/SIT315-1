// C++ code
//
int LED_pin = 9; // initialize LED pin 
int motion_pin = 2; // initialize motion sensor pin 
 
void setup()
{
  pinMode(LED_pin, OUTPUT); // Set LED as output
  pinMode (motion_pin, INPUT); // Set motion sensor as input
  digitalWrite(LED_pin, LOW); // Ensure LED is off 
  Serial.begin(9600); // initialize serial
  Serial.println("Motion: NOT Detected, LED: off ");
  attachInterrupt(digitalPinToInterrupt(motion_pin), motionTrigger, RISING); // Initialize interrupt
  
}

void loop()
{}

void motionTrigger()
{
  digitalWrite(LED_pin, HIGH); // Turn on LED
  Serial.println("Motion: Detected, LED: On");
  delay(1000); // Pause for a second
}
