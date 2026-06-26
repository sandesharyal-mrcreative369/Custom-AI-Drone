#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF radio(4,5);  // CE and CSN

//Address Pipe
const byte address[5] = "00011";

//ACK to be sent-->Transmitter
char ack[] = "Hello Transmitter";

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

//Enable CRC
radio.setCRCLength(RF24_CRC_16);

//Preparation of ACK before sending to TX
radio.writeAckPayload(1,&ack,sizeof(ack));

//Address Pipe
radio.openReadingPipe(1,address);

//Transmitter Mode
radio.startListening();

}

void loop() {

if(radio.available()){

  //Returns size of packet
  uint32_t packetSize = radio.getDynamicPayloadSize();

  //If packetSize > 32 it clears the RX buffer
  if(packetSize > 32 || packetSize ==0){
    radio.flush_rx();
    return;
  }

  // Creates Dynamic Array
  char *bufferDataPacket = new char[packetSize + 1];
  radio.read(&bufferDataPacket,sizeof(packetSize));

  //String null termination
  bufferDataPacket[packetSize] = '\0';

  Serial.print("Received Size: ");
  Serial.print(packetSize);
  Serial.print("Bytes: ");
  Serial.println(bufferDataPacket);

  //Sending ACK again and again
  radio.writeAckPayload(1,&ack,sizeof(ack));

  //Free UP Memory
  delete[] bufferDataPacket;

}

}
