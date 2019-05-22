const int trigPin=4;
const int echoPin=5;
long duration;
int distance;
void setup() {
 pinMode(2,OUTPUT);
 pinMode(trigPin,OUTPUT);




pinMode(echoPin,INPUT);
Serial.begin(115200);
}
void loop() {
 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;
Serial.print("Distance");
Serial.println(distance); 
if(distance > 50)
digitalWrite(2,HIGH);
else
digitalWrite(2,LOW);

}
