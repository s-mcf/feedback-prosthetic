#define GREEN 14
#define BLUE 15
#define RED 12
#define delayTime 20

void setup()
{                
  Serial.begin(38400);
    pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
}

float val;

void loop(){
  val = min((analogRead(1) - 700.0f) * 10.0f, 250.0f);
  Serial.print("analog 1 is: ");
  Serial.println(val);
  analogWrite(RED, val);
  delay(10);
}

