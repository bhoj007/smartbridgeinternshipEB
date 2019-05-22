#define ledPin 2 //On Board LED

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 10; //Resolution 8, 10, 12, 15

//=======================================================================
//                    Power on setup
//=======================================================================
void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO2 to be controlled
  ledcAttachPin(ledPin, ledChannel);
}
void loop(){
for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){

ledcWrite(ledChannel,dutyCycle);
delay(15);
}

for(int dutyCycle = 255; dutyCycle >=0 ; dutyCycle--){

ledcWrite(ledChannel,dutyCycle);
delay(15);
}
}
