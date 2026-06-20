#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(4,5);  // CS and CSN

//Address of receiver
const byte address[] = "00011";

//Message to be sent
const char message[] = "Hello World";


void setup() {
 Serial.begin(115200);

 if(!radio.begin()){
  Serial.println("Try to connect....");
  while(1);
 }

 Serial.println("Connected Successfully.....");

 //Power Amplifier Select
 radio.setPALevel(RF24_PA_LOW);


//Address(Writing Pipe)
radio.openWritingPipe(address);

//Mode Select
radio.stopListening();


 }


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Sending messages...");

  bool success = radio.write(&message,sizeof(message));

  if(success){
    Serial.println("ACK Received");
  } 
  else{
    Serial.println("Delivery failed..");
  }

  delay(1000);

}
