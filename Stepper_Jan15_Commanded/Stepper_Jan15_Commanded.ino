#define enable  8
#define xDir    5   // X Axis Direction Pin   Right Reloader
#define xStep   2   // X Axis Step Pin
// #define yDir    6   // Y Axis Direction Pin   Left Reloader
// #define yStep   3   // Y Axis Step Pin
// #define zDir    7   // Z Axis Direction Pin   Azimuth Control
// #define zStep   4   // Z Axis Step Pin

//int steps = 3200;      // Steps to move og 6400, 200 steps per rev
int stepDelay = 1000;    // Delay between each pause (1 ms)
//int incomingByte;   // for incoming serial data
int oldAngle = 0;
int steps;
int newAngle;
bool direction;

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


void loop() {
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                String incomingByte = Serial.readString();
                steps = round(incomingByte.toInt() / 1.8);
                newAngle = incomingByte.toInt() - oldAngle;
                
//                if (incomingByte.toInt() < 0) {
//                	direction = false;
//                } else {
//                	direction = true;
//                }

                // say what you got:
                Serial.print("Commanded Angle: ");
                Serial.println(incomingByte);
                Serial.println(steps);
                Serial.print(direction);
                 step(false,xDir,xStep,steps);
        }
}


      
