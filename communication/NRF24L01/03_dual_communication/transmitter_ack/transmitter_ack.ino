#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(4,5);

//Receiver address 
const byte address[] = "00001";

//Message to be sent 
const char message[] = "Hello Reciever";

//Data packets to be received from Receiver
char receiverData[50] = "";

void setup() {
Serial.begin(115200);

//SPI.begin(18,19,23,5);


if(!radio.begin()){
  Serial.println("Hardware error or failed to connect...");
  while(1);
}



Serial.println("Connected Successfully....");

//Power Amplifier set
radio.setPALevel(RF24_PA_LOW);

//Set channel
radio.setChannel(100);

//Enable Auto Acknowledge Payload
radio.enableAckPayload();

//Enable dynamic Payload
radio.enableDynamicPayloads();

//Address Pipe
radio.openWritingPipe(address);


//Transmitter mode set
radio.stopListening();

//For Debugging Purpose

// Serial.print("Chip Connected = ");
// Serial.println(radio.isChipConnected());

// radio.printDetails();

}

void loop() {

  bool success = radio.write(message,sizeof(message));
  Serial.print("Message has been sent to Receiver: ");
  Serial.println(message);

  if(success){
    
    Serial.println("Successfully Delievered...");

    if(radio.isAckPayloadAvailable()){
      radio.read(&receiverData, sizeof(receiverData));
      Serial.print("ACk has been received from Receiver..");
      Serial.println(receiverData);

    }
  }
    else{
    Serial.println("Delivery failed.No Ack Received");
  }

  delay(1000);

}
