#include <LAudio.h>
#include <LSD.h>
 
void setup()
{
  LAudio.begin(); // Init Audio
  LSD.begin(); // Init SD card
  Serial.begin(115200);
}
 
void loop()
{
   AudioStatus status;
 
   status = LAudio.getStatus();
   if (status == AudioCommonFailed) {
     Serial.println("Audio Status = AudioCommonFailed");
   } else if (status == AudioStop) {
     Serial.println("Audio Status = AudioStop");
   } else if (status == AudioPause) {
     Serial.println("Audio Status = AudioPause");
   } else if (status == AudioResume) {
     Serial.println("Audio Status = AudioResume");
   } else if (status == AudioEndOfFile) {
     Serial.println("Audio Status = AudioEndOfFile");
     LAudio.playFile( storageSD,(char*)"space.mp3");
     LAudio.setVolume(6);
     Serial.println("play again....");
   } else {
     // Play the mp3 file the very first time
     LAudio.playFile( storageSD,(char*)"space.mp3");
     LAudio.setVolume(6);
     Serial.println("play 1st time");
 
   }
 
    delay(31000);
}
 
