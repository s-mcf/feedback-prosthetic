// HWeekend 2014 - Feedback for augmented prostetic limb


#define GREEN 14
#define BLUE 15
#define RED 12
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

float val;
float val2;

void loop(){
  val = max(min((analogRead(1) - 700.0f) * 10.0f, 250.0f), 0);
  Serial.print("analog 1 is: ");
  Serial.println(val);
  analogWrite(RED, 255 - val);
  analogWrite(BLUE, val);
  
  //this section is for reading the analog pressure sensor
  val2 = analogRead(5);
  Serial.print("analog 2 is: ");
  Serial.println(val2);
  delay(10);
  
}

