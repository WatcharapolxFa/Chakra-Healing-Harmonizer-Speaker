#include <SD.h>                      
//#define SD_ChipSelectPin 53  
#define SD_ChipSelectPin 4  
#include <TMRpcm.h>          
#include <SPI.h>
char x = '0';
TMRpcm tmrpcm;  

void setup() {

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;   // don't do anything more if not
  }
  //tmrpcm.play("1"); //the sound file "1" will play each time the arduino powers up, or is reset
}

void loop() {

  if (Serial.available()) {
    x = Serial.read();
    Serial.println(x);
    if (x == '1') {  //ถ้า SerialMonitor ส่งค่า 1 มาให้ Arduino ให้ทำคำสั่งใน if นี้
      tmrpcm.play("level1.wav"); //เล่นไฟล์เสียง 1.wav
    }
    if (x == '2') {
      tmrpcm.play("level2.wav"); //เล่นไฟล์เสียง 2.wav
    }
    if (x == '3') { 
      tmrpcm.play("level3.wav"); //เล่นไฟล์เสียง 3.wav
    }
    if (x == '4') { 
      tmrpcm.play("level4.wav"); //เล่นไฟล์เสียง 4.wav
    }
    if (x == '5') { 
      tmrpcm.play("level5.wav"); //เล่นไฟล์เสียง 5.wav
    }
    if (x == '6') { 
      tmrpcm.play("level6.wav"); //เล่นไฟล์เสียง 6.wav
    }
  }
}
