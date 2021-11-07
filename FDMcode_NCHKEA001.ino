/* This code is for testing the simultaneous current injection and potential measurements on shared electrodes circuit designed by Tapson et al.
 *  16 of the Arduino's pins are used as GPIO pins to output square waves at different frequencies. The dalay function is used to set the different frequencies for
 *  each wave. The code also controls two of the select pins on the multiplexers. The other two multiplexer pins are set to ground as there are not enough pins to 
 *  control all the select lines of the multiplexers. Pin A1 is used to read the analog input value of the measured current or the measured potential, depending on 
 *  which section of the code is uncommented.
*/

int i;
int s[16] = {13,12,11,10,6,5,21,20,A3,A4,A5,24,23,22,1,A2}; /*Pins for the output signals*/
int k[2] = {A0,9}; /*Select pins*/
int count = 0;

int sense2 = {A1}; /*analog read pin*/
int val2 = 0;

//multiplexer table
int muxtable[16][4] = {
  {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {1,1,0,0},
  {0,0,1,0}, {1,0,1,0}, {0,1,1,0}, {1,1,1,0},
  {0,0,0,1}, {1,0,0,1}, {0,1,0,1}, {1,1,0,1},
  {0,0,1,1}, {1,0,1,1}, {0,1,1,1}, {1,1,1,1}
}; 


void setup(){
  for(i=0;i<16;i++) pinMode(s[i],OUTPUT);
  for(i=0;i<2;i++) pinMode(k[i],OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println("Potential measurements: ");
  val2 = analogRead(sense2);
  //count = count+1;
  //Serial.println(count);
  //Serial.print("Current: ");
  Serial.println(val2);

  //code for multiplexer selection and input signal frequencies from 50Hx to 900Hz

  selection(0);
  digitalWrite(s[0],HIGH);
  digitalWrite(s[1],HIGH);
  digitalWrite(s[2],HIGH);
  digitalWrite(s[3],HIGH);
  digitalWrite(s[4],HIGH);
  digitalWrite(s[5],HIGH);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.01);
  selection(1);
  digitalWrite(s[0],LOW);
  digitalWrite(s[1],HIGH);
  digitalWrite(s[2],HIGH);
  digitalWrite(s[3],HIGH);
  digitalWrite(s[4],HIGH);
  digitalWrite(s[5],HIGH);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.005);
  selection(2);
  digitalWrite(s[1],LOW);
  digitalWrite(s[2],HIGH);
  digitalWrite(s[3],HIGH);
  digitalWrite(s[4],HIGH);
  digitalWrite(s[5],HIGH);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.00333);
  selection(3);
  digitalWrite(s[2],LOW);
  digitalWrite(s[3],HIGH);
  digitalWrite(s[4],HIGH);
  digitalWrite(s[5],HIGH);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.0025);
  selection(4);
  digitalWrite(s[3],LOW);
  digitalWrite(s[4],HIGH);
  digitalWrite(s[5],HIGH);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.002);
  selection(5);
  digitalWrite(s[4],LOW);
  digitalWrite(s[5],HIGH);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.001667);
  selection(6);
  digitalWrite(s[5],LOW);
  digitalWrite(s[6],HIGH);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.0014285);
  selection(7);
  digitalWrite(s[6],LOW);
  digitalWrite(s[7],HIGH);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.00125);
  selection(8);
  digitalWrite(s[7],LOW);
  digitalWrite(s[8],HIGH);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.0011);
  selection(9);
  digitalWrite(s[8],LOW);
  digitalWrite(s[9],HIGH);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.001);
  selection(10);
  digitalWrite(s[9],LOW);
  digitalWrite(s[10],HIGH);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.00077);
  selection(11);
  digitalWrite(s[10],LOW);
  digitalWrite(s[11],HIGH);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.0007145);
  selection(12);
  digitalWrite(s[11],LOW);
  digitalWrite(s[12],HIGH);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.000665);
  selection(13);
  digitalWrite(s[12],LOW);
  digitalWrite(s[13],HIGH);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.000625);
  selection(14);
  digitalWrite(s[13],LOW);
  digitalWrite(s[14],HIGH);
  digitalWrite(s[15],HIGH);
  delay(0.000588);
  selection(15);
  digitalWrite(s[14],LOW);
  digitalWrite(s[15],HIGH);
  delay(0.000555);
  digitalWrite(s[15],LOW);
  delay(0.000555);
}

//Code for controlling multiplexer select channels
void selection(int j){
  digitalWrite(k[0],muxtable[j][0]);
  digitalWrite(k[1],muxtable[j][1]);
  digitalWrite(k[2],muxtable[j][2]);
  digitalWrite(k[3],muxtable[j][3]);
}
