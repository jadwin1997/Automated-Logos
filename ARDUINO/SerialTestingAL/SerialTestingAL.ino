//This 

int mode = 0;
String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
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
  
}
else{
  digitalWrite(LED_BUILTIN,LOW);
}
}
