#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(4,5);  // CS and CSN

//Address of receiver
const byte address[] = "00011";

//Message to be sent
 char message[20] = "";


void setup() {
 Serial.begin(115200);

 if(!radio.begin()){
  Serial.println("Try to connect....");
  while(1);
 }

 Serial.println("Connected Successfully.....");
 
//Power Amplifier Select
radio.setPALevel(RF24_PA_LOW);

//Address Writing Pipe
radio.openReadingPipe(0,address);

//Mode selection
radio.startListening();

 }


void loop() {
  // put your main code here, to run repeatedly:


  if(radio.available()){
    
    Serial.println("Received message...");

    radio.read(message,sizeof(message));

 
    Serial.println(message);
  }
  

}
