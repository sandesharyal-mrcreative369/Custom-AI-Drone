#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(4,5);  // CE and CSN

//Address Pipe
const byte address[] = "00011";

//Data to be sent
char dataPacket[] = "Hello Receiver";

//ACk to be received
char ack[] = "";


void setup() {
 Serial.begin(115200);

 if(!radio.begin()){
  Serial.println("Hardware Error...");
  while(1);
 }

 Serial.println("Started NRF comunnication..");

 //Channel Set
 radio.setChannel(100);

 //Power Amplifier
 radio.setPALevel(RF24_PA_LOW);

 //Enable Auto ACK Payload
 radio.enableAckPayload();

//Enable Dynamic Payload
radio.enableDynamicPayloads();

  //Address Pipe
 radio.openWritingPipe(address);

 //Transmitter Mode
 radio.stopListening();

}

void loop() {

  bool success = radio.write(dataPacket,sizeof(dataPacket));
  Serial.print("Data-->receiver successfully: ");
  Serial.println(dataPacket);

  if(success){
    Serial.println("Successfully Delievred");

    if(radio.isAckPayloadAvailable()){
      radio.read(ack,sizeof(ack));
      Serial.print("ACK Receive: ");
      Serial.println(ack);

    }

  }
  else{
    Serial.println("Failed No ACK Received..");
  }
 

}
