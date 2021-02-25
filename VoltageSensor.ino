#include <TM1637.h>

int CLK = 2;
int DIO = 3;
const byte VIN = A0;
float voltage;

TM1637 tm(CLK, DIO);

void setup() {
  Serial.begin(9600);
  pinMode(VIN, INPUT);
  
  //Initialize TM Object
  tm.init();

  //Set brightness 0-7
  tm.set(2);

}
void readSensor() {
  voltage = analogRead(VIN);
  voltage = voltage * 5.0;
  voltage = voltage / 1024;
}

void startUp(){
  for(int i = 5; i > 0; i--){
    tm.display(3, i);
    delay(1000);
  }
}

void test(){
  for(int i = 0; i <= 201){
    readSensor();
    displayVoltage();
    //Serial.print("Voltage:");
    Serial.print(voltage);
    Serial.println();
    delay(100);
  }
}

void displayVoltage(){
  //tm.display(position, character)
  if(voltage == 0.0){
    tm.display(1, 0);
    tm.display(2, 0);
    tm.display(3, 0);
    tm.point(1);
  }else if(voltage < .1){
    tm.displayNum(voltage, 2);
    tm.display(1,0);
    tm.display(2,0);
  }else if(voltage < 1.0){
    tm.displayNum(voltage, 2);
    tm.display(1,0);
  }
}

void loop() {
}
