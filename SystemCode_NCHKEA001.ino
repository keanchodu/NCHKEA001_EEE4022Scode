/* This code performs all the tests for the system designed in this paper. 16 pins on the Arduino are used to control the multiplexing devices' select
 *  lines. These pins are set to GPIO pins in the output mode. When separate electrode current injection and potential measurement occur, all 4 table 
 *  lists are used. For simultaneous current injection and potential measurement on shared electrodes, 2 of the table lists are used. Three of the 
 *  Arduino's analog input pins are used to read the measured currents and potentials from the system. These values are displayed in the serial monitor
 *  and must be multiplied by 3.3 and divided by 4096 to account for the reference voltage of the Arduino and the bit size of the ADCs. 
*/

//select lines for multiplexing devices
int s[4] = {13,12,11,10};
int k[4] = {5,6,A2,A3};
int m[4] = {A1,A0,SCK,MOSI};
int h[4] = {9,20,21,22};
int i;
//int sig = 5;

//Tables for multiplexers
int muxtable[16][4] = {
  {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {1,1,0,0},
  {0,0,1,0}, {1,0,1,0}, {0,1,1,0}, {1,1,1,0},
  {0,0,0,1}, {1,0,0,1}, {0,1,0,1}, {1,1,0,1},
  {0,0,1,1}, {1,0,1,1}, {0,1,1,1}, {1,1,1,1}
}; 
int muxtablea[16][4] = {
  {1,0,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,1,0}, 
  {1,0,1,0}, {0,1,1,0}, {1,1,1,0}, {0,0,0,1},
  {1,0,0,1}, {0,1,0,1}, {1,1,0,1}, {0,0,1,1}, 
  {1,0,1,1}, {0,1,1,1}, {1,1,1,1}, {0,0,0,0}
}; 
int muxtablem[16][4] = {
  {0,1,0,0}, {1,1,0,0}, {0,0,1,0}, {1,0,1,0},
  {0,1,1,0}, {1,1,1,0}, {0,0,0,1}, {1,0,0,1},
  {0,1,0,1}, {1,1,0,1}, {0,0,1,1}, {1,0,1,1},
  {0,1,1,1}, {1,1,1,1}, {0,0,0,0}, {1,0,0,0}
}; 
int muxtableh[16][4] = {
  {1,1,0,0}, {0,0,1,0}, {1,0,1,0}, {0,1,1,0},
  {1,1,1,0}, {0,0,0,1}, {1,0,0,1}, {0,1,0,1},
  {1,1,0,1}, {0,0,1,1}, {1,0,1,1}, {0,1,1,1},
  {1,1,1,1}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}
}; 

//Analog read pins
int sensorPin = A4;
int sense2 = {A5};
int sense3 = {1};
int val = 0;
int val2 = 0;
int val3 = 0;

unsigned long previousInjectTime = 0;
const long injectInterval = 34000;
int count = 0;

void setup(){
  //pinMode(sig,OUTPUT);
  for(i=0;i<4;i++) pinMode(s[i],OUTPUT);
  for(i=0;i<4;i++) pinMode(k[i],OUTPUT);
  for(i=0;i<4;i++) pinMode(m[i],OUTPUT);
  for(i=0;i<4;i++) pinMode(h[i],OUTPUT);
  Serial.begin(9600);
}

void loop(){
  unsigned long currentTime = millis();

  if(currentTime-previousInjectTime > injectInterval){
    previousInjectTime += injectInterval;

    val = analogRead(sensorPin);
    val2 = analogRead(sense2);
    //digitalWrite(sig,HIGH);
    if (count<16){
      selection(count);
      count = count+1;
    }
    else if (count==16){
      count = 0;
      selection(count);
    }
    Serial.println(count);
    Serial.print("Positive current: ");
    Serial.println(val);
    Serial.print("Negative current: ");
    Serial.println(val2);
    delay(1000);
    
    
  }

  else if(currentTime-previousInjectTime<injectInterval){
    //digitalWrite(sig,HIGH);
    for(i=0;i<16;i++){
      val3 = analogRead(sense3);
      selection2(i);
      //Serial.print("Potential measurement: ");
      Serial.println(val3);
      delay(100);
    }
  }
 
    //for(i=0;i<16;i++){    
      //val = analogRead(sensorPin);
      //val3 = analogRead(sense3);
      //val2 = analogRead(sense2);
      //selection(i);
      //digitalWrite(sig,HIGH);
      //Serial.print("Positive current: ");
      //Serial.println(val);
      //Serial.print("Negative current: ");
      //Serial.println(val2);
      //delay(14000); //in miliseconds
      //selection2(i);
      //Serial.print("Potential measurement: ");
      //Serial.println(val3);
      //delay(1000);
    //}
    
}

void selection(int j){
  digitalWrite(s[0],muxtable[j][0]);
  digitalWrite(s[1],muxtable[j][1]);
  digitalWrite(s[2],muxtable[j][2]);
  digitalWrite(s[3],muxtable[j][3]);
  digitalWrite(k[0],muxtablea[j][0]);
  digitalWrite(k[1],muxtablea[j][1]);
  digitalWrite(k[2],muxtablea[j][2]);
  digitalWrite(k[3],muxtablea[j][3]);
}

//Depending on the test being run, selection for m either from muxtablem or muxtable
//Depending on the test being run, selection for h either from muxtableh or muxtablea
void selection2(int j){
  digitalWrite(m[0],muxtable[j][0]);
  digitalWrite(m[1],muxtable[j][1]);
  digitalWrite(m[2],muxtable[j][2]);
  digitalWrite(m[3],muxtable[j][3]);
  digitalWrite(h[0],muxtablea[j][0]);
  digitalWrite(h[1],muxtablea[j][1]);
  digitalWrite(h[2],muxtablea[j][2]);
  digitalWrite(h[3],muxtablea[j][3]);
}
