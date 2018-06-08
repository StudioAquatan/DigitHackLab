#define PS0 A4
#define PS1 A5
#define LED 26
#define BUTTON 16

#define TH_PS0 3000
#define TH_PS1 3000

void setup() {

  // pin mode setup
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);

  // serial setup
  Serial.begin(115200);

}

void ledOn(){
  digitalWrite(LED, 1);
}
void ledOff(){
  digitalWrite(LED, 0);
}

void loop() {
  
  if(checkPressureSensor()){
    ledOn();
  }else{
    ledOff();
  }
  delay(100);
}

bool checkPressureSensor(){
  int ps0Val=analogRead(PS0);
  int ps1Val=analogRead(PS1);

  Serial.print(ps0Val);
  Serial.print(" ");
  Serial.println(ps1Val);

  if(ps0Val>TH_PS0 | ps1Val>TH_PS1){
    return true;
  }else{
    return false;
  }
}

