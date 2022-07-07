#define echoPin 12
#define trigPin 13
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9
#define MotorL1 5
#define MotorL2 4
#define MotorLE 3

long sure, uzaklik;

void setup() {

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);


pinMode(MotorL1, OUTPUT);
pinMode(MotorL2, OUTPUT);
pinMode(MotorLE, OUTPUT);
pinMode(MotorR1, OUTPUT);
pinMode(MotorR2, OUTPUT);
pinMode(MotorRE, OUTPUT);

Serial.begin(9600);
  
}

void loop(){

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

sure = pulseIn(echoPin, HIGH);
uzaklik = sure / 29.1 /2;

Serial.println(uzaklik);

if (uzaklik <15){  
    geri();
    delay(150);
    sag();  
  }
 else {
 
 ileri();
  }
}

void ileri() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, 150);
  
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, 150);  
}

void sag(){
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, 0);
  
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 150);
}
void geri(){
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 150);
  
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 150);
}
