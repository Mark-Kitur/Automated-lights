#include <Arduino.h>
#include "sound.h"

Eloquent::ML::Port::RandomForestClassifier clf;
int signal =A0;
int threshold =4;
int relay =2;
void setup() {
  // put your setup code here, to run once:
  pinMode(signal,INPUT);
  Serial.begin(9600);
  pinMode(threshold,INPUT);
  pinMode(relay,OUTPUT);
  
}

void loop() {
  //put your main code here, to run repeatedly
  float value = analogRead(signal);
  int threshold_value = digitalRead(threshold);
  if(threshold_value==1){
    Serial.println(value);
    float arr[8];
    
    for (int i=0;i<8;i++){
      float new_value = value;
      arr[i]=new_value;
      
    }
    Serial.print("Predicted label:");
    int predicted= clf.predict(arr);
    Serial.println(predicted);
    if(predicted ==1){
      Serial.println("Switch ON the lights");
      digitalWrite(relay,1);
    }
    else{
      Serial.println("Switch OFF the lights");
      digitalWrite(relay,0);
    }
    delay(150);
    
  }
  
  delay(400);

}

