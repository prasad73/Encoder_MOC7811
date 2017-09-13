const int pinA=2;//ref 
unsigned int lastCount=0;
volatile int c=0;
void isr1()
{      
 static unsigned long lastInterruptTime=0;
 unsigned long interruptTime=millis();
 if(interruptTime-lastInterruptTime>5)
 {
  c++;
 }
 lastInterruptTime=interruptTime;
}
void setup()
{
  pinMode(pinA,INPUT);
  attachInterrupt(digitalPinToInterrupt(pinA),isr1,RISING); 
  Serial.begin(9600);
  Serial.println("start");
 } 
 
 
 void loop()
 {
  if(c!=lastCount)
  {
    Serial.println(c);
    lastCount=c;
  }
  if(c>360)
  c=0;
 }
