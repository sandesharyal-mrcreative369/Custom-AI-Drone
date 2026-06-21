#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>


//Define CE(nrf module active) and CSN(SPI active)
RF24 radio(4,5);

//Address of receiver
const byte address[]="00001";

//Data Packets to be sent
bool buttonState = 1;

//Button Define
#define button_pin 32

void setup(){
  Serial.begin(115200);

  //Define internal pull-up resistor for push-button for input
  pinMode(button_pin,INPUT_PULLUP);

  //Initialize communication
  if(!radio.begin()){
    Serial.println("Initializing the communication..");
    while(1);
  }

  Serial.println("Connected Successfully...");

  //Power Aplifier set
  radio.setPALevel(RF24_PA_LOW);

  //Set datarate
  radio.setDataRate(RF24_250KBPS);

  //Address Pipe
  radio.openWritingPipe(address);

  //Mode Selection
  radio.stopListening();



}

void loop(){
  Serial.println("Sending data packets..");

  buttonState=digitalRead(button_pin);
  Serial.println(buttonState);

  //Sending data to receiver
  bool success = radio.write(&buttonState,sizeof(buttonState));

  if(success)
    Serial.println("Sent successfully..");
  else
    Serial.println("Failed...");

  delay(50);


}