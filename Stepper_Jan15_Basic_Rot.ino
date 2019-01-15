#define enable  8
#define xDir    5   // X Axis Dorection Pin   Right Reloader
#define xStep   2   // X Axis Step Pin
#define yDir    6   // Y Axis Dorection Pin   Left Reloader
#define yStep   3   // Y Axis Step Pin
#define zDir    7   // Z Axis Dorection Pin   Azimuth Control
#define zStep   4   // Z Axis Step Pin

//int steps = 3200;      // Steps to move og 6400, 200 steps per rev
int stepDelay = 1000;    // Delay between each pause (1 ms)

// 
void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(100);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    Serial.print(i);
    Serial.print("\n");
    delayMicroseconds(stepDelay);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(stepDelay);
  }
}

//
void setup(){
  pinMode(xDir, OUTPUT); pinMode(xStep, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(enable, LOW);
  Serial.begin(9600);
}

// Loop rotations back and forth for testing
void loop(){
  step(false, xDir, xStep, 201);   // Rotate X axis CW 1 turn
  delay(2000);
  step(true, xDir, xStep, 201);    // Rotate X axis CCW 1 turn
  delay(2000);
}

      
