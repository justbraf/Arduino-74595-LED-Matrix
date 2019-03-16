//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 10;
//Pin connected to SH_CP of 74HC595
int clockPin = 9;
////Pin connected to DS of 74HC595
int dataPin = 11;

//anode
int row[]={0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
//cathode
int col[]={0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};



void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() { 
  for (int index2 = 0; index2 < 8; index2++) {
    for (int index = 0; index < 8; index ++) {
      // take the latchPin low so 
      // the LEDs don't change while you're sending in bits:
      digitalWrite(latchPin, LOW);
      // shift out the bits:
      shiftOut(dataPin, clockPin, MSBFIRST, row[index]);  
      shiftOut(dataPin, clockPin, MSBFIRST, col[index2]);  
  
      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
      // pause before next value:
      delay(100);
    }
  }
}
