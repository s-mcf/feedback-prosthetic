// HWeekend 2014 - Feedback for augmented prostetic limb


#define GREEN 14
#define BLUE 15
#define RED 12
#define MOTOR 10
#define PRES_PIN 5
#define BUZZER 6
#define delayTime 20
#define pres_thres 150

void setup()
{                
  Serial.begin(38400);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  selftest();
}

void selftest() {
  setColor(255, 0, 0);
  for(int i = 0; i < 20; i++){
    digitalWrite(BUZZER, HIGH);
    delay(3);
    digitalWrite(BUZZER, LOW);
    delay(3);
  }
  setColor(0, 255, 0);
  for(int i = 0; i < 50; i++){
    digitalWrite(BUZZER, HIGH);
    delay(2);
    digitalWrite(BUZZER, LOW);
    delay(2);
  }
  setColor(0, 0, 150);
  for(int i = 0; i < 100; i++){
    digitalWrite(BUZZER, HIGH);
    delay(1);
    digitalWrite(BUZZER, LOW);
    delay(1);
  }
  setColor(255, 255, 255);
  delay(1000);
}

float temp;
float pres;

void loop(){
  temp = max(min((analogRead(1) - 700.0f) * 10.0f, 250.0f), 0);
  Serial.print("temp: ");
  Serial.println(temp);
  setColor(temp, 0, 255 - temp);

  //this section is for reading the analog pressure sensor
  pres = analogRead(PRES_PIN);
  Serial.print("pres: ");
  Serial.println(pres);
  analogWrite(MOTOR, pres);

  delay(delayTime);
}

void setColor(int red_val, int green_val, int blue_val){
  analogWrite(RED, 255 - red_val);
  analogWrite(GREEN, 255 - green_val);
  analogWrite(BLUE, 255 - blue_val);
}
