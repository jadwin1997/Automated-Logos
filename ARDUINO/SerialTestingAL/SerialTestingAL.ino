//This 

int mode = 0;
String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  mode = int(Serial.read());
  Serial.println(mode);
 
  //Serial.println(mode);
}
if(mode == 1){
  digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}
else{
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}
}
