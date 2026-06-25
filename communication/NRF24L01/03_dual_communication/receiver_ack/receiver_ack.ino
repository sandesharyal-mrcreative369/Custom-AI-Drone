#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

// CE and CSN Pin activate
RF24 radio(4,5);

//Receiver address 
const byte address[] = "00001";

//Message to be received 
char message[20] = "";

//ACK to be Sent to TRANSMITTER
char ack[50] = "Hello Transmitter Data received.";

void setup() {
Serial.begin(115200);

Serial.println("RECEIVER TEST 999");

//SPI.begin(18,19,23,5);


if(!radio.begin()){
  Serial.println("Hardware error or failed to connect...");
  while(1);
}


Serial.println("Connected Successfully....");

//Power Amplifier set
radio.setPALevel(RF24_PA_LOW);


//Set Channel 
radio.setChannel(100);

//Enable Auto Acknowledge Payload
radio.enableAckPayload();

//Enable Dyanmic Payload
radio.enableDynamicPayloads(); 

//Preparation of ACK
radio.writeAckPayload(0,&ack,sizeof(ack));

//Address Pipe
radio.openReadingPipe(0,address);

//Transmitter mode set
radio.startListening();

Serial.print("Chip Connected = ");
Serial.println(radio.isChipConnected());

radio.printDetails();


}

void loop() {

// Serial.print("From transmiter: ");
// Serial.println(radio.available());

if(radio.available()){

  radio.read(message,sizeof(message));
  Serial.print("Message received from Tranmitter: ");
  Serial.println(message);

  //Loading the ACK for next time
  radio.writeAckPayload(0,&ack,sizeof(ack));
  Serial.println("ACK Sent to transmitter");
}

}
