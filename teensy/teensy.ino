// HWeekend 2014 - Feedback for augmented prostetic limb


#define GREEN 14
#define BLUE 15
#define RED 12
#define MOTOR 10
#define PRES_PIN 5
#define delayTime 20
#define pres_thres 150

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

float temp;
float pres;

void loop(){
  temp = max(min((analogRead(1) - 700.0f) * 10.0f, 250.0f), 0);
  Serial.print("temp: ");
  Serial.println(temp);
  setColor(255 - temp, 255, temp);

  //this section is for reading the analog pressure sensor
  pres = analogRead(PRES_PIN);
  Serial.print("pres: ");
  Serial.println(pres);
  analogWrite(MOTOR, pres);

  delay(delayTime);
}

void setColor(int red_val, int green_val, int blue_val){
  analogWrite(RED, red_val);
  analogWrite(GREEN, green_val);
  analogWrite(BLUE, blue_val);
}
