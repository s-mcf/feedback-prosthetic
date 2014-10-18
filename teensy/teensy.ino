void setup()
{                
  Serial.begin(38400);
}

int val;

void loop()                     
{
  val = analogRead(1);
  Serial.print("analog 1 is: ");
  Serial.println(val);
  delay(200);
}

