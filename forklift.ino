//https://aouni0n.github.io
const int ENA = 3; 
const int ENB = 5;
const int IN1 = 2; 
const int IN2 = 4; 
const int IN3 = 7; 
const int IN4 = 8; 
const int relay1 = A0;
const int relay2 = A1; 
int val;
int Speeed = 90;  // Motor B 
int Speeed1 = 90; // Motor A 
int turnSpeed = 80;  // Motor B turn speed
int turnSpeed1 = 80; // Motor A turn speed



void applySpeed() {
  analogWrite(ENA, Speeed1);
  analogWrite(ENB, Speeed);
}

void applyTurnSpeed() {
  analogWrite(ENA, turnSpeed1);
  analogWrite(ENB, turnSpeed);
}

void Stop() {
  Serial.println("Wheels Stopped");
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  Serial.println("Moving Forward");
  applySpeed();
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(650);
  Stop();
}

void back() {
  Serial.println("Moving Backward");
  applySpeed();
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(650);
  Stop();
}

void left() {
  Serial.println("Turning Left");
  applyTurnSpeed(); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);
  Stop();
}

void right() {
  Serial.println("Turning Right");
  applyTurnSpeed(); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
  Stop();
}


void forkliftStop() {
  Serial.println("Forklift: PULLEY STOPPED");
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH); 
}

void forkliftUp() {
  Serial.println("Forklift: LIFTING UP");
  digitalWrite(relay1, LOW);  
  digitalWrite(relay2, HIGH); 
  delay(1500);
  forkliftStop();
}

void forkliftDown() {
  Serial.println("Forklift: LOWERING DOWN");
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW); 
  delay(1500);
  forkliftStop();
}


void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Stop();
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH); 
  Serial.println("Robot & Forklift System Ready");
}

void loop() {
  if (Serial.available() > 0) {
    val = Serial.read();
    Serial.println(val);
    if (val == 'F') { forward(); }
    else if (val == 'B') { back(); }
    else if (val == 'L') { left(); }
    else if (val == 'R') { right(); }
    else if (val == 'T') { Stop(); }
    else if (val == 'U') { forkliftUp(); }   
    else if (val == 'D') { forkliftDown(); } 
    else if (val == 'P') { forkliftStop(); } 
  }
}