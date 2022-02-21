int a;
void setup()
{

Serial.begin(9600); 
pinMode(13, OUTPUT);
pinMode( 3, INPUT);

}

void loop()
{

a = analogRead(0); 
if(a>275)
{
digitalWrite(13, HIGH);
}
else
digitalWrite(13, LOW);
Serial.println(a, DEC); 

delay(1000);

}
