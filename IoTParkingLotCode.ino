// --- Libraries ---
#include <NewPing.h>

// --- Variables ---
// -- RGB Pins --
#define redPin 3
#define greenPin 5
#define bluePin 4

// -- Sonar Pin --
#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 200

// - Sonar Object - 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// --- Function measuring distance ---
long getDistance(){
  float distance = sonar.ping_cm();
  return distance;

}

void setup() {
  // -- Setting the pins --
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // -- Start the Serial Monitor --
  Serial.begin(9600);

}

void loop() {
  // --- Initializing the function ---
  float distance = getDistance();
  delay(500);

  // --- LED Parking Conditions ---
  // -- When Parking Space Taken --
  if (distance < 20){
    Serial.println("Parking Taken");
    Serial.println(distance);
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

  }
  
  // -- When Parking Space Available --
  else{
    Serial.println("Parking Available");
    Serial.println(distance);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    
  }

}
