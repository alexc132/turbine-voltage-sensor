#include <TM1637.h>

int CLK = 2;
int DIO = 3;
const byte VIN = A0;
float voltage;
int voltageInt;
String voltageString;

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
  voltage = analogRead(VIN);            // read the voltage from the EC Meter
  voltage = voltage * 5.0;
  voltage = voltage / 1024;
}

void loop() {
  readSensor();
  Serial.print("Voltage:");
  Serial.print(voltage);
  Serial.println();
  
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
  delay(100);

}
