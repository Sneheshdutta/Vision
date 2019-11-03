//Digi-Torch by us sensor
// defines pins numbers
const int trigPin = 4;
const int echoPin = 5;
const int buzzer = 6;
const int red = 7;
const int green = 8;
const int vibp = 9;
const int vibn = 10;
// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(vibp, OUTPUT);
pinMode(vibn, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
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

safetyDistance = distance;
if (safetyDistance <= 70 && safetyDistance >60)
{
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(vibp, LOW);
  digitalWrite(vibn, LOW);
  if(safetyDistance <= 70 && safetyDistance >60)
  { digitalWrite(buzzer, HIGH);
  delay(400);
  digitalWrite(buzzer, LOW);
  delay(400);
  }
}
else if (safetyDistance <= 60 && safetyDistance >50)
{
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(vibp, LOW);
  digitalWrite(vibn, LOW);
  if(safetyDistance <= 60 && safetyDistance >50)
  { digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(300);
  }
}
else if (safetyDistance <= 50 && safetyDistance >40)
{
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(vibp, LOW);
  digitalWrite(vibn, LOW);
  if(safetyDistance <= 50 && safetyDistance >40)
  { digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  }
}
else if (safetyDistance <= 40 && safetyDistance >30)
{
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(vibp, LOW);
  digitalWrite(vibn, LOW);
  if(safetyDistance <= 40 && safetyDistance >30)
  { digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  }
}
else if (safetyDistance <= 30 && safetyDistance >20)
{
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(vibp, HIGH);
  digitalWrite(vibn, LOW);
   if (safetyDistance <= 30 && safetyDistance >20)
  { digitalWrite(buzzer, HIGH);
  delay(80);
  digitalWrite(buzzer, LOW);
  delay(80);
  }
}
else if (safetyDistance <= 20 && safetyDistance >0)
{
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(vibp, HIGH);
  digitalWrite(vibn, LOW);
   if(safetyDistance <= 20 && safetyDistance >0)
  { digitalWrite(buzzer, HIGH);
  delay(60);
  digitalWrite(buzzer, LOW);
  delay(60);
  }
}

else{
  digitalWrite(buzzer, LOW);
  digitalWrite(red, LOW);
  digitalWrite(vibp, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(vibn, LOW);
 
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
