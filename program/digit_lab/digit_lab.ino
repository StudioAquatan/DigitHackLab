int const ps0=A4;
int const ps1=A5;
int const led=26;
int const button=16;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  //Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  checkPressureSensor();
  delay(100);
}

void checkPressureSensor(void){
  int ps_value0=analogRead(ps0);
  int ps_value1=analogRead(ps1);
  Serial.print(ps_value0);
  Serial.print(" ");
  Serial.println(ps_value1);

  if(ps_value0>3000 | ps_value1>3000){
    ///処理関数///
    digitalWrite(led,1);
  }else{
    digitalWrite(led,0);
  }
}

