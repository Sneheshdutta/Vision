//Digital torch for blind:
const int ledPin = 13;
const int speakerPin = 6;

const int trigPin = 4;
const int echoPin = 5;

long duration;
int distance, temp=-1;


void setup() {
 
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(speakerPin,OUTPUT);
    pinMode( ledPin , OUTPUT);

    digitalWrite(ledPin, LOW);   
}

void loop() {
  // Clears the trigPin
  digitalWrite( trigPin , LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite( trigPin , LOW);
  // Reads the echoPin, returns the sound wave
  // travel time in microseconds
  duration = pulseIn( echoPin , HIGH);

  distance = duration * 0.034 / 2;



  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

   if( distance < 15 && distance > 0 ){

       // Whoop up
  for(int hz = 800; hz < 1000; hz++){
    digitalWrite(ledPin,HIGH);
    tone(speakerPin, hz, 50);
    delay(distance);
    digitalWrite(ledPin,LOW);
  }
  noTone(speakerPin);

 
     
   }

  
}
