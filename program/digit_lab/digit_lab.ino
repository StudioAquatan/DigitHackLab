#include <WiFi.h>
#include <HTTPClient.h>
#include "setting.h"

#define PS0 A4
#define PS1 A5
#define LED 26
#define BUTTON 16

#define TH_PS0 3000
#define TH_PS1 3000

#define DEBUG

void ledOn(){
  digitalWrite(LED, 1);
}
void ledOff(){
  digitalWrite(LED, 0);
}

void ledToggle(){
  if(digitalRead(LED)){
    ledOff();
  }else{
    ledOn();
  }
}

void post(){
  Serial.println("post");
  HTTPClient http;
  http.begin("http://192.168.42.2/lab");
  http.GET();
  http.end();
}

void setup() {

  // pin mode setup
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);

  // serial setup
  Serial.begin(115200);

  // wifi setup
  WiFi.begin(APSSID, APPASS);
  Serial.println("WiFi connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    ledToggle();
    delay(500);
  }
  Serial.println("\nconnencted");
  ledOff();

}

void loop() {
  if(checkPressureSensor()){
    post();
    ledOn();
    while(checkPressureSensor()){
      delay(100);
    }
  }else{
    ledOff();
  }
  delay(50);
}

bool checkPressureSensor(){
  int ps0Val=analogRead(PS0);
  int ps1Val=analogRead(PS1);

#ifdef DEBUG
  Serial.print(ps0Val);
  Serial.print(" ");
  Serial.println(ps1Val);
#endif

  if(ps0Val>TH_PS0 | ps1Val>TH_PS1){
    return true;
  }else{
    return false;
  }
}

